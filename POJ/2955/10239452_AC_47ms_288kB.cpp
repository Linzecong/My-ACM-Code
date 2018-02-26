#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char s[104];
int num[104][104];
int len;
bool OK(char a,char b)
{
  if((a=='('&&b==')')||(a=='['&&b==']'))
  return true;
  return false;
}
int main()
{
    while(scanf("%s",s)==1)
    {
      if(s[0]=='e')
      break;
      len=strlen(s);
      memset(num,0,sizeof num);
      for(int i=2;i<=len;i++)
      {
        for(int j=0;j<=len-i;j++)
        {
          if(OK(s[j],s[j+i-1]))
          num[j][i]=2+num[j+1][i-2];
          for(int k=1;k<i;k++)
          {
            num[j][i]=max(num[j][i],num[j][k]+num[j+k][i-k]);
          }
        }
      }
      cout<<num[0][len]<<'\n';
    }
    return 0;
}
