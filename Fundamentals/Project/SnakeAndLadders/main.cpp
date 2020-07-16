#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <math.h>

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
void delay(int time)
{
    for(int j=0;j<time;j++)
    {
        for(int i=0; i<999999; i++)
        {

        }
    }
}
void number_to_box_no(int &num)
{
    if(((num-1)/10)%2==0)
    {

    }
    else
    {
        int r=((num-1)/10)*10;
        int c=10-(num-1)%10;
        num=c+r;
    }
}

void initialize_players_position(int playes_position[],int no_of_players)
{
    for(int i=0;i<no_of_players;i++)
    {
        playes_position[i]=0;
    }
}

void print_box(int sr,int sc,int rdim,int cdim,char s)
{
    for(int ri=0;ri<rdim;ri++)
    {
        for(int ci=0;ci<cdim;ci++)
        {
            if(ri==0 || ri==rdim-1 ||ci==0 || ci==cdim-1)
                {
                    gotoRowCol(sr+ri,sc+ci);
                    cout <<s;
                }
        }
    }
}

void print_box_of_no(int num,int rdim,int cdim,char s)
{
    int sr=((num-1)/10)*rdim;
    int sc=((num-1)%10)*cdim;
    print_box(sr,sc,rdim,cdim,s);
}

void grid_printer(int rdim,int cdim,char s)
{
    for(int i=0;i<=100;i++)
    {
        print_box_of_no(i,rdim,cdim,s);
    }
}

void print_in_box_centre(int num,int value,int rdim,int cdim)
{
    int ri=(((num-1)/10)*rdim)+(rdim/2);
    int ci=(((num-1)%10)*cdim)+(cdim/2)-1;
    gotoRowCol(ri,ci);
    cout <<value;
}

void print_box_no(int rdim,int cdim)
{
    for(int i=1;i<=100;i++)
    {
        int r=i;
        number_to_box_no(r);
        print_in_box_centre(i,101-r,rdim,cdim);
    }
}

int roll_dice()
{
    int dice=0,total=0,counter=0,ddk=0;
    print_box(34,125,15,15,-37);
    gotoRowCol(39,127);
    //cout <<"-"<<"-"<<endl;
    int d = 0;
    do
    {
        while(!kbhit())
        {
            int r=37,c=127;

            dice=(rand()%6)+1;
            delay(d);
            char s=-37;

            if(dice==1)
            {
                gotoRowCol(r,c);
                cout <<s;
                delay(d);
            }
            else if(dice==2)
            {
                gotoRowCol(r,c);
                cout <<s<<" "<<s;
                delay(d);
                gotoRowCol(r,c);
            }
            else if(dice==3)
            {
                gotoRowCol(r,c);
                cout <<s<<" "<<s;
                delay(d);
                int z=r+2;
                gotoRowCol(z,c);
                cout <<s;
                delay(d);
            }
            else if(dice==4)
            {
                gotoRowCol(r,c);
                cout <<s<<" "<<s;
                delay(d);
                int z=r+2;
                gotoRowCol(z,c);
                cout <<s<<" "<<s;
                delay(d);
            }
            else if(dice==5)
            {
                gotoRowCol(r,c);
                cout <<s<<" "<<s;
                delay(d);
                int z=r+2;
                gotoRowCol(z,c);
                cout <<s;
                delay(d);
                int y=r+4;
                gotoRowCol(y,c);
                cout <<s<<" "<<s;
                delay(d);
            }
            else  if(dice==6)
            {
                gotoRowCol(r,c);
                cout <<s<<" "<<s;
                delay(d);
                int z=r+2;
                gotoRowCol(z,c);
                cout <<s<<" "<<s;
                delay(d);
                int y=r+4;
                gotoRowCol(y,c);
                cout <<s<<" "<<s;
                delay(d);
            }
            delay(70);
            gotoRowCol(r,c);
            cout <<"   ";
            int z=r+2;
            gotoRowCol(z,c);
            cout <<"   ";
            int y=r+4;
            gotoRowCol(y,c);
            cout <<"   "<<endl;
        }
        while(kbhit())
        {
            char cheat=getch();
            if(cheat=='c')
            {
                gotoRowCol(2,110);
                cin >>ddk;
                return ddk;
            }

        }
        total=total+dice;
        if(counter==3)
        {
            total=0;
            break;
        }
        counter++;
    }
    while(dice==6);
//    gotoRowCol(39,127);
//    cout <<total;
    return total;
}

