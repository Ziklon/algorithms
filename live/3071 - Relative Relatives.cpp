#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;
int D,N,E;
string nam_a, nam_b;

vector<pair<int,int> > G[110];
int A[110];

void dfs(int u, int age){
    A[u]=age;
    for(int i=0;i<G[u].size();i++){
        pair<int,int>  v=G[u][i];
        dfs(v.first,age-v.second);
    }    
}

bool comp(pair<string,int> p, pair<string,int> q){
    if(p.second!=q.second)return p.second>q.second;
    return p.first<q.first;
}
int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   cin>>D;
   REP(t,D){
        cin>>N;
        map<string,int> M;
        for(int i=0;i<110;i++){
            G[i].clear();
            A[i]=0;
        }
        M["Ted"]=1;
        int idx=2;        
        REP(i,N){
            cin>>nam_a>>nam_b>>E;
            if(M.count(nam_a)==0)M[nam_a]=idx++;
            if(M.count(nam_b)==0)M[nam_b]=idx++;            
            G[M[nam_a]].push_back(make_pair(M[nam_b],E));
        }
        dfs(1,100);        
        vector<pair<string,int> > v(M.begin(),M.end());
        vector<pair<string,int> > ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(make_pair(v[i].first,A[v[i].second]));            
        }       
        sort(ans.begin(),ans.end(),comp);
        cout<<"DATASET "<<(t+1)<<endl;
        for(int i=1;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
   }
   return 0;      
}
