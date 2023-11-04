#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>

using namespace std;

class Lender
{
private:
	string typeLender;
	string title;

public:

	Lender()
	{
		this->typeLender = "none";
		this->title = "none";
	}

	Lender(string type) :Lender()
	{
		this->typeLender = type;
	}

	Lender(
		string type,
		string titleValue
	)
	{
		this->typeLender = type;
		this->title = titleValue;
	}

	string GetTypeLender() {
		return typeLender;
	}

	string GetTitle() {
		return title;
	}

	void SetTypeLender(string type) {
		typeLender = type;
	}

	void SetTitle(string titleNew) {
		title = titleNew;
	}
};

class History
{
private:
	int repayLoan;
	int debt;
public:

	History()
	{
		this->repayLoan = 0;
		this->debt = 0;
	}
	History(
		int repay,
		int debtValue)
	{
		repayLoan = repay;
		debt = debtValue;
	}

	int GetRepayLoan() {
		return repayLoan;
	}

	int GetDebt() {
		return debt;
	}

	void SetRepayLoan(int repay) {
		repayLoan = repay;
	}

	void SetDebt(int debtNew) {
		debt = debtNew;
	}
};

class Guarantor
{
private:
	string nameGuarantor;
	int profitGuarantor;
public:

	Guarantor()
	{
		this->nameGuarantor = "none";
		this->profitGuarantor = 0;
	}
	Guarantor(
		string nameGuarant,
		int profitGuarant)
	{
		nameGuarantor = nameGuarant;
		profitGuarantor = profitGuarant;
	}

	string GetNameGuarantor() {
		return nameGuarantor;
	}

	int GetProfitGuarantor() {
		return profitGuarantor;
	}
	void SetNameGuarantor(string nameGuarant) {
		nameGuarantor = nameGuarant;
	}

	void SetProfitGuarantor(int profitGuarant) {
		profitGuarantor = profitGuarant;
	}
};

class Borrower
{
private:
	string name;
	int age;
	int profit;
	History historyBorrower;
	char criminal;
	Guarantor guarantorBorrower;
public:
	void OutBorrower();
	int CheckProbabilityApproval();

	Borrower()
	{
		this->name = "none";
		this->age = 0;
		this->profit = 0;
		this->criminal = '-';
	}
	Borrower(
		string nameValue,
		int ageValue,
		int profitValue,
		int repay,
		int debtValue,
		char criminalValue,
		string nameGuarant,
		int profitGuarant)
	{
		historyBorrower = History(repay, debtValue);
		guarantorBorrower = Guarantor(nameGuarant, profitGuarant);
		name = nameValue;
		age = ageValue;
		profit = profitValue;
		criminal = criminalValue;
	}

	string GetName() {
		return name;
	}

	int GetAge() {
		return age;
	}

	int GetProfit() {
		return profit;
	}

	int GetRepayLoan() {
		return historyBorrower.GetRepayLoan();
	}

	int GetDebt() {
		return historyBorrower.GetDebt();
	}

	char GetCriminal() {
		return criminal;
	}

	string GetNameGuarantor() {
		return guarantorBorrower.GetNameGuarantor();
	}

	int GetProfitGuarantor() {
		return guarantorBorrower.GetProfitGuarantor();
	}

	void SetName(string nameNew) {
		name = nameNew;
	}

	void SetAge(int ageNew) {
		age = ageNew;
	}

	void SetProfit(int profitNew) {
		profit = profitNew;
	}

	void SetCriminal(const char criminalNew) {
		criminal = criminalNew;
	}
};

class Credit
{
private:
	int number;
	Lender lenderCredit;
	Borrower borrowerCredit;
	int amount;
	float rate;
	int period;
	string currency;

public:
	Credit InputData();
	void OutData();
	void PercentCalculate();
	float CalculateMonthPayment();
	void EarlyRepaymentPercentCalculate();
	void Approve();
	void SearchNum(int* index, Credit* data, int sizeData);

	Credit()
	{
		this->number = 0;
		this->amount = 0;
		this->rate = 0;
		this->period = 0;
		this->currency = "рубль";
	};

	Credit(int numberValue) :Credit()
	{
		this->number = numberValue;
	}

	Credit(
		int numberValue,
		string type,
		string titleValue,
		string nameValue,
		int ageValue,
		int profitValue,
		int repay,
		int debtValue,
		char criminalValue,
		string nameGuarant,
		int profitGuarant,
		int amountValue,
		float rateValue,
		int periodValue,
		string cur)
	{
		lenderCredit = Lender(type, titleValue);
		borrowerCredit = Borrower(nameValue, ageValue, profitValue, repay, debtValue, criminalValue, \
			nameGuarant, profitGuarant);
		number = numberValue;
		amount = amountValue;
		rate = rateValue;
		period = periodValue;
		currency = cur;
	}

	int GetNumber() {
		return number;
	}
	int GetAmount() {
		return amount;
	}
	float GetRate() {
		return rate;
	}
	int GetPeriod() {
		return period;
	}
	string GetCurrency() {
		return currency;
	}
	void SetNumber(int num) {
		number = num;
	}
	void SetAmount(int amountNew) {
		amount = amountNew;
	}
	void SetRate(float rateNew) {
		rate = rateNew;
	}
	void SetPeriod(int periodNew) {
		period = periodNew;
	}
	void SetCurrency(string cur) {
		currency = cur;
	}
};
