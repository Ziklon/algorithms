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

vector<int> get(string s){
	istringstream is(s);
	vector<int> v;
	int tmp;
	while(is>>tmp)v.push_back(tmp);
	
	return v;
}

int main(){
	freopen("output","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>T;
	string line;
	getline(cin,line);
	
	for(int i=0;i<T;i++){
		getline(cin,line);		
		vector<int> tables=get(line);
		vector<int> busy(55,0);
		sort(all(tables));
		
		getline(cin,line);
		vector<int> groups=get(line);
		getline(cin,line);
		vector<int> start=get(line);
		getline(cin,line);
		vector<int> end=get(line);
		
		int ans=0;
		for(int i=0;i<groups.sz;i++){
			int index=-1;
			for(int j=0;j<tables.sz;j++){
				if(tables[j]>=groups[i] && busy[j]<=start[i]){
					index=j;
					break;
				}
			}
			if(index==-1){
				ans+=groups[i];
			}else{
				busy[index]=end[i];
			}
		}
		cout<<ans<<endl;		
		
	} 	
	return 0;
}
