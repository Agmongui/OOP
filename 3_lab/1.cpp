#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Класс для работы с денежными суммами
 * @details Хранит рубли и копейки, поддерживает арифметические
 * операции, сравнение и перегрузку унарных операторов.
 */
class Money 
{
private:
    long long rubles;
    int kopecks;
    mutable int accessCount = 0; // меняет const
    static int count; // статический счетчик

public:
    /**
     * @brief Конструктор без параметров
     * @details Создаёт объект с нулевой денежной суммой.
     */
    Money() 
    {
        rubles = 0;
        kopecks = 0;
        count++;
    }

    /**
     * @brief Конструктор с одним параметром
     * @param r Количество рублей
     * @details explicit запрещает неявное преобразование числа в Money.
     */
    explicit Money(long long r) 
    {
        rubles = r;
        kopecks = 0;
        count++;
    }

    /**
     * @brief Конструктор с рублями и копейками
     * @param r Количество рублей
     * @param k Количество копеек
     * @details Копейки, превышающие 99, переводятся в рубли.
     */
    Money(long long r, int k) 
    {
        rubles = r + k / 100;
        kopecks = k % 100;
        count++;
    }

    /**
     * @brief Деструктор класса
     * @details Выводит сообщение при уничтожении объекта.
     */
    ~Money() 
    {
        cout << "\nОбъект Money уничтожен" << endl;
    }

    /**
     * @brief Выводит денежную сумму
     */
    void show() const 
    {
        cout << rubles << " руб. ";

        if (kopecks < 10)
            cout << "0";

        cout << kopecks << " коп." << endl;
    }

    /**
     * @brief Возвращает количество вызовов конструкторов
     * @return Значение статического счётчика
     */
    static int getCount() 
    {
        return count;
    }

    /**
     * @brief Увеличивает и выводит счётчик обращений
     * @details Метод const изменяет поле accessCount благодаря mutable.
     */
    void showAccessCount() const 
    {
        accessCount++;
        cout << "Обращений к сумме: " << accessCount << endl;
    }

    /**
     * @brief Префиксный инкремент
     * @details Увеличивает сумму на одну копейку.
     * @return Ссылка на текущий объект
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
     * @details Сохраняет старую сумму и увеличивает текущую на копейку.
     * @return Копия объекта до изменения
     */
    Money operator++(int) 
    {
        Money old = *this;
        ++(*this);
        return old;
    }

    /**
     * @brief Префиксный декремент
     * @details Уменьшает сумму на одну копейку.
     * @return Ссылка на текущий объект
     */
    Money& operator--() 
    {
        if (kopecks == 0) 
        {
            rubles--;
            kopecks = 99;
        } else {
            kopecks--;
        }

        return *this;
    }

    /**
     * @brief Постфиксный декремент
     * @details Сохраняет старую сумму и уменьшает текущую на копейку.
     * @return Копия объекта до изменения
     */
    Money operator--(int) 
    {
        Money old = *this;
        --(*this);
        return old;
    }

    /**
     * @brief Сложение с присваиванием
     * @param other Денежная сумма для прибавления
     * @return Ссылка на изменённый объект
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
     * @param other Денежная сумма для вычитания
     * @return Ссылка на текущий объект
     * @details Если средств недостаточно, сумма не изменяется.
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
     * @param number Число-множитель
     * @return Ссылка на изменённый объект
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
     * @param number Число-делитель
     * @return Ссылка на текущий объект
     * @details При делении на ноль сумма не изменяется.
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
     * @brief Бинарное сложение денежных сумм
     * @param m1 Первая денежная сумма
     * @param m2 Вторая денежная сумма
     * @return Новый объект с результатом сложения
     * @details Использует оператор +=.
     */
    friend Money operator+(Money m1, const Money& m2) 
    {
        m1 += m2;
        return m1;
    }

    /**
     * @brief Бинарное вычитание денежных сумм
     * @param m1 Первая денежная сумма
     * @param m2 Вторая денежная сумма
     * @return Новый объект с результатом вычитания
     * @details Использует оператор -=.
     */
    friend Money operator-(Money m1, const Money& m2) 
    {
        m1 -= m2;
        return m1;
    }

