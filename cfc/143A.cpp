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
int A[8];
int B[8];
int main(){
	freopen("in.txt","r",stdin);	
	vector<int> v;
	REP(i,0,6)cin>>A[i];
	
	REP(i,1,10)v.push_back(i);
	do{
		B[0]=v[0]+v[1];
		B[1]=v[2]+v[3];
		B[2]=v[0]+v[2];
		B[3]=v[1]+v[3];
		B[4]=v[0]+v[3];
		B[5]=v[1]+v[2];
		bool ok=1;
		REP(i,0,6)if(A[i]!=B[i])ok=0;
		
		if(ok){
			printf("%d %d\n",v[0],v[1]);
			printf("%d %d\n",v[2],v[3]);
			return 0;
		}
	}while(next_permutation(all(v)));
	printf("-1\n");
	return 0;
}