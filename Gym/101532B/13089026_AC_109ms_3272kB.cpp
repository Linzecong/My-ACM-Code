#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int N,M;
int T;
int a[10005];

int main(){
	scanf("%d",&T);while(T--){
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)scanf("%d",&a[i]);
		int noti = 0; while(a[noti]==-1)noti++;
		int A = noti-1; while(A >= 0){a[A] = ((a[A+1]+M)%M-1+M)%M;A--;}
		int B = noti+1; while(B < N){a[B] = ((a[B-1]+M)%M+1+M)%M;B++;}
		for(int i=0;i<N;i++)printf("%d%c",a[i],i==N-1?'\n':' ');
	}
    return 0;
}
