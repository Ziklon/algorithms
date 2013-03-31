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
int getAngle(int n){
   return n*9;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,c,d,cur;
    int ans;
    while(cin>>a>>b>>c>>d){
      if(a==b && b==c && c==d && d==0)break;
      ans=1080;
      ans+=getAngle((40+a-b)%40);
      ans+=getAngle((40+c-b)%40);
      ans+=getAngle((40+c-d)%40);
      cout<<ans<<endl;
      
    }  
    //system("pause");
    return 0;
}
