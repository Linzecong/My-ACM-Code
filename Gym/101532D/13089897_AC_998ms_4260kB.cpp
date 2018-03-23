#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;



int T;
int n,q;
char buf[10005];
char buf2[5];
int psum[26][10005];

int getx(int i,char t){
	i--;
	return ((i/n)*psum[t-'a'][n-1]) + (psum[t-'a'][i%n]);
}

int main(){
	scanf("%d",&T);while(T--){
		memset(psum,0,sizeof(psum));
		scanf("%d%d%s",&n,&q,buf);
		psum[buf[0]-'a'][0] = 1;
		for(int i=0;i<n;i++){
			char X = buf[i]-'a';
			for(int k='a';k<='z';k++){
				psum[k-'a'][i] = psum[k-'a'][i-1];
			}
			psum[buf[i]-'a'][i]++;
		}
		
		for(int i=0;i<q;i++){
			int A,B;scanf("%d%d%s",&A,&B,buf2);
			printf("%d\n",getx(B,buf2[0])-getx(A-1,buf2[0]));
		}
	}
    return 0;
}
