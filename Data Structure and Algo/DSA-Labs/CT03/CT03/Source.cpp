#include "iostream"

using namespace std;

class Term{
public:
	int Coefficient;
	int Power;
	Term *Next;
	Term(int C=0, int P=0,Term *N=NULL){
		Coefficient = C;
		Power = P;
		Next = N;
	}
};

class Polynomial{
	Term *T;
public:
	Polynomial(int C[], int P[], int Size){
		T = new Term(C[0], P[0]);
		Term *Temp = T;
		for (int i = 1; i < Size; Temp = Temp->Next, i++)
			Temp->Next = new Term(C[i], P[i]);
	}

	void AddTerms(int C, int P){
		Term *Temp=T;
		bool Flag = true;
		for (Temp; Temp->Next != NULL; Temp = Temp->Next)
			if (Temp->Power == P){
				Temp->Coefficient += C;
				Flag = false;
				break;
			}
		if (Flag){
			Temp = T;
			for (Temp; Temp->Next != NULL; Temp = Temp->Next){
				if (Temp->Power > P){
					Term *STemp = Temp->Next;
					Temp->Next = new Term(C, P);
					T->Next->Next = STemp;
					Flag = false;
					break;
				}
			}
		}
		if (Flag){
			//Temp = T;
			T = new Term(C, P,T);
			//T->Next = Temp;
		}
	}
};

int main(){
	int a[] = { 1, 2, 3, 4, 5 }, b[] = { 2, 3, 4, 5, 6 };
	Polynomial pol(a, b, 5);
	pol.AddTerms(2, 1);
	return 0;
}