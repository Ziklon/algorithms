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

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    vector<int> v(8);
    scanf("%d\n",&T);
    REP(i,0,T){
      REP(j,0,8)scanf("%d",&v[j]);
      int p=v[7]-v[1];
      int q=v[6]-v[0];
      
      int r=v[3]-v[5];
      int s=v[2]-v[4];
      
      int a=v[5]-v[1];
      int b=v[4]-v[0];
      
      int c=v[7]-v[3];
      int d=v[6]-v[2];
      //cout<<(q*r)<<"|"<<(p*s)<<" "<<(b*c)<<"|"<<(a*d)<<endl;
      if(q*r==p*s && b*c==a*d)
         cout<<"Yes"<<endl;
      else
         cout<<"No"<<endl;
    } 
    //system("pause");
    return 0;
}
