import javax.swing.*;

public class Task4{

    public static void main(String[] args) {
	String Val;
    int Num1, Num2;
	char Opr;
	int Sum, Sub, Mul;
	float Div;

    Val = JOptionPane.showInputDialog("Please Enter Number 1");
	Num1=Integer.parseInt(“Val”); 
    Val = JOptionPane.showInputDialog("Please Enter Number 2");
	Num2=Integer.parseInt(“Val”); 
	Opr = JOptionPane.showInputDialog("Please Enter Operator");

	if(Opr=='+'){
		Sum=Num1+Num2;
    	   	JOptionPane.showMessageDialog(null, "Sum: " + Sum);
	}
	else if(Opr=='-'){
		Sub=Num1-Num2;
    	   	JOptionPane.showMessageDialog(null, "Sub: " + Sub);
	}
	else if(Opr=='*'){
		Mul=Num1*Num2;
    	   	JOptionPane.showMessageDialog(null, "Mul: " + Mul);
	}
	else if(Opr=='/'){
		Div=Num1/Num2;
    	   	JOptionPane.showMessageDialog(null, "Div: " + Div);
	}
	else{
		JOptionPane.showMessageDialog(null, "Invalid Operator.");
	}
    }
}