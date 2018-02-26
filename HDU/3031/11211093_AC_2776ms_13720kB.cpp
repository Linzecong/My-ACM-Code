#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<memory.h>
#include<queue>
using namespace std;
const int MAXN=100010;

inline void scanf(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}


priority_queue<int,vector<int>,less<int> > P[105];
priority_queue<int,vector<int>,less<int> > Y;
priority_queue<int,vector<int>,less<int> > W;
int num[105];
int main(){

    int R,n,m,temp;
    char op[10];
    scanf(R);
    int YP=0,WP=0;
    priority_queue<int,vector<int>,less<int> > null;
    for(int qqq=0;qqq<R;qqq++){
        scanf(n);
        scanf(m);
        Y=null;
        W=null;

        for(int i=1;i<=m;i++){
            P[i]=null;
            scanf(num[i]);
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=num[i];j++){
                scanf(temp);
                P[i].push(temp);
            }
        }


        for(int i=1;i<=n;i++){
            scanf("%s",op);

            if(op[0]=='C'){
                int yy=Y.top();
                int ww=W.top();
                if(yy>ww){
                    while(!W.empty()){
                        Y.push(W.top());
                        W.pop();
                    }
                }
                if(ww>yy){
                    while(!Y.empty()){
                        W.push(Y.top());
                        Y.pop();
                    }
                }
            }

            if(op[0]=='L'){
                if(i%2)
                    W.pop();
                else
                    Y.pop();
            }

            if(op[0]=='A'){
                scanf(temp);
                if(i%2){
                    int yy=W.top()+temp;
                    W.pop();
                    W.push(yy);
                }
                else{
                    int yy=Y.top()+temp;
                    Y.pop();
                    Y.push(yy);
                }
            }

            if(op[0]=='E'){
                scanf(temp);
                if(i%2){
                    W.pop();
                    W.push(temp);
                }
                else{
                    Y.pop();
                    Y.push(temp);
                }
            }

            if(op[0]=='T'){
                scanf(temp);
                if(i%2){
                    while(!P[temp].empty()){
                        W.push(P[temp].top());
                        P[temp].pop();
                    }
                }
                else{
                    while(!P[temp].empty()){
                        Y.push(P[temp].top());
                        P[temp].pop();
                    }
                }
            }

        }

        int yy=Y.size();
        int ww=W.size();
        printf("%d:%d\n",ww,yy);
        if(yy>ww)
            YP++;
        else
            WP++;

    }
    if(YP>WP)
        printf("I will be back!!\n");
    else
        printf("Hahaha...I win!!\n");





    return 0;
}
