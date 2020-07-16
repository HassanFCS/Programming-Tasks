#include "iostream"
#include "windows.h"
using namespace std;

//void gotoxy(int x, int y){
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	_COORD pos;
//	pos.X = x;
//	pos.Y = y;
//	SetConsoleCursorPosition(hConsole, pos);
//}
//
//void getRowColbyLeftClick(int &rpos, int &cpos){
//	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
//	DWORD Events;
//	INPUT_RECORD InputRecord;
//	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
//	do{
//		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
//		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
//			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
//			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
//			break;
//		}
//	} while (true);
//}
//
//void DisplayBoard(){
//	for (int i = 0; i <= 154; i += 22){
//		for (int j = 0; j < 48; j++){
//			gotoxy(i, j);
//			cout << (char)-37;
//		}
//	}
//	for (int i = 0; i <= 48; i+=8){
//		for (int j = 0; j <= 154;j++){
//			gotoxy(j, i);
//			cout << (char)-37;
//		}
//	}
//}


void InitBoard(int A[][7], int Rows){
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < 7; j++)
			A[i][j] = 0;
}

void PrintBoard(int A[][7], int Rows){
	cout << "\n\n";
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < 7; j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
	cout << "\n1 2 3 4 5 6 7\n\n\n";
}

bool IsFilled(int A[][7],int N){
	return (A[0][N - 1] == 0);
}

bool IsValid(int N){
	return (N >= 1 && N <= 7);
}

void ChngPlyr(int &P,int &M){
	if (M == 1){
		M = 2;
		P = 2;
	}
	else{
		M = 1;
		P = 1;
	}
}

void Input(int A[][7],int &M,int &P){
	int N;
	do{
		cout << "Turn Player " << P << ':' << ' ';
		cin >> N;
	} while (!IsFilled(A, N) || !IsValid(N));
	for (int i = 5; i >= 0; i--){
		if (A[i][N - 1] == 0){
			A[i][N - 1] = M;
			break;
		}
	}
	ChngPlyr(P, M);
}

bool Rwin(int A[][7], int &Plyr){
	int X = 0;
	int Y = 0;
	for (int i = 0; i<6; i++){
		for (int j = 0; j < 4; j++){
			for (int k = j; k < j + 4; k++){
				if (A[i][k] == 1)
					X++;
				else if (A[i][k] == 2)
					Y++;
			}
			if (X == 4 || Y == 4){
				if (X == 4){
					Plyr = 1;
					return true;
				}
				else{
					Plyr = 2;
					return true;
				}
			}
			else
				X = 0, Y = 0;
		}
	}
	return false;
}

bool Cwin(int A[][7], int &Plyr){
	int X = 0;
	int Y = 0;
	for (int i = 0; i<7; i++){
		for (int j = 0; j < 4; j++){
			for (int k = j; k < j + 4; k++){
				if (A[k][i] == 1)
					X++;
				else if (A[k][i] == 2)
					Y++;
			}
			if (X == 4 || Y == 4){
				if (X == 4){
					Plyr = 1;
					return true;
				}
				else{
					Plyr = 2;
					return true;
				}
			}
			else
				X = 0, Y = 0;
		}
	}
	return false;
}

bool Dwin(int A[][7], int &Plyr){
	int X = 0, Y = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				if (A[i + k][j + k] == 1)
					X++;
				else if (A[i + k][j + k] == 2)
					Y++;
			}
			if (X == 4 || Y == 4){
				if (X == 4){
					Plyr = 1;
					return true;
				}
				else{
					Plyr = 2;
					return true;
				}
			}
			else
				X = 0, Y = 0;
		}
	}
	return false;
}

bool IDwin(int A[][7], int &Plyr){
	int X = 0, Y = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 7; j > 3; j--){
			for(int k = 0; k < 4; k++){
				if (A[i + k][j - k] == 1)
					X++;
				else if (A[i + k][j - k] == 2)
					Y++;
			}
			if (X == 4 || Y == 4){
				if (X == 4){
					Plyr = 1;
					return true;
				}
				else{
					Plyr = 2;
					return true;
				}
			}
			else
				X = 0, Y = 0;
		}
	}
	return false;
}

bool WIN(int A[][7], int &Plyr){
	return (IDwin(A, Plyr) || Dwin(A, Plyr) || Rwin(A, Plyr) || Cwin(A, Plyr));
}

int main(){
	int A[6][7];
	int X=1;
	InitBoard(A, 6);
	PrintBoard(A, 6);
	int P=1, M=1;
	do{
		Input(A, P, M);
		system("cls");
		PrintBoard(A, 6);
	}while (!WIN(A,P));
	cout << "Player " << P << " Wins..!!\n";
	return 0;
}