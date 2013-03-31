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
#define REP(i,a,b) for(i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m,i,j,k,ans=0;
    char board[15][15];
    bool vis[15][15];
    cin>>n>>m;
    REP(i,0,n)
      REP(j,0,m)
         cin>>board[i][j];
   set<pair<int,int> >S;
    REP(i,0,n)
      REP(j,0,m)
         REP(k,0,4){
            int X=i+dx[k];
            int Y=j+dy[k];
            if(X>=0 && Y>=0 && X<n && Y<m && board[i][j]=='P' && board[X][Y]=='W')
               S.insert(make_pair(X,Y));
         }  
    cout<<S.sz<<endl;       
    //system("pause");
    return 0;
}
