#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int T;
int N;
int F[100005];
char S[105];

int main(){
	scanf("%d",&T);while(T--){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		int MINN = min(a,min(b,c));
		if(MINN==a)puts("First");
		else if(MINN==b)puts("Second");
		else puts("Third");
	}
	return 0;
}