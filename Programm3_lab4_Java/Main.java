import java.util.Scanner;
import java.util.ArrayList;
public class Main{
    public static void main(String[] args){
        int test = 0;
        Scanner in = new Scanner(System.in);
        Credit credit0 = new Credit();
        System.out.println(++test + ") Тест конструктора без параметров");
        credit0.OutData();

        Credit creditTest = new Credit(123, "банк", "Сбербанк", "Иванов И. И.", 30, 20000, 0, 1000, '-', "Петров П. П.", 45000, 100000, 4.8f, 10,"рубль");
        System.out.println("\n" + ++test + ") Тест конструктора со всеми параметрами");
        creditTest.OutData();

        System.out.println("\n" + ++test + ") Тест метода для проверки одобрения кредита");
        creditTest.Approve();

        System.out.println("\n" + ++test + ") Тест метода для расчета суммы, которую требуется выплатить по процентной ставке");
        creditTest.PercentCalculate();

        System.out.println("\n" + ++test + ") Тест метода для расчета месячной выплаты");
        System.out.printf("Выплата составляет %g\n", creditTest.CalculateMonthPayment());

        System.out.println("\n" + ++test + ") Тест метода для расчета суммы, которую требуется выплатить по процентной ставке при досрочном погашении");
        creditTest.EarlyRepaymentPercentCalculate();

        Borrower borrowerTest = new Borrower();
        System.out.println("\n" + ++test + ") Тест метода для оценки вероятности одобрения кредита");
        borrowerTest.CheckProbabilityApproval();

        System.out.println("\n" + ++test + ") Тест метода для ввода с консоли и вывода в консоль вероятности одобрения кредита");
        creditTest = creditTest.InputData();
        creditTest.OutData();

        System.out.println("\n" + ++test + ") Динамический массив объектов класса");
        ArrayList<Credit> data = new ArrayList<>();
        data.add(credit0);
        data.add(new Credit(123, "банк", "Сбербанк", "Иванов И. И.", 30, 20000, 0, 1000, '-', "Петров П. П.", 45000, 100000, 4.8f, 10,"рубль"));
        data.add(new Credit(45));
        for (int i = 0; i < 3; i++)
            System.out.println(data.get(i).GetNumber());

        data.removeAll(data);
    }
}