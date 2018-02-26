#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long int ll;




int main(){

    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    string str;
    char s[30];

    for(int qqq=1;qqq<=t;qqq++){



        cin>>str;





        string aaa;
        for(int i=0;i<str.size()-4;i++)
            aaa.push_back(str[i]);


        ll ans=stoll(aaa);
        ans+=str[str.size()-4]-'0';

        ll temp=(str[str.size()-3]-'0')*(str[str.size()-2]-'0')/(str[str.size()-1]-'0');

        ans-=temp;


        string aaa1;
        for(int i=1;i<str.size()-3;i++)
            aaa1.push_back(str[i]);

        ll ans1=stoll(aaa1);
        ans1+=str[0]-'0';
        ll temp1=(str[str.size()-3]-'0')*(str[str.size()-2]-'0')/(str[str.size()-1]-'0');
        ans1-=temp1;


        if(str.size()>=6){

        string aaa2;
        for(int i=1;i<str.size()-4;i++)
            aaa2.push_back(str[i]);

        ll ans2=stoll(aaa2);
        ans2+=str[0]-'0';
        ll temp2=(str[str.size()-4]-'0')*(str[str.size()-3]-'0')/((str[str.size()-2]-'0')*10+(str[str.size()-1]-'0'));
        ans2-=temp2;
        ans1=max(ans2,ans1);


        string aaa3;
        for(int i=0;i<str.size()-5;i++)
            aaa3.push_back(str[i]);


        ll ans3=stoll(aaa3);
        ans3+=str[str.size()-5]-'0';

        ll temp3=(str[str.size()-4]-'0')*(str[str.size()-3]-'0')/((str[str.size()-2]-'0')*10+(str[str.size()-1]-'0'));

        ans3-=temp3;
        ans1=max(ans3,ans1);
        }



        ans=max(ans,ans1);

        printf("Case #%d: %lld\n",qqq,ans);





    }

    return 0;
}


