#include "BankAccount.h"
#include <iostream>

using namespace std;

// Конструктор без параметров
BankAccount::BankAccount()
{
    accountNumber = 1;
    ownerName = "Unknown";
    balance = 0.0;
    active = true;

    currency.code = "RUB";
    currency.symbol = "₽";
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
    if (accountNumber <= 0)
    {
        accountNumber = 1;
    }

    if (ownerName.empty())
    {
        ownerName = "Unknown";
    }

    if (balance < 0)
    {
        balance = 0.0;
    }
}

// Конструктор с номером и владельцем
BankAccount::BankAccount(long long number,
                         const string& owner)
{
    accountNumber = number;
    ownerName = owner;
    balance = 0.0;
    active = true;

    currency.code = "RUB";
    currency.symbol = "₽";

    if (accountNumber <= 0)
    {
        accountNumber = 1;
    }

    if (ownerName.empty())
    {
        ownerName = "Unknown";
    }
}

long long BankAccount::getAccountNumber() const
{
    return accountNumber; // номер счета
}

string BankAccount::getOwnerName() const
{
    return ownerName; // имя
}

double BankAccount::getBalance() const
{
    return balance; // баланс
}

bool BankAccount::isActive() const
{
    return active; // счет
}

Currency BankAccount::getCurrency() const
{
    return currency; // валюта
}

void BankAccount::deposit(double amount)
{
    if (active && amount > 0)
    {
        balance += amount;
    }
}

void BankAccount::withdraw(double amount)
{
    if (active && amount > 0 && amount <= balance)
    {
        balance -= amount;
    }
}

void BankAccount::block()
{
    active = false;
}

void BankAccount::unblock()
{
    active = true;
}

void BankAccount::print() const
{
    cout << "Номер счёта: " << accountNumber << endl;
    cout << "Имя: " << ownerName << endl;
    cout << "Баланс: " << balance << " " << currency.symbol << endl;

    if (active)
    {
        cout << "Статус: Активный" << endl;
    }
    else
    {
        cout << "Статус: Заблокирован" << endl;
    }
}