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
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;
int y,k,n;
int main(){
	
	while(cin>>y>>k>>n){
		int cn=0;
		for(int a=k;a<=n;a+=k){
			int x=a-y;
			if(x>=1){
				cn++;
				printf("%d ",x);
			}
		}
		if(cn==0)printf("-1\n");
		else printf("\n");
	}	
	return 0;
}
