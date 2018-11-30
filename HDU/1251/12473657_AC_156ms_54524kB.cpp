#include<iostream>

using namespace std;

struct Node{
	int ch[26]={0};
	int cnt=0;
}node[500010];
int cnt=1;


void insert(string str){
	int cur=1;
	for(int i=0;i<str.length();i++){
		if(node[cur].ch[str[i]-'a']==0)
			node[cur].ch[str[i]-'a']=++cnt;	
		cur=node[cur].ch[str[i]-'a'];
		node[cur].cnt++;
	}
		
}

int search(string str){
	int cur=1;
	for(int i=0;i<str.length();i++){
		if(node[cur].ch[str[i]-'a']==0)
			return 0;	
		cur=node[cur].ch[str[i]-'a'];
	}
	return node[cur].cnt;
}



int main(){
	
	char c;
	string temp;
	while(1){
		c=getchar();
		if(c=='\n'){
			if(temp==""){
				break;
			}
			else{
				insert(temp);
				temp="";
			}
		}
		else{
			temp.push_back(c);
		}
	}
	
	temp="";
	while(1){
		c=getchar();
		if(c==-1){
			break;
		}
		else{
			if(c=='\n'){
				printf("%d\n",search(temp));
				temp="";
			}
			else
				temp.push_back(c);
		}
	}
	
	
	
	return 0;
}

//100


