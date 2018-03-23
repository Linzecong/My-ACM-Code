#include<iostream>
using namespace std;

char maze[11][11];

int main(){
	
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			cin>>maze[i][j];
	
	int x,y;
	cin>>x>>y;
	
	x=x%3;
	if(x==2)
	x=1;
	else if(x==1)
	x=0;
	else if(x==0)
	x=2;
	
	y=y%3;
	if(y==2)
	y=1;
	else if(y==1)
	y=0;
	else if(y==0)
	y=2;
	
	bool have=0;
	for(int i=1+3*x;i<=3+3*x;i++)
		for(int j=1+3*y;j<=3+3*y;j++)
			if(maze[i][j]=='.')
				have=1;
	
	if(have){
		for(int i=1+3*x;i<=3+3*x;i++)
		for(int j=1+3*y;j<=3+3*y;j++)
			if(maze[i][j]=='.')
				maze[i][j]='!';
	}
	else{
		for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			if(maze[i][j]=='.')
				maze[i][j]='!';
	}

	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cout<<maze[i][j];
			if(j%3==0)
				cout<<" ";
		}
		if(i%3==0)
			cout<<endl;
		cout<<endl;
	}
		
			
	
	
	
	return 0;
} 







