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

void mini(int& a,int& b,int c, int d){
    if((c+d)<(a+b)){
        a=c;
        b=d;
    }
    if((c+d)==(a+b)){
      if(c>a){
         a=c;
        b=d; 
     }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,a=1000000,b=1000000;
    cin>>n;
    bool ok=0;
    string ans=string(1000000,'7');
    for(int i=0;i*7<=n;i++){
        m=n-(7*i);
        if(m%4==0){
          ok=1;
          mini(a,b,m/4,i);          
        }
    }
    if(ok)cout<<string(a,'4')<<string(b,'7')<<endl;
    else cout<<"-1"<<endl;
    //system("pause");
    return 0;
}
