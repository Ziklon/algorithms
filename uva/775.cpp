/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int N,x,y,init;
vector<int> G[260];
int vis[260];
string line;
bool check(){
   REP(i,0,N)
      if(!vis[i+1])
         return false;
   return true;
}

void backTrack(int x){
   bool ok=check();
   REP(i,0,G[x].sz){
      
   }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d",&N)==1){
        REP(i,0,N)G[i+1].clear();
        fill(vis,0);
        while(getline(cin,line)){
         if(line=="%")break;
         istringstream is(line);
         is>>x>>y;   
         G[x].push_back(y);
         G[y].push-back(x);
       }
                 
    }  
    //system("pause");
    return 0;
}
