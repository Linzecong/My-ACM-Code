#include <iostream>
#include <algorithm>
using namespace std;

char temp;
struct node
{
	int cnt;
	char ch;
}nodes[5];

bool cmp(node a,node b)
{
	if(a.cnt!=b.cnt)return a.cnt>b.cnt;
	else return a.ch<b.ch;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(!n&&!m)break;
		nodes[0].cnt=0;
		nodes[0].ch='A';
		nodes[1].cnt=0;
		nodes[1].ch='C';
		nodes[2].cnt=0;
		nodes[2].ch='D';
		nodes[3].cnt=0;
		nodes[3].ch='E';
		nodes[4].cnt=0;
		nodes[4].ch='G';
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>temp;
				if(temp=='A')nodes[0].cnt++;
				else if(temp=='C')nodes[1].cnt++;
				else if(temp=='D')nodes[2].cnt++;
				else if(temp=='E')nodes[3].cnt++;
				else if(temp=='G')nodes[4].cnt++;
			}
		}
		
		sort(nodes,nodes+5,cmp);
		for(int i=0;i<5;i++)
		{
			if(nodes[i].cnt)
			{
				cout<<nodes[i].ch<<" "<<nodes[i].cnt<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}