    /**
     * @brief Умножение денежной суммы на число
     * @param m1 Денежная сумма
     * @param number Множитель
     * @return Новый объект с результатом умножения
     * @details Использует оператор *=.
     */
    friend Money operator*(Money m1, double number) 
    {
        m1 *= number;
        return m1;
    }

    /**
     * @brief Деление денежной суммы на число
     * @param m1 Денежная сумма
     * @param number Делитель
     * @return Новый объект с результатом деления
     * @details Использует оператор /=.
     */
    friend Money operator/(Money m1, double number) 
    {
        m1 /= number;
        return m1;
    }

    /**
     * @brief Проверяет, меньше ли первая сумма второй
     * @param m1 Первая сумма
     * @param m2 Вторая сумма
     * @return true, если m1 меньше m2
     */
    friend bool operator<(const Money& m1, const Money& m2) 
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 < total2;
    }

    /**
     * @brief Проверяет, больше ли первая сумма второй
     * @param m1 Первая сумма
     * @param m2 Вторая сумма
     * @return true, если m1 больше m2
     */
    friend bool operator>(const Money& m1, const Money& m2) 
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 > total2;
    }

    /**
     * @brief Проверяет, меньше или равна первая сумма второй
     * @param m1 Первая сумма
     * @param m2 Вторая сумма
     * @return true, если m1 меньше или равна m2
     */
    friend bool operator<=(const Money& m1, const Money& m2) 
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 <= total2;
    }

    /**
     * @brief Проверяет, больше или равна первая сумма второй
     * @param m1 Первая сумма
     * @param m2 Вторая сумма
     * @return true, если m1 больше или равна m2
     */
    friend bool operator>=(const Money& m1, const Money& m2) 
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 >= total2;
    }

    /**
     * @brief Проверяет равенство денежных сумм
     * @param m1 Первая сумма
     * @param m2 Вторая сумма
     * @return true, если суммы равны
     */
    friend bool operator==(const Money& m1, const Money& m2) 
    {
        return m1.rubles == m2.rubles &&
               m1.kopecks == m2.kopecks;
    }

    /**
     * @brief Проверяет неравенство денежных сумм
     * @param m1 Первая сумма
     * @param m2 Вторая сумма
     * @return true, если суммы не равны
     */
    friend bool operator!=(const Money& m1, const Money& m2) 
    {
        return !(m1 == m2);
    }
};

/**
 * @brief Инициализация статического счётчика класса Money
 */
int Money::count = 0;


/**
 * @brief Класс банковского счёта
 * @details Хранит баланс и историю денежных операций.
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

    vector<Operation> history;

public:
    // Создание банковского счёта
    BankAccount(int number, const Money& initialBalance = Money())
        : accountNumber(number), balance(initialBalance) {}

    // Просмотр баланса
    void showBalance() const
    {
        cout << "Счёт №" << accountNumber << ", баланс: ";
        balance.show();
    }

    // Зачисление денег
    void deposit(const Money& amount)
    {
        if (amount <= Money())
        {
            cout << "Сумма зачисления должна быть положительной" << endl;
            return;
        }

        balance += amount;
        history.push_back(Operation("Зачисление", amount));

        cout << "Деньги зачислены на счёт №" << accountNumber << endl;
    }

    // Снятие денег
    void withdraw(const Money& amount)
    {
        if (amount <= Money())
        {
            cout << "Сумма расхода должна быть положительной" << endl;
            return;
        }

        if (balance < amount)
        {
            cout << "Недостаточно средств на счёте №" << accountNumber << endl;
            return;
        }

        balance -= amount;
        history.push_back(Operation("Расход", amount));

        cout << "Деньги списаны со счёта №" << accountNumber << endl;
    }

    // Перевод денег на другой счёт
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

        balance -= amount;
        recipient.balance += amount;

        history.push_back(
            Operation("Перевод на счёт", amount, recipient.accountNumber));

        recipient.history.push_back(
            Operation("Перевод со счёта", amount, accountNumber));

    }

    // Просмотр истории операций
    void showHistory() const
    {
        cout << "\nИстория операций счёта №"
             << accountNumber << ":" << endl;

        if (history.empty())
        {
            cout << "Операций пока нет" << endl;
            return;
        }

        for (const Operation& op : history)
        {
            cout << op.type << ": ";
            op.amount.show();

            if (op.otherAccount != 0)
            {
                cout << "Счёт №" << op.otherAccount << endl;
            }
        }
    }
};

/**
 * @brief Выводит переданную денежную сумму
 * @param m Объект класса Money
 * @details Используется для демонстрации explicit.
 */
