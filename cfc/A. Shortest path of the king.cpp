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
int vis[9][9];
int di[]={-1,1,0,0,-1,-1,1,1};
int dj[]={0,0,1,-1,1,-1,-1,1};
string des[]={"L", "R", "U", "D", "LU", "LD", "RD","RU" };
int dir[9][9];
int dis[9][9];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string sa,sb;
    cin>>sa>>sb;
    int xs=sa[0]-'a';
    int ys=sa[1]-'1';
    int xf=sb[0]-'a';
    int yf=sb[1]-'1';
    queue<pair<int,int> >Q;
    Q.push(make_pair(xs,ys));
    fill(vis,0);
    fill(dis,0);
    vis[xs][ys]=1;
    while(!Q.empty()){
        pair<int,int> P=Q.front();
        if(P.first==xf && P.second==yf)break;
        Q.pop();
        REP(i,0,8){
            int X=P.first+di[i];
            int Y=P.second+dj[i];
            if(min(X,Y)>=0 && max(X,Y)<8 && !vis[X][Y]){
                dis[X][Y]=1+dis[P.first][P.second];
                vis[X][Y]=1;
                dir[X][Y]=i;
                Q.push(make_pair(X,Y));
            }
        }
    }
    cout<<dis[xf][yf]<<endl;
    vector<string> ans;
    int p=xf;
    int q=yf;
    while(1){
        if(p==xs && q==ys)break;
        ans.push_back(des[dir[p][q]]);
        int xp=p;
        int yq=q;
        p=xp-di[dir[xp][yq]];
        q=yq-dj[dir[xp][yq]];        
    }
    reverse(all(ans));
    REP(i,0,ans.sz)
        cout<<ans[i]<<endl;    
    //system("pause");
    return 0;
}
