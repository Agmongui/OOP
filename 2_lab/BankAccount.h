#pragma once // защита от многократного подключения одного и того же заголовочного файла.

#include <string> // для хранения текста

using namespace std;

/**
 * @brief Представляет тип банковского счета
 * Если savings == false, счет является дебетовым.
 * Если savings == true, счет является накопительным.
 */
class AccountType
{
private:
    bool savings;

public:
    AccountType(bool isSavings = false);

    bool isSavings() const;
    string toString() const;
};

/**
 * @brief Представляет банковский счет
 * 
 * Класс хранит информацию о банковском счете,
 * его владельце, балансе, валюте, статусе
 * и типе счета.
 * 
 * Поддерживает два типа счетов:
 * дебетовый и накопительный.
 *
 * Для накопительного счета при каждом пополнении
 * начисляется 3 процента от внесенной суммы.
 */
class BankAccount
{
private: 
    long long accountNumber;
    string ownerName;
    double balance;
    bool active;
    string currency;
    AccountType type;

    static int objectCount;

    // Проверка корректности данных
    void validateAccountNumber(long long number) const;
    void validateOwnerName(const string& owner) const;
    void validateBalance(double balance) const;

public:

    BankAccount();// Конструктор без параметров
    
    BankAccount(long long number,
                const string& owner,
                double initialBalance,
                const string& accountCurrency,
                const AccountType& accountType);// Конструктор с параметрами

    BankAccount(long long number,
                const string& owner);// Конструктор с номером и владельцем

    ~BankAccount();// Деструктор

    static int getObjectCount();// Статический счётчик
    // Геттеры
    long long getAccountNumber() const;
    string getOwnerName() const;
    double getBalance() const;
    bool isActive() const;
    string getCurrency() const;
    AccountType getType() const;
    // Изменяющие методы
    void deposit(double amount);
    bool withdraw(double amount);

    void block();
    void unblock();

    /**
     * @brief Выводит информацию о счете.
     */
    void print() const;
};