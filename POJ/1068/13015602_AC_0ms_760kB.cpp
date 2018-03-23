#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int temp;
        string str;

        int last=0;
        for(int i=0;i<n;i++){
            cin>>temp;
            int nn=temp-last;
            last=temp;

            for(int j=0;j<nn;j++){
                str.push_back('(');
            }
            str.push_back(')');

        }
       // cout<<str<<endl;

        vector<int> ans;
vector<int> ans22;
        for(int i=0;i<str.length();i++){

            if(str[i]=='('){
                ans.push_back(0);
                for(int j=0;j<ans.size();j++)
                ans[j]++;
            }
                
            else{
                ans22.push_back(ans.back());
                ans.pop_back();
            }
            

            

        }

        for(int i=0;i<ans22.size();i++)
        if(i<ans22.size()-1)
        cout<<ans22[i]<<" ";
        else
        cout<<ans22[i]<<endl;


    }
    

    return 0;
}


