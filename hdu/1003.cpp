#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <functional>
#include <numeric>
using namespace std;
#define all(V) (V).begin(),(V).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a, long long b){return a*(b/gcd(a,b));}
int T, N [100010],n,C;
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
	scanf("%d",&T);
	C=1;
	while(T){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&N[i]);
		int thisSum=N[0];
		int maxSum=-1<<20;
		int seqStart = 0,ansx;
		int suma=0;
      int seqEnd   = 0;
		for( int j = 1; j < n; j++ ){
         if( (thisSum+N[j]) < N[j] ){
            thisSum=N[j];
            seqStart=j;
         }
         else
            thisSum+=N[j];
         if(maxSum<thisSum){
            maxSum=thisSum;
            ansx=seqStart;
            seqEnd=j;
         }
      }
      printf("Case %d:\n",C);
      printf("%d %d %d\n",maxSum,ansx+1,seqEnd+1); 
      if(T)printf("\n");
      C++;	
		T--;
	}

}
