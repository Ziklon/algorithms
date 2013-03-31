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
int As[]={1,2,3,5,10,20},ans;


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string line;
    while(getline(cin,line)){
      stringstream ss(line);
      vector<int> v(6,0);
      set<int> S;
      REP(i,0,6)ss>>v[i];
      
      REP(mask,0,1<<6){
        int sm=0;
        REP(j,0,6)
          if(mask&(1<<j))
            sm+=(v[j]*As[j]);
        S.insert(sm);
      }
      ans=S.sz;
      printf("%d\n",ans);
      
    }
    
    //system("pause");
    return 0;
}
