#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

/**
 * @brief Класс для работы с денежными суммами
 */
class Money
{
private:
    long long rubles;
    int kopecks;
    mutable int accessCount = 0;
    static int count;

public:
    /**
     * @brief Конструктор без параметров
     */
    Money()
    {
        rubles = 0;
        kopecks = 0;
        count++;
    }

    /**
     * @brief Конструктор с одним параметром
     */
    explicit Money(long long r)
    {
        rubles = r;
        kopecks = 0;
        count++;
    }

    /**
     * @brief Конструктор с рублями и копейками
     */
    Money(long long r, int k)
    {
        rubles = r + k / 100;
        kopecks = k % 100;
        count++;
    }

    /**
     * @brief Конструктор копирования
     */
    Money(const Money& other)
        : rubles(other.rubles),
          kopecks(other.kopecks),
          accessCount(0)
    {
        count++;
    }

    /**
     * @brief Деструктор класса
     */
    ~Money()
    {
        count--;
        cout << "Объект Money уничтожен" << endl;
        cout << "Сейчас объектов Money: " << count << endl;
    }

    /**
     * @brief Вывод денежной суммы
     */
    void show() const
    {
        cout << rubles << " руб. ";

        if (kopecks < 10)
            cout << "0";

        cout << kopecks << " коп." << endl;
    }

    /**
     * @brief Возвращает количество существующих объектов
     */
    static int getCount()
    {
        return count;
    }

    /**
     * @brief Счётчик обращений к объекту
     */
    void showAccessCount() const
    {
        accessCount++;
        cout << "Обращений к сумме: " << accessCount << endl;
    }

    /**
     * @brief Префиксный инкремент
     */
    Money& operator++()
    {
        kopecks++;

        if (kopecks == 100)
        {
            rubles++;
            kopecks = 0;
        }

        return *this;
    }

    /**
     * @brief Постфиксный инкремент
     */
    Money operator++(int)
    {
        Money old = *this;
        ++(*this);
        return old;
    }

    /**
     * @brief Префиксный декремент
     */
    Money& operator--()
    {
        if (kopecks == 0)
        {
            rubles--;
            kopecks = 99;
        }
        else
        {
            kopecks--;
        }

        return *this;
    }

    /**
     * @brief Постфиксный декремент
     */
    Money operator--(int)
    {
        Money old = *this;
        --(*this);
        return old;
    }

    /**
     * @brief Сложение с присваиванием
     */
    Money& operator+=(const Money& other)
    {
        rubles += other.rubles;
        kopecks += other.kopecks;

        rubles += kopecks / 100;
        kopecks %= 100;

        return *this;
    }

    /**
     * @brief Вычитание с присваиванием
     */
    Money& operator-=(const Money& other)
    {
        long long total1 = rubles * 100 + kopecks;
        long long total2 = other.rubles * 100 + other.kopecks;

        if (total2 > total1)
        {
            cout << "Недостаточно средств" << endl;
            return *this;
        }

        long long result = total1 - total2;

        rubles = result / 100;
        kopecks = result % 100;

        return *this;
    }

    /**
     * @brief Умножение с присваиванием
     */
    Money& operator*=(double number)
    {
        long long total = rubles * 100 + kopecks;
        total = static_cast<long long>(total * number);

        rubles = total / 100;
        kopecks = total % 100;

        return *this;
    }

    /**
     * @brief Деление с присваиванием
     */
    Money& operator/=(double number)
    {
        if (number == 0)
        {
            cout << "На 0 делить нельзя" << endl;
            return *this;
        }

        long long total = rubles * 100 + kopecks;
        total = static_cast<long long>(total / number);

        rubles = total / 100;
        kopecks = total % 100;

        return *this;
    }

    /**
     * @brief Бинарное сложение
     */
    friend Money operator+(Money m1, const Money& m2)
    {
        m1 += m2;
        return m1;
    }

    /**
     * @brief Бинарное вычитание
     */
    friend Money operator-(Money m1, const Money& m2)
    {
        m1 -= m2;
        return m1;
    }

    /**
     * @brief Умножение на число
     */
    friend Money operator*(Money m1, double number)
    {
        m1 *= number;
        return m1;
    }

    /**
     * @brief Деление на число
     */
    friend Money operator/(Money m1, double number)
    {
        m1 /= number;
        return m1;
    }

