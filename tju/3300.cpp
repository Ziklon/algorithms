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
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
#define MAX 3000002
int A[MAX],a,b;
long long dev;
long long S[MAX];
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
	
  REP(i,0,MAX)A[i]=i;
  
  REP(i,1,MAX)
  	for(int j=2*i;j<MAX;j+=i)
  		A[j]-=A[i];

  S[0]=0;
  REP(i,1,MAX)
  	S[i]=S[i-1]+A[i];
     	
  while(cin>>a>>b){
	 printf("%lld\n",(S[b]-S[a-1]));

  }  	
  //system("pause");
  return 0;
}
