#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <windows.h>
#include<conio.h>
using namespace std;

ostream& operator<<(ostream &out, vector <vector <int>>&Puzzle){
	for (int i = 0; i < Puzzle.size(); i++){
		for (int j = 0; j < Puzzle[i].size(); j++)
			out << Puzzle[i][j] << "\t\t";
		out << "\n\n";
	}
	return out;
}

ostream& operator<<(ostream &out, stack <vector <vector <int>>>SolStates){
	while (!SolStates.empty()){
		Sleep(2000);
		system("cls");
		cout << SolStates.top();
		SolStates.pop();
	}
	return out;
}

struct PuzzleNode{
	vector<vector <int>> Node;	
	int ri, ci;
	int Distance;
	PuzzleNode(int r, int c, vector <vector <int>>N, vector<vector <int>>S){
		Node = N;
		ri = r;
		ci = c;
		ComputeDistance(S);
	}
	void ComputeDistance(vector<vector <int>>Sol){
		Distance = 0;
		for (int i = 0; i < Node.size(); i++)
			for (int j = 0; j < Node[i].size(); j++)
				if (Node[i][j] != Sol[i][j])
						Distance++;
	}
	bool operator<(PuzzleNode NewPuzzle){
		if (Distance < NewPuzzle.Distance)
			return true;
		return false;
	}
};


class GenericPuzzle{
	vector <vector<int>> Puzzle;
	vector <vector<int>> Solution;
	vector <vector<vector <int>>> PreviousStates;
	stack <vector<vector <int>>> SolutionStates;
	int NowDepth;
	int LimitDepth;

	void FindZero(int &i, int &j){
		for (int k = 0; k < Puzzle.size(); k++){
			for (int l = 0; l < Puzzle[k].size(); l++){
				if (Puzzle[k][l] == 0){
					i = k;
					j = l;
					return;
				}
			}
		}
	}

	bool InPrevious(vector <vector <int>> & M){
		for (int i = 0; i < PreviousStates.size(); i++){
			if (PreviousStates[i] == M)
				return true;
		}
		return false;
	}

	void PrintMap(vector <vector <int>> &M)
	{
		for (int ri = 0; ri < M.size(); ri++)
		{
			for (int ci = 0; ci < M[ri].size(); ci++)
				cout << M[ri][ci] << " ";
			cout << endl;
		}
	}
	
	bool CallRecursive(int ri, int ci, int ori, int oci){
		PreviousStates.push_back(Puzzle);
		swap(Puzzle[ri][ci], Puzzle[ori][oci]);
		NowDepth++;
		bool GotSolution  = DFID(ri, ci);
		if (GotSolution)
			SolutionStates.push(Puzzle);
		NowDepth--;
		swap(Puzzle[ri][ci], Puzzle[ori][oci]);
		return GotSolution;
	}

	void ASFilling(int ri, int ci, int ori, int oci, vector <PuzzleNode> &T){
//		PreviousStates.push_back(Puzzle);
		swap(Puzzle[ri][ci], Puzzle[ori][oci]);
		PuzzleNode Sample(ri, ci, Puzzle, Solution);
		T.push_back(Sample);
		swap(Puzzle[ri][ci], Puzzle[ori][oci]);
	}

	bool DFID(int ri, int ci){
		if (Puzzle == Solution)
			return true;
		if (InPrevious(Puzzle))
			return false;
		if (NowDepth > LimitDepth)
			return false;
		bool GotSolution = false;
		if (ri > 0)  //  Top  ^
			GotSolution = CallRecursive(ri - 1, ci, ri, ci);
		if (!GotSolution && ri < Puzzle.size() - 1)	//  down \/
			GotSolution = CallRecursive(ri + 1, ci, ri, ci);
		if (!GotSolution && ci > 0)				  // Left <
			GotSolution = CallRecursive(ri, ci - 1, ri, ci);
		if (!GotSolution && ci < Puzzle.size() - 1) 	// Right >
			GotSolution = CallRecursive(ri, ci + 1, ri, ci);
		return GotSolution;
	}

