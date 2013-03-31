#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz size()
using namespace std;



int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int nC,W,H,mW;
	long long N,P1,W1,M,K,A,B,C,D;
	
	cin>>nC;
	REP(i,0,nC){
		cin>>N>>P1>>W1>>M>>K>>A>>B>>C>>D;
		
		vector<pair<int,int> >v; 
		v.push_back(make_pair(P1,W1));
		REP(j,1,N){
			int a=(((v[j-1].first*A)+B)%M)+1;
			int b=(((v[j-1].first*C)+D)%K)+1;
			v.push_back(make_pair(a,b));
		}
		sort(all(v));
		REP(j,0,v.sz)
			cout<<v[j].first<<" "<<v[j].second<<endl;
		cout<<endl;
	}
	
	return 0;

}