void display_players_position(int player_position[],int no_of_players)
{
    int r=75,c=5;
    for(int i=0;i<no_of_players;i++)
    {
        gotoRowCol(r,c);
        cout <<"player : "<<i+1<<"  "<<"is at"<<"  "<<player_position[i]<<endl;
        r++;
    }
}
void PLayer_Position_Show(int Rdim,int Cdim,char S,int NoP, int Player_Position[],char Player_Symbol[])
{
    int R=Rdim*11,C=Cdim;
    gotoRowCol(R-3,C);
    cout<<"Player Position";
    gotoRowCol(R-1,C+1);
    cout<<"PNo.S";
    gotoRowCol(R-1,C+10);
    cout<<"PPos";
    for(int i=0;i<NoP;i++)
    {
        print_box(R,C,Rdim,Cdim,S);
        gotoRowCol(R+3,C+2);
        cout<<i+1<<"P";
        C+=Cdim;
        print_box(R,C,Rdim,Cdim,S);
        gotoRowCol(R+3,C+2);
        cout<<Player_Position[i]<<" ";
        C+=Cdim;
    }
}
void display_players_position_on_board(int num,char s,int rdim,int cdim)
{
    num=101-num;
        number_to_box_no(num);

    int ri=(((num-1)/10)*rdim)+(rdim/2)-2;
    int ci=(((num-1)%10)*cdim)+(cdim/2)-2;

    gotoRowCol(ri,ci);
    cout <<s;
}

void change_players_position(int &player_position,int dice)
{
    if(player_position==0)
    {
        if(dice>=6)
        {
            dice-=6;
            player_position+=dice;
        }
        else
        {


        }
    }
    else if((player_position+dice)<100)
    {
        player_position+=dice;
    }
}

void change_player_turn(int no_of_players,int &turn)
{
    turn=(turn+1)%no_of_players;
}

void print_snakes_box(int snakes[][2],int no_of_snakes,int ri,int ci,int rdim,int cdim)
{

    for(int s=0;s<no_of_snakes;s++)
    {
        int ss=snakes[s][0];
        int sc=snakes[s][1];
    }
}

void display_snakes_on_board(int snakes[][2],int no_of_snakes,int rdim,int cdim)
{
    for(int i=0;i<no_of_snakes;i++)
    {

        int ss=snakes[i][0];
        int se=snakes[i][1];

        number_to_box_no(ss);
        number_to_box_no(se);
        ss=101-ss;
        se=101-se;
        if(i==1)
        {
            int ri=(((ss-1)/10)*rdim)+4;
            int ci=(((ss-1)%10)*cdim)-7;

            int rr=(((se-1)/10)*rdim)+5;
            int cc=(((se-1)%10)*cdim)-7;

            int scale=(rr-ri)/2;
            int R=(rr+ri)/2;
            int H=-(cc-ci);
            int Dtheta=180/H;

    int Ci=ci;
        for(float theta=270;theta<=450;theta+=Dtheta)
    {

        int Ri=scale*(sin(theta*3.14/180))+R;
        gotoRowCol(Ri,Ci);
        cout<<'*';
        Ci++;
    }
        }
        else
        {
            int ri=(((ss-1)/10)*rdim)+4;
            int ci=(((ss-1)%10)*cdim)+10;

            int rr=(((se-1)/10)*rdim)+5;
            int cc=(((se-1)%10)*cdim)+10;

            int scale=(rr-ri)/2;
            int R=(rr+ri)/2;
            int H=-(cc-ci);
            int Dtheta=180/H;

    int Ci=ci;
        for(float theta=270;theta<=450;theta+=Dtheta)
    {

        int Ri=scale*(sin(theta*3.14/180))+R;
        gotoRowCol(Ri,Ci);
        cout<<'*';
        Ci++;
    }
        }

//    int ri=(((ss-1)/10)*rdim)+4;
//    int ci=(((ss-1)%10)*cdim)+10;
//
//    int rr=(((se-1)/10)*rdim)+5;
//    int cc=(((se-1)%10)*cdim)+10;


//    int scale=(rr-ri)/2;
//    int R=(rr+ri)/2;
//    int H=-(cc-ci);
//    int Dtheta=180/H;
//
//    int Ci=ci;
//        for(float theta=270;theta<=450;theta+=Dtheta)
//    {
//
//        int Ri=scale*(sin(theta*3.14/180))+R;
//        gotoRowCol(Ri,Ci);
//        cout<<'*';
//        Ci++;
//    }
    }
}

