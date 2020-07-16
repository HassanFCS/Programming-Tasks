//#include <iostream>
//#include <string>

//using namespace std;

/*int main(){
	int t;
	cin >> t;
	while (t>0){
		t--;
		int n, m;
		char c;
		cin >> n >> m;
		string **a;//[n][m];
		a = new string*[n];
		for (int i = 0; i < n; i++){
			a[i] = new string[m];
		}
		for (int i = 0; i<n; i++){
			for (int j = 0; j<m; j++){
				cin >> a[i][j];
			}
		}

		string k;
		cin >> k;
		int temp = 0;
		for (int i = 0; i<n; i++){
			for (int j = 0; j<m; j++){
				if (a[i][j] == k){
					temp = 1;
					continue;
				}
			}
			if (temp) break;
		}
		if (temp){
			int l = 0, r = 0, flag = 0;
			while (l<n || r<m){
				for (int i = r; i<m; i++){
					cout << a[l][i];
					if (a[l][i] == k){
						flag = 1;
						break;
					}
				}
				l++;
				/*/////////////
/*				if (r<m){
					for (int i = m - 1; i>n; i++){
						cout << a[m-1][i];
						if (a[i][r] == k){
							flag = 1;
							break;
						}
					}
					r++;
				}
				if (flag) break;
				////////////*/
/*				if (flag) break;
				for (int i = l; i<n; i++){
					cout << a[i][m - 1];
					if (a[i][m - 1] == k){
						flag = 1;
						break;
					}
				}
				m--;
				if (flag) break;
				if (l<n){
					for (int i = m-1; i > r; i--){
						cout << a[n - 1][i];
						if (a[n - 1][i] == k){
							flag = 1;
							break;
						}
					}
					n--;
				}
				if (flag) break;
				if (r<m){
					for (int i = n; i>=l; i--){
						cout << a[i][r];
						if (a[i][r] == k){
							flag = 1;
							break;
						}
					}
					r++;
				}
				if (flag) break;
			}
			if (flag)
				cout << "\nNO";
			cout << endl;
		}
		else cout << "NO\n";
	}
	system("PAUSE");
	return 0;
}*/




/*#include <math.h>
#include<iostream>
using namespace std;
int prime(int n){
	int sqt = sqrt(n);
	for (int i = 2; i < sqt; i++){
		if (n%i == 0)
			return -1;
	}
	return 1;
}
int main()
{
	int t, n, i, j, k;
	char a[100000];
	cin >> t;
	while (t--)
	{
		k = 0;
		cin >> n;
		for (i = 0; i<n; i++)
		{
			cin >> a[i];
			j = a[i] - 96;
			k = k + j;
		}

		if (prime(k) == 1)
			cout << "seen" << endl;
		else
			cout << "unseen" << endl;
	}
	return 0;
}*/


#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
	int n, x, y;
	cin >> n >> x >> y;
	int *arr;
	arr = new int[n];
	char map[1000000] = {};

	for (int i = 0; i < n; i++)
		map[i] = '0';


	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}

	sort(arr, arr + n);

	int cost = 0, sumd = 0;

	for (int i = 0; i < n; i++) {
		sumd = 0;
		int j = arr[i];
		if (map[j] == '1') {
			while (map[j] == '1') {
				sumd += y;
				j--;
			}
		}
		map[j] = '1';
		if (sumd > x)
			cost += x;
		else
			cost += sumd;
	}

	cout << cost << endl;
	system("PAUSE");
	return 0;
}