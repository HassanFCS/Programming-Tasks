#include "iostream"
#include "fstream"
#include "string"
#include "vector"
using namespace std;

int Rows, Cols;
int **TT;
int **BigArray;
int *FinalStates;
vector <vector<int>> CompactedArray;
vector <int> Hashmap;

void Read(){
	ifstream fin("Table.txt");
	fin >> Rows;
	fin >> Cols;
	TT = new int*[Rows + 1];
	for (int i = 0; i < Rows + 1; i++)
		TT[i] = new int[Cols + 1];
	for (int i = 0; i < Rows + 1; i++){
		for (int j = 0; j < Cols + 1; j++){
			fin >> TT[i][j];
		}
	}

	/*cout << Rows << '\t' << Cols << '\n';
	for (int i = 0; i < Rows + 1; i++){
		for (int j = 0; j < Cols + 1; j++){
			cout << TT[i][j] << '\t';
		}
		cout << '\n';
	}*/
}

void CreateBigArray(){
	BigArray = new int*[Rows];
	for (int i = 0; i < Rows; i++)
		BigArray[i] = new int[128];
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < 128; j++){
			BigArray[i][j] = -1;
		}
	}
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			BigArray[i][TT[0][j]] = TT[i + 1][j];
		}
	}
	/*for (int i = 0; i < 128; i++)
	cout << i << '\t';
	cout << '\n';
	for (int i = 0; i < Rows; i++){
	for (int j = 0; j < 128; j++){
	cout << BigArray[i][j] << '\t';
	}
	cout << "\n\n\n\n\n";
	}*/
}

void SetFinalStates(){
	FinalStates = new int[Rows];
	for (int i = 0; i < Rows; i++){
		FinalStates[i] = TT[i + 1][Cols];
		//cout << FinalStates[i] << '\n';
	}
}

void ColumnCompaction(){
	Hashmap.resize(128);
	vector <int> Temp;
	bool change = true;
	for (int j = 0; j < Rows; j++){
		Temp.push_back(-1);
	}
	int Count = 0;
	CompactedArray.push_back(Temp);	
	int RepeatedCol=0;
	for (int i = 0; i < 128; i++){
		for (int k = 0; k < CompactedArray.size(); k++){
			for (int j = 0; j < Rows; j++){
				if (CompactedArray[k][j] == BigArray[j][i]){
					Count++;
				}
				else
					break;
			}
			if (Count == Rows){
				change = false;
				RepeatedCol = k;
				break;
			}
			else{
				change = true;
			}
			Count = 0;
		}
		if (change){
			Temp.clear();
			for (int j = 0; j < Rows; j++){
				Temp.push_back(BigArray[j][i]);
			}
			CompactedArray.push_back(Temp);
			Hashmap[i] = CompactedArray.size() - 1;
		}
		else
			Hashmap[i] = RepeatedCol;
		change = true;
		Count = 0;
	}
	for (int i = 0; i < Hashmap.size(); i++)
		cout << i << " " << Hashmap[i] << '\n';
	for (int i = 0; i < CompactedArray.size(); i++){
		cout << i << " : ";
		for (int j = 0; j < CompactedArray[i].size(); j++)
			cout << CompactedArray[i][j] << ' ';
		cout << '\n';
		cout << "\n\n";
	}
}


void LexicalAnalyzer(){
	int LS = 0, Remember = -1, Forward = 0, Current = 0, LSFV = -1;
	ifstream fin("Input.txt");
	string Str;
	getline(fin, Str, '\0');
	cout << Str << "\n\n";
	for (Forward= 0; Forward < Str.length();){
		int AN = int(Str[Forward]);
		Current = CompactedArray[Hashmap[AN]][Current];
		if (Current != -1){
			Forward++;
		}
		if (Current > -1){
			if (FinalStates[Current] != -1){
				LSFV = FinalStates[Current];
				Remember = Forward - 1;
			}
		}

		if (Current == -1 && LSFV == -1){
			cout << "<";
			for (int i = LS; i <= Forward; i++){
				cout << Str[i];
			}
			cout << ",Error>" << "\n\n";
			LS = Forward + 1;
			Remember = -1;
			Forward = Forward + 1;
			if (Forward > Str.length() - 1){
				break;
			}
			Current = 0;
		}
		else if (Current == -1 && LSFV != -1){
			cout << "<";
			for (int i = LS; i <= Remember; i++)
			{
				cout << Str[i];
			}
			cout << "," << LSFV << ">" << "\n\n";
			Forward = Remember + 1;
			LS = Remember + 1;
			Current = 0;
			LSFV = -1;
			Remember = -1;
		}
		if (Forward >= Str.length()){
			cout << "<";
			for (int i = LS; i <= Remember; i++)
			{
				cout << Str[i];
			}
			cout << "," << LSFV << ">" << '\n';
			Forward = Remember + 1;
			LS = Remember + 1;
			Remember = -1;
			LSFV = -1;
			Current = 0;
		}
	}
}

int main(){
	Read();
	CreateBigArray();
	SetFinalStates();
	ColumnCompaction();
	LexicalAnalyzer();
	system("PAUSE");
	return 0;
}