void display_ledders_on_board(int ladders[][2],int no_of_ledders,int rdim,int cdim)
{
    for(int i=0;i<no_of_ledders;i++)
    {
        int sl=ladders[i][0];
        int el=ladders[i][1];

        sl=101-sl;
        el=101-el;
        number_to_box_no(sl);
        number_to_box_no(el);

    int ri=(((sl-1)/10)*rdim)+1;
    int ci=(((sl-1)%10)*cdim)+1;

    int rr=(((el-1)/10)*rdim)+1;
    int cc=(((el-1)%10)*cdim)+1;

    int cd=ci+(cdim/2);

    for(int k=ri;k>rr;k--)
    {
        if(k%3==0)
        {
            gotoRowCol(ri,ci);
            cout <<'*';
            int ccc=ci+1;
            gotoRowCol(ri,ccc);
            cout <<'*'<<'*';
            gotoRowCol(ri,cd);
            cout <<'*';
            ri--;
            ci++;
            cd++;
        }
        else
        {
            gotoRowCol(ri,ci);
            cout <<'*';
            gotoRowCol(ri,cd);
            cout <<'*';
            ri--;
            ci++;
            cd++;
        }
    }


    }

}
void Snake_boxes_array(int rdim,int cdim,char s,int no_of_snakes, int snakes[][2])
{
    int r=rdim,c=cdim*12,no_snakes;
    gotoRowCol(r-3,c+4);
    cout <<"Snakes";
    gotoRowCol(r-1,c+1);
    cout <<"Start";
    gotoRowCol(r-1,r+9);
    ifstream reader("snakes.txt");
    reader>>no_snakes;
    for(int i=0;i<no_snakes;i++)
    {
        print_box(r,c,rdim,cdim,s);
        reader>>snakes[i][0];
        gotoRowCol(r+3,c+2);
        cout<<snakes[i][0];
        c+=cdim;
        print_box(r,c,rdim,cdim,s);
        reader>>snakes[i][1];
        gotoRowCol(r+3,c+3);
        cout<<snakes[i][1];
        r+=rdim;
        c-=cdim;
    }
}
void Ladder_boxes_print(int rdim,int cdim,char s,int bo_of_ladders, int Ladders[][2])
{

    int r=rdim,c=cdim*15,no_ladders;
    gotoRowCol(r-3,c+4);
    cout<<"Ladders";
    gotoRowCol(r-1,c+1);
    cout<<"Start";
    gotoRowCol(r-1,c+9);
    cout<<"End";
    ifstream reader("Ledder.txt");
    reader>>no_ladders;
    for(int i=0;i<=no_ladders;i++)
    {
        print_box(r,c,rdim,cdim,s);
        reader>>Ladders[i][0];
        gotoRowCol(r+3,c+2);
        cout<<Ladders[i][0];
        c+=cdim;
        print_box(r,c,rdim,cdim,s);
        reader>>Ladders[i][1];
        gotoRowCol(r+3,c+3);
        cout<<Ladders[i][1];
        r+=rdim;
        c-=cdim;
    }
}

