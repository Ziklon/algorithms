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
    long long a,b,c;
    double r;
    int k=1;
    while(cin>>a>>b>>c){
      if(a==0 && b==0 && c==0)break;
    
      r=-1.0;
      printf("Triangle #%d\n",k++);
       if(c==-1){
         r=sqrt((b*b)+ (a*a));
         printf("c = ");
       }
       if(a==-1 && c>b){
         r=sqrt((c*c) - (b*b)); 
         printf("a = ");
      }
      if(b==-1 && c>a){
         r=sqrt((c*c) - (a*a));
         printf("b = "); 
      }
      if(r>=0)
        printf("%0.3f\n",r);
      else
        printf("Impossible.\n");
      printf("\n");
      
    }
    //system("pause");
    return 0;
}
