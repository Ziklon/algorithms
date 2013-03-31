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
vector<int> get(string s){
	istringstream is(s);
	vector<int> v;
	int tmp;
	while(is>>tmp)v.push_back(tmp);
	
	return v;
}
string line;

int solve(vector<int> a, vector<int> b){
	int ans=0;
	int index=-1;
	vector<bool> vis(55,0);
	for(int i=0;i<a.sz;i++){
		index=-1;
		for(int j=0;j<b.sz;j++){
			if(a[i]>b[j]){
				index=j;
			}
		}
		if(index>-1){
			ans+=2;
			b.erase(b.begin()+index);
			vis[i]=1;
		}
		
	}
	for(int i=0;i<a.sz;i++){
		if(vis[i])continue;
		index=-1;
		for(int j=0;j<b.sz;j++){
			if(a[i]==b[j]){
				index=j;
			}
		}
		if(index>-1){
			ans++;
			b.erase(b.begin()+index);
		}
	}
		
	return ans;
	
}

int main(){
	freopen("output","w",stdout);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	getline(cin,line);
	for(int i=0;i<N;i++){
		getline(cin,line);
		vector<int> peru=get(line);
		getline(cin,line);
		vector<int> other=get(line);
		sort(all(peru));
		sort(all(other));
		
		cout<<solve(peru,other)<<endl;
		
	} 	
	return 0;
}
