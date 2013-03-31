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
int n,ans;
int main(){
	while(scanf("%d",&n)==1){
		ans=1;
		int five=0;
		int two=0;
		for(int i=2;i<=n;i++){
			int cur=i;
			while(cur%2==0){
				cur/=2;
				two++;
			}
			while(cur%5==0){
				cur/=5;
				five++;
			}
			ans=(ans*cur)%10;
		}
		for(int i=0;i<(two-five);i++)ans=(ans*2)%10;
		printf("%5d -> %d\n",n,ans);
	}	
	return 0;
}
