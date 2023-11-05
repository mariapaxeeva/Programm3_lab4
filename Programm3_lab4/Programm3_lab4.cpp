// Programm3_lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "CreditLib.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Тесты:" << endl;

    int test = 0;

    Credit credit0;
    cout << "\n" << ++test << ") Тест конструктора без параметров (+ демонстрация использования статического поля number - счетчика еомера кредита)" << endl;
    credit0.OutData();

    Credit creditTest("банк", "Сбербанк", "Иванов И. И.", 30, 20000, 0, 1000, '-', "Петров П. П.", 45000, 100000, 4.8, 10, "рубль");
    cout << "\n" << ++test << ") Тест конструктора со всеми параметрами" << endl;
    creditTest.OutData();

    cout << "\n" << ++test << ") Тест метода для проверки одобрения кредита" << endl;
    creditTest.Approve();

    cout << "\n" << ++test << ") Тест метода для расчета суммы, которую требуется выплатить по процентной ставке" << endl;
    creditTest.PercentCalculate();

    cout << "\n" << ++test << ") Тест метода для расчета месячной выплаты" << endl;
    cout << "Выплата составляет " << creditTest.CalculateMonthPayment() << endl;

    cout << "\n" << ++test << ") Тест метода для расчета суммы, которую требуется выплатить по процентной ставке при досрочном погашении" << endl;
    creditTest.EarlyRepaymentPercentCalculate();

    Borrower borrowerTest;
    cout << "\n" << ++test << ") Тест метода для оценки вероятности одобрения кредита" << endl;
    borrowerTest.CheckProbabilityApproval();

    cout << "\n" << ++test << ") Тест метода для ввода с консоли и вывода в консоль вероятности одобрения кредита" << endl;
    creditTest = creditTest.InputData();
    creditTest.OutData();

    cout << "\n" << ++test << ") Динамический массив объектов класса " << endl;
    Credit* data = new Credit[3]{ int(123), int(111), int(1000) };
    for (int i = 0; i < 3; i++)
        cout << data[i].GetPeriod() << endl;

    delete[] data;

    cout << "\n" << ++test << ") Массив динамических объектов класса " << endl;
    Credit* dinamicData[3]{ new Credit(207), new Credit(1890), new Credit(43) };
    for (int i = 0; i < 3; i++)
        cout << dinamicData[i]->GetPeriod() << endl;

    for (int i = 0; i < 3; i++)
        delete dinamicData[i];
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
