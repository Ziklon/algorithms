#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	int N,a,b;
	while(cin>>N && N){
		map<pair<int,int>,int>M;
		for(int i=0;i<N;i++){
			cin>>a>>b;
			M[make_pair(a,b)]++;	
		}
		vector<pair<pair<int,int>,int > > v(M.begin(),M.end());
		bool ok=1;
		for(int i=0;i<v.size();i++){
			int na=v[i].second;
			if(M[make_pair(v[i].first.second,v[i].first.first)]!=na)
				ok=0;
		
		}
		puts(ok?"YES":"NO");	
	}
	return 0;
}
