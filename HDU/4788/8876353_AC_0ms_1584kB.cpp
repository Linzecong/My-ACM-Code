#include <bits/stdc++.h>
using namespace std;
int T,n;
char s[10];
char s_list[]="KMGTPEZY";

double get_pow(){
	if(strlen(s)==1){
		return 0.0;
	}
	else{
		for(int i=0;i<8;i++){
			if(s_list[i]==s[0]){
				return i+1.0;
			}
		}
	}
	return 0.0;
}

double solve(){
	double p=get_pow();
	return (1.0-pow(1000.0/1024.0,p))*100.0;
}
int main(int argc, char** argv) {
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d[%s]",&n,s);
		printf("Case #%d: %.2f%%\n",t,solve());
	}
	return 0;
}