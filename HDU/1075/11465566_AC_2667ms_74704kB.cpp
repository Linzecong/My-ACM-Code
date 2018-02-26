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

    map<string,string> m;

    string temp;
    cin>>temp;
    while(1){
        string a,b;
        cin>>a;
        if(a=="END")
            break;
        cin>>b;
        m[b]=a;

    }
    cin>>temp;
    getchar();
    string ans;
    char c;
    string danci;
    while(1){
        c=getchar();
        if(c=='E'){
            getchar();
            getchar();
            cout<<ans;
            break;
        }
        if(c==' '||c=='\n'){
            if(m.find(danci)==m.end()){
                ans=ans+danci;
                ans.push_back(c);
            }
            else{
                ans=ans+m[danci];
                ans.push_back(c);
            }
            danci="";

        }
        else
        {
            if(islower(c)){
                danci.push_back(c);
            }
            else{
                if(m.find(danci)==m.end()){
                    ans=ans+danci;
                    ans.push_back(c);
                }
                else{
                    ans=ans+m[danci];
                    ans.push_back(c);
                }
                danci="";
            }
        }
    }


    return 0;
}








