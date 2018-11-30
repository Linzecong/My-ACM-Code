#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector <int>b;
char s[20];
int main()
{
    int n,m,now;
    bool flag;
    scanf("%d%d",&n,&m);
    b.clear();
    now=0;
    for (int i=1;i<=m;i++)
        {
        flag=false;
        scanf("%s",s);
        if (s[0]=='u')
        {
            flag=true;
            scanf("%s",s);
        }
        int len=strlen(s);
        int Num=0;
        if (s[0]!='-') Num=s[0]-'0';
        for (int j=1;j<len;j++)
            Num=Num*10+s[j]-'0';
        if (s[0]=='-') Num=-Num;
       // cout << Num << endl;
        if (!flag)
            {
            now=(now+Num)%n;
            b.push_back(Num);
        }
        else
        while (Num--){
            if (b.size()==0) break;
            int u=b[b.size()-1];
            b.erase(b.end()-1);
            now=(now-u)%n;
        }
    }
    printf("%d\n",(now+n)%n);
}






