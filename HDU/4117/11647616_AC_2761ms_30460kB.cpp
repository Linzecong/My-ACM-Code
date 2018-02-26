#include <cstring>
#include <cstdio>
#define max(a,b) a>b?a:b
const int mn=300005;
struct Trie{
	int father,fail,next[26];
	void init(){
		father=fail=0;
		memset(next,0,sizeof next);
	}
}tree[mn];
struct Xls{
	int size,y[mn],nxt[mn],fst[mn];
	void set(){
		size=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++size]=b;
		nxt[size]=fst[a];
		fst[a]=size;
	}
}g;
struct Segtree{
	int val,add,l,r;
}segtree[mn*4];
char str[mn];
int pos[mn],n,cnt,val[21000],in[mn],out[mn];
void build(char ch[]){
	int rt=1,t,len=strlen(ch);
	for (int i=0;i<len;i++){
		t=ch[i]-'a';
		if (!tree[rt].next[t]){
			tree[++cnt].init();
			tree[rt].next[t]=cnt;
		}
		tree[tree[rt].next[t]].father=rt;
		rt=tree[rt].next[t];
	}
}
int q[310000];
void build_AC(){
	int head=0,tail=0,rt,son,k;
	q[++tail]=1;tree[0].fail=1;
	while (head<tail){
		rt=q[++head];
		for (int i=0;i<26;i++){
			son=tree[rt].next[i];
			if (!son){
				tree[rt].next[i]=tree[tree[rt].fail].next[i];
				continue;
			}
			k=tree[rt].fail;
			while (!tree[k].next[i])
				k=tree[k].fail;
			tree[son].fail=tree[k].next[i];
			q[++tail]=son;
		}
	}
	g.set();
	for (int i=1;i<=cnt;i++)
		g.add(tree[i].fail,i);
}
int count_dfs;
void dfs(int rt){
	in[rt]=++count_dfs;
	for (int i=g.fst[rt];i;i=g.nxt[i])
		dfs(i);
	out[rt]=count_dfs;
}
void buildseg(int rt,int le,int ri){
	segtree[rt].val=segtree[rt].add=0;
	segtree[rt].l=le;segtree[rt].r=ri;
	if (le==ri)
		return;
	buildseg(rt<<1,le,(le+ri)>>1);
	buildseg(rt<<1|1,((le+ri)>>1)+1,ri);
}
void pushdown(int rt){
	if (segtree[rt].add){
		segtree[rt<<1].add=max(segtree[rt<<1].add,segtree[rt].add);
		segtree[rt<<1].val=max(segtree[rt<<1].val,segtree[rt].add);
		segtree[rt<<1|1].add=max(segtree[rt<<1|1].add,segtree[rt].add);
		segtree[rt<<1|1].val=max(segtree[rt<<1|1].val,segtree[rt].add);
		segtree[rt].add=0;
	}
}
int query(int rt,int x){
	if (segtree[rt].l==segtree[rt].r)
		return segtree[rt].val;
	pushdown(rt);
	if (x<=segtree[rt<<1].r)
		return query(rt<<1,x);
	else
		return query(rt<<1|1,x);
}
int XLE,XRI,Xval;
void update(int rt){
	if (segtree[rt].l>XRI||segtree[rt].r<XLE)
		return;
	if (XLE<=segtree[rt].l&&segtree[rt].r<=XRI){
		segtree[rt].val=max(segtree[rt].val,Xval);
		segtree[rt].add=max(segtree[rt].add,Xval);
		return;
	}
	pushdown(rt);
	update(rt<<1);
	update(rt<<1|1);
	segtree[rt].val=max(segtree[rt<<1].val,segtree[rt<<1|1].val);
}
int solve(){
	int rt,t,big,result=0;
	for (int i=1;i<=n;i++){
		rt=1;big=0;
		for (int j=pos[i-1];j<pos[i];j++){
			t=str[j]-'a';
			rt=tree[rt].next[t];
			big=max(big,query(1,in[rt]));
		}
		XLE=in[rt];XRI=out[rt];Xval=big+val[i];
		update(1);
		result=max(result,Xval);
	}
	return result;
}
int main(){
	int T;
	scanf("%d",&T);
	for (int Case=1;Case<=T;Case++){
		memset(str,0,sizeof str);
		memset(pos,0,sizeof pos);
		cnt=1;
		tree[0].init();
		tree[1].init();
		for (int i=0;i<26;i++)
			tree[0].next[i]=1;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%s%d",str+pos[i-1],&val[i]);
			build(str+pos[i-1]);
			pos[i]=pos[i-1]+strlen(str+pos[i-1]);
		}
		build_AC();
		count_dfs=0;
		dfs(1);
		buildseg(1,1,count_dfs);
		printf("Case #%d: %d\n",Case,solve());
	}
	return 0;
}