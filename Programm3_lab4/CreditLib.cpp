#include "CreditLib.h"
#include "stdio.h"
#include "conio.h"
#include "string"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

bool ProtectInputString(string* str)
{
	string word;
	getline(cin, word);
	*str = word;
	int l = word.length();
	if (word[0] == '\n' || word[0] == ' ')
		return true;
	for (int i = 1; i < l; i++) {
		if (word[i] != '\n' && word[i] != ' ')
			return false;
	}
	return true;
}

bool ProtectInputUnsigned(int* num, string message)
{
	cout << message << endl;
	while ((scanf("%d", num) < 1) || (*num < 0))
	{
		while (getchar() != '\n');
		cout << message << endl;
	}
	return false;
}

bool ProtectInputRate(float* num, string message)
{
	cout << message << endl;
	while ((scanf("%f", num) < 1) || (*num <= 0))
	{
		while (getchar() != '\n');
		cout << message << endl;
	}
	return false;
}

Borrower InputBorrower()
{
	string nameValue;
	int ageValue;
	int profitValue;
	int repay;
	int debtValue;
	char criminalValue;
	string nameGuarant;
	int profitGuarant;
	while (getchar() != '\n');
	do {
		cout << "Введите ФИО заёмщика:" << endl;
	} while (ProtectInputString(&nameValue));
	ProtectInputUnsigned(&ageValue, "Введите возраст заёмщика:");
	ProtectInputUnsigned(&profitValue, "Введите сумму дохода заёмщика в месяц:");
	ProtectInputUnsigned(&repay, "Введите количество ранее погашенных кредитов:");
	ProtectInputUnsigned(&debtValue, "Введите сумму имеющейся задолженности:");
	do
	{
		printf("Наличие судимости (- - нет, + - есть):\n");
		while (getchar() != '\n');
		scanf("%c", &criminalValue);
	} while (criminalValue != '-' && criminalValue != '+');
	do {
		cout << "Введите ФИО поручителя:" << endl;
		while (getchar() != '\n');
	} while (ProtectInputString(&nameGuarant));
	ProtectInputUnsigned(&profitGuarant, "Введите сумму дохода поручителя в месяц:");
	Borrower borrower = Borrower(nameValue, ageValue, profitValue, repay, debtValue, criminalValue, \
		nameGuarant, profitGuarant);
	return borrower;
}

void Borrower::OutBorrower()
{
	cout << "ФИО заёмщика:                      " + this->name << endl;
	cout << "Возраст заёмщика:                  " << this->age << endl;
	cout << "Доход заёмщика:                    " << this->profit << endl;
	cout << "Количество погашенных кредитов     " << this->historyBorrower.GetRepayLoan() << endl;
	cout << "Сумма задолженности:               " << this->historyBorrower.GetDebt() << endl;
	cout << "Наличие судимости:                 " + this->criminal;
	cout << "ФИО поручителя:                    " + this->guarantorBorrower.GetNameGuarantor() << endl;
	cout << "Доход поручителя:                  " << this->guarantorBorrower.GetProfitGuarantor() << endl;
}

//функция оценивает вероятность одобрения кредита некоторому заёмщику
int Borrower::CheckProbabilityApproval()
{
	Borrower borrowerCredit = InputBorrower();
	bool conditionAge = true;
	bool conditionProfit = true;
	bool conditionHistory = true;
	bool conditionCriminal = true;
	if (borrowerCredit.age < 18)
		conditionAge = false;
	if (borrowerCredit.profit < 14375)
		conditionProfit = false;
	if (borrowerCredit.historyBorrower.GetRepayLoan() < 2 && borrowerCredit.historyBorrower.GetDebt() > borrowerCredit.profit * 3)
		conditionHistory = false;
	if (borrowerCredit.criminal == '+')
		conditionCriminal = false;
	cout << "Заёмщик: " << borrowerCredit.name << endl;
	if (conditionAge && conditionProfit && conditionHistory && conditionCriminal)
	{
		cout << "Вероятность одобрения кредита высока!" << endl;
		return 0;
	}
	else
	{
		cout << "К сожалению, кредит вряд ли будет одобрен." << endl;
		return -1;
	}
}

