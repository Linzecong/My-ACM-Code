#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>
#include<string>
#include<stdlib.h>

using namespace std;



int main(){

    int N;
    cin>>N;

    if(N%5)
    cout<<N/5+1<<endl;
    else
        cout<<N/5<<endl;



    return 0;
}

