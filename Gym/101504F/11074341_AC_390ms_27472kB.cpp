#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<bitset>
#include<list>
#define INF 1<<29
using namespace std;
typedef long long int ll;

int dig[30];


int main(){

  string str;


  cin>>str;


  list<char> l;


  list<char>::iterator it=l.begin();

  for(int i=0;i<str.size();i++){
      if(str[i]=='L'){
          if(it!=l.begin())
          it--;
      }
      else{
      if(str[i]=='R'){
          if(it!=(l.end()))
          it++;
      }
      else
      l.insert(it,str[i]);
      }
  }



  for(list<char>::iterator i=l.begin();i!=l.end();i++)
      cout<<(*i);
cout<<endl;


    return 0;
}




