#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>G[5];
map<long long,int>M;
bool vis[5];
int num[5],num1[5];
bool dfs(int w){
	vis[w]=true;
	for (int i=0;i<G[w].size();i++){
		if (vis[G[w][i]]) return false;
		if (!dfs(G[w][i])) return false;
	}
	vis[w]=false;
	return true;
}
long long u;
int main(){
	int T,Case=0;
	cin >> T;
	while (T--){
		Case++;
		int ans=0;
		for (int i=1;i<=4;i++)
			cin >> num[i];
		for (int i=0;i<729;i++)
		{
			u=i;
			for (int j=1;j<=4;j++) G[j].clear(),num1[j]=0;
			for (int j=1;j<=3;j++)
				for (int k=j+1;k<=4;k++){
					if (u%3==0)
						G[j].push_back(k),num1[k]+=3;
					else if (u%3==1)
						G[k].push_back(j),num1[j]+=3;
					else 
						num1[k]++,num1[j]++;
					u/=3;
				}
			bool flag=true;
			for (int j=1;j<=4;j++){
				if (num1[j]!=num[j])
				{
					flag=false;
					break;
				}
			}
			if (flag)
				ans++;
		}
		cout << "Case #"<< Case << ": ";
		if (ans){
			if (ans==1){
				cout << "Yes" << endl;
			}
			else cout << "No" << endl;
		}else
			cout << "Wrong Scoreboard" << endl;
	}
} 