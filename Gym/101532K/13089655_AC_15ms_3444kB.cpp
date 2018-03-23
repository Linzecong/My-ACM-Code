#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
ll fac[15];

int T;
char s[30];

int cnt[30];

void init(){
	fac[1]=1;
	for (int i=2; i<=13; i++){
		fac[i]=fac[i-1]*i;
	}
}

int main(){
	cin>>T;
	init();
	while(T--){
		int n; cin>>n;
		memset(cnt,0,sizeof(cnt));
		cin>>s;
		int flag=0;
		for (int i=0; s[i]; i++){
			cnt[s[i]-'a']++;
		}
		for (int i=0; i<26; i++){
			if (cnt[i]%2==1) flag++;
		}
		
		ll ans=0;
		if (n%2==0){
			if (flag!=0) ans=0;
			else{
				int num=0;
				int chu=1;
				for (int i=0; i<26; i++){
					if (cnt[i]==0) continue;
					num++;
					chu*=fac[cnt[i]/2];
				}
				ans=fac[n/2]/chu;
			}
		}
		else if (n%2==1){
			if (flag==0||flag>1) ans=0;
			else{
				for (int i=0; i<26; i++){
					if (cnt[i]%2==1){
						cnt[i]--;
						break;
					}
				}
				int num=0;
				int chu=1;
				for (int i=0; i<26; i++){
					if (cnt[i]==0) continue;
					num++;
					chu*=fac[cnt[i]/2];
				}
				ans=fac[(n-1)/2]/chu;
			}
		}
		if (n==1) ans=1;
		cout<<ans<<endl;
	}

	return 0;
}
