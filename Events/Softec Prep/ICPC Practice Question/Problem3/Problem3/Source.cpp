#include "iostream"

using namespace std;

bool wellorder(int N){
	if (N / 10 == 0)
		return true;
	if (wellorder(N / 10)){
		if (N % 10 > (N / 10) % 10)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main(){
	int Start, End;
	Start = 200;
	End = 400;
	for (int i = Start; i <= End; i++){
		if (i % 20 == 19)
			cout << endl;
		if (wellorder(i))
			cout << i << ' ';
	}
	system("pause");
}