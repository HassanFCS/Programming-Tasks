#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	for (int qq = 1; qq <= tt; qq++) {
		cout << "Case #" << qq << ": ";
		int n;
		cin >> n;
		const int ALPHA = 26;
		vector<vector<int>> trie;
		trie.emplace_back(ALPHA, -1);
		vector<int> visits(1, 0);
		vector<int> pv(1, -1);
		while (n--) {
			string s;
			cin >> s;
			int t = 0;
			for (char c : string(s.rbegin(), s.rend())) {
				int d = (int)(c - 'A');
				if (trie[t][d] == -1) {
					trie[t][d] = (int)trie.size();
					trie.emplace_back(ALPHA, -1);
					visits.push_back(0);
					pv.push_back(t);
				}
				t = trie[t][d];
				visits[t]++;
			}
		}
		int ans = 0;
		for (int i = (int)trie.size() - 1; i >= 0; i--) {
			if (visits[i] < 2) {
				continue;
			}
			ans++;
			int v = i;
			while (v != -1) {
				visits[v] -= 2;
				v = pv[v];
			}
		}
		cout << 2 * ans << '\n';
	}
	return 0;
}
