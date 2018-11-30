#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, len, idx;
string s;
set<string> st[10];

void dfs(string m, int fa, int start) {
	st[idx].insert(m);
	for(int i = start + 1; i < s.length() && i < fa + len; i++) {
		dfs(m + s[i], fa, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	while(cin >> n) {
		for(idx = 0; idx < n; idx++) {
			cin >> s;
			len = s.length();
			s = s + s;
			for(int i = 0; i < len; i++) {
				dfs(s.substr(i, 1), i, i);
			}
		}
		string ans = "0";
		for(auto i : st[0]) {
			bool flag = 0;
			for(int j = 1; j < n; j++) {
				if(!st[j].count(i)) {
					flag = 1;
					break;
				}
			}
			if(!flag) {
				if(ans[0] == '0'){
					ans = i;
					continue;
				}
				if(i.length() > ans.length()) {
					ans = i;
				} else if(i.length() == ans.length()) {
					ans = min(ans, i);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			st[i].clear();
		}
		cout << ans << endl;
	}
	return 0;
}
