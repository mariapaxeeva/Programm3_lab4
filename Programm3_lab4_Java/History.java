public class History
{
	int repayLoan;
	int debt;

	public History()
	{
		this.repayLoan = 0;
		this.debt = 0;
	}
	public History(
		int repay,
		int debtValue)
	{
		repayLoan = repay;
		debt = debtValue;
	}

	public int GetRepayLoan(){
		return repayLoan;
	}

	public int GetDebt() {
		return debt;
	}

	public void SetRepayLoan(int repay) {
		repayLoan = repay;
	}

	public void SetDebt(int debtNew) {
		debt = debtNew;
	}
};