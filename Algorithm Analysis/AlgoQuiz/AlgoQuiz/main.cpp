#include "iostream"

using namespace std;

								//Wrong Workinkg for some specific input only :(

int main(){
	int len;
	int *Ar;
	cin >> len;
	Ar = new int[len];
	for (int i = 0; i < len; i++)
		cin >> Ar[i];
	int start = 0, end = 0, HSum = 0, Sum = 0, NSum=0;
	for (int i = 0; i < len; i++){
		if (Ar[i] < 0){
			NSum = 0;
			while (Ar[i] < 0){
				NSum += Ar[i];
				i++;
			}
			if (i < len){
				NSum += Ar[i];
				if (NSum>0){
					Sum += NSum;
					end = i;
				}
			}
			if (Ar[i]>HSum)
				start = i;
		}
		else
			Sum += Ar[i];
		if (Sum>HSum){
			HSum = Sum;
			end = i;
		}
	}
	cout << "Index Start from " << start << " Ends at " << end << '\n';
	for (int i = start; i <= end; i++)
		cout << Ar[i] << ' ';
	system("PAUSE");
	return 0;
}