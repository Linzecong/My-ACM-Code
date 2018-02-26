#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<cstdlib>  
#include<queue>  
using namespace std;  
struct node  
{  
    int step,cur;  
};  
int len;  
bool flag[1<<16]; //  记录哪些格子已是最终颜色  
char str[20];  
int bfs()  
{  
    memset(flag,0,sizeof(flag));  
    queue<node>que;  
    node start={0,0};  
    que.push(start);  
    flag[0]=true;  
    while(!que.empty()){  
        node now=que.front();  
        que.pop();  
        if(now.cur==(1<<2*len)-1) return now.step; //颜色已涂满所有格子  
        node next;  
        next.step=now.step+1;  
        for(int i=0;i<2*len;i++){  //遍历这个图，找个起点开始涂色  
            int tmp=0;  
            if((1<<i)&now.cur) continue; //这个点已是最终颜色，continue  
            for(int j=i;j<(i/len+1)*len;j++){  //单行向右扩展，上界的确定是技巧  
                if((1<<j)&now.cur) break;       //已扩展到最终颜色，不能把它覆盖，扩展结束  
                if(str[j]==str[i]) tmp|=(1<<j); //如果拓展的位置需涂的颜色和起点颜色一样，那么就涂  
            }  
            for(int j=i-1;j>=(i/len)*len;j--){ //单行向左扩展，下界的确定是技巧  
                if((1<<j)&now.cur) break;   //已扩展到最终颜色，不能把它覆盖，扩展结束  
                if(str[j]==str[i]) tmp|=(1<<j);//如果拓展的位置需涂的颜色和起点颜色一样，那么就涂  
            }  
            for(int j=tmp;j;j=tmp&(j-1)){   
    //把本次单行扩展的所有格子最终哪些格子成为最终颜色的所有可能入队，所有  
    //可能也就是子集的所有可能,这种遍历集合子集的方式属于位压缩的知识  
                if(!flag[j|now.cur]){  //这种情况已经产生过就不需入队了  
                    flag[j|now.cur]=1;  
                    next.cur=(j|now.cur);   
                    que.push(next);  
                }  
            }  
            if(i>=len) continue;  //双行扩展，只要对某一行的点遍历作为起点即可  
            if((1<<(i+len))&now.cur) continue; //易错，这个起点的另一行对应的起点如果已是最终颜色，continue  
            tmp=0;   
            for(int j=i;j<len;j++){  //和单行拓展类似  
                if((1<<j)&now.cur)break;  
                if((1<<(j+len))&now.cur)break;  
                if(str[j]==str[i]) tmp|=(1<<j);  
                if(str[j+len]==str[i]) tmp|=(1<<(j+len));  
            }  
            for(int j=i-1;j>=0;j--){  
                if((1<<j)&now.cur) break;  
                if((1<<(j+len))&now.cur) break;  
                if(str[j]==str[i])tmp|=(1<<j);  
                if(str[j+len]==str[i]) tmp|=(1<<(j+len));  
            }  
            for(int j=tmp;j;j=(j-1)&tmp){ //和单行拓展子集入队类似  
                if(!flag[j|now.cur ]){  
                    flag[j|now.cur ]=1;  
                    next.cur=(j|now.cur);  
                    que.push(next);  
                }  
            }  
        }  
    }  
}  
int main()  
{  
    int _,cnt=0;  
    scanf("%d",&_);  
    while(_--){  
        scanf("%d",&len);  
        scanf("%s%s",str,str+len);  
        printf("Case #%d: %d\n",++cnt,bfs());  
    }  
    return 0;  
}  