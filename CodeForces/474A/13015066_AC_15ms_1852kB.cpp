#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;



int M,N;
int main(){

    char a[500]="qwertyuiop";
    char b[500]="asdfghjkl;";
    char c[500]="zxcvbnm,./";
    char d[500];

    char C;
    cin>>C;
    if(C=='R'){
        cin>>d;
        int len=strlen(d);

        for(int i=0;i<len;i++){

            for(int j=0;j<10;j++)
                if(a[j]==d[i])
                    d[i]=a[j-1];

            for(int j=0;j<10;j++)
                if(b[j]==d[i])
                    d[i]=b[j-1];

            for(int j=0;j<10;j++)
                if(c[j]==d[i])
                    d[i]=c[j-1];
        }

    }
    else{
        cin>>d;
        int len=strlen(d);


        for(int i=0;i<len;i++){

            for(int j=0;j<10;j++)
                if(a[j]==d[i]){
                    d[i]=a[j+1];
                    break;
                }
                    

            for(int j=0;j<10;j++)
                if(b[j]==d[i]){
                    d[i]=b[j+1];
                    break;
                }
                    

            for(int j=0;j<10;j++)
                if(c[j]==d[i]){
                    d[i]=c[j+1];
                    break;
                }
                    
        }
        
    }
    
cout<<d<<endl;

    return 0;
}


