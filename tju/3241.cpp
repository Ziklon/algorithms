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
#define MAX 1000000
bool A[MAX+5];
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int n,x,a,b;
   fill(A,0);
   for(int i=2;i*i<=MAX;i++)
		if(!A[i])
			for(int j=i*2;j<=MAX;j+=i)
				A[j]=1;
	vector<int> primes;
	REP(i,2,MAX+1){
		if(!A[i]){
			x=i*i;
			if(x>MAX)break;
			primes.push_back(x);
		}
	}
	scanf("%d\n",&n);
	//cout<<primes.sz<<endl;
	while(n--){
		scanf("%d\n",&x);
		bool ok=0;
		REP(i,0,primes.sz){
			if(ok)break;
			a=primes[i];
			if(a>x)break;
			if(binary_search(all(primes),x-a))
				ok=1;
		}
		if(ok && (x&1))printf("yes\n");
		else printf("no\n");
	}
   //system("pause");
   return 0;
}
