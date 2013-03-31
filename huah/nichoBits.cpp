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
int T,N,ans;
int main(){
	freopen("output","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		ans=0;
		while(N){
			ans++;
			N/=2;
		}
		cout<<ans<<endl;
	} 	
	return 0;
}
