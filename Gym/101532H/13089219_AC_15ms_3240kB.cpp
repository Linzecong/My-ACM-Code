#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int N,M;
int T;
char buf[55][55];
int main(){
	scanf("%d",&T);while(T--){
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)scanf("%s",&buf[i]);
		int cnti = 0; for(int i=0;i<N;i++)for(int j=0;j<M;j++)cnti+=buf[i][j]-'0';
		if(cnti<N+N+M+M-4)printf("-1\n");
		else {
			int X = 0;
			for(int i=1;i<M-1;i++){
				if(buf[0][i]=='0')X++;
				if(buf[N-1][i]=='0')X++;
			}
			for(int i=1;i<N-1;i++){
				if(buf[i][0]=='0')X++;
				if(buf[i][M-1]=='0')X++;
			}
			if(buf[0][0]=='0')X++;
			if(buf[0][M-1]=='0')X++;
			if(buf[N-1][0]=='0')X++;
			if(buf[N-1][M-1]=='0')X++;
			printf("%d\n",X);
		}
	}
    return 0;
}
