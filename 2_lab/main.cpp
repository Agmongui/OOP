#include "BankAccount.h"
#include <iostream>

using namespace std;

int main()
{
    system("chcp 65001 > nul");

    // Создаем валюту
    Currency ruble;
    ruble.code = "RUB";
    ruble.symbol = "₽";


    // Создание трех объектов разными конструкторами
    // Эти счета нужны для проверки независимости объектов
    BankAccount account(1, "Маша", 0, ruble);
    BankAccount account2(2, "Даня");
    BankAccount account3;


    cout << "Количество существующих объектов: "
         << BankAccount::getObjectCount() << endl;


    // Проверка независимости объектов
    cout << endl;
    cout << "Проверка" << endl;

    cout << endl;
    cout << "Состояние счета Маши:" << endl;
    account.print();

    cout << endl;
    cout << "Состояние счета Дани:" << endl;
    account2.print();

    cout << endl;
    cout << "Пополняем только счет Маши на 1000 рублей." << endl;
    account.deposit(1000);

    cout << endl;
    cout << "Счет Маши после изменения:" << endl;
    account.print();

    cout << endl;
    cout << "Счет Дани:" << endl;
    account2.print();

    // Создание собственного счета пользователя
    cout << endl;
    cout << "Создание счета" << endl;

    long long number;
    string owner;
    double initialBalance;

    cout << endl;
    cout << "Введите номер счета: ";
    cin >> number;

    cin.ignore();

    cout << "Введите имя владельца: ";
    getline(cin, owner);

    cout << "Введите начальный баланс: ";
    cin >> initialBalance;


    // Создаем собственный счет
    BankAccount myAccount(number, owner, initialBalance, ruble);


    cout << endl;
    cout << "Ваш счет успешно создан." << endl;

    cout << endl;
    cout << "Информация о вашем счете:" << endl;
    myAccount.print();


    // Главное меню
    int choice;

    do
    {
        cout << endl;
        cout << "Меню" << endl;
        cout << "1) Пополнение счета" << endl;
        cout << "2) Снятие" << endl;
        cout << "3) Статус счета" << endl;
        cout << "0) Выход" << endl;

        // Статический счетчик показывает количество
        // существующих объектов BankAccount
        cout << endl;
        cout << "Количество существующих счетов: "
             << BankAccount::getObjectCount() << endl;

        cout << endl;
        cout << "Выберите действие: ";
        cin >> choice;


        // Пополнение счета
        if (choice == 1)
        {
            double amount;

            cout << endl;
            cout << "Введите сумму для пополнения: ";
            cin >> amount;

            myAccount.deposit(amount);

            cout << endl;
            cout << "Текущее состояние счета:" << endl;
            myAccount.print();
        }


        // Снятие денег
        else if (choice == 2)
        {
            double amount;

            cout << endl;
            cout << "Введите сумму для снятия: ";
            cin >> amount;

            myAccount.withdraw(amount);

            cout << endl;
            cout << "Текущее состояние счета:" << endl;
            myAccount.print();
        }


        // Статус счета
        else if (choice == 3)
        {
            int statusChoice;

            cout << endl;
            cout << "Статус счета:" << endl;
            cout << "1) Заблокировать" << endl;
            cout << "2) Разблокировать" << endl;

            cout << endl;
            cout << "Выберите действие: ";
            cin >> statusChoice;

            if (statusChoice == 1)
            {
                myAccount.block();

                cout << endl;
                cout << "Счет заблокирован." << endl;
            }
            else if (statusChoice == 2)
            {
                myAccount.unblock();

                cout << endl;
                cout << "Счет разблокирован." << endl;
            }
            else
            {
                cout << endl;
                cout << "Неверный выбор." << endl;
            }

            cout << endl;
            cout << "Текущее состояние счета:" << endl;
            myAccount.print();
        }


        // Выход
        else if (choice == 0)
        {
            cout << endl;
            cout << "Выход из программы." << endl;
        }


        // Неверный пункт меню
        else
        {
            cout << endl;
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }

    } while (choice != 0);


    return 0;
}