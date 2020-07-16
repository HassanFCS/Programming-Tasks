#include <iostream>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>

using namespace std;

#define TTTSize 30

void LoadStructure(char S);
bool ClickOnLoad(int ri,int ci);
void LoadGame(char A[][TTTSize],int Dim,int s,int r,int Turn,int ri,int ci,int Click);
void HumanvsComputer(char A[][TTTSize],int Rows,int Cols,int Dim,int Turn,char S,int s,int r,int Click,int Load);
void HumanvsHuman(char A[][TTTSize],int Rows,int Cols,int Dim,int Turn,char S,int s,int r,int Click,int Load);

void Copy(char A[][TTTSize], char TA[][3])
{
    int dim=3;
    for(int ri=0; ri<dim; ri++)
        for(int ci=0; ci<dim; ci++)
            A[ri][ci] = TA[ri][ci];
}
void Copy(char A[][TTTSize], char TA[][4])
{
    int dim=4;
    for(int ri=0; ri<dim; ri++)
        for(int ci=0; ci<dim; ci++)
            A[ri][ci] = TA[ri][ci];
}
void Copy(char A[][TTTSize], char TA[][5])
{
    int dim=5;
    for(int ri=0; ri<dim; ri++)
        for(int ci=0; ci<dim; ci++)
            A[ri][ci] = TA[ri][ci];
}


void printDEBUG(int Dim,char A[][TTTSize]){
    system("cls");
    for(int ri=0; ri<Dim; ri++)
    {
        for(int ci=0; ci<Dim; ci++)
            cout<<A[ci][ri];
        cout<<endl;
    }
}


void SaveRecord(int Dim,char A[][TTTSize]){
    printDEBUG(Dim, A);
    char TA[Dim][Dim];
    ofstream RecordsWrtr;
    if(Dim==3){
         RecordsWrtr.open("Records3x3.bin", ios::binary | ios::app);
     }else if(Dim==4){
        RecordsWrtr.open("Records4x4.bin", ios::binary | ios::app);
    }else if(Dim==5){
        RecordsWrtr.open("Records5x5.bin", ios::binary | ios::app);
    }

    for(int ri=0; ri<Dim; ri++)
        for(int ci=0; ci<Dim; ci++)
            TA[ri][ci] = A[ri][ci];


    RecordsWrtr.write((char*)TA,sizeof(char)*(Dim*Dim));
    RecordsWrtr.close();
}

void Records3x3(char A[][TTTSize],int GN){
    char TA[3][3];
    ifstream Rdr1("Records3x3.bin",ios::binary);
    Rdr1.seekg ((GN-1)*(3*3),ios::beg);
    Rdr1.read((char*)TA,sizeof(char)*(3*3));
    Rdr1.close();
    Copy(A, TA);
}

void Records4x4(char A[][TTTSize],int GN){
    char TA[4][4];
    ifstream Rdr2("Records4x4.bin",ios::binary);
    Rdr2.seekg ((GN-1)*(4*4),ios::beg);
    Rdr2.read((char*)TA,sizeof(char)*(4*4));
    Rdr2.close();
    Copy(A, TA);
}

void Records5x5(char A[][TTTSize],int GN){
    char TA[5][5];
    ifstream Rdr3("Records5x5.bin",ios::binary);
    Rdr3.seekg ((GN-1)*(5*5),ios::beg);
    Rdr3.read((char*)TA,sizeof(char)*(5*5));
    Rdr3.close();
    Copy(A, TA);
}

void SeeRecords(char A[][TTTSize],int GN,int Dim){
    if(Dim==3)
        Records3x3(A,GN);
    else if(Dim==4)
        Records4x4(A,GN);
    else if(Dim==5)
        Records5x5(A,GN);
}

void Delay(){
    for(int i=0;i<10000;i++)
        for(int j=0;j<10000;j++){}
}

void getRowColbyLeftClick(int &rpos,int &cpos){
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    do{
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }
    }
    while(true);
}

