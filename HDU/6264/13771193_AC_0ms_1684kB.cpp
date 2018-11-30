#include <bits/stdc++.h>
using namespace std;

char s[105];
int cnt[30];
int n,mx;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",s+1);
		memset(cnt,0,sizeof(cnt));
		mx=0;
		int len=strlen(s+1);
		for (int i=1; i<=len; i++){
			cnt[s[i]-'a']++;
			mx=max(mx,cnt[s[i]-'a']);
		}
		int ans1=len-mx;
		int ans2;
		int mx1=0,mx2=0;
		memset(cnt,0,sizeof(cnt));
		for (int i=1; i<=len; i+=2){
			cnt[s[i]-'a']++;
			mx1=max(mx1,cnt[s[i]-'a']);
		} 
		memset(cnt,0,sizeof(cnt));
		for (int i=2; i<=len; i+=2){
			cnt[s[i]-'a']++;
			mx2=max(mx2,cnt[s[i]-'a']);
		}
		ans2=(len+1)/2-mx1+len/2-mx2;
		/*
		cout<<ans1<<endl;
		cout<<ans2<<endl;
		cout<<mx<<endl;
		cout<<mx1<<endl;
		cout<<mx2<<endl;
		*/
		cout<<min(ans1,ans2)<<endl;
	}
	
	
	return 0;
} 