    /**
     * @brief Операторы сравнения
     */
    friend bool operator<(const Money& m1, const Money& m2)
    {
        return m1.rubles * 100 + m1.kopecks <
               m2.rubles * 100 + m2.kopecks;
    }

    friend bool operator>(const Money& m1, const Money& m2)
    {
        return m1.rubles * 100 + m1.kopecks >
               m2.rubles * 100 + m2.kopecks;
    }

    friend bool operator<=(const Money& m1, const Money& m2)
    {
        return !(m1 > m2);
    }

    friend bool operator>=(const Money& m1, const Money& m2)
    {
        return !(m1 < m2);
    }

    friend bool operator==(const Money& m1, const Money& m2)
    {
        return m1.rubles == m2.rubles &&
               m1.kopecks == m2.kopecks;
    }

    friend bool operator!=(const Money& m1, const Money& m2)
    {
        return !(m1 == m2);
    }
};

int Money::count = 0;


/**
 * @brief Класс банковского счёта
 */
class BankAccount
{
private:
    int accountNumber;
    Money balance;

    struct Operation
    {
        string type;
        Money amount;
        int otherAccount;

        Operation(string t, const Money& a, int other = 0)
            : type(t), amount(a), otherAccount(other) {}
    };

    // Обычный массив вместо vector
    static const int MAX_OPERATIONS = 100;
    Operation* history[MAX_OPERATIONS];
    int historySize = 0;

    /**
     * @brief Добавление операции в историю
     */
    void addOperation(const string& type,
                      const Money& amount,
                      int otherAccount = 0)
    {
        if (historySize >= MAX_OPERATIONS)
        {
            cout << "История операций заполнена" << endl;
            return;
        }

        history[historySize] = new Operation(type, amount, otherAccount);//создаёт новый объект Operation, который хранит информацию об одной банковской операции

        historySize++;
    }

public:
    BankAccount(int number, const Money& initialBalance = Money())
        : accountNumber(number), balance(initialBalance)
    {
        for (int i = 0; i < MAX_OPERATIONS; i++)
            history[i] = nullptr;
    }

    // Запрещаем копирование счёта, чтобы не копировать указатели
    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;

    ~BankAccount()
    {
        for (int i = 0; i < historySize; i++)
            delete history[i];
    }

    void showBalance() const
    {
        cout << "Счёт №" << accountNumber << ", баланс: ";
        balance.show();
    }

    void deposit(const Money& amount)
    {
        if (amount <= Money())
        {
            cout << "Сумма зачисления должна быть положительной" << endl;
            return;
        }

        balance += amount;
        addOperation("Зачисление", amount);

        cout << "Деньги зачислены на счёт №"
             << accountNumber << endl;
    }

    void withdraw(const Money& amount)
    {
        if (amount <= Money())
        {
            cout << "Сумма расхода должна быть положительной" << endl;
            return;
        }

        if (balance < amount)
        {
            cout << "Недостаточно средств на счёте №"
                 << accountNumber << endl;
            return;
        }

        balance -= amount;
        addOperation("Расход", amount);

        cout << "Деньги списаны со счёта №"
             << accountNumber << endl;
    }

    void transferTo(BankAccount& recipient,
                    const Money& amount)
    {
        if (&recipient == this)
        {
            cout << "Нельзя переводить деньги на тот же счёт" << endl;
            return;
        }

        if (amount <= Money())
        {
            cout << "Сумма перевода должна быть положительной" << endl;
            return;
        }

        if (balance < amount)
        {
            cout << "Недостаточно средств для перевода" << endl;
            return;
        }

        // Проверяем наличие места в обеих историях
        if (historySize >= MAX_OPERATIONS ||
            recipient.historySize >= MAX_OPERATIONS)
        {
            cout << "История одного из счетов заполнена" << endl;
            return;
        }

        balance -= amount;
        recipient.balance += amount;

        addOperation("Перевод на счёт", amount,
                     recipient.accountNumber);

        recipient.addOperation("Перевод со счёта", amount,
                               accountNumber);
    }

