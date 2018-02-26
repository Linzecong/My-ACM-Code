#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int C,P,X,L;

stack<int> leave;

struct node{
    bool now=true;
    vector<int> partner;
    set<int> leftpartner;
}tempnode,curnode,state[200001];

int main(){
    cin>>C>>P>>X>>L;
    int temp1,temp2,tempsize;
    for(int i=1;i<=C;i++)
    {
        state[i].now=true;
        state[i].partner.clear();
        state[i].leftpartner.clear();
    }
    for(int i=0;i<P;i++)
    {
        cin>>temp1>>temp2;
        state[temp1].partner.push_back(temp2);
        state[temp2].partner.push_back(temp1);
    }
    leave.push(L);

    while(!leave.empty())
    {
        int nodeid=leave.top();
        leave.pop();
        if(!state[nodeid].now)continue;
        state[nodeid].now=false;
        tempnode=state[nodeid];
        tempsize=tempnode.partner.size();
        for(int i=0;i<tempsize;i++)
        {
            int partnerid=tempnode.partner[i];
            curnode=state[partnerid];
            state[partnerid].leftpartner.insert(nodeid);
            if(state[partnerid].leftpartner.size()*2>=state[partnerid].partner.size())
            {
                leave.push(partnerid);
                curnode.now=false;
            }
        }
    }
    if(state[X].now)cout<<"stay"<<endl;
    else cout<<"leave"<<endl;
    return 0;
}
