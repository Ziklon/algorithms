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
    freopen("in.txt","r",stdin);
	int m,n,c,peki;
	
	while(scanf("%d %d %d",&n,&m,&c)==3 && n && m ){
		if(c==0){
			peki=((n-1)/8)*(m/8);
			peki=max(peki,((m-1)/8)*(n/8));
		}else{
			peki=(n/8)*(m/8);
		}
		printf("%d\n",peki);	
	}	
	return 0;
}