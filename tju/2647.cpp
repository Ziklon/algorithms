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
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;

struct node{
  int p,i;
  node(int _p, int _i){
    p=_p;
    i=_i;
  }
  bool operator < (const node q)const{
    if(q.p!=p)return p<q.p;
    return i>q.i;
  }
};
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,n,m,p,ans;
    scanf("%d\n",&t);
    REP(i,0,t){
      scanf("%d %d\n",&n,&m);
      queue<node> Q;
      map<int,int>M;
      REP(j,0,n){
        scanf("%d",&p);
        Q.push(node(p,j));
        M[p]++;
      }
      vector<pair<int,int> >vp(all(M));
      sort(vp.rbegin(),vp.rend());      
      ans=0;
      int j=0;
      while(!Q.empty()){
        if(vp[j].second==0)j++;       
        node cur=Q.front();
        Q.pop();
        if(vp[j].first>cur.p)
           Q.push(cur);
        else{
           ans++;  
           vp[j].second--;
           if(cur.i==m)break;
          }
      }
      printf("%d\n",ans);
    }
    //system("pause");
    return 0;
}