Credit Credit::InputData()
{
	string typeLender = "";
	string title = "";
	string nameValue = "";
	int ageValue = 0;
	int profitValue = 0;
	int repay = 0;
	int debtValue = 0;
	char criminalValue = '-';
	string nameGuarant = "";
	int profitGuarant = 0;
	int amountValue = 0;
	float rateValue = 0;
	int periodValue = 0;
	string cur = "";
	do {
		printf("Введите вид кредитора (банк или МФО):\n");
		cin >> typeLender;
	} while ((typeLender != "банк") && (typeLender != "МФО"));
	while (getchar() != '\n');
	do {
		cout << "Введите название организации:" << endl;
	} while (ProtectInputString(&title));
	do {
		cout << "Введите ФИО заёмщика:" << endl;
	} while (ProtectInputString(&nameValue));
	ProtectInputUnsigned(&ageValue, "Введите возраст заёмщика:");
	ProtectInputUnsigned(&profitValue, "Введите сумму дохода заёмщика в месяц:");
	ProtectInputUnsigned(&repay, "Введите количество ранее погашенных кредитов:");
	ProtectInputUnsigned(&debtValue, "Введите сумму имеющейся задолженности:");
	do
	{
		printf("Наличие судимости (- - нет, + - есть):\n");
		while (getchar() != '\n');
		scanf("%c", &criminalValue);
	} while (criminalValue != '-' && criminalValue != '+');
	do {
		cout << "Введите ФИО поручителя:" << endl;
		while (getchar() != '\n');
	} while (ProtectInputString(&nameGuarant));
	ProtectInputUnsigned(&profitGuarant, "Введите сумму дохода поручителя в месяц:");
	ProtectInputUnsigned(&amountValue, "Введите сумму кредита:");
	ProtectInputRate(&rateValue, "Введите процентную ставку:");
	ProtectInputUnsigned(&periodValue, "Введите срок:");
	while (getchar() != '\n');
	do {
		cout << "Введите валюту:" << endl;
	} while (ProtectInputString(&cur));

	Credit credit = Credit(typeLender, title, nameValue, ageValue, profitValue, repay, debtValue, criminalValue, \
		nameGuarant, profitGuarant, amountValue, rateValue, periodValue, cur);
	return credit;
}

void Credit::OutData()
{
	cout << "\nИнформация по кредиту №" << this->number << endl;
	cout << "Название кредитной организации:    " + this->lenderCredit.GetTitle() << endl;
	cout << "Вид кредитора (банк или МФО):      " + this->lenderCredit.GetTypeLender() << endl;
	cout << "ФИО заёмщика:                      " + this->borrowerCredit.GetName() << endl;
	cout << "Возраст заёмщика:                  " << this->borrowerCredit.GetAge() << endl;
	cout << "Доход заёмщика:                    " << this->borrowerCredit.GetProfit() << endl;
	cout << "Количество погашенных кредитов     " << this->borrowerCredit.GetRepayLoan() << endl;
	cout << "Сумма задолженности:               " << this->borrowerCredit.GetDebt() << endl;
	cout << "Наличие судимости:                 " + this->borrowerCredit.GetCriminal();
	cout << "ФИО поручителя:                    " + this->borrowerCredit.GetNameGuarantor() << endl;
	cout << "Доход поручителя:                  " << this->borrowerCredit.GetProfitGuarantor() << endl;
	cout << "Сумма кредита:                     " << this->amount << endl;
	cout << "Годовая процентная ставка:         " << this->rate << endl;
	cout << "Срок:                              " << this->period << endl;
	cout << "Валюта:                            " + this->currency << endl;
}

void Credit::PercentCalculate()
{
	float rezult = this->amount * this->rate * this->period / 100;
	cout << "По кредиту №" << this->number << " за " << this->period << " лет сверх суммы потребуется выплатить "\
		<< rezult << " (" << this->currency << ") " << endl;
}

float Credit::CalculateMonthPayment()
{
	float monthPayment = (1 + this->rate / 100) * this->amount / 12;
	return monthPayment;
}

void Credit::EarlyRepaymentPercentCalculate()
{
	int factPeriod = 0;
	do
	{
		ProtectInputUnsigned(&factPeriod, "Введите фактический срок погашения кредита:");
	} while (factPeriod >= this->period);
	float rezult = this->amount * this->rate * factPeriod / 100;
	cout << "По кредиту №" << this->number << " за " << this->period << " лет (погасив досрочно за " << factPeriod\
		<< " лет) сверх суммы потребуется выплатить " << rezult << " (" << this->currency << ") " << endl;
}

//функция проверяет критерии для одобрения кредита и выносит вердикт
void Credit::Approve()
{
	bool conditionAge = true;
	bool conditionProfit = true;
	bool conditionHistory = true;
	bool conditionCriminal = true;
	float monthPayment = CalculateMonthPayment();
	if (this->borrowerCredit.GetAge() < 18)
		conditionAge = false;
	if (this->borrowerCredit.GetProfit() < monthPayment * 3)
		conditionProfit = false;
	if (this->borrowerCredit.GetRepayLoan() < 2 && this->borrowerCredit.GetDebt() > monthPayment * 6 \
		&& this->borrowerCredit.GetProfitGuarantor() < monthPayment * 3)
		conditionHistory = false;
	if (this->borrowerCredit.GetCriminal() == '+')
		conditionCriminal = false;
	cout << "Заёмщик: " << this->borrowerCredit.GetName() << endl;
	if (conditionAge && conditionProfit && conditionHistory && conditionCriminal)
	{
		cout << "Кредит одобрен." << endl;
	}
	else
	{
		cout << "Кредит не одобрен." << endl;
	}
}

//функция поиска индекса элемента в массиве по полю <номер кредита>
void Credit::SearchNum(int* index, Credit* data, int sizeData)
{
	int num = 0;
	bool flag = true;
	puts("Введите номер кредита:");
	scanf("%d", &num);
	for (int j = 0; j < sizeData; j++)
		if (data[j].GetNumber() == num)
		{
			flag = false;
			*index = j;
		}
	if (flag)
	{
		puts("По введенному номеру не найдено данных.");
		*index = -1;
	}
}

