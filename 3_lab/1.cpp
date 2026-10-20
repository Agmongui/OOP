#include <iostream>
#include <windows.h>

using namespace std;

class Money 
{
private:
    long long rubles;
    int kopecks;
    mutable int accessCount = 0; // меняет const
    static int count; // статический счетчик

public:
    // конструктор без параметров
    Money() 
    {
        rubles = 0;
        kopecks = 0;
        count++;
    }

    // конструктор с рублями
    explicit Money(long long r) 
    {
        rubles = r;
        kopecks = 0;
        count++;
    }

    // конструктор с рублями и копейками
    Money(long long r, int k) 
    {
        rubles = r + k / 100;
        kopecks = k % 100;
        count++;
    }

    // деструктор
    ~Money() 
    {
        cout << "\nОбъект Money уничтожен" << endl;
    }

    // вывод суммы
    void show() const 
    {
        cout << rubles << " руб. ";

        if (kopecks < 10)
            cout << "0";

        cout << kopecks << " коп." << endl;
    }

    // статический счетчик
    static int getCount() 
    {
        return count;
    }

    // счетчик обращений
    void showAccessCount() const 
    {
        accessCount++;
        cout << "Обращений к сумме: "
             << accessCount << endl;
    }

    // префиксный инкремент
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

    // постфиксный инкремент
    Money operator++(int) 
    {
        Money old = *this;
        ++(*this);
        return old;
    }

    // префиксный декремент
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

    // постфиксный декремент
    Money operator--(int) 
    {
        Money old = *this;
        --(*this);
        return old;
    }

    // оператор +=
    Money& operator+=(const Money& other) 
    {
        rubles += other.rubles;
        kopecks += other.kopecks;

        rubles += kopecks / 100;
        kopecks %= 100;

        return *this;
    }

    // оператор -=
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

    // оператор *=
    Money& operator*=(double number) 
    {
        long long total = rubles * 100 + kopecks;
        total = static_cast<long long>(total * number);

        rubles = total / 100;
        kopecks = total % 100;

        return *this;
    }

    // оператор /=
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

    // оператор +
    friend Money operator+(Money m1, const Money& m2) 
    {
        m1 += m2;
        return m1;
    }

    // оператор -
    friend Money operator-(Money m1, const Money& m2) 
    {
        m1 -= m2;
        return m1;
    }

    // оператор *
    friend Money operator*(Money m1, double number) 
    {
        m1 *= number;
        return m1;
    }

    // оператор /
    friend Money operator/(Money m1, double number) 
    {
        m1 /= number;
        return m1;
    }

    // оператор <
    friend bool operator<(const Money& m1, const Money& m2) 
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 < total2;
    }

    // оператор >
    friend bool operator>(const Money& m1, const Money& m2) 
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 > total2;
    }

    // оператор <=
    friend bool operator<=(const Money& m1, const Money& m2) 
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 <= total2;
    }

    // оператор >=
    friend bool operator>=(const Money& m1, const Money& m2) 
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 >= total2;
    }

    // оператор ==
    friend bool operator==(const Money& m1, const Money& m2) 
    {
        return m1.rubles == m2.rubles &&
               m1.kopecks == m2.kopecks;
    }

    // оператор !=
    friend bool operator!=(const Money& m1, const Money& m2) 
    {
        return !(m1 == m2);
    }
};

int Money::count = 0;

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

    // бинарные арифметические операторы
    cout << "\nАрифметические операции" << endl;

    cout << "m2 + m4 = ";
    m2.show();
    cout << "+ ";
    m4.show();
    cout << "= ";
    (m2 + m4).show();

    cout << "m2 - m4 = ";
    m2.show();
    cout << "- ";
    m4.show();
    cout << "= ";
    (m2 - m4).show();

    cout << "m2 * 2 = ";
    m2.show();
    cout << "* 2 = ";
    (m2 * 2).show();

    cout << "m2 / 2 = ";
    m2.show();
    cout << "/ 2 = ";
    (m2 / 2).show();

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

    // операторы сравнения
    cout << "\nСравнение сумм" << endl;
    cout << "m2 < m3: " << (m2 < m3) << endl;
    cout << "m2 > m3: " << (m2 > m3) << endl;
    cout << "m2 <= m3: " << (m2 <= m3) << endl;
    cout << "m2 >= m3: " << (m2 >= m3) << endl;
    cout << "m2 == m3: " << (m2 == m3) << endl;
    cout << "m2 != m3: " << (m2 != m3) << endl;

    // демонстрация explicit
    cout << "\nЯвное создание суммы Money(5)" << endl;
    Money(5).show();

    // демонстрация mutable
    cout << "\nСчетчик обращений к m4" << endl;
    m4.showAccessCount();
    m4.showAccessCount();

    // демонстрация статического поля
    cout << "\nКоличество созданных объектов" << endl;
    cout << "Количество вызовов конструкторов: "
         << Money::getCount() << endl;

    return 0;
}
