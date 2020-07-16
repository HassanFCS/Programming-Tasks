import java.util.*;

class Task1{
	public static void main(String[] args){
		float Sum=0, Avg, Num;
     	Scanner in = new Scanner(System.in);
		System.out.print("Enter the upper bound: ");
		Num = in.nextInt();
		for(int i=1;i<Num;i++){
			Sum=Sum+i;
		}
		System.out.println("The Sum is " + Sum);
		Avg=Sum/Num;
		System.out.println("The Avg is " + Avg);
	}
}