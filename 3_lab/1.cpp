#include <iostream>

using namespace std;

class Money 
{
private:
    long long rubles;
    int kopecks;

public:
    //конструктор без параметров
    Money() 
    {
        rubles = 0;
        kopecks = 0;
    }

    //конструктор с рублями
    Money(long long r) 
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
};

int main() 
{
    Money m1;
    Money m2(100);
    Money m3(250, 50);

    return 0;
}