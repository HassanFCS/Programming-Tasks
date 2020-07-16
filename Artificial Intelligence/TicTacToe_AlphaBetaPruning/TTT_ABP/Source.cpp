#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

struct LNode{
	int index;
	int value;
};

LNode max(LNode a, LNode b){
	return a.value > b.value ? a : b;
}

LNode min(LNode a, LNode b){
	return a.value < b.value ? a : b;
}

class Board{
	vector <vector <char>> B;
	int Size;
	LNode MAX;
	LNode MIN;

	bool Valid(int i, int j){
		if ((i >= 0 && j >= 0) && (j < Size && i < Size)){
			if (B[i][j] == '-')
				return true;
		}
		return false;
	}
	void Compute(int &i, int &j, int val){
		for (i = 0; i < B.size(); i++){
			for (j = 0; j < B[i].size(); j++){
				if (i*B.size() + j == val){
					return;
				}
			}
		}
	}

	bool RWin(char ch){
		int Count = 0;
		for (int i = 0; i < B.size(); i++){
			for (int j = 0; j < B[i].size(); j++){
				if (B[i][j] == ch)
					Count++;
			}
			if (Count == Size)
				return true;
			Count = 0;
		}
		return false;
	}
	bool CWin(char ch){
		int Count = 0;
		for (int i = 0; i < B.size(); i++){
			for (int j = 0; j < B[i].size(); j++){
				if (B[j][i] == ch)
					Count++;
			}
			if(Count == Size)
				return true;
			Count = 0;
		}
		return false;

	}
	bool DWin(char ch){
		int Count = 0;
		for (int i = 0; i < B.size(); i++){
			if (B[i][i] == ch)
					Count++;
		}
		if (Count == Size)
			return true;
		return false;
	}
	bool IDWin(char ch){
		int Count = 0;
		for (int i = 0; i < B.size(); i++){
			if (B[i][Size - 1 - i] == ch)
				Count++;
		}
		if (Count == Size)
			return true;
		return false;
	}

