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
using namespace std;


vector<int> factors(int n){
	vector<int> v;
	//cout<<n<<endl;
	while(n>1 && n%2==0){
		v.push_back(2);
		n/=2;
	}
	long long i;
	for(i=3;i*i<=n;i+=2){
		while(n>1 && n%i==0){
			n/=i;
			v.push_back(i);
		}
	}
	//cout<<i<<endl;
	if(n>1)v.push_back(n);
	return v;
}

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	vector<int> v;
	while(scanf("%d",&n)==1 && n!=0){
		v=factors(abs(n));
		printf("%d = ",n);
		if(n<0)printf("-1 x ");
		printf("%d",v[0]);
		REP(i,1,v.sz)printf(" x %d",v[i]);
		printf("\n");
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
