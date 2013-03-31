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
bool ispal(string s){
  string aux=s;
  reverse(all(s));
  return s==aux;
}
int main(){
    //freopen("in.txt",stdin);
    //freopen("out.txt",stdout);
    int h,m;
    string line,ans;
    cin>>line;
    sscanf(line.c_str(),"%d:%d",&h,&m);
    bool ok=1;
    for(int j=m+1;j<60;j++){
          char res[15];
          sprintf(res,"%02d:%02d",h,j);
          string che=res;
          if(ispal(che)){
            ans=che;
            ok=0;
            break;
          }
    }    
    for(int i=(h+1)%24;ok;i=(i+1)%24){
        for(int j=0;j<60;j++){
          char res[15];
          sprintf(res,"%02d:%02d",i,j);
          string che=res;
          if(ispal(che)){
            ans=che;
            ok=0;
            break;
          }
        }
    }
    cout<<ans<<endl;  
    
    //system("pause");
    return 0;
}
