public class Main {
	
	public static void main(String args[]) {
		
		 String name;
		 String address;
		 int age;
		 char gender;
		 float basicSalary;
		 float HRA;
		 float overTime;
		 float commission;
		 
		 
		 int choice;
		 
		 int NumOfMang=0;
		 int NumOfEngg=0;		 
		 int NumOfSales=0;		 
				 
		 Manager manager[]= new Manager[40];
		 Engineer engineer[]=new Engineer[40];
		 SalesPerson salesPerson[]= new SalesPerson[40];
		 
		 do {
			 System.out.println("Choose A Option");
			 System.out.println("1.Add");
			 System.out.println("2.Display");
			 System.out.println("3.Delete(TBD)");
			 System.out.println("4.Sort");
			 System.out.println("5.Save");
			 System.out.println("6.Load");
			 System.out.println("7.Exit");
			 choice=ConsoleInput.getInt();
			 
			 switch(choice){
			 
			 case 1:do {
							 System.out.println("1. Manager");
							 System.out.println("2. Engineer");
							 System.out.println("3. Sales Person");
							 System.out.println("4. Exit");
							 choice=ConsoleInput.getInt();
							 switch(choice){
							 case 1:
									 System.out.println("How Many MAnager Want to add");
									 int tempMang=0;
									 tempMang=ConsoleInput.getInt();
									 NumOfMang=NumOfMang+tempMang;
								   for(int tmp=0; tmp<NumOfMang; tmp++){
										   
										System.out.println("Enter the Name:");
										name=ConsoleInput.getString();
										System.out.println("Enter the Address:");
										address=ConsoleInput.getString();
										System.out.println("Enter the Age:");
										age=ConsoleInput.getInt();
										System.out.println("Enter the Gender:");
										gender=ConsoleInput.getChar();
										System.out.println("Enter the Basic Salary:");
										basicSalary=ConsoleInput.getFloat();
										System.out.println("Enter the HRA:");
										HRA=ConsoleInput.getFloat();
										
										manager[tmp]= new Manager(name, address, age, gender, basicSalary,HRA);												
										}
								   break;
							 case 2: 
									 System.out.println("How Many Engineer Want to add");
									 int tempEngg=0;
									 tempEngg=ConsoleInput.getInt();
									 NumOfEngg=NumOfEngg+tempEngg;
								   for(int tmp=0; tmp<NumOfEngg; tmp++){
										   
										System.out.println("Enter the Name:");
										name=ConsoleInput.getString();
										System.out.println("Enter the Address:");
										address=ConsoleInput.getString();
										System.out.println("Enter the Age:");
										age=ConsoleInput.getInt();
										System.out.println("Enter the Gender:");
										gender=ConsoleInput.getChar();
										System.out.println("Enter the Basic Salary:");
										basicSalary=ConsoleInput.getFloat();
										System.out.println("Enter the Over-Time:");
										overTime=ConsoleInput.getFloat();
										
										engineer[tmp]= new Engineer(name, address, age, gender, basicSalary,overTime);												
										}
								   break;
							 case 3:
									 System.out.println("How Many Sales Person Want to add");
									 int tempSales=0;
									 tempSales=ConsoleInput.getInt();
									 NumOfSales=NumOfSales+tempSales;
								   for(int tmp=0; tmp<NumOfSales; tmp++){
									   
										System.out.println("Enter the Name:");
										name=ConsoleInput.getString();
										System.out.println("Enter the Address:");
										address=ConsoleInput.getString();
										System.out.println("Enter the Age:");
										age=ConsoleInput.getInt();
										System.out.println("Enter the Gender:");
										gender=ConsoleInput.getChar();
										System.out.println("Enter the Basic Salary:");
										basicSalary=ConsoleInput.getFloat();
										System.out.println("Enter the Over-Time:");
										commission=ConsoleInput.getFloat();
										
										salesPerson[tmp]= new SalesPerson(name, address, age, gender, basicSalary,commission);												
										}
								   break;
							 default:break;
							 }
							 
						 }while(choice!=4);	
			 
			           break;
			 case 2:do {
							 System.out.println("1.Display Manager");
							 System.out.println("2.Display Engineer");
							 System.out.println("3.Display Sales Person");
							 System.out.println("4.Exit");
							 choice=ConsoleInput.getInt();
							 switch(choice){
							 case 1:
								   for(int tmp=0; tmp<NumOfMang; tmp++){
									
										System.out.println("Manager      :"+manager[tmp].getName().toUpperCase());
										System.out.println("Address      :"+manager[tmp].getAddress());
										System.out.println("Age          :"+manager[tmp].getAge());
										System.out.println("Gender       :"+manager[tmp].getGender());
										System.out.println("Basic Salary :"+manager[tmp].getBasicSalary());
										System.out.println("HRA          :"+manager[tmp].getHRA());											
									}
								   System.out.println();
									break;
							 case 2: 
								   for(int tmp=0; tmp<NumOfEngg; tmp++){
										
										System.out.println("Engineer     :"+engineer[tmp].getName().toUpperCase());
										System.out.println("Address      :"+engineer[tmp].getAddress());
										System.out.println("Age          :"+engineer[tmp].getAge());
										System.out.println("Gender       :"+engineer[tmp].getGender());
										System.out.println("Basic Salary :"+engineer[tmp].getBasicSalary());
										System.out.println("Over Time    :"+engineer[tmp].getOverTime());											
									}
								   System.out.println();
									break;
							 case 3:
								   for(int tmp=0; tmp<NumOfSales; tmp++){
										
										System.out.println("Sales PErson :"+salesPerson[tmp].getName().toUpperCase());
										System.out.println("Address      :"+salesPerson[tmp].getAddress());
										System.out.println("Age          :"+salesPerson[tmp].getAge());
										System.out.println("Gender       :"+salesPerson[tmp].getGender());
										System.out.println("Basic Salary :"+salesPerson[tmp].getBasicSalary());
										System.out.println("Commission   :"+salesPerson[tmp].getCommission());											
									}
								   System.out.println();
									break;
							 default: break;
							 }
						 }while(choice!=4);				 
							 
			 case 3: break;// 3 Delete Implemeted later 
				 
			 case 4:do {
							 System.out.println("1.By Name Ascending");
							 System.out.println("2.By Name Descending");
							 System.out.println("3.By Designation(TBD)");
							 System.out.println("4.Exit");
							 choice=ConsoleInput.getInt();
							 switch(choice){
							      case 1: do {
										  System.out.println("1.Manger");
										  System.out.println("2.Engineer");
										  System.out.println("3.Sales Person");
										  System.out.println("4.Exit");
										  choice=ConsoleInput.getInt();
										  switch(choice){
										     case 1: // Ascending Order
										    	 int asdendingMag=0;
										    	 for(int tmp=0; tmp<NumOfMang-1; tmp++) {
										    		 asdendingMag=manager[tmp].getName().compareTo(manager[tmp+1].getName());
										    	 if(asdendingMag==0) {
										    		 System.out.println(manager[tmp].getName());
										    	     System.out.println(manager[tmp+1].getName());
										    	   }else if(asdendingMag<0) {
										    		   System.out.println(manager[tmp].getName());
										    	       System.out.println(manager[tmp+1].getName());
										    	   }
										    	    else {
										    	    	System.out.println(manager[tmp+1].getName());
									    	            System.out.println(manager[tmp].getName());
										    	    }
										    		   
										    	  }
										    	 break;
										     case 2:
										    	 int asdendingEng=0;
										    	 for(int tmp=0; tmp<NumOfEngg-1; tmp++) {
										    		 asdendingEng=engineer[tmp].getName().compareTo(engineer[tmp+1].getName());
										    	 if(asdendingEng==0) {
										    		 System.out.println(engineer[tmp].getName());
										    	     System.out.println(engineer[tmp+1].getName());
										    	   }else if(asdendingEng<0) {
										    		   System.out.println(engineer[tmp].getName());
										    	       System.out.println(engineer[tmp+1].getName());
										    	   }
										    	    else {
										    	    	System.out.println(engineer[tmp+1].getName());
									    	            System.out.println(engineer[tmp].getName());
										    	    }
										    		   
										    	  }
										    	 break;
										     case 3: 
										    	 int asdendingSales=0;
										    	 for(int tmp=0; tmp<NumOfSales-1; tmp++) {
										    		 asdendingSales=salesPerson[tmp].getName().compareTo(salesPerson[tmp+1].getName());
										    	 if(asdendingSales==0) {
										    		 System.out.println(salesPerson[tmp].getName());
										    	     System.out.println(salesPerson[tmp+1].getName());
										    	   }else if(asdendingSales<0) {
										    		   System.out.println(salesPerson[tmp].getName());
										    	       System.out.println(salesPerson[tmp+1].getName());
										    	   }
										    	    else {
										    	    	System.out.println(salesPerson[tmp+1].getName());
									    	            System.out.println(salesPerson[tmp].getName());
										    	    }
										    		   
										    	  }
										    	 break;
										     default: break;
										    }
							           }while(choice!=4);
							           break;
							      case 2:
							    	  do {
										  System.out.println("1.Manger");
										  System.out.println("2.Engineer");
										  System.out.println("3.Sales Person");
										  System.out.println("4.Exit");
										  choice=ConsoleInput.getInt();
										  switch(choice){
										     case 1: // Ascending Order
										    	 int asdendingMag=0;
										    	 for(int tmp=0; tmp<NumOfMang-1; tmp++) {
										    		 asdendingMag=manager[tmp].getName().compareTo(manager[tmp+1].getName());
										    	 if(asdendingMag==0) {
										    		 System.out.println(manager[tmp].getName());
										    	     System.out.println(manager[tmp+1].getName());
										    	   }else if(asdendingMag<0) {
										    		   System.out.println(manager[tmp+1].getName());
										    	       System.out.println(manager[tmp].getName());
										    	   }
										    	    else {
										    	    	System.out.println(manager[tmp].getName());
									    	            System.out.println(manager[tmp+1].getName());
										    	    }
										    		   
										    	  }
										    	 break;
										     case 2:
										    	 int asdendingEng=0;
										    	 for(int tmp=0; tmp<NumOfEngg-1; tmp++) {
										    		 asdendingEng=engineer[tmp].getName().compareTo(engineer[tmp+1].getName());
										    	 if(asdendingEng==0) {
										    		 System.out.println(engineer[tmp].getName());
										    	     System.out.println(engineer[tmp+1].getName());
										    	   }else if(asdendingEng<0) {
										    		   System.out.println(engineer[tmp+1].getName());
										    	       System.out.println(engineer[tmp].getName());
										    	   }
										    	    else {
										    	    	System.out.println(engineer[tmp].getName());
									    	            System.out.println(engineer[tmp+1].getName());
										    	    }
										    		   
										    	  }
										    	 break;
										     case 3: 
										    	 int asdendingSales=0;
										    	 for(int tmp=0; tmp<NumOfSales-1; tmp++) {
										    		 asdendingSales=salesPerson[tmp].getName().compareTo(salesPerson[tmp+1].getName());
										    	 if(asdendingSales==0) {
										    		 System.out.println(salesPerson[tmp].getName());
										    	     System.out.println(salesPerson[tmp+1].getName());
										    	   }else if(asdendingSales<0) {
										    		   System.out.println(salesPerson[tmp+1].getName());
										    	       System.out.println(salesPerson[tmp].getName());
										    	   }
										    	    else {
										    	    	System.out.println(salesPerson[tmp].getName());
									    	            System.out.println(salesPerson[tmp+1].getName());
										    	    }
										    		   
										    	  }
										    	 break;
										     default: break;
										    }
							           }while(choice!=4);
							    	   break;
							      case 3:break; //3.By Designation(TBD)
							      default:break;
							     }
			                 }while(choice!=4);
			 case 5:break; //Save Not Implemented
			 case 6:break; //Load Not Implemented
			 default:
				 
			 }
			 
		 }while(choice!=7);
		 
		
			
//		System.out.println("Enter the Over-Time:");
//		overTime=ConsoleInput.getFloat();
//		System.out.println("Enter the Commission:");
//		overTime=ConsoleInput.getFloat();
		

		
		
		
		
	}

}
