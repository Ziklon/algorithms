/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int nc,a,b;
    scanf("%d",&nc);
    while(nc>0){
      scanf("%d %d",&a,&b);
      vector<int> v(9,0);
      int ans=0;
      printf("SOLN       COLUMN\n");
      printf(" #      1 2 3 4 5 6 7 8\n\n");
      for(int i=0;i<9;i++)v[i]=i;
      do{
          if(v[b]!=a)continue;
          bool ok=true;
          for(int i=1;i<9;i++)
            for(int j=i+1;j<9;j++)
              if(abs(i-j)==abs(v[i]-v[j]))
                ok=0;
          if(ok){
            ans++;
            printf("%2d     ",ans);
            for(int i=1;i<9;i++)printf(" %d",v[i]);
            printf("\n");          
          }
          
      }while(next_permutation(v.begin()+1,v.end()));
          
      nc--;
      if(nc)printf("\n");
    }
    //system("pause");
    return 0;
}
