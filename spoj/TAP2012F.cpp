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

string cad;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>N){
		if(N==-1)break;
		vector<pair<int,int> > v;
		for(int i=2;i<=N;i++){
			cin>>cad;
			for(int j=0;j<cad.sz;j++){
				if(cad[j]=='1')
					v.push_back(make_pair(j,-i));
			}
		}
		sort(all(v));
		for(int i=0;i<v.sz;i++)cout<<(-v[i].second);
		cout<<endl;		
	} 	
	return 0;
}




