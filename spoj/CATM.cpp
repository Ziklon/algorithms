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
int n,m,k;
int A[1<<3];
int step;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>k;
	for(int i=0;i<k;i++){
		for(int j=0;j<6;j++)cin>>A[j];
		bool ok=0;
		//n is rows
		//m is columns
		vector<pair<int,int> >v;
		v.push_back(make_pair(1,A[1]));//UP
		v.push_back(make_pair(n,A[1]));//DOWN
		v.push_back(make_pair(A[0],1));//LEFT
		v.push_back(make_pair(A[0],m));//RIGHT
		
		for(int j=0;j<v.sz;j++){
			int dis=abs(A[0]-v[j].first)+abs(A[1]-v[j].second);
			int daa=abs(A[2]-v[j].first)+abs(A[3]-v[j].second);
			int dbb=abs(A[4]-v[j].first)+abs(A[5]-v[j].second);
			if(dis<min(daa,dbb))ok=1;
			//cout<<dis<<" "<<daa<<" "<<dbb<<" - "<<v[j].first<<" "<<v[j].second<<endl;			
		}
		if(ok)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	 
		
	} 	
	return 0;
}
