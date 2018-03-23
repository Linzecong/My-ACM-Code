#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

char type;
string word;
bool yes;
int num=0;

int main(){
	int n;
	cin>>n;
	
	set<char> hou;
	for(int i=0;i<26;i++)
		hou.insert('a'+i);
	
	for(int i=0;i<n;i++){
		cin>>type>>word;
		
			
		if(type=='!'){
			if(yes)
			num++;
			set<char> tt;
			for(int j=0;j<word.size();j++)
				tt.insert(word[j]);
			set<char> temp;
			set_intersection(hou.begin(),hou.end(),tt.begin(),tt.end(),inserter(temp,temp.begin()));
			hou=temp;
			
			if(hou.size()==1)
				yes=1;
		}
		
		if(type=='.'){
			
			for(int j=0;j<word.size();j++)
				hou.erase(word[j]);
			if(hou.size()==1)
				yes=1;
		}
		
		if(type=='?'){
			if(yes)
				num++;
			for(int j=0;j<word.size();j++)
				hou.erase(word[j]);
			if(hou.size()==1)
				yes=1;
		}
		
	
	
	}
	
	
	if(num!=0)
	cout<<num-1<<endl;
	else
	cout<<num<<endl;
	
	
	
	return 0;
} 