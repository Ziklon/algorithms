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




int main(){
	ios::sync_with_stdio(false);
	double num;
	int ans;
	while(cin>>num){
		if(num==0.0)break;
		double sum=0;
		ans=0;
		for(int i=2;;i++){
			sum+=(1.0/i);
			if(sum>=num){
				ans=i-1;
				break;
			}
		}
		printf("%d card(s)\n",ans);				
	} 	
	return 0;
}




