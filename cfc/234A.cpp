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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
int n;
string s;
void solve(){
	cin>>n>>s;
	vector<pair<int,int> >v;
	for(int i=0;i*2<n;i++){
		v.push_back(make_pair(i,i+(n/2)));
	}
	REP(i,0,v.sz){
		int a=v[i].first;
		int b=v[i].second;
		if(s[a]==s[b])
			cout<<(a+1)<<" "<<(b+1)<<endl;
		else{
			int c=a;
			int d=b;
			if(s[b]=='L')c=b;
			if(s[a]=='R')d=a;
			cout<<(c+1)<<" "<<(d+1)<<endl;	
		}
	}
	
}
int main(){
	//freopen("E:/input.txt","r",stdin);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	solve();	
	return 0;
}

