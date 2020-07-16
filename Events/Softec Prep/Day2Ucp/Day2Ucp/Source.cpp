#include <iostream>
using namespace std;

//int DigitSum(int N){
//	int res = 0;
//	if (N == 0){
//		return 0;
//	}
//
//			//Both Fine\\
//
//	/*res += DigitSum(N / 10);
//	cout << N % 10 << "+";
//	return (N % 10) + res;*/
//
//	res =(N%10) + DigitSum(N / 10);
//	cout << N % 10 << '+' ;
//	return res;
//}

			//Both Fine\\

//int jumps(int h, int j, int s){
//	if (s > j || s == j){
//		cout << "Mission Impossible" << endl;
//		return -1;
//	}
//	if (h < j)
//		return 1;
//	return 1 + jumps(h-(j-s), j, s);
//}
//
//int FJmp(int J , int S, int Height){
//	int Step = J - S;
//	if (Height <= J)
//		return 1;
//	return 1+FJmp(J,S,Height-Step);
//}

int MCount(int N){
	if (N == 1)
		return 1;
	if (N % 2 == 0)
		return 1 + MCount(N / 2);
	else
		return 1 + MCount((3 * N) + 1);
}

int MaxNSeries(int N){
	cout << N << "->";
	if (N == 1){
		cout << "\b\b  ";
		return 1;
	}
	if (N % 2 == 0)
		return MaxNSeries(N / 2);
	else
		return MaxNSeries((3 * N) + 1);
}


int main(){
//	cout <<'\b' << '=' << DigitSum(6549421) << "\n\n";

//	cout << "Jumps : " << jumps(16, 5, 2) << '\n';
//	cout << FJmp(5,2,16) << '\n';

	int Max = MCount(1);
	for (int i = 2; i <= 100; i++){
		if (Max < MCount(i))
			Max = i;
	}
	cout << Max << ' ' << MCount(Max)  << '\n';
	MaxNSeries(Max);
	

	system("PAUSE");
	return 0;
}