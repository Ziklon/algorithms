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


int main(){
	ios::sync_with_stdio(false);
	while(cin>>N){
		if(N==-1)break;
		ans=0;
		
		for(int i=1;i*i<=N;i++) if(N%i==0)ans++;
				
		for(int i=1;i<=N;i++){
			tmp=N-i;		
			for(int j=1;j*j<=tmp;j++){
				if(tmp%j==0){
					int z=j;
					int y=tmp/j;
					if(i%(z+y)==0){
						int x=i/(z+y);
						if(x>=y && y>=z)ans++;
					}					
				}				
			}			
			
		}
		cout<<ans<<endl;
		
	} 	
	return 0;
}




