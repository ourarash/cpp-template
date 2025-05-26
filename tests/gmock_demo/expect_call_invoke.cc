

#include <exception>
#include <iostream>
#include <vector>

#include "bankserver/atm_machine.h"
#include "bankserver/bankserver.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
//-----------------------------------------------------------------------------

class MockBankServer : public BankServer {
public:
  MOCK_METHOD(void, Connect, (), (override));
  MOCK_METHOD(void, Disconnect, (), (override));
  MOCK_METHOD(void, Credit, (int, int), (override));
  MOCK_METHOD(void, Debit, (int, int), (override));
  MOCK_METHOD(bool, DoubleTransaction, (int, int, int), (override));
  MOCK_METHOD(int, GetBalance, (int), (const, override));
};

using ::testing::_;
using ::testing::Assign;
using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Exactly;
using ::testing::Invoke;
using ::testing::InvokeWithoutArgs;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::StrEq;
using ::testing::ThrowsMessage;
using ::testing::Unused;
using ::testing::WithArgs;

void PrintHello() { std::cout << "Hello!" << std::endl; }
double Square(double x) { return (x * x); }
int Sum(int x, int y) { return x + y; }
int Return10000() { return 10000; }

class Helper {
public:
  static int ComplexJobSingleParameter(int x) { return (x * x); }
  static int ComplexJobMultiParameter(int x, int y, int z) {
    return (x * y * z);
  }
};

TEST(AtmMachine, CanWithdrawWithMultipleInvoke) {
  // Arrange
  const int account_number = 1234;
  const int withdraw_value = 1000;
  const int number_of_calls = 11;

  NiceMock<MockBankServer> mock_bankserver;

  // Expectations
  EXPECT_CALL(mock_bankserver, GetBalance(account_number))
      .Times(number_of_calls)
      .WillOnce(Invoke(Square))
      .WillOnce(Square)
      .WillOnce(DoAll(InvokeWithoutArgs(PrintHello), Return(1000)))
      .WillOnce([](int n) { return Square(n); })
      .WillOnce([](int n) { return Sum(n, 1000); })
      .WillOnce([]() { return Return10000(); })
      .WillOnce(Return10000)
      .WillRepeatedly(Return(Return10000()));

  EXPECT_CALL(mock_bankserver, Debit(account_number, withdraw_value))
      .WillRepeatedly(Invoke([](int a, int w) {
        std::cout << "a: " << a << ", w: " << w << std::endl;
      }));

  // Act
  AtmMachine atm_machine(&mock_bankserver);
  bool withdraw_result = true;
  for (int i = 0; i < number_of_calls; i++) {
    withdraw_result =
        withdraw_result && atm_machine.Withdraw(account_number, withdraw_value);
  }

  // Assert
  EXPECT_TRUE(withdraw_result);
}
