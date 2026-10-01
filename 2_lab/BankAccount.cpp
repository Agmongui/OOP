#include "BankAccount.h"

BankAccount::BankAccount()
{
    accountNumber = 1;
    ownerName = "Mary";
    balance = 0.0;
    active = true;

    currency.code = "EUR";
    currency.symbol = "€";
}
