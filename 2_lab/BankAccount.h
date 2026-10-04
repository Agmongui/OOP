#pragma once // чтобы один и тот же файл не подключался несколько раз при компиляции

#include <string>

using namespace std;

struct Currency
{
    string code;
    string symbol;
};

class BankAccount
{
private:
    long long accountNumber;
    string ownerName;
    double balance;
    bool active;
    Currency currency;

public:
    BankAccount();// Конструктор без параметров

    BankAccount(long long number,
                const string& owner,
                double initialBalance,
                const Currency& accountCurrency);// Конструктор с параметрами

    BankAccount(long long number,
                const string& owner);// Конструктор с номером и владельцем
};