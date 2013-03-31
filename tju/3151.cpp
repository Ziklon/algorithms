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
    int k,n=1;
    string a,b,c;
    scanf("%d\n",&k);
    while(k--){
      getline(cin,a);
      getline(cin,b);
      c="";
      REP(i,0,a.sz){
         if(isalpha(a[i]))
            c+=b[a[i]-'A'];
         else
            c+=a[i];
      }
      printf("%d %s\n",n++,c.c_str());
    }  
    //system("pause");
    return 0;
}
