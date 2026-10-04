#include "BankAccount.h"
#include <iostream>

using namespace std;

int main()
{
    system("chcp 65001 > nul");

    Currency ruble;
    ruble.code = "RUB";
    ruble.symbol = "₽";

    BankAccount account(123456, "Ivan", 5000, ruble);
    BankAccount account2(654321, "Petr");
    BankAccount account3;

    cout << "Количество существующих объектов: "
         << BankAccount::getObjectCount() << endl;

    cout << endl;
    cout << "Состояние первого счёта:" << endl;
    account.print();

    cout << endl;
    cout << "Состояние второго счёта:" << endl;
    account2.print();

    cout << endl;
    cout << "Пополняем первый счёт на 500 рублей." << endl;
    account.deposit(500);

    cout << endl;
    cout << "После изменения первого счёта:" << endl;

    cout << endl;
    cout << "Первый счёт:" << endl;
    account.print();

    cout << endl;
    cout << "Второй счёт:" << endl;
    account2.print();

    cout << endl;
    cout << "Информация о банковском счёте:" << endl;

    account.print();

    double amount;

    cout << endl;
    cout << "Введите сумму для пополнения: ";
    cin >> amount;

    account.deposit(amount);

    cout << endl;
    cout << "После пополнения:" << endl;
    account.print();

    cout << endl;
    cout << "Введите сумму для снятия: ";
    cin >> amount;

    account.withdraw(amount);

    cout << endl;
    cout << "После снятия:" << endl;
    account.print();

    cout << endl;
    cout << "Заблокировать счёт? (1 - да, 0 - нет): ";
    
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        account.block();
    }

    cout << endl;
    cout << "Текущее состояние счёта:" << endl;
    account.print();

    cout << endl;
    cout << "Разблокировать счёт? (1 - да, 0 - нет): ";
    cin >> choice;

    if (choice == 1)
    {
        account.unblock();
    }

    cout << endl;
    cout << "Итоговое состояние счёта:" << endl;
    account.print();

    return 0;
}