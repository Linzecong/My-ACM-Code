#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=4e5+5;
long long ans;
struct Pld_T{
	int tot,last;
	int len[maxn],fail[maxn],go[maxn][30],Len1,Len2,cnt1[maxn],cnt2[maxn];
	char s1[maxn],s2[maxn];
	void init(){
		ans=0;
		len[1]=-1;len[0]=0;Len1=strlen(s1);Len2=strlen(s2);
		fail[0]=1;
		tot=1;last=0;
		memset(go,0,sizeof(go));
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for (int i=0;i<Len1;i++) insert(i,s1,1);
		for (int i=0;i<Len2;i++) insert(i,s2,2);
		update();
	}	
	void insert(int x,char *s,int flag){
		int c=s[x]-'a';
		while (s[x-len[last]-1]!=s[x]) last=fail[last];
		if (!go[last][c]){
			len[++tot]=len[last]+2;
			int t=fail[last];
			while (s[x-len[t]-1]!=s[x]) t=fail[t];
			fail[tot]=go[t][c];
			go[last][c]=tot;
			last=tot;
			if (flag==1)cnt1[tot]=1;
			if (flag==2)cnt2[tot]=1;
		}
		else{
			last=go[last][c];
			if (flag==1)cnt1[last]++;
			if (flag==2)cnt2[last]++;
		}
	}
	void update(){
		for (int i=tot;i>=2;i--){
			cnt1[fail[i]]+=cnt1[i];
			cnt2[fail[i]]+=cnt2[i];
		}
		for (int i=2;i<=tot;i++)
			ans+=1ll*cnt1[i]*cnt2[i];
	}
}a;
int main(){
	int T,Case=0;
	cin >> T;
	while (T--){
		Case++;
		scanf("%s%s",a.s1,a.s2);
		ans=0;
		a.init();
		printf("Case #%d: %lld\n",Case,ans);
	}
}