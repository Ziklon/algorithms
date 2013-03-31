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
int T,N,K,ans;
int dp[1000001][11];

string tos(int n){
	string ans="";
	while(n){
		ans=string(1,'0'+n%10)+ans;
		n/=10;
	}
	return ans;	
}
int toi(string s){
	int ans=0;
	for(int i=0;i<s.sz;i++)ans=(ans*10)+(s[i]-'0');
	return ans;
}

int go(int num, int k){
	if(k==0)return num;
	int& ref=dp[num][k];
	if(ref!=-1)return ref;
	ref=-INF;
	string cur=tos(num);
	
	for(int i=0;i<cur.sz;i++)
		for(int j=i+1;j<cur.sz;j++){
			swap(cur[i],cur[j]);
			if(cur[0]!='0')
				ref=max(ref,go(toi(cur),k-1));	
							
			swap(cur[i],cur[j]);
	
		}
		
	return ref;	
}



int main(){
	freopen("output","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>T;
	fill(dp,-1);
	
	for(int i=0;i<T;i++){
		cin>>N>>K;
		ans=go(N,K);
		if(ans<0)cout<<"-1"<<endl;
		else cout<<ans<<endl;		
		
	} 	
	return 0;
}
