#include "BankAccount.h"

#include <iostream> // для ввода и вывода
#include <stdexcept> // для исклбчений
#include <iomanip> // баланс выводился 5000.00

using namespace std;

/**
 * @brief Создает объект типа AccountType.
 * @param isSavings Определяет тип банковского счета.
 * true — накопительный счет, false — дебетовый.
 * @details Значение параметра сохраняется в поле savings
 * и используется для определения поведения счета.
 * @note По умолчанию создается дебетовый счет.
 */
AccountType::AccountType(bool isSavings)
    : savings(isSavings) // поле savings получает значение параметра isSavings
{
}

/**
 * @brief Проверяет, является ли счет накопительным.
 * @return true, если счет накопительный.
 * @return false, если счет дебетовый.
 */
bool AccountType::isSavings() const // возвращает тип счета
{
    return savings;
}

/**
 * @brief Возвращает название типа банковского счета.
 * @return Строка с названием типа счета.
 * @details Если счет накопительный, возвращается
 * "Накопительный". Для дебетового счета возвращается
 * "Дебетовый".
 */
string AccountType::toString() const
{
    if (savings)
    {
        return "Накопительный";
    }
    return "Дебетовый";
}

int BankAccount::objectCount = 0; // статическое поле

/**
 * @brief Проверяет корректность номера счета.
 * @param number Номер банковского счета.
 * @details Номер счета должен быть больше нуля.
 * Если условие не выполняется, функция выбрасывает исключение.
 * @warning Номер, равный нулю или меньше нуля, считается некорректным.
 */
void BankAccount::validateAccountNumber(long long number) const 
{
    if (number <= 0)
    {
        throw invalid_argument(
            "Ошибка: номер счета должен быть больше 0."
        );
    }
}

/**
 * @brief Проверяет корректность имени владельца.
 * @param owner Имя владельца банковского счета.
 * @details Имя не должно быть пустой строкой.
 * Если имя пустое, функция выбрасывает исключение.
 * @warning Пустое имя владельца считается некорректным.
 */
void BankAccount::validateOwnerName(const string& owner) const
{
    if (owner.empty())
    {
        throw invalid_argument(
            "Ошибка: имя владельца не может быть пустым."
        );
    }
}
/**
 * @brief Проверяет корректность баланса.
 * @param balance Баланс банковского счета.
 * @details Баланс не может быть отрицательным.
 * Если баланс меньше нуля, функция выбрасывает исключение.
 * @warning Отрицательный баланс считается некорректным.
 */
void BankAccount::validateBalance(double balance) const
{
    if (balance < 0)
    {
        throw invalid_argument(
            "Ошибка: баланс не может быть отрицательным."
        );
    }
}

/**
 * @brief Создает банковский счет по умолчанию. (без параметров)
 * @details Создается активный дебетовый счет
 * с номером 1, именем "Unknown", нулевым балансом
 * и валютой "₽".
 * @note После создания объекта счетчик objectCount увеличивается.
 */
BankAccount::BankAccount()
    : accountNumber(1),
      ownerName("Unknown"),
      balance(0.0),
      active(true),
      currency("₽"),
      type(false)
{
    objectCount++;
}

/**
 * @brief Создает банковский счет с заданными параметрами.
 * @param number Номер банковского счета.
 * @param owner Имя владельца счета.
 * @param initialBalance Начальный баланс.
 * @param accountCurrency Валюта счета.
 * @param accountType Тип банковского счета.
 * @details Перед созданием объекта выполняется проверка
 * номера, имени владельца, баланса и валюты.
 * @note Создаваемый счет является активным.
 * @warning Некорректные данные приводят к выбрасыванию исключения.
 */
BankAccount::BankAccount(
    long long number,
    const string& owner,
    double initialBalance,
    const string& accountCurrency,
    const AccountType& accountType)
    : accountNumber(number),
      ownerName(owner),
      balance(initialBalance),
      active(true),
      currency(accountCurrency),
      type(accountType)
{
    validateAccountNumber(accountNumber); // проверка номер
    validateOwnerName(ownerName); // проыерка имени
    validateBalance(balance); // проверка баланса

    if (currency.empty())
    {
        throw invalid_argument(
            "Ошибка: валюта не может быть пустой."
        );
    }

    objectCount++;
}

/**
 * @brief Создает дебетовый счет с номером и именем владельца.
 * @param number Номер банковского счета.
 * @param owner Имя владельца счета.
 * @details Баланс устанавливается в 0,
 * валюта — в "₽", а счет создается активным.
 */
