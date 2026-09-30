
public class SalesPerson extends Employeee{
	private double commission;
	
	SalesPerson(String name, String address, int age, char gender, float basicSalary,float commission){
	  	  
	  	  super(name, address, age, gender, ValidateSalary(basicSalary));
	  	  if(commission<0||commission>2000)
	  		  this.commission=0;
	  	  else
	  	      this.commission=commission;
	  	  
	    }
	
	public static float ValidateSalary(float basicSalary) {
		if(basicSalary<5000||basicSalary>100000)
			return 5000;
		else
			return basicSalary;
	}

	public double getCommission() {
		return commission;
	}
	

}
