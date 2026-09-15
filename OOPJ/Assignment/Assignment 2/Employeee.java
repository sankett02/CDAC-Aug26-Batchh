
public abstract class Employeee {
	protected String name;
	protected String address;
	protected int age;
	protected char gender;
	protected float basicSalary;
	
	Employeee(String name, String address, int age, char gender, float basicSalary){
		if(name=="")
			this.name="Default(Name Not Entred";
		else
			this.name=name;
		
		if(address=="")
			this.address="Default(Address Not Entred";
		else
			this.address=address;
		
		if(age<18||age>60)
			this.age=21;
		else
			this.age=age;
		
		if(gender!='M'||gender!='F'||gender!='m'||gender!='f')
			this.gender='T';
		else
			this.gender=gender;		
		
		if(basicSalary<5000f||age>200000f)
			this.basicSalary=5000;
		else
			this.basicSalary=basicSalary;				
	}

	public String getName() {
		return name;
	}

	public String getAddress() {
		return address;
	}

	public int getAge() {
		return age;
	}

	public char getGender() {
		return gender;
	}

	public float getBasicSalary() {
		return basicSalary;
	}	

}
