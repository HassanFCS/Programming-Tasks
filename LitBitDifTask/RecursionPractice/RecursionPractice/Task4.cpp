//#include "iostream"
//
//using  namespace std;
//
//int BinarySearch(int A[], int S, int E,int Ele) {
//	int M = (S + E) / 2;
//	if (S > E)
//		return -1;
//	else if (A[M] == Ele)
//		return M;
//	else if (A[M] > Ele)
//		BinarySearch(A, S, M-1, Ele);
//	else
//		BinarySearch(A, M+1, E, Ele);
//}
//
//int main() {
//	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int E;
//	cin >> E;
//	int Ind = BinarySearch(A, 0, 9, E);
//	if (Ind == -1)
//		cout << "Not in Array\n";
//	else
//		cout << "At Index : " << Ind << '\n';
//	return 0;
//}