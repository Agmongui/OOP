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
    BankAccount();

    BankAccount(long long number,
                string owner,
                double initialBalance,
                Currency accountCurrency);
};