BankAccount::BankAccount(
    long long number,
    const string& owner)
    : accountNumber(number),
      ownerName(owner),
      balance(0.0),
      active(true),
      currency("₽"),
      type(false)
{
    validateAccountNumber(accountNumber);
    validateOwnerName(ownerName);

    objectCount++;
}
/**
 * @brief Уничтожает объект банковского счета.
 * @details При уничтожении объекта выводится сообщение
 * и уменьшается количество существующих объектов.
 * @note Счетчик objectCount уменьшается на единицу.
 */
BankAccount::~BankAccount() 
{
    cout << "Деструктор: счет "
         << accountNumber
         << " уничтожен."
         << endl;

    objectCount--;
}
/**
 * @brief Возвращает количество существующих объектов BankAccount.
 * @return Текущее количество объектов класса.
 */
int BankAccount::getObjectCount()
{
    return objectCount;
}
/**
 * @brief Возвращает номер банковского счета.
 * @return Номер счета.
 */
long long BankAccount::getAccountNumber() const
{
    return accountNumber;
}
/**
 * @brief Возвращает имя банковского счета.
 * @return Имя счета.
 */
string BankAccount::getOwnerName() const
{
    return ownerName;
}
/**
 * @brief Возвращает баланс банковского счета.
 * @return Баланс счета.
 */
double BankAccount::getBalance() const
{
    return balance;
}
/**
 * @brief Возвращает статус банковского счета.
 * @return true, если счет активен.
 * @return false, если счет заблокирован.
 */
bool BankAccount::isActive() const
{
    return active;
}
/**
 * @brief Возвращает валюту банковского счета.
 * @return Валюту счета.
 */
string BankAccount::getCurrency() const
{
    return currency;
}
/**
 * @brief Возвращает тип банковского счета.
 * @return Объект AccountType, описывающий тип счета
 */
AccountType BankAccount::getType() const
{
    return type;
}
/**
 * @brief Пополняет банковский счет.
 * @param amount Сумма пополнения счета.
 * @details Сначала проверяется активность счета
 * и корректность суммы.
 *
 * Для дебетового счета сумма просто добавляется к балансу.
 *
 * Для накопительного счета дополнительно начисляется
 * 3 процента от внесенной суммы.
 * @note Накопительный счет получает 3% именно
 * от суммы текущего пополнения.
 * @warning Заблокированный счет нельзя пополнять.
 * Сумма пополнения должна быть больше нуля.
 */
void BankAccount::deposit(double amount)
{
    if (!active)
    {
        throw runtime_error(
            "Ошибка: нельзя пополнить заблокированный счет."
        );
    }

    if (amount <= 0)
    {
        throw invalid_argument(
            "Ошибка: сумма пополнения должна быть больше 0."
        );
    }

    balance += amount;

    // Для накопительного счета начисляем 3%
    if (type.isSavings())
    {
        double interest = amount * 0.03;

        balance += interest;

        cout << "Начислено 3%: "
             << fixed << setprecision(2)
             << interest << " "
             << currency << endl;
    }
}
/**
 * @brief Снимает деньги с банковского счета.
 * @param amount Сумма, которую необходимо снять.
 * @return true, если деньги успешно сняты.
 * @return false, если на счете недостаточно средств.
 *
 * @details С дебетового счета деньги можно снять,
 * если сумма не превышает текущий баланс.
 *
 * Накопительный счет не позволяет снимать деньги.
 * @note Баланс изменяется только при успешном снятии.
 * @warning Нельзя снимать деньги с заблокированного
 * или накопительного счета.
 */
bool BankAccount::withdraw(double amount)
{
    if (!active)
    {
        throw runtime_error(
            "Ошибка: счет заблокирован."
        );
    }

    if (type.isSavings())
    {
        throw runtime_error(
            "Ошибка: с накопительного счета нельзя снимать деньги."
        );
    }

    if (amount <= 0)
    {
        throw invalid_argument(
            "Ошибка: сумма снятия должна быть больше 0."
        );
    }

    if (amount > balance)
    {
        return false;
    }

    balance -= amount;

    return true;
}
/**
 * @brief Блокирует банковский счет.
 */
void BankAccount::block()
{
    active = false;
}
/**
 * @brief Разблокирует банковский счет.
 */
void BankAccount::unblock()
{
    active = true;
}
/**
 * @brief Выводит информацию о банковском счете.
 * @details Выводит номер счета, имя владельца,
 * тип счета, баланс, валюту и текущий статус.
 * Баланс выводится с двумя знаками после десятичной точки.
 */
void BankAccount::print() const
{
    cout << "Номер счета: "
         << accountNumber << endl;

    cout << "Имя: "
         << ownerName << endl;

    cout << "Тип счета: "
         << type.toString() << endl;

    cout << "Баланс: "
         << fixed << setprecision(2)
         << balance << " "
         << currency << endl;

    if (active)
    {
        cout << "Статус: Активный" << endl;
    }
    else
    {
        cout << "Статус: Заблокирован" << endl;
    }
}