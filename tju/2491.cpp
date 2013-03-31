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
    string cline,text;
    int nv,n;
    while(getline(cin,cline)){
      if(cline==".")break;
      istringstream is(cline);
      is>>text>>nv;
      n=text.sz;
      REP(i,0,n){
         int p=i;
         REP(k,0,n*nv){
            printf("%c",text[p]);
            p=(p+1)%n;
         }
         printf("\n");
      }
      
    }  
    //system("pause");
    return 0;
}
