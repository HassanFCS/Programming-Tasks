#include "iostream"
#include "math.h"
using namespace std;

int TL(int Dim){
	Dim -= 2;
	Dim = pow(Dim, 2);
	Dim++;
	return Dim;
}

int TR(int Dim){
	int NinLine = Dim;
	return TL(Dim) + (NinLine - 1);
}

int BR(int Dim){
	int NinLine = Dim;
	return TR(Dim) + (NinLine - 1);
}

int BL(int Dim){
	int NinLine = Dim;
	return BR(Dim) + (NinLine - 1);
}

int Last(int Dim){
	int NinLine = Dim;
	return BL(Dim) + (NinLine - 2);
}

bool IsCorner(int Dim,int N){
	if ((TR(Dim) == N) || (TL(Dim) == N) || (BR(Dim) == N) || (BL(Dim) == N) || (Last(Dim) == N))
		return true;
	return false;
}

void LtUpRtDn(int &Left, int &Up, int &Right, int &Down, int Dim,int N) //No Corner Include
{
	if (N == 3){
		Left = N - 1;
		Right = N + 1;
		Up = TL(Dim + 2) + (N - TL(Dim) + 1);
		Down = 1;
	}
	else if (N == 5){
		Up = N - 1;
		Down = N + 1;
		Right = TR(Dim + 2) + (N - TR(Dim) + 1);
		Left = 1;
	}
	else if (N == 7){
		Left = N + 1;
		Right = N - 1;
		Down = BL(Dim + 2) - (BL(Dim) - N + 1);
		Up = 1;
	}
	else if (N > TL(Dim) && N < TR(Dim)){
		Left = N-1;
		Right = N+1;
		Up = TL(Dim + 2) + (N - TL(Dim) + 1);
		Down = TL(Dim - 2) + (N - TL(Dim) - 1);
	}
	else if (N > TR(Dim) && N < BR(Dim)){
		Up = N - 1;
		Down = N + 1;
		Right = TR(Dim + 2) + (N - TR(Dim) + 1);
		Left = TR(Dim - 2) + (N - TR(Dim) - 1);
	}
	else if (N > BR(Dim) && N < BL(Dim)){
		Left = N + 1;
		Right = N - 1;
		Down = BL(Dim + 2) - (BL(Dim) - N + 1);
		Up = BL(Dim - 2) - (BL(Dim) - N - 1);
	}
	else if (N > BL(Dim) && N < Last(Dim)){
		Up = N + 1;
		Down = N - 1;
		Right = Last(Dim - 2) - (Last(Dim) - N - 1);
		Left = Last(Dim + 2) - (Last(Dim) - N + 1);
	}
}


void CLtUpRtDn(int &Left, int &Up, int &Right, int &Down, int Dim, int N)//Including Corners
{
	if (N == 1){
		Up = 3;
		Left = 9;
		Right = 5;
		Down = 7;
	}
	else if (N == TL(Dim)){
		Right = N + 1;
		Down = Last(Dim);
		Up = TL(Dim + 2) + 1;
		Left = Last(Dim + 2);
	}
	else if(N==TR(Dim)){
		Left = N - 1;
		Down = N + 1;
		Up = TR(Dim + 2) - 1;
		Right = TR(Dim + 2) + 1;
	}
	else if (N == BR(Dim)){
		Left = N + 1;
		Up = N - 1;
		Right = BR(Dim + 2) - 1;
		Down = BR(Dim + 2) + 1;
	}
	else if (N == BL(Dim)){
		Right = N - 1;
		Up = N + 1;
		Left = BL(Dim + 2) + 1;
		Down = BL(Dim + 2) - 1;
	}
	else if (N == Last(Dim)){
		if (N == 9){
			Up = TL(Dim);
			Right = 1;
			Left = Last(Dim + 2) - 1;
			Down = N - 1;
		}
		else{
			Up = TL(Dim);
			Right = TL(Dim - 2);
			Left = Last(Dim + 2) - 1;
			Down = N - 1;
		}
	}
}
int main(){
	int N;
	cin >> N;
	int RingDim = ceil(sqrt(N));
	if (RingDim % 2 == 0)
		RingDim++;
	cout << "Ring Dim : " << RingDim << '\n';
	int RingNo = RingDim / 2;
	RingNo++;
	cout << "Ring No : " << RingNo << '\n';
	int Lt, Rt, Up, Dn;
	if (!IsCorner(RingDim,N))
		LtUpRtDn(Lt, Up, Rt, Dn, RingDim, N);
	else
		CLtUpRtDn(Lt, Up, Rt, Dn, RingDim, N);
	cout << Lt << ' ' << Up << ' ' << Rt << ' ' << Dn << '\n';
	return 0;
}