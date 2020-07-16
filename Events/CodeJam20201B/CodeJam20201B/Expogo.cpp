#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isPower(long long int n){
	if (n>0){
		while (n % 2 == 0){
			n /= 2;
		}
		if (n == 1){
			return true;
		}
	}
	if (n == 0 || n != 1)
	{
		return false;
	}
}

int main(){
	int TC;
	cin >> TC;
	int CN = 1;
	while (TC--){
		long long int x, y;
		cin >> x >> y;
		long long int mx =0, my = 0;
		if (abs(x) == abs(y))
			cout << "Case #" << CN << ": IMPOSSIBLE\n";
		else{
			int i = 0;
			string Res = "";
			while (mx != x || my != y){
				long long int difx = x - mx;
				long long int dify = y - my;
				if (pow(2, i) == abs(difx)){
					if (difx < 0){
						Res += "W";
						mx -= pow(2, i);
					}
					else{
						Res += "E";
						mx += pow(2, i);
					}
				}
				else if (pow(2, i) == abs(dify)){
					if (dify < 0){
						Res += "S";
						my -= pow(2, i);
					}
					else{
						Res += "N";
						my += pow(2, i);
					}
				}
				else{
					long long int XB1 = x - (mx + pow(2, i));
					long long int XB2 = x - (mx - pow(2, i));
					long long int YB1 = y - (my + pow(2, i));
					long long int YB2 = y - (my - pow(2, i));
					vector <long long int> Vs(4);
					Vs[0] = abs(XB1);
					Vs[1] = abs(XB2);
					Vs[2] = abs(YB1);
					Vs[3] = abs(YB2);
					sort(Vs.begin(), Vs.end());
					long long int Max = -999999;
					for (int j = 3; j >= 0; j--){
						if (isPower(Vs[j])){
							Max = Vs[j];
							break;
						}
					}
					if (abs(XB1) == Max){
						Res += "E";
						mx += pow(2, i);
					}
					else if (abs(XB2) == Max){
						Res += "W";
						mx -= pow(2, i);
					}
					else if (abs(YB1) == Max){
						Res += "N";
						my += pow(2, i);
					}
					else if (abs(YB2) == Max){
						Res += "S";
						my -= pow(2, i);
					}
					else{
						Res = "IMPOSSIBLE";
						break;
					}
				}
				i++;
			}
			cout << "Case #" << CN << ": " << Res << '\n';
		}
		CN++;
	}
	system("PAUSE");
	return 0;
}