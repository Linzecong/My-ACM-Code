#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <cstdio>
#include <queue>
#include <map>
#define maxn 100050

using namespace std;

map<string, int>man;
int pra[maxn];
int num[maxn];

int find_pra(int x){
   return x==pra[x]?x:pra[x]=find_pra(pra[x]);
}
void mymerge(int a, int b){
    int temp1 = find_pra(a);
    int temp2 = find_pra(b);
    if(temp1 == temp2)return;
    pra[temp1] = temp2;
    num[temp2] += num[temp1];
}


int main()
{
    int casenum;
    while(scanf("%d", &casenum) != EOF){
        while(casenum--){
            
            int mannum = 0;
            int datanum = 0;
            scanf("%d", &datanum);
            man.clear();
            for(int i=0; i<datanum+1; i++){
                pra[i] = i;
                num[i] = 1;
            }
            while(datanum--){
                char a[30],b[30];
                scanf("%s%s", &a[0], &b[0]);
                if(man.find(a) == man.end()){
                    man[a] = mannum++;
                }
                if(man.find(b) == man.end()){
                    man[b] = mannum++;
                }
                mymerge(man[a],man[b]);
                printf("%d\n", num[find_pra(man[b])]);
            }
            
        }
    }
    return 0;
    
    
    
}