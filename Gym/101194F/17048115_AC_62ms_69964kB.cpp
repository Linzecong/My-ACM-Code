#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=250005;
int pos[maxn<<1],len[maxn<<1],fa[maxn<<1];
int nxt[maxn<<1][30],tot,last,root,mark[maxn<<1];
char s[maxn],s1[maxn];
int a[maxn],b[maxn<<1];
int newnode(int _len,int _id){
	len[++tot]=_len;
	memset(nxt[tot],0,sizeof(nxt[tot]));
	mark[tot]=0;
	pos[tot]=_id;
	return tot;
}
void Extend(int c,int id){
	int p=last,np=newnode(len[p]+1,id);
	last=np;
	for (;p&&!nxt[p][c];p=fa[p]) nxt[p][c]=np;
	if (!p) fa[np]=root;
	else{
		int q=nxt[p][c];
		if (len[q]==len[p]+1) fa[np]=q;
		else{
			int nq=newnode(len[p]+1,pos[q]);
			fa[nq]=fa[q];
			memcpy(nxt[nq],nxt[q],sizeof(nxt[q]));
			fa[np]=fa[q]=nq;
			for (;p&&nxt[p][c]==q;p=fa[p]) nxt[p][c]=nq;
		}
	} 
}
void Find(int Len){
	int Pos=root,L=0;
	for (int j=0;j<Len;j++){
		if (nxt[Pos][s1[j]-'a']){
			Pos=nxt[Pos][s1[j]-'a'];
			L++;
			mark[Pos]=max(L,mark[Pos]);
		}else{
			for (;Pos&&!nxt[Pos][s1[j]-'a'];Pos=fa[Pos]);
			if (!Pos){
				L=0;
				Pos=root;
			}
			else {
				L=len[Pos]+1;
				Pos=nxt[Pos][s1[j]-'a'];
				mark[Pos]=max(mark[Pos],L);
			}
		}
	}
}
void jssort(int Len){
	for (int i=0;i<=Len;i++) a[i]=0;
	for (int i=1;i<=tot;i++) a[len[i]]++;
	for (int i=1;i<=Len;i++) a[i]+=a[i-1];
	for (int i=1;i<=tot;i++) b[a[len[i]]--]=i;
	for (int i=tot;i>=1;i--){
		int u=b[i];
		if (mark[u]) mark[fa[u]]=len[fa[u]];
	}
}
bool cmp(int p1,int p2,int Len){
	for (int i=Len-1;i>=0;i--){
		if (s[p1-1-i]>s[p2-1-i]) return false;
		if (s[p1-1-i]<s[p2-1-i]) return true;
	}
	return false;
}
int n;
int main(){
	int T,Case=0;
	cin >> T;
	while (T--){
		Case++;
		scanf("%d",&n);		
		scanf("%s",s);
		tot=0;
		last=root=newnode(0,0);
		int Len=strlen(s);
		for (int i=0;i<Len;i++){
			Extend(s[i]-'a',i+1);
		}
		for (int i=2;i<=n;i++){
			scanf("%s",s1);
			Find(strlen(s1));
		}
		jssort(Len);
		int ans=maxn*4,POS;
		for (int i=1;i<=tot;i++){
			if (mark[i]<len[i]){
				if (max(len[fa[i]],mark[i])+1<ans){
					ans=max(len[fa[i]],mark[i])+1;
					POS=pos[i];
				}else if (max(len[fa[i]],mark[i])+1==ans&&cmp(pos[i],POS,ans)){
					POS=pos[i];
				}	
			}
		}
		printf("Case #%d: ",Case);
		if (ans==maxn*4){
			printf("Impossible\n");
			continue;
		}
		for (int i=ans-1;i>=0;i--)
			if (isalpha(s[POS-i-1]))
				printf("%c",s[POS-i-1]);
		printf("\n");
	}
}/*
55
2
bana
a*/