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

bool check(vector<int>& v, int sep, int& C){
	int ind=0;
	int c=1;
	for(int i=1;i<v.sz;i++){
		if(v[i]-v[ind]>=sep){
			ind=i;
			c++;
		}
	}
	return c>=C;		
}

int main(){
	ios::sync_with_stdio(false);
	int T,N,C;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N>>C;
		vector<int> v(N);
		for(int j=0;j<N;j++)cin>>v[j];
		sort(all(v));
		
		int low=1;
		int hih=v[N-1];
		while(low<hih){
			int mid=(low+hih+1)/2;
			if(check(v,mid,C))
				low=mid;
			else
				hih=mid-1;		
		}
		cout<<low<<endl;
		
	}		
	return 0;
}