    void showHistory() const
    {
        cout << "\nИстория операций счёта №"
             << accountNumber << ":" << endl;

        if (historySize == 0)
        {
            cout << "Операций пока нет" << endl;
            return;
        }

        for (int i = 0; i < historySize; i++)
        {
            cout << history[i]->type << ": ";
            history[i]->amount.show();

            if (history[i]->otherAccount != 0)
                cout << "Счёт №"
                     << history[i]->otherAccount << endl;
        }
    }
};


/**
 * @brief Вывод денежной суммы
 */
void printMoney(Money m)
{
    cout << "Переданная сумма: ";
    m.show();
}


/**
 * @brief Главная функция
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Money m1;
    Money m2(100);
    Money m3(100, 1);
    Money m4(99, 99);

    cout << "Начальные суммы" << endl;
    cout << "m1 = ";
    m1.show();
    cout << "m2 = ";
    m2.show();
    cout << "m3 = ";
    m3.show();
    cout << "m4 = ";
    m4.show();

    cout << "\nПостфиксный инкремент m2++" << endl;
    cout << "До: ";
    m2.show();
    m2++;
    cout << "После: ";
    m2.show();

    cout << "\nПрефиксный инкремент ++m2" << endl;
    cout << "До: ";
    m2.show();
    ++m2;
    cout << "После: ";
    m2.show();

    cout << "\nПостфиксный декремент m2--" << endl;
    cout << "До: ";
    m2.show();
    m2--;
    cout << "После: ";
    m2.show();

    cout << "\nПрефиксный декремент --m2" << endl;
    cout << "До: ";
    m2.show();
    --m2;
    cout << "После: ";
    m2.show();

    cout << "\nАрифметические операции присваивания" << endl;

    cout << "m2 += m4: ";
    m2.show();
    cout << "+ ";
    m4.show();
    m2 += m4;
    cout << "= ";
    m2.show();

    cout << "m2 -= m4: ";
    m2.show();
    cout << "- ";
    m4.show();
    m2 -= m4;
    cout << "= ";
    m2.show();

    cout << "m2 *= 2: ";
    m2.show();
    cout << "* 2 = ";
    m2 *= 2;
    m2.show();

    cout << "m2 /= 2: ";
    m2.show();
    cout << "/ 2 = ";
    m2 /= 2;
    m2.show();

    cout << "\nБинарные арифметические операции" << endl;

    cout << "m2 + m4 = ";
    (m2 + m4).show();

    cout << "m2 - m4 = ";
    (m2 - m4).show();

    cout << "m2 * 2 = ";
    (m2 * 2).show();

    cout << "m2 / 2 = ";
    (m2 / 2).show();

    cout << "\nСравнение сумм" << endl;
    cout << "m2 < m3: " << (m2 < m3) << endl;
    cout << "m2 > m3: " << (m2 > m3) << endl;
    cout << "m2 <= m3: " << (m2 <= m3) << endl;
    cout << "m2 >= m3: " << (m2 >= m3) << endl;
    cout << "m2 == m3: " << (m2 == m3) << endl;
    cout << "m2 != m3: " << (m2 != m3) << endl;

    cout << "\nДемонстрация explicit" << endl;
    printMoney(Money(10));
    // printMoney(10);

    cout << "\nДемонстрация mutable" << endl;
    const Money m5(50, 25);
    m5.show();
    m5.showAccessCount();
    m5.showAccessCount();

    cout << "\nКоличество существующих объектов: "
         << Money::getCount() << endl;

    cout << "\nБанковские счета" << endl;

    BankAccount account1(1, Money(5000, 50));
    BankAccount account2(2, Money(1000, 0));

    cout << "\nНачальные балансы:" << endl;
    account1.showBalance();
    account2.showBalance();

    cout << "\nЗачисление денег на счёт №1 (+ 500,25)" << endl;
    account1.deposit(Money(500, 25));
    account1.showBalance();

    cout << "\nРасход денег со счёта №1 (- 200,50)" << endl;
    account1.withdraw(Money(200, 50));
    account1.showBalance();

    cout << "\nПеревод денег со счёта №1 на счёт №2: 1000" << endl;
    account1.transferTo(account2, Money(1000, 0));

    cout << "\nБалансы после перевода:" << endl;
    account1.showBalance();
    account2.showBalance();

    account1.showHistory();
    account2.showHistory();

    cout << "\nКоличество существующих объектов перед выходом: "
         << Money::getCount() << endl;

    return 0;
}
