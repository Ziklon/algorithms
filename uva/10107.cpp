#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
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
#define sz size()
using namespace std;
vector<int> v;
void add(int n){
	int pos=lower_bound(all(v),n)-v.begin();
	v.insert(v.begin()+pos,n);	
}

int main(){
	//freopen("in.txt","r",stdin);
	int num,n;
	long long peki;
	while(scanf("%d",&num)==1){
		add(num);
		n=v.sz;
		if(n&1)
			peki=v[n/2];
		else 
			peki=(v[n/2]+v[(n/2)-1]+0LL)/2;
		printf("%lld\n",peki);	
	}
	return 0;
	
}