#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
const int maxn=1e3+5;
struct node{
	int x,y,num;
}a[maxn*maxn];
struct Node{
	int x,y;
	bool operator <(const Node& a)const {
		if (a.x==x) return y<a.y;
		return x<a.x;
	}
};
string s;
int n,m;
int tot;
int getnum(){
	int k=0;
	for (int i=0;i<s.length();i++){
		k=k*10+s[i]-'0';
	}
	return k;
}
int main(){
	int T,Case=0;
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		set<Node>S;
		S.clear();
		int n,m;
		Case++;
		tot=0;
		cin >> n >> m;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin >> s;
				if (s!="?"){
					a[++tot].num=getnum();
					a[tot].x=i;
					a[tot].y=j;
				}
			}
		}
		cout << "Case #" << Case << ": " ;
		if (tot==0){
			cout << "Yes" << endl;
			continue;
		}
		int q=sqrt(a[1].num);
		for (int i=1;i<=q;i++){
			if (a[1].num%i==0){
				if (a[1].x<=i&&a[1].y<=a[1].num/i)
					S.insert({i,a[1].num/i});
				if (a[1].y<=i&&a[1].x<=a[1].num/i)
					S.insert({a[1].num/i,i});
			}
		}
		for (int i=2;i<=tot;i++){
			set<Node>S1;
			S1.clear();
			for (auto u:S){
				int h=a[i].x-a[1].x;
				int d=a[i].y-a[1].y;
				if (u.x*d+u.y*h+h*d==a[i].num-a[1].num){
					S1.insert(u);
				}
			}
			S=S1;
		}
		if (S.size()>0){
			cout << "Yes"<< endl;
		}
		else 
			cout << "No" << endl;
	}
}