	bool BFS(int ri, int ci){
		if (Puzzle == Solution)
			return true;
		if (InPrevious(Puzzle))
			return false;
		if (NowDepth > LimitDepth)
			return false;
		PreviousStates.push_back(Puzzle);
		vector <PuzzleNode> Tree;
		bool GotSolution = false;
		if (ri > 0)  //  Top  ^
			ASFilling(ri - 1, ci, ri, ci, Tree);
		if (!GotSolution && ri < Puzzle.size() - 1)	//  down \/
			ASFilling(ri + 1, ci, ri, ci, Tree);
		if (!GotSolution && ci > 0)				  // Left <
			ASFilling(ri, ci - 1, ri, ci, Tree);
		if (!GotSolution && ci < Puzzle.size() - 1) 	// Right >
			ASFilling(ri, ci + 1, ri, ci, Tree);
		sort(Tree.begin(), Tree.end());
		for (int i = 0; i < Tree.size(); i++){
			/*if (InPrevious(Puzzle))
				cout << Tree[i].Node << "\n\n";
			_getch();*/
			Puzzle = Tree[i].Node;
			NowDepth++;
			GotSolution = BFS(Tree[i].ri, Tree[i].ci);
			if (GotSolution){
				SolutionStates.push(Tree[i].Node);
				return true;
			}
			NowDepth--;
//			Tree.clear();
		}
		return GotSolution;
	}

public:
	GenericPuzzle(int D=10){
		ifstream fin("Given.txt");
		int row, col, val;
		LimitDepth = D;
		NowDepth = 0;
		fin >> row >> col;
		for (int i = 0; i < row; i++){
			vector <int> Samp(row);
			for (int j = 0; j < col; j++){
				fin >> val;
				Samp[j] = val;
			}
			Puzzle.push_back(Samp);
		}
		fin.close();
		/*cout << "Starting Stage of the Puzzle.\n\n";
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				cout << Puzzle[i][j] << '\t';
			}
			cout << '\n';
		}*/
		ifstream Sin("Goal.txt");
		Sin >> row >> col;
		for (int i = 0; i < row; i++){
			vector <int> Samp(row);
			for (int j = 0; j < col; j++){
				Sin >> val;
				Samp[j] = val;
			}
			Solution.push_back(Samp);
		}
		Sin.close();
		/*cout << "Goal Stage of the Puzzle.\n\n";
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				cout << Solution[i][j] << '\t';
			}
			cout << '\n';
		}*/
	}



	void PrintSolutionUsingDFID(){
		int i, j;
		FindZero(i, j);
		
		//PrintMap(Solution);

		//_getch();

		while (!SolutionStates.empty())
			SolutionStates.pop();
		cout << "We are Using Depth First Iterative Deeping.\n\n";
		cout << "Given Puzzle\n";
		cout << Puzzle << "\n\n";
		cout << "Given Solution\n";
		cout << Solution << "\n\n";
		if (DFID(i, j)){
			cout << "I Got The Solution\n\nEnter to see the solution\n\n";
			system("PAUSE");
			cout << SolutionStates;
		}
		else{
			cout << "Can't find the Solution Till Depth = " << LimitDepth << "\n\n";
		}
	}

	void PrintSolutionUsingBFS(){
		int i, j;
		FindZero(i, j);

		//PrintMap(Solution);

		//_getch();
		while (!SolutionStates.empty())
			SolutionStates.pop();
		cout << "We are Using Best First Search.\n\n";
		cout << "Given Puzzle\n";
		cout << Puzzle << "\n\n";
		cout << "Given Solution\n";
		cout << Solution << "\n\n";
		if (BFS(i, j)){
			cout << "I Got The Solution\n\nEnter to see the solution.\n\n";
			system("PAUSE");
			cout << SolutionStates;
		}
		else{
			cout << "Can't find the Solution Till Depth = " << LimitDepth << "\n\n";
		}
	}
};

int main(){
	GenericPuzzle Puzzle1(6);
	Puzzle1.PrintSolutionUsingDFID();
	Sleep(2000);
	system("cls");
	GenericPuzzle Puzzle2(6);
	Puzzle2.PrintSolutionUsingBFS();
	system("PAUSE");
	return 0;
}