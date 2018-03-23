#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

char maze[100][100];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main(){
	int n,m;
	cin>>n>>m;
	int sx,sy;
	int ex,ey;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			maze[i][j]='#';
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>maze[i][j];
			if(maze[i][j]=='S'){
				sx=i;
				sy=j;
			}
			if(maze[i][j]=='E'){
				ex=i;
				ey=j;
			}
		}
			
			
	string str;
	cin>>str;
	
	int mp[4]={0,1,2,3};
	
	int map[10];
	
	int ans=0;
	do{
		int nx=sx;
		int ny=sy;
	//	cout<<mp[0]<<mp[1]<<mp[2]<<mp[3]<<endl;
		map[mp[0]]=0;
		map[mp[1]]=1;
		map[mp[2]]=2;
		map[mp[3]]=3;
		
		for(int i=0;i<str.size();i++){
			int x=nx+dx[map[str[i]-'0']];
			int y=ny+dy[map[str[i]-'0']];
			if(maze[x][y]=='#')
				break;
			if(maze[x][y]=='E')
			{
				ans++;
				break;
			}
			nx=x;
			ny=y;
		}
		
		
	}while(next_permutation(mp,mp+4));
	
	cout<<ans<<endl;
	
	
	return 0;
} 