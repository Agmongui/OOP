#include "BankAccount.h"

// Конструктор без параметров
BankAccount::BankAccount()
{
    accountNumber = 1;
    ownerName = "Unknown";
    balance = 0.0;
    active = true;

    currency.code = "EUR";
    currency.symbol = "€";
}

// Конструктор с параметрами (через список инициализации)
BankAccount::BankAccount(long long number,
                         const string& owner,
                         double initialBalance,
                         const Currency& accountCurrency)
    : accountNumber(number),
      ownerName(owner),
      balance(initialBalance),
      active(true),
      currency(accountCurrency)
{
}

// Конструктор с номером и владельцем
BankAccount::BankAccount(long long number,
                         const string& owner)
{
    accountNumber = number;
    ownerName = owner;
    balance = 0.0;
    active = true;

    currency.code = "EUR";
    currency.symbol = "€";
}