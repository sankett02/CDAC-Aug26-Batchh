
public class Engineer extends Employeee{
	private float overTime;
	
	Engineer(String name, String address, int age, char gender, float basicSalary,float overTime){
  	  
  	  super(name, address, age, gender, validateSalary(basicSalary));
  	  
  	  if(overTime<0||overTime>5000)
  		  this.overTime=0;
  	  else
  	      this.overTime=overTime;
  	  
    }
	
	
	public static float validateSalary(float basicSalary) {
		
		if(basicSalary<5000||basicSalary>150000)
			return 50000;		
	     else 
		 return basicSalary;

	}
	
	
	public float getOverTime() {
		return overTime;
	}
	
	
	

}
