#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<vector>
using namespace std;
typedef long long int ll;


int main(){

    int n;
    cin>>n;

    while(n--){

        string a,msg;
        cin>>a>>msg;

        for(int i=a.length()-1;i>=0;i--){

            if(a[i]=='J'){
                string temp;
                temp.push_back(msg[msg.size()-1]);
                msg.erase(msg.begin()+msg.size()-1);
                msg=temp+msg;
                continue;
            }

            if(a[i]=='C'){
                string temp;
                temp.push_back(msg[0]);
                msg.erase(msg.begin());
                msg+=temp;
            }

            if(a[i]=='E'){
                if(msg.size()%2==0){
                    string front;
                    string back;
                    for(int j=0;j<msg.size()/2;j++){
                        front.push_back(msg[j]);
                        back.push_back(msg[msg.size()/2+j]);
                    }
                    msg=back+front;
                }
                else{
                    string front;
                    string back;
                    for(int j=0;j<msg.size()/2;j++){
                        front.push_back(msg[j]);
                        back.push_back(msg[msg.size()/2+j+1]);
                    }
                    string mid;
                    mid.push_back(msg[msg.size()/2]);
                    msg=back+mid+front;
                }
            }

            if(a[i]=='A'){
                reverse(msg.begin(),msg.end());
            }

            if(a[i]=='P'){
                for(int j=0;j<msg.length();j++){
                    if(msg[j]=='0')
                        msg[j]='9';
                    else{
                        if(msg[j]=='1'||msg[j]=='2'||msg[j]=='3'||msg[j]=='4'||msg[j]=='5'||msg[j]=='6'||msg[j]=='7'||msg[j]=='8'||msg[j]=='9'){
                            msg[j]--;
                        }
                    }
                }
                continue;
            }

            if(a[i]=='M'){
                for(int j=0;j<msg.length();j++){
                    if(msg[j]=='9')
                        msg[j]='0';
                    else{
                        if(msg[j]=='1'||msg[j]=='2'||msg[j]=='3'||msg[j]=='4'||msg[j]=='5'||msg[j]=='6'||msg[j]=='7'||msg[j]=='8'||msg[j]=='0'){
                            msg[j]++;
                        }
                    }
                }
                continue;
            }


        }

        cout<<msg<<endl;

    }


    return 0;
}
