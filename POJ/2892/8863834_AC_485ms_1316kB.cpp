#include <iostream>
#include <stdio.h>
#include <algorithm>

#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

const int maxn=50005;

int C[maxn];



int lowbit(int x){
    return x& -x;
}

int sum(int x){
    int s=0;
    for(int i=x;i;i-=lowbit(i))
        s+=C[i];
    return s;
}

void add(int x,int v){
    for(int i=x;i<=maxn;i+=lowbit(i))
        C[i]+=v;
}

int main(){
    
    
    int N,M;
    
    while(~scanf("%d%d",&N,&M)){
        
        
        
        memset(C,0,sizeof(C));
        
        for(int i=1;i<=N;i++)
            add(i,1);
        
        vector<int> last;
        
        for(int i=0;i<M;i++){
            char s[10];
            scanf("%s",s);
            
            
            
            if(s[0]=='D'){
                int x;
                scanf("%d",&x);
                add(x,-1);
                last.push_back(x);
            }
            
            if(s[0]=='R'){
                add(last.back(),1);
                last.pop_back();
            }
            
            
            if(s[0]=='Q'){
                
                int x;
                scanf("%d",&x);
                
                if(sum(x)-sum(x-1)==0){
                    printf("%d\n",0);
                    continue;
                }
                
                int ln=1;
                int rn=0;
                
                
                int l=1;
                int r=x;
                
                
                while(l<=r){
                    int m=(l+r)/2;
                    
                    if(sum(r)-sum(m-1)==r-m+1){
                        
                        ln=m;
                        r=m-1;
                    }
                    else
                        l=m+1;
                }
                
                
                
                
                l=x;
                r=N;
                
                
                while(l<=r){
                    int m=(l+r)/2;
                    
                    if(sum(m)-sum(l-1)==m-l+1){
                        l=m+1;
                        rn=m;
                        
                        
                    }
                    else
                        r=m-1;
                }
                
                
                
                
                printf("%d\n",rn-ln+1);
            }
            
        }
        
        
        
        
    }
    
    return 0;
}














