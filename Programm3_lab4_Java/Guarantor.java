public class Guarantor
{
	String nameGuarantor;
	int profitGuarantor;

    public Guarantor()
	{
		this.nameGuarantor = "none";
		this.profitGuarantor = 0;
	}
	public Guarantor(
		String nameGuarant,
		int profitGuarant)
	{
		nameGuarantor = nameGuarant;
		profitGuarantor = profitGuarant;
	}

	public String GetNameGuarantor() {
		return nameGuarantor;
	}

	public int GetProfitGuarantor() {
		return profitGuarantor;
	}

	public void SetNameGuarantor(String nameGuarant) {
		nameGuarantor = nameGuarant;
	}

	public void SetProfitGuarantor(int profitGuarant) {
		profitGuarantor = profitGuarant;
	}
};