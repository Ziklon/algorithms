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
bool compare(string& p, string& q){
  if(p[0]=='-' && q[0]!='-')return 0; 
  if(p[0]!='-' && q[0]=='-')return 1;
  if(p[0]=='-'){//ambos nega
    if(p.sz!=q.sz)return p.sz<q.sz;
    REP(i,1,p.sz)
      if(p[i]!=q[i])
        return p[i]<q[i];
    return 0;
  }else{
    if(p.sz!=q.sz)return p.sz>q.sz;
    REP(i,0,p.sz)
      if(p[i]!=q[i])
        return p[i]>q[i];
    return 0;  
  }
}
string dif(string a, string b){
  
}
vector<string> v;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,k;
    char num[30];
    scanf("%d",&n);
    REP(i,0,n){
      scanf("%d\n",&k);
      v.clear();
      REP(j,0,k){
        scanf("%s\n",num);
        v.push_back(num);
      }
      sort(all(v),compare);
      
    }
    //system("pause");
    return 0;
}
