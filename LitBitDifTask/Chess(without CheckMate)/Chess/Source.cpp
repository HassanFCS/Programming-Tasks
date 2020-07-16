#include <iostream>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int Black = 1; //Capital
int White = -1;//Small


void ChangeColor(int color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;
	SetConsoleTextAttribute(hConsole, color);
}
void gotoRowCol(int rpos, int cpos){
	int xpos = cpos, ypos = rpos;
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}
void getRowColbyLeftClick(int &rpos, int &cpos){
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void L2R(int r, int sc, int ec, char sym, float T){
	for (int c = sc; c <= ec; c++){
		gotoRowCol(r, c);
		cout << sym;
	}
}
void T2B(int c, int sr, int er, char sym, float T){
	for (int r = sr; r <= er; r++){
		gotoRowCol(r, c);
		cout << sym;
	}
}
void PAWN(int Cr, int Cc){
	gotoRowCol(Cr - 3, Cc);
	cout << '*';
	L2R(Cr - 2, Cc - 1, Cc + 1, '*', 0);
	L2R(Cr - 1, Cc - 2, Cc + 2, '*', 0);
	L2R(Cr, Cc - 2, Cc + 2, '*', 0);
	gotoRowCol(Cr + 1, Cc - 1);
	cout << '*';
	gotoRowCol(Cr + 1, Cc + 1);
	cout << '*';
	gotoRowCol(Cr + 2, Cc - 1);
	cout << '*';
	gotoRowCol(Cr + 2, Cc + 1);
	cout << '*';
	gotoRowCol(Cr + 2, Cc - 2);
	cout << '*';
	gotoRowCol(Cr + 2, Cc + 2);
	cout << '*';
	L2R(Cr + 3, Cc - 2, Cc + 2, '*', 0);
}
void ROOK(int Cr, int Cc){
	L2R(Cr - 3, Cc - 2, Cc + 2, '*', 0);
	gotoRowCol(Cr - 2, Cc - 2);
	cout << "*";
	gotoRowCol(Cr - 2, Cc + 2);
	cout << "*";
	gotoRowCol(Cr - 1, Cc - 2);
	cout << "**";
	gotoRowCol(Cr - 1, Cc + 1);
	cout << "**";
	gotoRowCol(Cr, Cc - 1);
	cout << "*";
	gotoRowCol(Cr, Cc + 1);
	cout << "*";
	gotoRowCol(Cr + 1, Cc - 1);
	cout << "*";
	gotoRowCol(Cr + 1, Cc + 1);
	cout << "*";
	gotoRowCol(Cr + 2, Cc - 2);
	cout << "**";
	gotoRowCol(Cr + 2, Cc + 1);
	cout << "**";
	L2R(Cr + 3, Cc - 3, Cc + 3, '*', 0);
}
void BISHOP(int Cr, int Cc){
	gotoRowCol(Cr - 4, Cc);
	cout << '*';
	L2R(Cr - 3, Cc - 2, Cc + 2, '*', 0);
	gotoRowCol(Cr - 2, Cc - 2);
	cout << "*";
	gotoRowCol(Cr - 2, Cc + 2);
	cout << "*";
	gotoRowCol(Cr - 1, Cc - 2);
	cout << "**";
	gotoRowCol(Cr - 1, Cc + 1);
	cout << "**";
	gotoRowCol(Cr, Cc);
	cout << '*';
	L2R(Cr + 1, Cc - 2, Cc + 2, '*', 0);
	L2R(Cr + 2, Cc - 2, Cc + 2, '*', 0);
	gotoRowCol(Cr + 3, Cc);
	cout << '*';
	L2R(Cr + 4, Cc - 2, Cc + 2, '*', 0);
}
void QUEEN(int Cr, int Cc){
	gotoRowCol(Cr - 3, Cc - 3);
	cout << "**";
	gotoRowCol(Cr - 3, Cc + 2);
	cout << "**";
	gotoRowCol(Cr - 3, Cc);
	cout << "*";
	gotoRowCol(Cr - 2, Cc - 3);
	cout << "*";
	gotoRowCol(Cr - 2, Cc + 3);
	cout << "*";
	gotoRowCol(Cr - 2, Cc - 1);
	cout << "*";
	gotoRowCol(Cr - 2, Cc + 1);
	cout << "*";
	gotoRowCol(Cr - 1, Cc - 3);
	cout << "*";
	gotoRowCol(Cr - 1, Cc + 3);
	cout << "*";
	gotoRowCol(Cr - 1, Cc);
	cout << "*";
	gotoRowCol(Cr, Cc - 3);
	cout << "*";
	gotoRowCol(Cr, Cc + 3);
	cout << "*";
	gotoRowCol(Cr + 1, Cc - 3);
	cout << "*******";
	gotoRowCol(Cr + 2, Cc - 3);
	cout << "*";
	gotoRowCol(Cr + 2, Cc + 3);
	cout << "*";
	gotoRowCol(Cr + 3, Cc - 3);
	cout << "*******";
}
void KING(int Cr, int Cc){
	gotoRowCol(Cr - 4, Cc);
	cout << "*";
	gotoRowCol(Cr - 3, Cc - 1);
	cout << "***";
	gotoRowCol(Cr - 2, Cc - 3);
	cout << "**";
	gotoRowCol(Cr - 2, Cc + 2);
	cout << "**";
	gotoRowCol(Cr - 2, Cc);
	cout << "*";
	gotoRowCol(Cr - 1, Cc - 3);
	cout << "*";
	gotoRowCol(Cr - 1, Cc + 3);
	cout << "*";
	gotoRowCol(Cr - 1, Cc - 1);
	cout << "*";
	gotoRowCol(Cr - 1, Cc + 1);
	cout << "*";
	gotoRowCol(Cr, Cc - 3);
	cout << "*";
	gotoRowCol(Cr, Cc + 3);
	cout << "*";
	gotoRowCol(Cr, Cc);
	cout << "*";
	gotoRowCol(Cr + 1, Cc - 3);
	cout << "*";
	gotoRowCol(Cr + 1, Cc + 3);
	cout << "*";
	gotoRowCol(Cr + 2, Cc - 3);
	cout << "*******";
	gotoRowCol(Cr + 3, Cc - 3);
	cout << "*";
	gotoRowCol(Cr + 3, Cc + 3);
	cout << "*";
	gotoRowCol(Cr + 4, Cc - 3);
	cout << "*******";
}
void HORSE(int Cr, int Cc){
	gotoRowCol(Cr - 3, Cc);
	cout << "*";
	gotoRowCol(Cr - 2, Cc - 1);
	cout << "**";
	gotoRowCol(Cr - 1, Cc - 3);
	cout << "**";
	gotoRowCol(Cr - 1, Cc);
	cout << "*";
	gotoRowCol(Cr, Cc - 2);
	cout << "***";
	gotoRowCol(Cr + 1, Cc - 1);
	cout << "**";
	gotoRowCol(Cr + 2, Cc - 1);
	cout << "**";
	gotoRowCol(Cr + 3, Cc - 3);
	cout << "*******";
}

bool IsCapital(char sym){
	return (sym >= 'A' && sym <= 'Z');
}
bool IsSmall(char sym){
	return (sym >= 'a' && sym <= 'z');
}

bool IsVertical(int sri, int sci, int dri, int dci){
	return (sri != dri && sci == dci);
}
bool IsHorizontal(int sri, int sci, int dri, int dci){
	return (sri == dri && sci != dci);
}
bool IsDiagonal(int sri, int sci, int dri, int dci){
	return abs(dci - sci) == abs(dri - sri);
}
bool IsVerticalClear(char B[][8], int sri, int sci, int dri, int dci){
	int StartR = (sri<dri) ? sri + 1 : dri + 1;
	int EndR = (sri<dri) ? dri - 1 : sri - 1;
	for (int r = StartR; r <= EndR; r++){
		if (B[r][sci] != ' ')
			return false;
	}
	return true;
}
bool IsHorizontalClear(char B[][8], int sri, int sci, int dri, int dci){
	int StartC = (sci<dci) ? sci + 1 : dci + 1;
	int EndC = (sci<dci) ? dci - 1 : sci - 1;
	for (int c = StartC; c <= EndC; c++){
		if (B[sri][c] != ' ')
			return false;
	}
	return true;
}
//bool IsDiagonalClear(char B[][8], int sri, int sci, int dri, int dci){
//    int delta=abs(dri-sri);
//    if(((dri-sri)<0 && (dci-sci)<0) || ((dri-sri)>0 && (dci-sci)>0)){
//        int R=(sri<dri)?sri:dri;
//        int C=(sci<dci)?sci:dci;
//        for(int t=1; t<delta; t++){
//            if(B[R+t][C+t]!=' ')
//                return false;
//        }
//        return true;
//    }
//    else{
//        int R=(sri<dri)?sri:dri;
//        int C=(sri<dri)?sci:dci;
//        int signR=(sri<dri)?1:-1;
//        int signC=(sci<dci)?1:-1;
//        for(int t=1; t<delta; t++){
//            if(B[R+(signR*t)][C+(signC*t)]!=' ')
//                return false;
//        }
//        return true;
//    }
//}

bool IsDiagonalClear(char b[8][8], int sr, int sc, int er, int ec){
	int dr = er - sr;
	int dc = ec - sc;
	int t = abs(dr);
	if (dr<0 && dc<0){
		for (int i = 1; i<t; i++){
			if (b[sr - i][sc - i] != ' ')return false;
		}
		return true;
	}
	if (dr>0 && dc<0){
		for (int i = 1; i<t; i++){
			if (b[sr + i][sc - i] != ' ')return false;
		}
		return true;
	}
	if (dr>0 && dc>0){
		for (int i = 1; i<t; i++){
			if (b[sr + i][sc + i] != ' ')return false;
		}
		return true;
	}
	if (dr<0 && dc>0){
		for (int i = 1; i<t; i++){
			if (b[sr - i][sc + i] != ' ')return false;
		}
		return true;
	}
	return false;
}

bool RookLegal(char B[][8], int sri, int sci, int dri, int dci){
	return ((IsVertical(sri, sci, dri, dci) && IsVerticalClear(B, sri, sci, dri, dci)) || (IsHorizontal(sri, sci, dri, dci) && IsHorizontalClear(B, sri, sci, dri, dci)));
}
bool BishopLegal(char B[][8], int sri, int sci, int dri, int dci){
	return (IsDiagonal(sri, sci, dri, dci) && IsDiagonalClear(B, sri, sci, dri, dci));
}
bool QueenLegal(char B[][8], int sri, int sci, int dri, int dci){
	return RookLegal(B, sri, sci, dri, dci) || BishopLegal(B, sri, sci, dri, dci);
}
bool KingLegal(char B[][8], int sri, int sci, int dri, int dci){
	int dR = abs(dri - sri);
	int dC = abs(dci - sci);
	return (QueenLegal(B, sri, sci, dri, dci) && ((dR == 1 || dR == 0) && (dC == 1 || dC == 0)));
}
bool HorseLegal(char B[][8], int sri, int sci, int dri, int dci){
	int dR = abs(dri - sri);
	int dC = abs(dci - sci);
	return ((dR == 1 && dC == 2) || (dR == 2 && dC == 1));
}
bool PawnLegal(char B[][8], int sri, int sci, int dri, int dci, int Turn){
	int dR = (dri - sri);
	int dC = abs(dci - sci);
	if (dR == 1 * (Turn) && dC == 1 && (IsSmall(B[dri][dci]) || IsCapital(B[dri][dci])))
		return true;
	else if ((sri == 1 || sri == 6) && (dR == 1 * Turn || dR == 2 * Turn) && dC == 0 && B[dri][dci] == ' ' && IsVerticalClear(B, sri, sci, dri, dci))
		return true;
	else if ((dC == 0 && dR == 1 * Turn) && B[dri][dci] == ' ' && IsVerticalClear(B, sri, sci, dri, dci))
		return true;
	return false;
}
bool IsLegalMove(char B[][8], int sri, int sci, int dri, int dci, int Turn){
	char sym = B[sri][sci];
	//    if(sym!='p')
	sym = toupper(sym);
	switch (sym){
	case 'R':
		return RookLegal(B, sri, sci, dri, dci);
	case 'H':
		return HorseLegal(B, sri, sci, dri, dci);

	case 'B':
		return BishopLegal(B, sri, sci, dri, dci);
	case 'Q':
		return QueenLegal(B, sri, sci, dri, dci);
	case 'K':
		return KingLegal(B, sri, sci, dri, dci);
	case 'P':
		return PawnLegal(B, sri, sci, dri, dci, Turn);
	}
}

void Init(char B[][8], int &Turn, int Rows, int &rDim, int &cDim){
	Turn = (rand() % 2);
	if (Turn == 0){
		Turn = -1;
	}
	B[0][0] = B[0][7] = 'R';
	B[0][1] = B[0][6] = 'H';
	B[0][2] = B[0][5] = 'B';
	B[0][3] = 'Q';
	B[0][4] = 'K';

	B[7][0] = B[7][7] = 'r';
	B[7][1] = B[7][6] = 'h';
	B[7][2] = B[7][5] = 'b';
	B[7][3] = 'q';
	B[7][4] = 'k';

	for (int ri = 1; ri <= 6; ri++){
		for (int ci = 0; ci<8; ci++){
			if (ri == 1){
				B[ri][ci] = 'P';
			}
			else if (ri == 6){
				B[ri][ci] = 'p';
			}
			else{
				B[ri][ci] = ' ';
			}
		}
	}

	rDim = Rows / 8;
	cDim = rDim;
	rDim--;
	cDim--;
}

bool IsMyPiece(char B[][8], int ri, int ci, int Turn){
	if ((Turn == Black && IsCapital(B[ri][ci])) || (Turn == White && IsSmall(B[ri][ci]))){
		return true;
	}
	return false;
}
void PrintFillBox(int Cr, int Cc, int rDim, int cDim){
	for (int i = Cr - rDim / 2 + 1; i <= Cr + rDim / 2 - 1; i++){
		L2R(i, (Cc - cDim / 2) + 1, (Cc + cDim / 2) - 1, 219, 0);
	}
}

void PrintGrid(int rDim, int cDim){
	ChangeColor(7);
	for (int ci = 0; ci <= cDim * 8; ci += cDim){
		T2B(ci, 0, rDim * 8, 219, 0);
	}
	for (int ri = 0; ri <= rDim * 8; ri += rDim){
		L2R(ri, 0, cDim * 8, 219, 0);
	}
	for (int r = 0; r<8; r++){
		for (int c = 0; c<8; c++){
			if ((r + c) % 2 == 0){
				int ri = (r*rDim) + rDim / 2;
				int ci = (c*cDim) + cDim / 2;
				ChangeColor(4);
				PrintFillBox(ri, ci, rDim, cDim);
			}
			else{
				int ri = (r*rDim) + rDim / 2;
				int ci = (c*cDim) + cDim / 2;
				ChangeColor(1);
				PrintFillBox(ri, ci, rDim, cDim);
			}
		}
	}
}
void BoxSelection(int &ri, int &ci, int rDim, int cDim){
	getRowColbyLeftClick(ri, ci);
	ri++, ci++;
	ri = floor(ri*1.0 / rDim);
	ci = floor(ci*1.0 / cDim);
}

bool IsValidSource(char B[][8], int ri, int ci, int Turn){
	return (ri<8 && ri >= 0 && ci<8 && ci >= 0 && IsMyPiece(B, ri, ci, Turn));
}

bool IsValidDestination(char B[][8], int ri, int ci, int Turn){
	return (ri<8 && ri >= 0 && ci<8 && ci >= 0 && !IsMyPiece(B, ri, ci, Turn));
}

void PrintSymPiece(char B[][8], int Cr, int Cc, int r, int c){
	int sym = B[r][c];
	if (IsCapital(sym))
		ChangeColor(10);
	else if (IsSmall(sym))
		ChangeColor(11);
	sym = toupper(sym);
	switch (sym){
	case 'P':
		PAWN(Cr, Cc);
		break;
	case 'R':
		ROOK(Cr, Cc);
		break;
	case 'B':
		BISHOP(Cr, Cc);
		break;
	case 'Q':
		QUEEN(Cr, Cc);
		break;
	case 'K':
		KING(Cr, Cc);
		break;
	case 'H':
		HORSE(Cr, Cc);
		break;
	}
}

void PrintBoard(char B[][8], int rDim, int cDim){
	for (int r = 0; r<8; r++){
		for (int c = 0; c<8; c++){
			int ri = (r*rDim) + rDim / 2;
			int ci = (c*cDim) + cDim / 2;
			PrintSymPiece(B, ri, ci, r, c);
		}
	}
}

void WriteonBoard(char B[][8], int sci, int sri, int dci, int dri){
	B[dri][dci] = B[sri][sci];
	B[sri][sci] = ' ';
}

void TurnChanger(int & Turn){
	Turn = (Turn == Black) ? White : Black;
}

void DisplayTurnMessage(int Turn, int Rows){
	ChangeColor(7);
	if (Turn == Black){
		gotoRowCol(10, Rows - 10);
		cout << "Black's Turn (Capital)";
	}
	else if (Turn == White){
		gotoRowCol(80, Rows - 10);
		cout << "White's Turn   (Small)";
	}
}

void Highlighting(char B[][8], int sri, int sci, int Turn, int rDim, int cDim){
	for (int R = 0; R<8; R++){
		for (int C = 0; C<8; C++){
			if (IsLegalMove(B, sri, sci, R, C, Turn) && IsValidDestination(B, R, C, Turn)){
				int ri = (R*rDim) + rDim / 2;
				int ci = (C*cDim) + cDim / 2;
				ChangeColor(14);
				PrintFillBox(ri, ci, rDim, cDim);
				PrintSymPiece(B, ri, ci, R, C);
			}
		}
	}
}

void UnHighlighting(char B[][8], int sri, int sci, int Turn, int rDim, int cDim){
	PrintGrid(rDim, cDim);
	PrintBoard(B, rDim, cDim);
}

void GetKing(char B[][8], int & r, int & c, int Turn){
	char sym = (Turn == 1) ? 'K' : 'k';
	for (int R = 0; R<8; R++){
		for (int C = 0; C<8; C++){
			if (B[R][C] == sym){
				r = R;
				c = C;
				return;
			}
		}
	}
}

bool IsMyCheck(char B[][8], int Turn){
	int Kr, Kc;
	GetKing(B, Kr, Kc, Turn);

	TurnChanger(Turn);

	for (int R = 0; R<8; R++){
		for (int C = 0; C<8; C++){
			if (IsLegalMove(B, R, C, Kr, Kc, Turn)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	srand(time(0));
	char B[8][8];
	int sri, sci, dri, dci;
	int Turn, Rows, Columns, rDim, cDim;
	cout << "Enter Rows : ";
	cin >> Rows;
	Init(B, Turn, Rows, rDim, cDim);
	do{
		ChangeColor(7);
		system("cls");
		PrintGrid(rDim, cDim);
		PrintBoard(B, rDim, cDim);
		DisplayTurnMessage(Turn, Rows);
		do{
			do{
				do{
					BoxSelection(sri, sci, rDim, cDim);
				} while (!IsValidSource(B, sri, sci, Turn));
				gotoRowCol(12, Rows * 2 + 10);
				cout << "                         ";
				Highlighting(B, sri, sci, Turn, rDim, cDim);
				BoxSelection(dri, dci, rDim, cDim);
				UnHighlighting(B, sri, sci, Turn, rDim, cDim);
			} while (!IsValidDestination(B, dri, dci, Turn));
			if (!IsLegalMove(B, sri, sci, dri, dci, Turn)){
				gotoRowCol(12, Rows * 2 + 10);
				cout << "Invalid Move. Try Again. ";
			}
		} while (!IsLegalMove(B, sri, sci, dri, dci, Turn));
		WriteonBoard(B, sci, sri, dci, dri);
		TurnChanger(Turn);
		if (IsMyCheck(B, Turn)){
			gotoRowCol(14, Rows * 2 + 10);
			cout << "                         ";
			gotoRowCol(14, Rows * 2 + 10);
			cout << "Your are Checked.";
		}

	} while (true);
	return 0;
}
