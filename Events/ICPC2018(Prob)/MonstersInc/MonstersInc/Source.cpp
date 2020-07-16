#include<map>
#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

void PrintVec(vector<int> & A)
{
	for (auto i : A)
	{
		cout << i<<" ";
	}
}

struct Coordinate
{
	int Px;
	int Py;

	bool operator<(const Coordinate & B) const
	{
		return this->Px<B.Px;
	}
	bool operator==(const Coordinate & B) const
	{
		return this->Px == B.Px && this->Py == B.Py;
	}
};


int maxValue(vector<int>  Vs)
{
	int max = Vs[0];
	for (int i = 1; i < Vs.size(); i++)
	{
		if (max < Vs[i])
			max = Vs[i];
	}
	return max;
}


pair<Coordinate, int> FindMaxRadAndCount(map<Coordinate, vector<int>> M,int &R)
{
	auto i = M.begin();
	auto maxi = M.begin();
	int maxV = i->second.size();
	for (; i != M.end(); i++)
	{
		if (maxV < i->second.size())
		{
			maxi = i;
			maxV = i->second.size();
		}
		else if (maxV == i->second.size())
		{
			// Which one is closer to origin
			int dissqrMax = maxi->first.Px * maxi->first.Px + maxi->first.Py * maxi->first.Px;
			int dissqrI = i->first.Px * i->first.Px + i->first.Py * i->first.Px;
			if (dissqrMax > dissqrI)
			{
				maxi = i;
				maxV = i->second.size();
			}
		}
	}
	R = maxValue(maxi->second);
	return pair<Coordinate, int>(maxi->first, maxi->second.size()-1);
}

int main1()
{
	int T;
	int N;
	ifstream fin("M.txt");
	fin >> T;
	for (int t = 1; t <= T; t++)
	{
		map<Coordinate, vector<int>> Rs;
		fin >> N;
		int Px, Py, R;
		Coordinate C;
		for (int i = 1; i <= N; i++)
		{
			fin >> Px >> Py >>R;
			C.Px = Px;
			C.Py = Py;

			Rs[C].push_back(R);
		}

		pair<Coordinate, int> Ans = FindMaxRadAndCount(Rs, R);
		cout << "Case " << t << ":" << Ans.first.Px << " " << Ans.first.Py << " " << R << " " << Ans.second << endl;
	}
	return 0;
}


struct Coordinate2
{
	int Px;
	int Py;
	int R;

};

double Dist(int x1, int x2, int y1, int y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}



pair<Coordinate2, int> FindMaxRadAndCount2(vector<Coordinate2> &  M)
{
	auto maxi = 0;
	int maxV = 0;
	for (int i = 0; i<M.size(); i++)
	{
		int Count = 0;
		for (int j = 0; j < M.size(); j++)
		{
			if (i == j) continue;
			if (M[i].R >= Dist(M[j].Px, M[i].Px, M[j].Py, M[i].Py) + M[j].R)
			{
				Count++;
			}		
		}
		if (maxV < Count)
		{
			maxi = i;
			maxV = Count;
		}
		else if (maxV == Count)
		{
			// Which one is closer to origin
			int dissqrMax = M[maxi].Px * M[maxi].Px + M[maxi].Py * M[maxi].Px;
			int dissqrI = M[i].Px * M[i].Px + M[i].Py * M[i].Px;

			if (dissqrMax > dissqrI)
			{
				maxi = i;
			}
		}
	}
	
	return pair<Coordinate2, int>(M[maxi], maxV);
}

int main()
{
	int T;
	int N;
	ifstream fin("M.txt");
	fin >> T;
	for (int t = 1; t <= T; t++)
	{
		vector<Coordinate2> Rs;
		fin >> N;
		int Px, Py, R;
		Coordinate2 C;
		for (int i = 1; i <= N; i++)
		{
			fin >> Px >> Py >> R;
			C.Px = Px;
			C.Py = Py;
			C.R = R;
			Rs.push_back(C);
		}

		pair<Coordinate2, int> Ans = FindMaxRadAndCount2(Rs);
		cout << "Case " << t << ":" << Ans.first.Px << " " << Ans.first.Py << " " << Ans.first.R << " " << Ans.second << endl;
	}
	return 0;
}