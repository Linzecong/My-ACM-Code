#include<iostream>
#include<queue>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;

string make(string a,string b){
    string temp;

    for(int i=0;i<a.length();i++){
        temp.push_back(b[i]);
        temp.push_back(a[i]);
    }
    return temp;
}


int main(){

    int t;
    scanf("%d",&t);

    for(int qqq=1;qqq<=t;qqq++){

        map<string,int> m;

        int n;
        scanf("%d",&n);

        string a,b;
        cin>>a>>b;
        string c;
        cin>>c;

        m[c]=1;

        string temp;
        int sum=0;
        do{
            temp=make(a,b);

            sum++;

            if(temp==c){
                cout<<qqq<<" "<<sum<<endl;
                break;
            }

            if(m[temp]==1)
            {
                cout<<qqq<<" "<<-1<<endl;
                break;
            }
            else{
                m[temp]=1;

            }
            a.clear();
            b.clear();
            for(int i=0;i<n;i++){
                a.push_back(temp[i]);
                b.push_back(temp[i+n]);
            }


        }while(1);









}

return 0;

}
