import java.util.Scanner;
public class Credit
{
	int number;
	Lender lenderCredit;
	Borrower borrowerCredit;
	int amount;
	float rate;
	int period;
	String currency;

    public Credit InputData()
    {
        int numberValue = 0;
        String title = "";
        String nameValue = "";
        String typeLender = "";
        int ageValue = 0;
        int profitValue = 0;
        int repay = 0;
        int debtValue = 0;
        char criminalValue = '-';
        String nameGuarant = "";
        int profitGuarant = 0;
        int amountValue = 0;
        float rateValue = 0;
        int periodValue = 0;
        String cur = "";
        Scanner in = new Scanner(System.in);
        numberValue = ProtectInputUnsigned("Введите номер кредитного договора:");
        do {
            System.out.print("Введите вид кредитора (bank or MFO): ");
            typeLender = in.nextLine();
        } while (!typeLender.equals("bank") && !typeLender.equals("MFO"));
        do {
            System.out.println("Введите название организации:");
        } while ((title = ProtectInputString()) == null);
        do {
            System.out.println("Введите ФИО заёмщика:");
        } while ((nameValue = ProtectInputString()) == null);
        ageValue = ProtectInputUnsigned("Введите возраст заёмщика:");
        profitValue = ProtectInputUnsigned("Введите сумму дохода заёмщика в месяц:");
        repay = ProtectInputUnsigned("Введите количество ранее погашенных кредитов:");
        debtValue = ProtectInputUnsigned("Введите сумму имеющейся задолженности:");
        do
        {
            System.out.println("Наличие судимости (- - нет, + - есть):");
            criminalValue = in.next().charAt(0);
        } while (criminalValue != '-' && criminalValue != '+');
        do {
            System.out.println("Введите ФИО поручителя:");
        } while ((nameGuarant = ProtectInputString()) == null);
        profitGuarant = ProtectInputUnsigned("Введите сумму дохода поручителя в месяц:");
        amountValue = ProtectInputUnsigned("Введите сумму кредита:");
        rateValue = ProtectInputRate("Введите процентную ставку:");
        periodValue = ProtectInputUnsigned("Введите срок:");
        do {
            System.out.println("Введите валюту:");
        } while ((cur = ProtectInputString()) == null);

        Credit credit = new Credit(numberValue, typeLender, title, nameValue, ageValue, profitValue, repay, debtValue, criminalValue,
            nameGuarant, profitGuarant, amountValue, rateValue, periodValue, cur);
        return credit;
    }

    public void OutData()
    {
        System.out.println("\nИнформация по кредиту №" + this.number);
        System.out.println("Название кредитной организации:    " + this.lenderCredit.GetTitle());
        System.out.println("Вид кредитора (банк или МФО):      " + this.lenderCredit.GetTypeLender());
        System.out.println("ФИО заёмщика:                      " + this.borrowerCredit.GetName());
        System.out.println("Возраст заёмщика:                  " + this.borrowerCredit.GetAge());
        System.out.println("Доход заёмщика:                    " + this.borrowerCredit.GetProfit());
        System.out.println("Количество погашенных кредитов     " + this.borrowerCredit.GetRepayLoan());
        System.out.println("Сумма задолженности:               " + this.borrowerCredit.GetDebt());
        System.out.println("Наличие судимости:                 " + this.borrowerCredit.GetCriminal());
        System.out.println("ФИО поручителя:                    " + this.borrowerCredit.GetNameGuarantor());
        System.out.println("Доход поручителя:                  " + this.borrowerCredit.GetProfitGuarantor());
        System.out.println("Сумма кредита:                     " + this.amount);
        System.out.println("Годовая процентная ставка:         " + this.rate); 
        System.out.println("Срок:                              " + this.period);
        System.out.println("Валюта:                            " + this.currency);
    }

    public void PercentCalculate()
    {
        float rezult = this.amount * this.rate * this.period / 100;
        System.out.printf("По кредиту №%d за %d лет сверх суммы потребуется выплатить %g (%s)\n", this.number, this.period, rezult, this.currency);
    }

    public float CalculateMonthPayment()
    {
        float monthPayment = (1 + this.rate / 100) * this.amount / 12;
        return monthPayment;
    }

