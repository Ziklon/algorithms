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


int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	string num;
	cin>>n>>num;
	num=num.substr(0,n);
	bool ok=1;
	REP(i,0,n)if(num[i]!='4' && num[i]!='7')ok=0;
	
	int A=0,B=0;
	REP(i,0,n/2){
		A+=num[i];
		B+=num[(n/2)+i];
	}
	if(A!=B)ok=0;
	if(ok)puts("YES");
	else puts("NO");
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
