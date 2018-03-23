#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int T;
int n,m;
// if the first player wins.
bool decide(int n,int m){
	if(n==0&&m==0)return false;
	if(n==0)return m%2;
	if(m==0)return n%2;
	
	int MIN = min(n,m);
	if(MIN%2)return true;
	else {
		if(MIN==n)return(m-MIN)%2;
		else return(n-MIN)%2;
	}
}
int main(){
	scanf("%d",&T);while(T--){
		scanf("%d%d",&n,&m);
		if(n==0){
			printf(m%2?"hasan\n":"abdullah\n");
		} else if(m==0){
			printf(n%2?"hasan\n":"abdullah\n");
		} else {
			printf(decide(n,m)?"hasan\n":"abdullah\n");
		}
	}
}