	vector<int> Heuristic(){
		vector<int> Result(Size*Size);
		bool HumWin = false, ComWin = false;
		for (int index = 0; index < Size*Size; index++){
			HumWin = false, ComWin = false;
			int i, j;
			Compute(i, j, index);
			if (B[i][j] != '-')
				Result[index] = -2;
			else{
				//Check for Human Win
				B[i][j] = 'O';
				if (RWin('O') || CWin('O') || DWin('O') || IDWin('O'))
					HumWin = true;
				B[i][j] = '-';
				//Check for Computer Win
				B[i][j] = 'X';
				if (RWin('X') || CWin('X') || DWin('X') || IDWin('X'))
					ComWin = true;
				B[i][j] = '-';
				if (HumWin && !ComWin)
					Result[index] = 0;
				else if (!HumWin && ComWin)
					Result[index] = 2;
				else if (HumWin && ComWin)
					Result[index] = 3;
				else if (!HumWin && !ComWin)
					Result[index] = 1;
			}
		}
		/*if (HumWin && !ComWin){
			for (int i = 0; i < Result.size(); i++){
				if (Result[i] != 1){
					Result[i] = 0;
				}
			}
		}
		if (!HumWin && ComWin){
			for (int i = 0; i < Result.size(); i++){
				if (Result[i] != 2){
					Result[i] = 0;
				}
			}
		}*/
		return Result;
	}
	LNode apPruning(int depth, int nodeIndex, bool maximizingPlayer, vector <LNode> &values, LNode alpha, LNode beta){
		if (depth == 3)
			return values[nodeIndex];
		if (maximizingPlayer){
			LNode Best;
			Best.value = MIN.value;

			for (int i = 0; i < 2; i++){

				LNode val = apPruning(depth + 1, nodeIndex * 2 + i,
					false, values, alpha, beta);
				Best = max(Best, val);
				alpha = max(alpha, Best);

				// Alpha Beta Pruning 
				if (beta.value <= alpha.value)
					break;
			}
			return Best;
		}
		else{
			LNode Best;
			Best.value = MAX.value;

			for (int i = 0; i < 2; i++){
				LNode val = apPruning(depth + 1, nodeIndex * 2 + i,
					true, values, alpha, beta);
				Best = min(Best, val);
				beta = min(beta, Best);

				// Alpha Beta Pruning 
				if (beta.value <= alpha.value)
					break;
			}
			return Best;
		}
	}
public:
	Board(int S){
		MAX.value = 1000;
		MIN.value = -1000;
		Size = S;
		B.resize(Size);
		for (int i = 0; i < Size; i++)
			B[i].resize(Size, '-');
	}
	void FillBoard(char ch){
		int i=0, j=0;
		if (ch == 'H'){
			do{
				cin >> i >> j;
			} while (!Valid(i, j));
			B[i][j] = 'O';
		}
		else{
			vector<int> Sol = Heuristic();
			vector<LNode> LNSol(Size*Size);
			for (int i = 0; i < Size*Size; i++){
				LNSol[i].index = i;
				LNSol[i].value = Sol[i];
			}
			int val = apPruning(0, 0, false, LNSol, MIN, MAX).index;
			Compute(i, j, val);
			bool flag = false;
			if (!Valid(i, j)){
				for (int k = 0; k < B.size(); k++){
					for (int l = 0; l < B[k].size(); l++){
						if (B[k][l] == '-'){
							//for Computer
							B[k][l] = 'X';
							if (RWin('X') || CWin('X') || DWin('X') || IDWin('X')){
								i = k;
								j = l;
								flag = true;
								B[k][l] = '-';
								break;
							}
							B[k][l] = '-';
						}
					}
				}
				if (!flag){
					for (int k = 0; k < B.size(); k++){
						for (int l = 0; l < B[k].size(); l++){
							if (B[k][l]=='-'){
								//for Human
								B[k][l] = 'O';
								if (RWin('O') || CWin('O') || DWin('O') || IDWin('O')){
									i = k;
									j = l;
									flag = true;
									B[k][l] = '-';
									break;
								}
								B[k][l] = '-';
							}
						}
					}
				}
				if (!flag){
					do{
						i = rand() % 3;
						j = rand() % 3;
					} while (!Valid(i, j));
				}
			}
			B[i][j] = 'X';
		}
	}
	void PrintBoard(){
		for (int i = 0; i < Size; i++){
			for (int j = 0; j < Size; j++)
				cout << B[i][j] << '\t';
			cout << '\n';
		}
	}
	bool IsWin(char Turn){
		if (Turn == 'H')
			return (RWin('O') || CWin('O') || DWin('O') || IDWin('O'));
		else
			return (RWin('X') || CWin('X') || DWin('X') || IDWin('X'));
	}
	bool IsDraw(){
		int count = 0;
		for (int i = 0; i < Size; i++){
			for (int j = 0; j < Size; j++){
				if (B[i][j] == '-')
					count++;
			}
		}
		return count>0 ? false : true;
	}
};

int main(){
	srand(time(0));
	Board Game(3);
	Game.PrintBoard();
	int i = 0;
	char Win = 'D';
	while (!Game.IsDraw()){
		if (i % 2 == 0){
			cout << "Human's Turn.\n";
			Game.FillBoard('H');
			if (Game.IsWin('H')){
				Win = 'H';
				break;
			}
			system("cls");
		}
		else{
			cout << "Computer's Turn.\n";
			Game.FillBoard('C');
			if (Game.IsWin('C')){
				Win = 'C';
				break;
			}
			system("cls");

		}
		Game.PrintBoard();
		i++;
	}
	system("cls");
	Game.PrintBoard();
	if (Win == 'D')
		cout << "Game Draw.\n";
	else if (Win == 'H')
		cout << "Human Win.\n";
	else if (Win == 'C')
		cout << "Computer Win.\n";
	system("PAUSE");
	return 0;
}