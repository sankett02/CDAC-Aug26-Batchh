
public class ConsoleInput {
		public static int getInt() {
			return Integer.parseInt(getString());
		}
		
		public static float getFloat() {
			return Float.parseFloat(getString());
		}
		
		public static boolean getBoolean() {
			return Boolean.parseBoolean(getString());
		}
		
		public static char getChar() {
			return getString().charAt(0);
		}
		
		public static String getString(){
			 try {
					byte arr[]= new byte [100];      
					int length= System.in.read(arr);       
					byte []arrfinal=new byte[length-2];      
					System.arraycopy(arr, 0, arrfinal, 0, length-2); 
		            String objString=new String(arrfinal);        
				      return objString;
			       }catch(Exception e) {	
					 e.printStackTrace();
					 return null;
				 }

         }
}
