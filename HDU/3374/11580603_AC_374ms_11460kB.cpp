#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXN 2000010

int len;
int nxt[MAXN/2];
char String[MAXN];
char minString[MAXN/2] , maxString[MAXN/2];
int minTimes , maxTimes;
int minRank , maxRank;

/*求最小表示的起始坐标*/
int getMin(){
   int i = 0 , j = 1 , k = 0;
   while(i+k < len && j+k < len){
      if(String[i+k] == String[j+k])
        k++;
      else{
        if(String[i+k] > String[j+k])
           i = i+k+1;
        else
           j = j+k+1;
        k = 0;
        if(i == j)/*若滑动后i == j那么j++*/
           j++;
      }
   }
   return min(i , j);
}

/*求最大表示的起始坐标*/
int getMax(){
   int i = 0 , j = 1 , k = 0;
   while(i+k < len && j+k < len){
      if(String[i+k] == String[j+k])
        k++;
      else{
        if(String[i+k] < String[j+k])
           i = i+k+1;
        else
           j = j+k+1;
        k = 0;
        if(i == j)/*若滑动后i == j那么j++*/
           j++;
      }
   }
   return min(i , j);
}

/*求出最小表示*/
void getMinString(){
   int pos = 0;
   for(int i = minRank ; i < minRank+len/2 ; i++)
      minString[pos++] = String[i];
   minString[pos] = '\0';
}

/*求出最大表示*/
void getMaxString(){
   int pos = 0;
   for(int i = maxRank ; i < maxRank+len/2 ; i++)
      maxString[pos++] = String[i];
   maxString[pos] = '\0';
}

/*求nxt数组*/
void getnxt(char *pattern){
    int m = strlen(pattern);
    nxt[0] = nxt[1] = 0;

    for(int i = 1 ; i < m ; i++){
       int j = nxt[i];
       while(j && pattern[i] != pattern[j])
          j = nxt[j];
       nxt[i+1] = pattern[i] == pattern[j] ? j+1 : 0;
    }
}

/*kmp匹配找到有几个*/
int find(char *pattern){

   int count = 0;
   int m = strlen(pattern);
   int j = 0;

   for(int i = 0 ; i < len-1 ; i++){/*这里只要判断到len-1即可，这样就可以避免多算了一次*/
      while(j && pattern[j] != String[i])
          j = nxt[j];
      if(pattern[j] == String[i])
          j++;
      if(j == m)
          count++;
   }
   return count;
}


int main(){
   while(scanf("%s" , String) != EOF){

      int flag;
      char tmp[MAXN];
      memcpy(tmp , String , sizeof(String));
      strcat(String , tmp);
      len = strlen(String);

      /*求字符串的最小表示*/
      minRank = getMin();
      getMinString();
      getnxt(minString);
      minTimes = find(minString);

      /*求字符串的最大表示*/
      maxRank = getMax();
      getMaxString();
      getnxt(maxString);
      maxTimes = find(maxString);

      /*输出*/
      printf("%d %d %d %d\n" , minRank+1 , minTimes , maxRank+1 , maxTimes);
   }
   return 0;
}


