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

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    double a,b,c,x,y,z;
    scanf("%d\n",&n);
    REP(i,0,n){
      cin>>a>>b>>c;
      z=(b*b)-(4*a*c);
      if(z>=0){
        x= (-b+ sqrt(z))/(2*a);
        y= (-b -sqrt(z))/(2*a);
        if(x!=y)
          printf("%0.3f %0.3f\n",min(x,y),max(x,y));
        else
          printf("%0.3f\n",x);
      }else{
        printf("No solution!\n");
      }
    }
    
    //system("pause");
    return 0;
}
