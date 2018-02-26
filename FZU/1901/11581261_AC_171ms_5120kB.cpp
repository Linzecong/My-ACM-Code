#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

#define MAXN 1000010

int Case;
int next[MAXN];
char words[MAXN];

void getNext(){
   int len = strlen(words);
   next[0] = next[1] = 0;

   for(int i = 1 ; i < len ; i++){
      int j = next[i];
      while(j && words[i] != words[j])
          j = next[j];
      next[i+1] = words[i] == words[j] ? j+1 : 0;
   }
}

int main(){
   int t = 1;
   scanf("%d" , &Case);
   while(Case--){
      scanf("%s" , words);
      getNext();
      int len = strlen(words);
      int i = next[len];
      int ans = 1;
      while(i){
         ans++;
         i = next[i];
      }
      printf("Case #%d: %d\n" , t++ , ans);
      i = next[len];
      while(i){
         printf("%d " , len-i);
         i = next[i];
      }
      printf("%d\n" , len);
   }
   return 0;
}
