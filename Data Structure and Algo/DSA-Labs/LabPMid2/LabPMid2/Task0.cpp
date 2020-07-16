//#include "iostream"
//
//using namespace std;
//
//bool Check(int A[], int &i, int &j, int &k) {
//	if (A[i] == A[j] + A[k] && (j!=k && i!=k)) 
//		return true;
//	if (j < k) {
//		j++;
//		if(j<k)
//			return Check(A, i, j, k);
//	}
//	if (j == k) {
//		j = 0, k++;
//		if (k < i)
//			return Check(A, i, j, k);
//	}
//	if (k == i) {
//		i--;
//		j = 0;
//		k = 0;
//		return Check(A, i, j, k);
//	}
//	if (j >= k || k >= i)
//		return false;
//}
//
//int main() {
//	int A[10] = { 1,1,1,1,1,1,2,1,1,1 };
//	int Size = 10;
//	int i = Size - 1, j = 0, k = 1;
//	if (Check(A, i, j, k))
//		cout << "Number Exist..!!\n" << "For Example\n" << A[i] << '=' << A[j] << '+' << A[k] << ':' << A[j] + A[k] << '\n';
//	else
//		cout << "Not Found..!!\n";
//	return 0;
//}