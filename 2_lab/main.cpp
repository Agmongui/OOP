#include "BankAccount.h"

#include <iostream>
#include <string>

using namespace std;

/** 
 * @brief Главная функция программы.   
 * @details Создает несколько банковских счетов с использованием 
 * разных конструкторов, демонстрирует начальное состояние 
 * и независимость объектов. 
 * 
 * После этого пользователь может создать собственный счет 
 * и выполнять с ним основные операции:пополнение, снятие денег, блокировку, разблокировку  
 * @return 0 при успешном завершении программы.  
 */
int main()
{
    system("chcp 65001 > nul");

    AccountType debitType(false);
    AccountType savingsType(true, 5.0); // накопительный счет со ставкой 5%

    BankAccount account(
        1,
        "Маша",
        0,
        "₽",
        debitType
    );

    BankAccount account2(
        2,
        "Даня"
    );

    BankAccount account3;

    cout << "Количество существующих объектов: "
         << BankAccount::getObjectCount()
         << endl;

    cout << endl;
    cout << "=== Начальное состояние ===" << endl;

    cout << endl;
    cout << "Счет Маши:" << endl;
    account.print();

    cout << endl;
    cout << "Счет Дани:" << endl;
    account2.print();

    cout << endl;
    cout << "Счет 3:" << endl;
    account3.print();

    cout << endl;
    cout << "=== Проверка независимости ===" << endl;

    cout << endl;
    cout << "Пополняем только счет Маши на 1000 рублей."
         << endl;

    account.deposit(1000);

    cout << endl;
    cout << "Счет Маши:" << endl;
    account.print();

    cout << endl;
    cout << "Счет Дани:" << endl;
    account2.print();

    cout << endl;
    cout << "Создать счёт" << endl;

    long long number;
    string owner;
    double initialBalance;
    int accountTypeChoice;

    cout << endl;
    cout << "Какой счет создать?" << endl;
    cout << "1) Дебетовый" << endl;
    cout << "2) Накопительный" << endl;

// Ввод номера типа счета
    do
    {
        cout << endl;
        cout << "Ваш выбор: ";
        cin >> accountTypeChoice;

        if (accountTypeChoice != 1 &&
            accountTypeChoice != 2)
        {
            cout << "Ошибка! Выберите 1 или 2."
                 << endl;
        }

    } while (accountTypeChoice != 1 &&
             accountTypeChoice != 2);

    // Для накопительного счета используем ставку 5%
    AccountType selectedType(
        accountTypeChoice == 2,
        5.0
    );

// Ввод номера
    do
    {
        cout << endl;
        cout << "Введите номер счета: ";
        cin >> number;

        if (number <= 0)
        {
            cout << "Ошибка! Номер счета должен быть больше 0."
                 << endl;
        }

    } while (number <= 0);


    cin.ignore();

// Ввод имени
    do
    {
        cout << "Введите имя владельца: ";
        getline(cin, owner);

        if (owner.empty())
        {
            cout << "Ошибка! Имя владельца не может быть пустым."
                 << endl;
        }

    } while (owner.empty());

// Ввод начального баланса
    do
    {
        cout << "Введите начальный баланс: ";
        cin >> initialBalance;

        if (initialBalance < 0)
        {
            cout << "Ошибка! Баланс не может быть отрицательным."
                 << endl;
        }

    } while (initialBalance < 0);

    // Создание счета
    BankAccount myAccount(
        number,
        owner,
        initialBalance,
        "₽",
        selectedType
    );

    cout << endl;
    cout << "Ваш счет успешно создан."
         << endl;

    cout << endl;
    cout << "Информация о вашем счете:"
         << endl;

    myAccount.print();

    int choice;

    do
    {
        cout << endl;
        cout << "Меню" << endl;

        cout << "1) Пополнить счет" << endl;
        cout << "2) Снять деньги" << endl;
        cout << "3) Статус счета" << endl;
        cout << "4) Показать информацию" << endl;
        cout << "0) Выход" << endl;

        cout << endl;
        cout << "Количество существующих счетов: "
             << BankAccount::getObjectCount()
             << endl;

        cout << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        // Пополнение
        if (choice == 1)
        {
            double amount;

            cout << endl;
            cout << "Введите сумму для пополнения: ";
            cin >> amount;

            try
            {
                myAccount.deposit(amount);

                cout << endl;
                cout << "Счет успешно пополнен."
                     << endl;

                cout << endl;
                cout << "Текущее состояние:"
                     << endl;

                myAccount.print();
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
            }
        }
        // Снятие
        else if (choice == 2)
        {
            double amount;

            cout << endl;
            cout << "Введите сумму для снятия: ";
            cin >> amount;


            try
            {
                if (myAccount.withdraw(amount))
                {
                    cout << endl;
                    cout << "Деньги успешно сняты."
                         << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Ошибка! Недостаточно средств."
                         << endl;
                }

                cout << endl;
                cout << "Текущее состояние:"
                     << endl;

                myAccount.print();
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
            }
        }
        // Статус счета
        else if (choice == 3)
        {
            int statusChoice;


            cout << endl;
            cout << "Статус счета" << endl;

            cout << "1) Заблокировать счет" << endl;
            cout << "2) Разблокировать счет" << endl;
            cout << "0) Назад" << endl;

            cout << endl;
            cout << "Выберите действие: ";
            cin >> statusChoice;

            if (statusChoice == 1)
            {
                myAccount.block();

                cout << endl;
                cout << "Счет заблокирован."
                     << endl;

                cout << endl;
                myAccount.print();
            }

            else if (statusChoice == 2)
            {
                myAccount.unblock();

                cout << endl;
                cout << "Счет разблокирован."
                     << endl;

                cout << endl;
                myAccount.print();
            }

            else if (statusChoice == 0)
            {
                cout << endl;
                cout << "Возврат в главное меню."
                     << endl;
            }

            else
            {
                cout << endl;
                cout << "Ошибка! Неверный выбор."
                     << endl;
            }
        }
        // Информация о счете
        else if (choice == 4)
        {
            cout << endl;
            cout << "Информация о счете:"
                 << endl;

            myAccount.print();
        }
        // Выход
        else if (choice == 0)
        {
            cout << endl;
            cout << "Выход из программы."
                 << endl;
        }
        // Неверный пункт
        else
        {
            cout << endl;
            cout << "Ошибка! Неверный выбор."
                 << endl;
        }


    } while (choice != 0);


    return 0;
}