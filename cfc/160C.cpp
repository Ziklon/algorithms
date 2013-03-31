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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define oo 1<<30
using namespace std;
long long n,k,val,aux;



void solve(){
	cin>>n>>k;
	map<long long,long long>M;
	vector<long long> v(n);
	REP(i,0,n){
		cin>>val;
		M[val]++;
		v[i]=val;
	}
	sort(all(v));
		int val=0,vec;
		int index=0;
		foreach(M,it){
			val=it->first;
			vec=it->second;
			aux=vec*n;
			if(aux>=k)break;
			k-=aux;
		}
		index=0;
		int ubi=0;
		foreach(M,it){
			aux=vec*it->second;
			if(aux>=k){
				index=it->first;
				break;
			}
			k-=aux;
		}
		//cout<<index<<" "<<endl;
		//printf("%I64d %I64d\n",val,v[index]);
		cout<<val<<" "<<index<<endl;
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

