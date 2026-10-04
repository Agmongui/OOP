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
 
    // геттер(позволяет читать значения приватного воля) 
    long long getAccountNumber() const; 
    string getOwnerName() const; 
    double getBalance() const; 
    bool isActive() const; 
    Currency getCurrency() const; 
 
    // изменяет состояние объекта 
    void deposit(double amount);// получает счет 
    void withdraw(double amount);// снять деньги 
    void block(); // заблокировать счет 
    void unblock(); // разблокировать счет
 
    void print() const; 
};