    public void EarlyRepaymentPercentCalculate()
    {
        int factPeriod = 0;
        do
        {
            factPeriod = ProtectInputUnsigned("Введите фактический срок погашения кредита:");
        } while (factPeriod >= this.period);
        float rezult = this.amount * this.rate * factPeriod / 100;
        System.out.printf("По кредиту №%d за %d лет (погасив досрочно за %d лет) сверх суммы потребуется выплатить %g (%s)\n", this.number, this.period, factPeriod, rezult, this.currency);
    }

    //функция проверяет критерии для одобрения кредита и выносит вердикт
    public void Approve()
    {
        boolean conditionAge = true;
        boolean conditionProfit = true;
        boolean conditionHistory = true;
        boolean conditionCriminal = true;
        float monthPayment = CalculateMonthPayment();
        if (this.borrowerCredit.GetAge() < 18)
            conditionAge = false;
        if (this.borrowerCredit.GetProfit() < monthPayment * 3)
            conditionProfit = false;
        if (this.borrowerCredit.GetRepayLoan() < 2 && this.borrowerCredit.GetDebt() > monthPayment * 6
            && this.borrowerCredit.GetProfitGuarantor() < monthPayment * 3)
            conditionHistory = false;
        if (this.borrowerCredit.GetCriminal() == '+')
            conditionCriminal = false;
        System.out.println("Заёмщик: " + this.borrowerCredit.GetName());
        if (conditionAge && conditionProfit && conditionHistory && conditionCriminal)
        {
            System.out.println("Кредит одобрен.");
        }
        else
        {
            System.out.println("Кредит не одобрен.");
        }
    }

     public String ProtectInputString()
    {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        if(str == null || str.isEmpty())
            return null;
        return str;
    }

    public int ProtectInputUnsigned(String message)
    {
        Scanner in = new Scanner(System.in);
        int num;
        while (true) {  
            System.out.println(message);  
            try {  
                num = Integer.parseInt(in.nextLine());
                if (num >= 0)
                    break;
            } catch (Exception e) {  
                System.out.println("Неверный формат ввода! Попробуйте ещё раз.");  
            }  
        }
        return num;
    }

    public float ProtectInputRate(String message)
    {
        Scanner in = new Scanner(System.in);
        float num;
        while (true) {  
            System.out.println(message);  
            try {  
                num = Float.parseFloat(in.nextLine());
                if (num >= 0)
                    break;
            } catch (Exception e) {  
                System.out.println("Неверный формат ввода! Попробуйте ещё раз.");  
            }  
        }
        return num;
    }

	public Credit()
	{
        this.lenderCredit = new Lender();
        this.borrowerCredit = new Borrower();
		this.number = 0;
		this.amount = 0;
		this.rate = 0;
		this.period = 0;
		this.currency = "рубль";
	};

	public Credit(int numberValue)
	{
        this();
		this.number = numberValue;
	}

	public Credit(
		int numberValue,
		String type,
		String titleValue,
		String nameValue,
		int ageValue,
		int profitValue,
		int repay,
		int debtValue,
		char criminalValue,
		String nameGuarant,
		int profitGuarant,
		int amountValue,
		float rateValue,
		int periodValue,
		String cur)
	{
		lenderCredit = new Lender(type, titleValue);
		borrowerCredit = new Borrower(nameValue, ageValue, profitValue, repay, debtValue, criminalValue,
			nameGuarant, profitGuarant);
		number = numberValue;
		amount = amountValue;
		rate = rateValue;
		period = periodValue;
		currency = cur;
	}

	public int GetNumber() {
		return number;
	}
	public int GetAmount() {
		return amount;
	}
	public float GetRate() {
		return rate;
	}
	public int GetPeriod() {
		return period;
	}
	public String GetCurrency() {
		return currency;
	}
	public void SetNumber(int num) {
		number = num;
	}
	public void SetAmount(int amountNew) {
		amount = amountNew;
	}
	public void SetRate(float rateNew) {
		rate = rateNew;
	}
	public void SetPeriod(int periodNew) {
		period = periodNew;
	}
	public void SetCurrency(String cur) {
		currency = cur;
	}
}