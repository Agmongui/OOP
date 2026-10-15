#include <iostream>

using namespace std;

class Money 
{
private:
    long long rubles;
    int kopecks;
    mutable int accessCount = 0;//меняет const

public:
    //конструктор без параметров
    Money() 
    {
        rubles = 0;
        kopecks = 0;
    }

    //конструктор с рублями
    explicit Money(long long r) // explicit запрещает неявное преобразование числа в Money
    {
        rubles = r;
        kopecks = 0;
    }

    //конструктор с рублями и копейками
    Money(long long r, int k) 
    {
        rubles = r + k / 100;
        kopecks = k % 100;
    }

    void showAccessCount() const// вывод количества обращений к объекту
    {
        accessCount++;
        cout << "Количество обращений: " << accessCount << endl;
    }
    //префиксный инкремент 
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
    //постфиксный инкремент
    Money operator++(int) 
    {
        Money old = *this;
        ++(*this);
        return old;
    }
    //префиксный декремент 
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
    //постфиксный декремент
    Money operator--(int) 
    {
        Money old = *this;
        --(*this);
        return old;
    }
    //cложение с присваиванием
    Money& operator+=(const Money& other) 
    {
        rubles += other.rubles;
        kopecks += other.kopecks;

        rubles += kopecks / 100;
        kopecks %= 100;

        return *this;
    }
    //вычитание с присваиванием
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
    //умножение с присваиванием
    Money& operator*=(double number) 
    {
    long long total = rubles * 100 + kopecks;
    total = static_cast<long long>(total * number);//преобразует результат обратно в ценлое число копеек
    rubles = total / 100;
    kopecks = total % 100;
    return *this;
    }
    //деление с присваиванием
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
    //сложение двух сумм
    friend Money operator+(Money m1, const Money& m2)//разрешает обращаться к закрытым полям
    {
    m1 += m2;
    return m1;
    }
    //вычитание двух сумм
    friend Money operator-(Money m1, const Money& m2)
    {
        m1 -= m2;
        return m1;
    }
    // Умножение двух сумм
    friend Money operator*(Money m1, double number)
    {
        m1 *= number;
        return m1;
    }
    // Деление двух сумм
    friend Money operator/(Money m1, double number)
    {
        m1 /= number;
        return m1;
    }
    // Проверка: m1 меньше m2
    friend bool operator<(const Money& m1, const Money& m2)
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 < total2;
    }
    // Проверка: m1 больше m2
    friend bool operator>(const Money& m1, const Money& m2)
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 > total2;
    }
    // Проверка: m1 меньше или равна m2
    friend bool operator<=(const Money& m1, const Money& m2)
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 <= total2;
    }
    // Проверка: m1 больше или равна m2
    friend bool operator>=(const Money& m1, const Money& m2)
    {
        long long total1 = m1.rubles * 100 + m1.kopecks;
        long long total2 = m2.rubles * 100 + m2.kopecks;

        return total1 >= total2;
    }
    // Проверка равенства сумм
    friend bool operator==(const Money& m1, const Money& m2)
    {
        return m1.rubles == m2.rubles &&
            m1.kopecks == m2.kopecks;
    }
    // Проверка неравенства сумм
    friend bool operator!=(const Money& m1, const Money& m2)
    {
        return !(m1 == m2);
    }

};

int main() 
{
    Money m1;
    Money m2(100);
    Money m3(250, 50);

    return 0;
}