bool check_for_snakes(int &player_position,int snakes[][2],int no_of_snakes)
{
    for(int s=0;s<no_of_snakes;s++)
    {
        if((snakes[s][0])==player_position)
        {
            player_position=snakes[s][1];
            return true;
        }
    }
    return false;
}
bool check_for_ledders(int &player_position,int ledders[][2],int no_of_ledders)
{
    for(int s=0;s<no_of_ledders;s++)
    {
        if((ledders[s][0])==player_position)
        {
            player_position=ledders[s][1];
            return true;
        }
    }
    return false;
}



int main()
{
    int rows=100;
    int cols=120;
    int rdim=rows/13;
    int cdim=cols/13;
    int no_of_players;
    cout <<"enter no of players"<<endl;
    cin >>no_of_players;
    char symbol_of_players[no_of_players];
    for(int i=0;i<no_of_players;i++)
    {
        cout <<"enter symbol of player"<<i+1<<endl;
        cin >>symbol_of_players[i];
    }
    system("CLS");
    int winner[no_of_players];
    int w=0;
    int players_position[no_of_players];
    int turn=0;
    int dice=1;


    int no_of_snakes;
    int no_of_ladders;
    ifstream snakes_reader("snakes.txt");
    snakes_reader >>no_of_snakes;
    ifstream ladders_reader("ledders.txt");
    ladders_reader >>no_of_ladders;
    int snakes[no_of_snakes][2];
    int r=30,c=130;

    for(int i=0;i<no_of_snakes;i++)
    {
        snakes_reader >>snakes[i][0]
                        >>snakes[i][1];
    }


    int ladders[no_of_ladders][2];
    int rr=40,cc=130;
    for(int i=0;i<no_of_ladders;i++)
    {
        ladders_reader >>ladders[i][0]
                        >>ladders[i][1];
    }
    int srand(time(0));
    initialize_players_position(players_position,no_of_players);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    grid_printer(rdim,cdim,-37);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    print_box_no(rdim,cdim);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    Snake_boxes_array(rdim,cdim,-37,no_of_snakes,snakes);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    Ladder_boxes_print(rdim,cdim,-37,no_of_ladders, ladders);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    display_snakes_on_board(snakes,no_of_snakes,rdim,cdim);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    display_ledders_on_board(ladders,no_of_ladders,rdim,cdim);
    do
    {
        gotoRowCol(30,125);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
        cout <<"turn : "<<turn+1<<endl;
        gotoRowCol(32,125);
        cout <<"press any key for dice roll"<<endl;
        getch();
        dice=roll_dice();
        gotoRowCol(55,122);
        cout <<"press any key to change your position"<<endl;
        getch();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
        display_players_position_on_board(players_position[turn],' ',rdim,cdim);
        change_players_position(players_position[turn],dice);
        PLayer_Position_Show(rdim,cdim,-37,no_of_players, players_position,symbol_of_players);
        display_players_position_on_board(players_position[turn],symbol_of_players[turn],rdim,cdim);
        int previous_position=players_position[turn];
        if(check_for_snakes(players_position[turn],snakes,no_of_snakes))
        {
            cout <<"\b"<<endl;
            display_players_position_on_board(previous_position,' ',rdim,cdim);
            display_players_position_on_board(players_position[turn],symbol_of_players[turn],rdim,cdim);
        }
        previous_position=players_position[turn];
        if(check_for_ledders(players_position[turn],ladders,no_of_ladders));
        {
            cout <<"\b"<<endl;
            display_players_position_on_board(previous_position,' ',rdim,cdim);
            display_players_position_on_board(players_position[turn],symbol_of_players[turn],rdim,cdim);
        }
        if(players_position[turn]==99)
        {
            winner[w]=turn;
            w++;
        }
        do
        {
            change_player_turn(no_of_players,turn);
        }
        while(players_position[turn]==100);

    }
    while(w<no_of_players-1);

    winner[w]=turn;
    system("CLS");
    gotoRowCol(40,1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);

    for(int i=0;i<no_of_players;i++)
    {
        cout <<"winner"<<i+1<<" : "<<winner[i]<<endl;
        cout <<endl;
    }



    return 0;
}