void printMoney(Money m)
{
    cout << "Переданная сумма: ";
    m.show();
}

/**
 * @brief Главная функция программы
 * @details Создаёт объекты и демонстрирует работу перегруженных
 * операторов, explicit, mutable и статического поля.
 * @return 0 при успешном завершении
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

    // постфиксный инкремент
    cout << "\nПостфиксный инкремент m2++" << endl;
    cout << "До: ";
    m2.show();

    m2++;

    cout << "После: ";
    m2.show();

    // префиксный инкремент
    cout << "\nПрефиксный инкремент ++m2" << endl;
    cout << "До: ";
    m2.show();

    ++m2;

    cout << "После: ";
    m2.show();

    // постфиксный декремент
    cout << "\nПостфиксный декремент m2--" << endl;
    cout << "До: ";
    m2.show();

    m2--;

    cout << "После: ";
    m2.show();

    // префиксный декремент
    cout << "\nПрефиксный декремент --m2" << endl;
    cout << "До: ";
    m2.show();

    --m2;

    cout << "После: ";
    m2.show();

    // арифметические операторы присваивания
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
    cout << "* 2";
    m2 *= 2;
    cout << " = ";
    m2.show();

    cout << "m2 /= 2: ";
    m2.show();
    cout << "/ 2";
    m2 /= 2;
    cout << " = ";
    m2.show();
    
    // бинарные арифметические операторы
    cout << "\nБинарные арифметические операции" << endl;

    cout << "m2 + m4 = ";
    (m2 + m4).show();

    cout << "m2 - m4 = ";
    (m2 - m4).show();

    cout << "m2 * 2 = ";
    (m2 * 2).show();

    cout << "m2 / 2 = ";
    (m2 / 2).show();

    // операторы сравнения
    cout << "\nСравнение сумм" << endl;
    cout << "m2 < m3: " << (m2 < m3) << endl;
    cout << "m2 > m3: " << (m2 > m3) << endl;
    cout << "m2 <= m3: " << (m2 <= m3) << endl;
    cout << "m2 >= m3: " << (m2 >= m3) << endl;
    cout << "m2 == m3: " << (m2 == m3) << endl;
    cout << "m2 != m3: " << (m2 != m3) << endl;

    // демонстрация explicit
    cout << "\nДемонстрация explicit" << endl;
    printMoney(Money(10));
    // printMoney(10);

    // Демонстрация mutable у const-объекта
    cout << "\nДемонстрация mutable" << endl;

    const Money m5(50, 25);

    m5.show();
    m5.showAccessCount();
    m5.showAccessCount();

    // демонстрация статического поля
    cout << "\nКоличество созданных объектов" << endl;
    cout << "Количество вызовов конструкторов: "
         << Money::getCount() << endl;

    // Демонстрация банковских счетов
    cout << "\nБанковсие счета" << endl;

    BankAccount account1(001, Money(5000, 50));
    BankAccount account2(002, Money(1000, 0));

    // Начальные балансы
    cout << "\nНачальные балансы:" << endl;
    account1.showBalance();
    account2.showBalance();

    // Зачисление
    cout << "\nЗачисление денег на счет №1 (+ 500,25)" << endl;
    account1.deposit(Money(500, 25));
    account1.showBalance();

    // Расход
    cout << "\nРасход денег со счета №1 (- 200,50)" << endl;
    account1.withdraw(Money(200, 50));
    account1.showBalance();

    // Перевод между счетами
    cout << "\nПеревод денег с счета №1 на счет №2, в размере 1000" << endl;
    account1.transferTo(account2, Money(1000, 0));

    // Балансы после перевода
    cout << "\nБалансы после перевода:" << endl;
    account1.showBalance();
    account2.showBalance();

    // История операций
    account1.showHistory();
    account2.showHistory();

    return 0;
}
