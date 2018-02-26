#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{

    int num=0;

    while(1){
        cin>>num;

        if(num!=0){



            string str;
            cin>>str;


            int sum=0;
            vector<char> temp;

            for(int i=0;i<str.size();i++){
                char cos=str[i];

                int have=0;
                for(int j=0;j<temp.size();j++){
                    if(temp[j]==cos){
                        temp.erase(temp.begin()+j);
                        have=1;
                        break;
                    }
                }



                if(!have)
                    if(temp.size()>=num){
                        sum++;


                    }
                    else{
                        temp.push_back(cos);


                    }


            }




            if(sum==0)
                cout<<"All customers tanned successfully."<<endl;
            else
                cout<<sum/2<<" customer(s) walked away."<<endl;



        }
        else
            break;



    }





    return 0;
}
