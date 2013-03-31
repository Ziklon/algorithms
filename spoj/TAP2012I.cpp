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
int N,ans,tmp;
int A[1<<7];

int main(){
	ios::sync_with_stdio(false);
	while(cin>>N){
		if(N==-1)break;
		for(int i=0;i<N;i++)cin>>A[i];
		ans=0;
		tmp=0;
		for(int i=0;i<N;i++){
			tmp=(tmp+A[i])%100;
			if(tmp==0)ans++;
			
		}		
		cout<<ans<<endl;	
	} 	
	return 0;
}




