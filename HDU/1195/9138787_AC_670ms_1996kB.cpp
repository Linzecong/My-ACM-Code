#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

int m[10000];

int stringtoint(string a){
    int sum=0;

    sum+=(a[0]-'0')*1000;
    sum+=(a[1]-'0')*100;
    sum+=(a[2]-'0')*10;
    sum+=(a[3]-'0')*1;
    return sum;
}


int bfs(string a,string b){

    m[stringtoint(a)]=1;

    queue<string> que;
    que.push(a);

    while(!que.empty()){
        string tp=que.front();
        que.pop();

        if(tp==b)
            return m[stringtoint(tp)]-1;

        for(int i=0;i<4;i++){
            string tmp=tp;

            tmp[i]++;
            if(tmp[i]=='9'+1)
                tmp[i]='1';

            if(!m[stringtoint(tmp)]){
                que.push(tmp);
                m[stringtoint(tmp)]=m[stringtoint(tp)]+1;
            }
        }


        for(int i=0;i<4;i++){
            string tmp=tp;

            tmp[i]--;
            if(tmp[i]=='0')
                tmp[i]='9';

            if(!m[stringtoint(tmp)]){
                que.push(tmp);
                m[stringtoint(tmp)]=m[stringtoint(tp)]+1;
            }
        }




        for(int i=0;i<=2;i++){
            string tmp=tp;

            char aa=tmp[i];
            tmp[i]=tmp[i+1];
            tmp[i+1]=aa;

            if(!m[stringtoint(tmp)]){
                que.push(tmp);
                m[stringtoint(tmp)]=m[stringtoint(tp)]+1;
            }

        }



    }

    return 0;
}


int main()
{

    int t;
cin>>t;
    while(t--){
        memset(m,0,sizeof(m));
        string a;
        string b;
cin>>a>>b;
        cout<<bfs(a,b)<<endl;

    }



    return 0;
}

