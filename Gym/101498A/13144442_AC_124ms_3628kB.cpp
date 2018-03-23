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
		memset(F,0,sizeof(F));
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%s",S);
			int x;scanf("%d",&x);F[x]++;
		}
		int maxi=0; for(int i=11111;i<=99999;i++){
			if(F[maxi]<F[i])maxi = i;
		}
		printf("%d\n",maxi);
	}
	return 0;
}