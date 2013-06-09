#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int N,x,y;

bool cmp(pair<int,pii> p, pair<int,pii> q){
    if(p.first!=q.first)return p.first>q.first;
    return p.second.first<q.second.first;
}
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   scanf("%d",&N);
   vector<pair<int,pii> > list;
   REP(i,N){
      scanf("%d %d",&x,&y);
      list.push_back(make_pair(y,make_pair(i,x)));
   }
   sort(list.begin(),list.end(),cmp);
   REP(i,N)printf("%d %d\n",list[i].second.second,list[i].first);
   return 0;      
}

