#include <cstdio>  
#include <cstdlib>  
#include <climits>  
  
  
const int MAX = 550;  
  
//存储11中类型的土地，二维中的0 1 2 3分别代表这种类型的土地的左上右下  
//为1表示这个方向有接口，为0表示这个方向没有接口  
const int type[11][4]={{1,1,0,0},{0,1,1,0},  
                        {1,0,0,1},{0,0,1,1},  
                        {0,1,0,1},{1,0,1,0},  
                        {1,1,1,0},{1,1,0,1},  
                        {1,0,1,1},{0,1,1,1},  
                        {1,1,1,1}  
                        };  
  
const bool VERTICAL = true;  
  
//pre数组就是正常的并查集中所用，但是在合并的时候要注意将二维坐标转换成一维的标号，此处用行优先  
int pre[MAX*MAX+1],cnt,m,n;  
char farm[MAX][MAX];  
  
  
  
void init(int n){  
    int i;  
    for(i=1;i<=n;++i){  
        pre[i] = i;  
    }  
    cnt = n;  
}  
  
int root(int x){  
    if(x!=pre[x]){  
        pre[x] = root(pre[x]);  
    }  
    return pre[x];  
}  
  
void merge(int ax,int ay,int bx,int by,bool dir){  
    if(bx>n || by>m)return;//超出地图的部分不进行合并  
    bool mark = false;//标识两块地是否可连  
    int ta,tb;//两点的类型值0-10  
  
    ta = farm[ax][ay]-'A';  
    tb = farm[bx][by]-'A';  
  
    if(dir){//竖直方向判断可连性  
        if(type[ta][3] && type[tb][1])mark = true;  
    }else{//水平方向判断可连性  
        if(type[ta][2] && type[tb][0])mark = true;  
    }  
  
    if(mark){//只要可连就合并，这就是正常的并查集了  
        int fx = root((ax-1)*m+ay);  
        int fy = root((bx-1)*m+by);  
        if(fx!=fy){  
            pre[fy] = fx;  
            --cnt;  
        }  
    }  
}  
  
  
int main(){  
    //freopen("in.txt","r",stdin);  
    int i,j;  
    while(scanf("%d %d",&n,&m)!=EOF){  
        if(n==-1 && m==-1)break;  
        init(n*m);  
        for(i=1;i<=n;++i){  
            scanf("%s",farm[i]+1);  
        }  
        for(i=1;i<=n;++i){  
            for(j=1;j<=m;++j){  
                merge(i,j,i+1,j,VERTICAL);  
                merge(i,j,i,j+1,!VERTICAL);  
            }  
        }  
        printf("%d\n",cnt);  
    }  
    return 0;  
}  