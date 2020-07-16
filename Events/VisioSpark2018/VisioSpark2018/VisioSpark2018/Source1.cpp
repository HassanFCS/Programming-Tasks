// C++ program to sort a vector in non-decreasing 
// order. 
#include"vector"
#include"iostream"
#include"algorithm"
using namespace std;

int main()
{
	vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int ToSort = (v.size() - 3) / 2;
	for (auto x : v)
		cout << x << " ";

	sort(v.begin() + 3, v.begin() + (ToSort + 3));

	sort(v.begin() + (ToSort + 3), v.end());

	cout << "Sorted \n";
	for (auto x : v)
		cout << x << " ";
	


	system("PAUSE");
	return 0;
}














//
//int CheckSumDP(int *Data, int MaxSize, int *Arr, int Start, int Size){
//	
//}
//
//int main(){
//	int *A;
//	int S;
//	cin >> S;
//	A = new int[S];
//	int Amount;
//	cin >> Amount;
//	int Size = sizeof(A) / sizeof(A[0]);
//	cout << Size << '\n';
//	sort(A, A + Size);
//	int *Data;
//	Data = new int[A[Size] - 1];
//	cout << CheckSumDP(Data, A[Size - 1], A, 1, Size) << '\n';
//	for (int i = 0; i < A[Size] - 1; i++){
//		cout << Data[i] << ' ';
//	}
//	system("PAUSE");
//	return 0;
//}
//

/*
int Total = 0;
for (int i = 0; i < Size; i++){
for (int j = 0; j < Size; j++){
Total += A[j];
if (Amount == Total){
cout << "Yes\n";
break;
}
else if (Amount > Total){
cout << "No\n";
break;
}
}
}
*/