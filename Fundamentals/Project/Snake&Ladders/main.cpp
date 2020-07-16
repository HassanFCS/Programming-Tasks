#include <iostream>
#include<time.h>
#include<conio.h>
#include<math.h>
#include<fstream>

#include<windows.h>
using namespace std;
void gotoRowCol(int rpos, int cpos)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int xpos=cpos, ypos = rpos;
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}
void printbox(int sr,int sc,int rdim,int cdim,char s)
{
    for(int ri=0;ri<rdim;ri++)
    {
        for(int ci=0;ci<cdim;ci++)
        {
            if(ri==0||ri==rdim-1||ci==cdim-1||ci==0)
            {
                gotoRowCol(sr+ri,sc+ci);
                cout<<s;
            }
        }
    }
}
void printboxno(int num,int rdim,int cdim,char s)
{
    int sr=((num-1)/10)*rdim;
    int sc=((num-1)%10)*cdim;
    printbox(sr,sc,rdim,cdim,s);
}
void printinboxcenter(int num,int val,int rdim,int cdim)
{
    int ri=((num-1)/10*rdim)+rdim/2;
    int ci=((num-1)%10*cdim)+cdim/2;
    gotoRowCol(ri,ci);
    cout<<val;
}
void printinboxcenter1(int num,int val,int rdim,int cdim)
{
    int ri=((num-1)/10*rdim)+rdim/2;
    int ci=((num-1)%10*cdim)+cdim/2;
    gotoRowCol(ri-39,ci+48);
    cout<<val;
}
void printgrid(int rdim,int cdim,char s)
{


   int n=100,j=1,boxno=1,boxnos=100,Num=10;
    for(int n=1;n<=100;n++)
    {


      printboxno(n,rdim,cdim,s);

    }
    for(int i=1;i<=5;i++)
    {

        for( n;j<=10;n--,j++,boxno++)
        {
            printinboxcenter(boxno,n,rdim,cdim);
        }
       n-=10,boxno+=10,j-=10;
    }
      for(int i=1;i<=5;i++)
    {

        for( Num;j<=10;Num--,j++,boxnos--)
        {
            printinboxcenter(boxnos,Num,rdim,cdim);
        }
        Num+=30,boxnos-=10,j-=10;

    }
}
void diceshow()
{
   printbox(70,60,10,10,-37);
   gotoRowCol(67,60);
   cout<<"Dice";
}

void snakeshow(int rdim,int cdim,char s,int nosnake, int Snake[][2])
{

    int r=rdim,c=cdim*12,nos;
    gotoRowCol(r-3,c+4);
    cout<<"Snakes";
    gotoRowCol(r-1,c+1);
    cout<<"Start";
    gotoRowCol(r-1,c+9);
    cout<<"End";
    ifstream Sr("Snakes.txt");
    Sr>>nos;
    for(int i=0;i<nos;i++)
    {

       printbox(r,c,rdim,cdim,s);
        Sr>>Snake[i][0];
        gotoRowCol(r+3,c+2);
        cout<<Snake[i][0];
        c+=cdim;
        printbox(r,c,rdim,cdim,s);
        Sr>>Snake[i][1];
        gotoRowCol(r+3,c+3);
        cout<<Snake[i][1];
        r+=rdim;
        c-=cdim;
    }


}
void Laddersshow(int Ladder[][2],int NOl,int ri,int ci,int rd,int cd,int BoxN)
{
    char S=-37;
    gotoRowCol(37,79);
    cout<<"   Ladders";
    gotoRowCol(39,83);
    cout<<"start";
    gotoRowCol(39,93);
    cout<<"End";
    for(int s=0; s<NOl; s++)
    {
        int ls=Ladder[s][0];
        int le=Ladder[s][1];

        printbox(ri,ci,rd,cd,S);
        printinboxcenter1(BoxN,ls,rd,cd);
        printbox(ri,ci+cd,rd,cd,S);
        printinboxcenter1(BoxN+1,le,rd,cd);
        BoxN=BoxN+10;
        ri=ri+rd;

    }
}

/*void snakereader (ifstream &sr, int snakes[][2], int ss)
{
    for(int i=0; i<ss; i++)
    {
        sr>>snakes[i][0];
        sr>>snakes[i][1];
    }
}

void ladderreader(ifstream &lr, int ladders[][2], int ls)
{
    for(int i=0; i<ls; i++)
    {
        lr>>ladders[i][0];
        lr>>ladders[i][1];
    }
}*/

void init(int ppos[], int totalplayers,int &turn)
{
     turn=0;

    for(int i=0; i<totalplayers; i++)
    {
        ppos[i] = 0;
    }

}

int rolldice ()
{
    int dice,total=0;
    do
    {
        getch();
        while(!kbhit())
        {
           dice=rand()%6+1;
           gotoRowCol(74,64);
           cout<<dice;
           cout<<" ";
        }
        while(kbhit())
        {
            getch();
        }
        total+=dice;
        if(total==18)
        {
            total=0;
            break;
        }
    }
    while(dice==6);
    return total;
}

