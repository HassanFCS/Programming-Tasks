#include <iostream>

using namespace std;

int BinSearch(int A[],int S,int E,int N){
    if(S>E)     // Base case
        return -1;
    int m=(S+E)/2;
    if(A[m]==N) // Base case
        return m;
    else if(A[m]>N)
        BinSearch(A,S,m-1,N);
    else if(A[m]<N)
        BinSearch(A,m+1,E,N);
}

int GCD(int a, int b,int m){
    if(a%m==0 && b%m==0)
        return m;
    else
        GCD(a,b,m-1);
}

int GCD2(int a,int b){
    int rem;
    if(a%b==0)
        return b;
    else{
        rem=a%b;
        GCD2(b,rem);
    }
}

int Power(int a, int b){
    if(b==1)
        return a;
    else
        return a*Power(a,b-1);
}

int FP(int x,int y){
    if(y==0)
        return 1;
    int res=FP(x,y/2);
    if(y%2==0)
        res=res*res;
    else
        res=x*(res*res);
}

int main()
{
                //Binary Search
    cout << "\t\t\t\t\t Binary Search \n";
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int n,s=0,e=9; //  s is Starting Index & e is Ending Index.
    cin >> n;
    cout << BinSearch(A,s,e,n);
                //Greatest Common Deviser
    cout << "\n\n\n";
    cout << "\t\t\t\t\t GCD \n";
    int x,y;
    cin >> x >> y;
    cout << "\nGCD : " << GCD(x,y,x);
    cout << "\nGCD : " << GCD2(x,y);
                //Power
    cout << "\n\n\n";
    cout << "\t\t\t\t\t Power \n";
    cin >> x >> y;
    cout << "\nPower : " << Power(x,y);
}
