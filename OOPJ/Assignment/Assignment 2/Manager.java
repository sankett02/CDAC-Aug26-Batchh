
public class Manager extends Employeee{
      private float HRA;
      
      Manager(String name, String address, int age, char gender, float basicSalary,float HRA){
    	  
    	  super(name, address, age, gender, ValidateSalary(basicSalary)); 
    	  
    	  if(HRA<0||HRA>20000)
    		  this.HRA=0;
    	  else
    	      this.HRA=HRA;  	  
      }
      
      
      public static float ValidateSalary(float basicSalary) {
    	  if(basicSalary<5000f||basicSalary>200000f)
    		  return 5000;
    	  else 
    		  return basicSalary;
      }
      
      


	  public float getHRA(){
		  return HRA;
	  }
           
}






// Why we have used Static to validate Salary And how can i Do without Static 
//And:  Because without Static we need to create object first then only we can update thats why we used static
// Without static we need to update salary using this keyword after super keyword becz super need to run first
//class Manager extends Employee {
//
//    Manager(String name, double salary) {
//
//        super(name, 0);  // salary = 0 initially
//
//        this.salary = validateSalary(salary);  // salary updated here
//    }
//
//    private double validateSalary(double salary) {
//        if (salary >= 50000 && salary <= 200000) {
//            return salary;
//        }
//
//        return 50000;
//    }
//}




//Q. why Not validation Void 
//public static void ValidateSalary(float basicSalary) {
//if(basicSalary<5000f||basicSalary>200000f)
//	  this.basicSalary=50000;    we can not do this also Beacause This can not be used
//because static do not have relation between object this
//else 
//	  this.basicSalary=50000;
//	
//}