#include<iostream>
#include<map>
using namespace std;
const int MOD=1e9+7;
typedef long long int ll;
int N;
int M;

int f[50][7];

map<ll,int> ans1;


long long qpow(long long x,int n)  
{  
    long long y=1;  
    long long u=x%MOD;  
    while(n)  
    {  
        if(n&1) y=y*u%MOD;  
        n>>=1;  
        u=u*u%MOD;  
    }  
    return y;  
} 
 
ll ans=0;
void dfs1(int x,int num,ll cur){
	if(x>N/2)
		return;
		
	cur=cur*f[x][num]%MOD;
	
	if(x==N/2)
		ans1[cur]++;
	
		
	
	for(int j=1;j<=6;j++)
		dfs1(x+1,j,cur);
}

void dfs2(int x,int num,ll cur){
	if(x>N)
		return;
		
	cur=cur*f[x][num]%MOD;
	
	if(x==N){
		ans+=(ans1[M*qpow(cur,MOD-2)%MOD]);
		//ans2[cur]++;
	}
		
	
	for(int j=1;j<=6;j++)
		dfs2(x+1,j,cur);
}


inline void scan_d(int &ret) 
{
    char c; 
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    { 
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main(){
	
	
	int T;
	scan_d(T);
	while(T--){
		
		scan_d(N);
		scan_d(M);
		ans1.clear();
		ans=0;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=6;j++)
				scan_d(f[i][j]);
		
		for(int i=1;i<=6;i++)
			dfs1(1,i,1);
		
		for(int i=1;i<=6;i++)
			dfs2(N/2+1,i,1);
			
		printf("%lld\n",ans);
	
		
	}
	
	
	return 0;
}