void gotoxy(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

void PrintO1(int cx,int cy,int r,char S){
    for(int theta=0;theta<360;theta++)
    {
      float rtheta=theta*3.14/180;
      int X=ceil(r*cos(rtheta)+cx);
      int Y=ceil(r*sin(rtheta)*-1+cy);
      gotoxy(Y,X);
      cout << S;
    }
}

void PrintX1(int cx,int cy,int Max,char S){
    gotoxy(cy,cx);
    int x,y,i=1;
    for(x=0;x<(Max/2)+1;x++){
        for(y=0;y<Max;y++){
            if(y==x || y==Max-(x+1))
                cout << S;
            else
                cout << ' ';
        }
        gotoxy(cy,cx+i);
        i++;
    }
    for(x=(Max/2)-1;x>=0;x--){
        for(y=0;y<Max;y++){
            if(y==x || y==(Max-1)-x)
                cout << S;
            else
                cout << ' ';
        }
        gotoxy(cy,cx+i);
        i++;
    }
}

void Board(int Cs,int Ce,int Rs,int Re,int Rows,int Cols,char S){
    int x,y;
    for(x=Cs;x<=Ce;x=x+Cs){
        for(y=0;y<Rows;y++){
            gotoxy(x,y);
            cout << S;
        }}
    for(y=Rs;y<=Re;y=y+Rs){
        for(x=0;x<Cols;x++){
            gotoxy(x,y);
            cout << S;
        }}
}

void PrintO(int x,int y,int Dim,int Rows,int Cols,int r,char S){
    int Cx,Cy,Rs,Re,Cs,Ce;
    Rs=(y)*(Rows/Dim);
    Re=(y+1)*(Rows/Dim);
    Cx=(Rs+Re)/2;
    Cs=(x)*(Cols/Dim);
    Ce=(x+1)*(Cols/Dim);
    Cy=(Cs+Ce)/2;
    PrintO1(Cx,Cy,r,S);
}

void PrintX(int x,int y,int Dim,int Max,char S,int Rows,int Cols){
    int Cx,Cy;
    Cx=(y)*(Rows/Dim)+3-(Dim-3);
    Cy=(x)*(Cols/Dim)+12-(4*Dim-12);
    PrintX1(Cx,Cy,Max,S);
}

bool Valid(char A[][TTTSize],int Dim,int x,int y,char S){
    if((x>=0 && x<=Dim)&&(y>=0 && y<=Dim)&&(A[x][y]==S))
        return true;
    return false;
}

bool Rwin(char A[][TTTSize],int Dim,char S1,char S2,int &Turn){
    int X=0,Y=0;
    for(int i=0;i<Dim;i++){
        for(int j=0;j<Dim;j++){
            if(A[i][j]==S1)
                X++;
            if(A[i][j]==S2)
                Y++;
        }
        if(X==Dim || Y==Dim){
            if(X==3){
                Turn=1;
                return true;
            }
            else{
                Turn=2;
                return true;
            }
        }
        else
            X=0,Y=0;
    }
    return false;
}

bool Cwin(char A[][TTTSize],int Dim,char S1,char S2,int &Turn){
    int X=0,Y=0;
    for(int j=0;j<Dim;j++){
        for(int i=0;i<Dim;i++){
            if(A[i][j]==S1)
                X++;
            if(A[i][j]==S2)
                Y++;
        }
        if(X==Dim || Y==Dim){
            if(X==3){
                Turn=1;
                return true;
            }
            else{
                Turn=2;
                return true;
            }
        }
        else
            X=0,Y=0;
    }
    return false;
}

bool Vwin(char A[][TTTSize],int Dim,char S1,char S2,int &Turn){
    int X=0,Y=0;
    for(int i=0;i<Dim;i++){
        if(A[i][i]==S1)
            X++;
        if(A[i][i]==S2)
            Y++;
    }
    if(X==Dim || Y==Dim){
        if(X==3){
            Turn=1;
            return true;
        }
        else{
            Turn=2;
            return true;
        }}
    else
        return false;
}

bool RVwin(char A[][TTTSize],int Dim,char S1,char S2,int &Turn){
    int X=0,Y=0,n=Dim-1;
    for(int i=0;i<=n;i++){
        if(A[i][n-i]==S1)
            X++;
        if(A[i][n-i]==S2)
            Y++;
    }
    if(X==Dim || Y==Dim){
        if(X==3){
            Turn=1;
            return true;
        }
        else{
            Turn=2;
            return true;
        }}
    else
        return false;
}

bool Win(char A[][TTTSize],int Dim,char S1,char S2,int &Turn){
    if((Rwin(A,Dim,S1,S2,Turn)) || (Cwin(A,Dim,S1,S2,Turn)) || (Vwin(A,Dim,S1,S2,Turn)) || (RVwin(A,Dim,S1,S2,Turn)))
        return true;
}

bool IsTie(char A[][TTTSize],int Dim,char S){
    int a=0;
    for(int i=0;i<Dim;i++){
        for(int j=0;j<Dim;j++){
            if(A[i][j]!=S)
                a++;
        }
    }
    if(a==Dim*Dim)
        return true;
    return false;
}

void Box(int &ci, int &ri,int cx,int cy,int Dim,int Rows,int Cols){
    ci=(cx)/(Cols/Dim);
    ri=(cy)/(Rows/Dim);
}

char vsHuman(char A[][TTTSize],int Dim,int Rows,int Cols,int r,int SIZE,char S,int Turn,int Click){
    int x=-1,y=-1,C=Turn,a=1,cx,cy;
    char B;
    if(Turn==1)
        B='O';
    else
        B='X';
    while(a<=Dim*Dim){
        while(!Valid(A,Dim,x,y,'-')){
            getRowColbyLeftClick(cy,cx);
            Box(x,y,cx,cy,Dim,Rows,Cols);
            if(ClickOnLoad(cx,cy)){
                LoadGame(A,Dim,SIZE,r,Turn,cx,cy,Click);
                exit(0);
            }
        }
        if(B=='O'){
            PrintO(x,y,Dim,Rows,Cols,r,S);
            A[x][y]=B;
        }
        if(B=='X'){
            PrintX(x,y,Dim,SIZE,S,Rows,Cols);
            A[x][y]=B;
        }
        if(Win(A,Dim,'X','O',Turn) || IsTie(A,Dim,'-'))
            break;
        C++;
        if(C%2==0){
            B='X';
            Turn=2;
        }
        else{
            B='O';
            Turn=1;
        }
        x=-1,y=-1;
        a++;
    }
    return B;
}

bool IsComputerMove(char B){
    if(B=='X')
        return true;
    else
        return false;
}

bool ComputerWin(char A[][TTTSize],int Dim,int &ri,int &ci,char S1,char S2,int &Turn){
    for(int i=0;i<Dim;i++){
        for(int j=0;j<Dim;j++){
            if(A[i][j]=='-'){
                A[i][j]='X';
                if(Win(A,Dim,S1,S2,Turn)){
                    if(Turn=2){
                        ri=j;
                        ci=i;
                        return true;
                    }}
                A[i][j]='-';
            }}}
    return false;
}

bool HumanWin(char A[][TTTSize],int Dim,int &ri,int &ci,char S1,char S2,int &Turn){
    for(int i=0;i<Dim;i++){
        for(int j=0;j<Dim;j++){
            if(A[i][j]=='-'){
                A[i][j]='O';
                if(Win(A,Dim,S1,S2,Turn)){
                    if(Turn=1){
                        ri=j;
                        ci=i;
                        return true;
                    }}
                A[i][j]='-';
            }}}
    return false;
}

bool VerticalValid(char A[][TTTSize],int Dim,int &x,int &y,char S){
    for(int i=0;i<Dim;i++){
        if(Valid(A,Dim,i,i,S)){
            x=i;
            y=i;
            return true;
        }
    }
    return false;
}

bool RVerticalValid(char A[][TTTSize],int Dim,int &x,int &y,char S){
    int n=Dim-1;
    for(int i=0;i<=n;i++){
        if(Valid(A,Dim,n-i,i,S)){
            x=i;
            y=n-i;
            return true;
        }
    }
    return false;
}

void ComputerMakesMove(char A[][TTTSize],int Dim,int &ri,int &ci,int &Turn){
    srand(time(0));
    if(ComputerWin(A,Dim,ri,ci,'O','X',Turn))
        return;
    else if(HumanWin(A,Dim,ri,ci,'O','X',Turn))
        return;
    else if(VerticalValid(A,Dim,ri,ci,'-'))
        return;
    else if(RVerticalValid(A,Dim,ri,ci,'-'))
        return;
    else{
        while(!Valid(A,Dim,ci,ri,'-')){
            ci=rand()%Dim;
            ri=rand()%Dim;
        }
        return;
    }
}

char vsComputer(char A[][TTTSize],int Dim,int Rows,int Cols,int r,int Size,char S,int &Turn,int Click){
    int x=-1,y=-1,C=1,a=1,cx,cy;
    char B='O';
    while(a<=Dim*Dim){
        if(!IsComputerMove(B)){
            while(!Valid(A,Dim,x,y,'-')){
                getRowColbyLeftClick(cy,cx);
                Box(x,y,cx,cy,Dim,Rows,Cols);
                if(ClickOnLoad(cx,cy)){
                    LoadGame(A,Dim,Size,r,Turn,cx,cy,Click);
                    exit(0);
                }}
        }else{
            Delay();
            Delay();
            Delay();
            ComputerMakesMove(A,Dim,y,x,Turn);
        }
        if(B=='O'){
            PrintO(x,y,Dim,Rows,Cols,r,S);
            A[x][y]=B;
        }if(B=='X'){
            PrintX(x,y,Dim,Size,S,Rows,Cols);
            A[x][y]=B;
        }if((Win(A,Dim,'O','X',Turn))|| IsTie(A,Dim,'-'))
            break;
        C++;
        if(C%2==0)
            B='X';
        else
            B='O';
        x=-1,y=-1;
        a++;
        }
    }

void Init(char A[][TTTSize],int Dim){
    for(int i=0;i<Dim;i++)
        for(int j=0;j<Dim;j++)
            A[i][j]='-';
}

void MenuStructure(char S){
    int i,j,rs=24,re=72,cs=6,ce=11,a=1;
    while(a<=3){
        for(i=rs;i<=re;i++){
            for(j=cs;j<=ce;j++){
                if(i==rs || i==re){
                    gotoxy(i,j);
                    cout << S;
                }else if(j==cs || j==ce){
                    gotoxy(i,j);
                    cout << S;
                }else{
                    gotoxy(i,j);
                    cout << ' ';
                }}}
        a++;
        cs=cs+8;
        ce=ce+8;
    }
}

void MenuBoxs(){
    gotoxy(40,8);
    cout << "HUMAN VS HUMAN";
    gotoxy(39,16);
    cout << "HUMAN VS COMPUTER";
    gotoxy(44,24);
    cout << "RECORDS";
}

void Dimension(){
    gotoxy(44,8);
    cout << "3 x 3";
    gotoxy(44,16);
    cout << "4 x 4";
    gotoxy(44,24);
    cout << "5 x 5";
}

void LoadStructure(char S){
    int i,j,rs=0,re=99,cs=37,ce=41;
    for(i=rs;i<=re;i++){
        for(j=cs;j<=ce;j++){
            if(i==rs || i==re){
                gotoxy(i,j);
                cout << S;
            }else if(j==cs || j==ce){
                gotoxy(i,j);
                cout << S;
            }else{
                gotoxy(i,j);
                cout << ' ';
            }}}
    gotoxy(43,39);
    cout << "L O A D";
}

bool ClickOnLoad(int ri,int ci){
    int cs=37,ce=41;
    if(ci>=cs && ci<=ce)
        return true;
    return false;
}

void LoadGame(char A[][TTTSize],int Dim,int s,int r,int Turn,int ri,int ci,int Click){
    ofstream out("LoadGame.txt");
    out << Click << '\n';
    out << Turn << '\n';
    out << Dim << ' ' << s << ' ' << r << '\n';
    if(ClickOnLoad(ri,ci)){
        for(int i=0;i<Dim;i++){
            for(int j=0;j<Dim;j++)
                out << A[j][i];
            cout << '\n';
        }
    }
    out.close();
}

void LoadBoard(char A[][TTTSize],int Rows,int Cols,int Dim,char S,int s,int r){
    for(int i=0;i<Dim;i++){
        for(int j=0;j<Dim;j++){
            if(A[j][i]=='O')
                PrintO(j,i,Dim,Rows,Cols,r,S);
            else if(A[j][i]=='X')
                PrintX(j,i,Dim,s,S,Rows,Cols);
        }
    }
}

void PlayLoadGame(char A[][TTTSize],int Rows,int Cols,char S,int Load){
    int Turn,Click,Dim,s,r;
    ifstream in("LoadGame.txt");
    if(in.is_open()){
        in >> Click;
        in >> Turn;
        in >> Dim >> s >> r;
        for(int i=0;i<Dim;i++){
            for(int j=0;j<Dim;j++)
                in >> A[j][i];
        }
        if(Click==1)
            HumanvsHuman(A,Rows,Cols,Dim,Turn,S,s,r,Click,Load);
        else
            HumanvsComputer(A,Rows,Cols,Dim,Turn,S,s,r,Click,Load);
    }
    else{
        gotoxy(40,17);
        cout << "No save Game";
        Delay();
        Delay();
        Delay();
    }
}

int ClickInMenu(int ri,int ci){
    int cs=6,ce=11,a=1,rs=24 , re=72;
    while(a<=3){
        if(ci>=cs && ci <=ce && ri>=rs && ri <=re)
            return a;
        a++;
        cs=cs+8;
        ce=ce+8;
    }
    cs=37,ce=41;
    if(ci>=cs && ci<=ce)
        return a;
    a++;
    return a;
}

void HumanvsComputer(char A[][TTTSize],int Rows,int Cols,int Dim,int Turn,char S,int s,int r,int Click,int Load){
    Board(Cols/Dim,(Dim-1)*(Cols/Dim),Rows/Dim,(Dim-1)*(Rows/Dim),Rows,Cols,S);
    LoadStructure(S);
    if(Load==0)
        Init(A,Dim);
    else
        LoadBoard(A,Rows,Cols,Dim,S,s,r);
    char B=vsComputer(A,Dim,Rows,Cols,r,s,S,Turn,Click);
    Delay();
    Delay();
    system("cls");
    SaveRecord(Dim,A);
    gotoxy(40,17);
    if(Win(A,Dim,'O','X',Turn)){
        if(Turn==1)
            cout << "Player     Wins...!!";
        else
            cout << "Computer     Wins...!!";
    }
    else
        cout << "Game   is   Tie..!!";
    Delay();
    Delay();
    Delay();
}

void HumanvsHuman(char A[][TTTSize],int Rows,int Cols,int Dim,int Turn,char S,int s,int r,int Click,int Load){
    Board(Cols/Dim,(Dim-1)*(Cols/Dim),Rows/Dim,(Dim-1)*(Rows/Dim),Rows,Cols,S);
    LoadStructure(S);
    if(Load==0)
        Init(A,Dim);
    else
        LoadBoard(A,Rows,Cols,Dim,S,s,r);
    char B=vsHuman(A,Dim,Rows,Cols,r,s,S,Turn,Click);
    Delay();
    Delay();
    system("cls");
    SaveRecord(Dim,A);
    gotoxy(40,17);
    if(Win(A,Dim,'O','X',Turn))
        cout << "Player " << B << " Wins..!!";
    else
        cout << "Game   is   Tie..!!";
    Delay();
    Delay();
    Delay();
}

void Dimm(int Click,int &Dim,int &r,int &s){
    if(Click==1){
        Dim=3;
        r=5;
        s=7;
    }
    else if(Click==2){
        Dim=4;
        r=3;
        s=5;
    }
    else{
        Dim=5;
        s=3;
        r=2;
    }
}

void HvH(char A[][TTTSize],int x ,int y,int Rows,int Cols,int Turn,char S,int Cl){
    int Load=0,Dim,r,s,CM;
    MenuStructure(S);
    Dimension();
    do{
        getRowColbyLeftClick(y,x);
        CM=ClickInMenu(x,y);
    }while(CM==4 || CM==5);
    Dimm(CM,Dim,r,s);
    system("cls");
    Cl=1;
    HumanvsHuman(A,Rows,Cols,Dim,Turn,S,s,r,Cl,Load);
}

void HvC(char A[][TTTSize],int x ,int y,int Rows,int Cols,int Turn,char S,int Cl){
    int Load=0,Dim,r,s,CM;
    MenuStructure(S);
    Dimension();
    do{
        getRowColbyLeftClick(y,x);
        CM=ClickInMenu(x,y);
    }while(CM==4 || CM==5);
    Dimm(CM,Dim,r,s);
    system("cls");
    Cl=2;
    HumanvsComputer(A,Rows,Cols,Dim,Turn,S,s,r,Cl,Load);
}

void Record(char A[][TTTSize],int x ,int y,int Rows,int Cols,int Turn,char S,int Cl){
    int Dim,r,s,CM;
    int GN;
    MenuStructure(S);
    Dimension();
    do{
        getRowColbyLeftClick(y,x);
        CM=ClickInMenu(x,y);
    }while(CM==4 || CM==5);
    Dimm(CM,Dim,r,s);
    system("cls");
    gotoxy(40,17);
    cout << "RECORD No : ";
    cin >> GN;
    Delay();
    system("cls");
    Board(Cols/Dim,(Dim-1)*(Cols/Dim),Rows/Dim,(Dim-1)*(Rows/Dim),Rows,Cols,S);
    SeeRecords(A,GN,Dim);
    LoadBoard(A,Rows,Cols,Dim,S,s,r);
    getch();
}

void Menu(char A[][TTTSize],int x ,int y,int Rows,int Cols,int Turn,char S,int Click,int Cl){
    int Load=0,Dim,r,s;
    if(Click==1){
        system("cls");
        HvH(A,x,y,Rows,Cols,Turn,S,Cl);
    }else if(Click==2){
        system("cls");
        HvC(A,x,y,Rows,Cols,Turn,S,Cl);
    }else if(Click==3){
        system("cls");
        Record(A,x,y,Rows,Cols,Turn,S,Cl);
    }else if(Click==4){
        Load=1;
        PlayLoadGame(A,Rows,Cols,S,Load);
    }
}

void PlayAgainStructure(char S){
    int i,j,rs=24,re=72,cs=10,ce=15,a=1;
    while(a<=2){
        for(i=rs;i<=re;i++){
            for(j=cs;j<=ce;j++){
                if(i==rs || i==re){
                    gotoxy(i,j);
                    cout << S;
                }else if(j==cs || j==ce){
                    gotoxy(i,j);
                    cout << S;
                }else{
                    gotoxy(i,j);
                    cout << ' ';
                }}}
        a++;
        cs=cs+12;
        ce=ce+12;
    }
}

void PlayAgain(){
    gotoxy(42,12);
    cout << "Play Again";
    gotoxy(44,24);
    cout << "Quit";
}

bool IsQuit(int x,int y){
    int rs=24,re=72,cs=22,ce=27;
    if((y>=rs && y<=re)&&(x>=cs && x<=ce))
        return true;
    return false;
}

bool IsPlayAgain(int x,int y){
    int rs=24,re=72,cs=10,ce=15;
    if((y>=rs && y<=re)&&(x>=cs && x<=ce))
        return true;
    return false;
}

int main()
{
    int x,y,Cols=100,Rows=36,Click=1,Turn=1; //IF -->> Dim 3 , s 7 , r 5 &&  Dim 4 , s 5 , r 3  &&  Dim 5  , s 3 , r 2
    char S=-37;
    char A[TTTSize][TTTSize];
    do{
    system("cls");
    MenuStructure(S);
    MenuBoxs();
    LoadStructure(S);
    int Cl=1;
    do{
        getRowColbyLeftClick(y,x);
        Cl=ClickInMenu(x,y);
    }while(Cl==5);
    Delay();
    system("cls");
    Menu(A,x,y,Rows,Cols,Turn,S,Cl,Click);
    system("cls");
    Delay();
    PlayAgainStructure(S);
    PlayAgain();
    do{
        getRowColbyLeftClick(x,y);
    }while(!IsQuit(x,y) && !IsPlayAgain(x,y));
    if(IsQuit(x,y))
        break;
    }while(IsPlayAgain(x,y));
    system("cls");
    gotoxy(41,17);
    cout << "Well Played";
    gotoxy(35,20);
    cout << "Hope You Will Play Again";
    getch();
}
