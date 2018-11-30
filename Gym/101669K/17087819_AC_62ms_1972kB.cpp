#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=1e5+5;
struct node{
	int id,Num;
	friend bool operator <(node a,node b){
		if (b.Num==a.Num) return a.id>b.id;
		return a.Num>b.Num;
	}
};
int p;
priority_queue<node>Q;
int tot;
int ans[maxn];
int main(){
	int n,w;
	scanf("%d",&n);
	w=n;
	for (int i=1;i<=n;i++){
		scanf("%d",&p);
		Q.push({i,p});
	}
	while (!Q.empty()){
		node w=Q.top();
		Q.pop();
		ans[w.id]=n--;
	}
	for (int i=1;i<=w;i++){
		printf("%d ",ans[i]);
	}
}