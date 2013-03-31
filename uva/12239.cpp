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
int N,B;
int A[100];
bool vis[100],ok;


int main(){
	ios::sync_with_stdio(false);
	while(cin>>N>>B){
		
		if(N==0 && B==0)break;
		
		for(int i=0;i<B;i++)cin>>A[i];
		
		fill(vis,0);
		ok=1;
		
		for(int i=0;i<B;i++)for(int j=i+1;j<B;j++){
			vis[A[i]]=1;
			vis[A[j]]=1;
			vis[abs(A[i]-A[j])]=1;	
		}
		for(int i=0;i<=N;i++)if(vis[i]==0)ok=0;
		
		if(ok)cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	} 	
	return 0;
}
