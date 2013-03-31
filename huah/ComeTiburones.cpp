#include<iostream> 
#include<string> 
#include<vector> 
#include<queue> 
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    string s;
    int di[8]={1,1,1,-1,-1,-1,0,0};
    int dj[8]={1,-1,0,1,-1,0,1,-1};
    for(int caso=1;caso<=t;caso++)
    {
        queue<pair<pair<int,int>,int> >Q;
        int R,C;
        cin>>R>>C;
        vector<string>v(R);
        vector<vector<bool> >visited(R,vector<bool>(C,0));
        for(int i=0;i<R;i++)cin>>v[i];
        int inix,iniy,finx,finy;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++)
        {
            if(v[i][j]=='X')inix=i,iniy=j;
            if(v[i][j]=='@')finx=i,finy=j;
        }
        Q.push(make_pair(make_pair(inix,iniy),0));
        visited[inix][iniy]=1;
        int dev=-1;
        while(!Q.empty())
        {
            pair<pair<int,int>,int>P=Q.front();
            Q.pop();
            pair<int,int>ind=P.first;
            int cost=P.second;
            if(ind.first==finx && ind.second==finy)
            {
                dev=cost;
                break;
            }
            for(int i=0;i<8;i++)
            {
                int X=ind.first+di[i];
                int Y=ind.second+dj[i];
                if(X>=0 && X<R && Y>=0 &&Y<C) if(!visited[X][Y] && v[X][Y]!='#')
                {
                    Q.push(make_pair(make_pair(X,Y),cost+1));
                    visited[X][Y]=1;
                }
            }
        }
        if(dev==-1)cout<<"Caso #"<<caso<<": FML"<<endl;
        else cout<<"Caso #"<<caso<<": "<<dev<<endl;
    }
    //system("pause");
    return 0;
}