void changepos (int &ppos, int dice)
{
    if(ppos==0)
    {
        if(dice>6)
        {
            dice=dice-6;
            ppos += dice;
        }

    }
    else
    {
        if(ppos+dice<=100)
        ppos +=dice;
    }

}
void playerpositionshow(int rdim,int cdim,char s,int nop, int ppos[])
{
    int r=rdim*11,c=cdim;
    gotoRowCol(r-3,c);
    cout<<"Player Position";
    gotoRowCol(r-1,c+1);
    cout<<"PNo.S";
    gotoRowCol(r-1,c+9);
    cout<<"PPos";
    for(int i=0;i<nop;i++)
    {
        printbox(r,c,rdim,cdim,s);
        gotoRowCol(r+3,c+2);
        cout<<i+1<<"P";
        c+=cdim;
        printbox(r,c,rdim,cdim,s);
        gotoRowCol(r+3,c+3);
        cout<<ppos[i];
        r+=rdim,c-=cdim;
    }
}
void Print_In_Box_center_Symbol(int Num,char s,int Rdim,int Cdim,int div)
{
    int Ri=((Num-1)/10*Rdim)+Rdim/div;
    int Ci=((Num-1)%10*Cdim)+Cdim/div;
    gotoRowCol(Ri,Ci);
    cout<<s;
}
void PLayer_Position_Board(int PPos,int Rdim, int Cdim, char s)
{
     int N=100,j=1,BoxNo=1,BoxNos=100,Num=10,div=4;
     if(PPos==0)
     {
         cout<< " ";
     }
     else
     {
        for(int i=1;i<=5;i++)
        {

            for( N;j<=10;N--,j++,BoxNo++)
            {
                if(N==PPos)
                {
                  Print_In_Box_center_Symbol(BoxNo,s,Rdim,Cdim,div);
                }

            }
            N-=10,BoxNo+=10,j-=10;
        }
        for(int i=1;i<=5;i++)
        {

            for( Num;j<=10;Num--,j++,BoxNos--)
            {
                if(Num==PPos)
                {
                  Print_In_Box_center_Symbol(BoxNos,s,Rdim,Cdim,div);
                }
            }
            Num+=30,BoxNos-=10,j-=10;

        }
     }

}
bool checksnakebite(int ppos,int snake[][2],int ss)
{
    for(int s=0;s<ss;s++)
    {
        if(ppos==snake[s][0])
        {
            ppos=snake[s][1];
            return true;
        }
    }
    return false;
}
bool ladderclimbing(int ppos,int ladder[][2],int ls)
{
    for(int l=0;l<ls;l++)
    {
        if(ppos==ladder[l][0])
        {
            ppos=ladder[l][1];
            return true;
        }
        return false;
    }
}
void changeturn(int &turn,int totalplayers)
{
    turn=(turn+1)%totalplayers;
}
int main()
{
    srand(time(0));
    int dice=0;
     int totalplayers;
    int wi=0;
    int rows=88, cols=100;
    int rdim=rows/13,cdim=cols/13;
    /*printgrid(rdim,cdim,-37);
    snakeshow();
    laddershow();
    diceshow();
   int d= rolldice();*/
    gotoRowCol(60,1);
    cout<<"total players";
    cin>>totalplayers;
    char ps[totalplayers];
    int winners[totalplayers];
    int turn;
    for(int i=0;i<totalplayers;i++)
    {
        cout<<"Enter Player "<<i+1<<"'s Symbol: ";
        cin>>ps[i];
    }
    int ss;
    int ls;
    ifstream sr("Snakes.txt");
    sr>>ss;
    int snakes[ss][2];
   //snakereader(sr,snakes,ss);
   int LadderSize;
  ifstream LadderReader("Ladder.txt");
  LadderReader>>LadderSize;
  int Ladder[LadderSize][2];
  for(int l=0;l<LadderSize;l++)
  {
    int ls,le;
    LadderReader>>ls>>le;
    Ladder[l][0]=ls;
    Ladder[l][1]=le;
  }

   int ppos[totalplayers];
   printgrid(rdim,cdim,-37);
    snakeshow(rdim,cdim,-37,ss,snakes);
    Laddersshow(Ladder,LadderSize,40,83,rdim,cdim,136);
    diceshow();
    init(ppos,totalplayers,turn);
    playerpositionshow(rdim,cdim,-37,totalplayers,ppos);

   do
   {
    gotoRowCol(rdim*11,cdim*5);
    cout<<turn+1<<"'s Player Turn: ";
    dice= rolldice();
    PLayer_Position_Board(ppos[turn],rdim,cdim,' ');
    changepos(ppos[turn],dice);
    PLayer_Position_Board(ppos[turn],rdim,cdim,ps[turn]);
    playerpositionshow(rdim,cdim,-37,totalplayers,ppos);
     int prep=ppos[turn];
     if(checksnakebite(ppos[turn],snakes,ss))
    {
        cout<<"  SNAKE BITE";
        PLayer_Position_Board(prep,rdim,cdim,' ');
        PLayer_Position_Board(ppos[turn],rdim,cdim,ps[turn]);
        playerpositionshow(rdim,cdim,-37,totalplayers,ppos);

    }
  else  if(ladderclimbing(ppos[turn],Ladder,ls))
    {
        cout<<"  LADDER CLIMBING";
       PLayer_Position_Board(prep,rdim,cdim,' ');
        PLayer_Position_Board(ppos[turn],rdim,cdim,ps[turn]);
        playerpositionshow(rdim,cdim,-37,totalplayers,ppos);

    }
  else  if(ppos[turn]==100)
    {
        winners[wi]=turn;
        wi++;
    }
    do
    {
      changeturn(turn,totalplayers);
    }
    while(ppos[turn]==100);
   }
   while(wi<totalplayers-1);
   winners[wi]=turn;
   for(int i=0;i<totalplayers;i++)
   {
       cout<<" "<<i+1<<"    Winner is "<<winners[i]+1;
    }
getch();



}

