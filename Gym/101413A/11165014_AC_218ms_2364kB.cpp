#include<bits/stdc++.h>
using namespace std;



bool vis[1000];

int main(){
freopen("A.in","r",stdin);
    int n;
    while(cin>>n){
        if(n==0)
            break;
        memset(vis,0,sizeof(vis));
        vector<string> id;
        vector<set<string> > list;
        map<string,bool> vis;

        for(int i=0;i<n;i++){
            string str;
            cin>>str;

            string name;
            int j;
            for(j=0;j<str.size();j++){
                if(str[j]==':')
                    break;
                name.push_back(str[j]);
            }
            id.push_back(name);

            set<string> s;

            string temp;
            for(j++;j<str.size();j++){
                if(str[j]==','){
                    s.insert(temp);
                    temp="";
                }
                else
                    if(str[j]!='.')
                        temp.push_back(str[j]);
                    else{
                        s.insert(temp);
                        temp="";
                    }
            }

            list.push_back(s);


        }



        vector<string> ans;
        for(set<string>::iterator it=list[0].begin();it!=list[0].end();it++){
              vis[*it]=1;
              ans.push_back(*it);
        }

        int qqq=100;
        while(qqq--)
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<id.size();j++){
                if(id[j]==ans[i]){

                    for(set<string>::iterator it1=list[j].begin();it1!=list[j].end();it1++){

                          if(vis[*it1]==0){
                            ans.push_back(*it1);
                            vis[*it1]=1;
                          }


                    }

                }
            }
        }


        int num=0;
        for(int i=0;i<ans.size();i++){
            bool flag=0;
            for(int j=0;j<id.size();j++){
                if(id[j]==ans[i])
                    flag=1;
            }
            if(!flag)
                num++;
        }

        cout<<num<<endl;





       // cout<<ans.size()<<endl;

      //  for(set<string>::iterator it=ans.begin();it!=ans.end();it++)
      //      cout<<(*it)<<" ";
      //  cout<<endl;

    }








    return 0;
}










