import java.util.*;

class Task3{
	public static void main(String[] args){
     	Scanner in = new Scanner(System.in);
		int Num;
		System.out.print("Enter Number: ");
		Num = in.nextInt();
		if(Num>0){
			System.out.println("Number is positive.");
		}
		else if(Num<0){
			System.out.println("Number is negative.");
		}
		else{
			System.out.println("Number is Zero.");
		}
	}
}