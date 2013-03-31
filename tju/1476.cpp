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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define MOD 1000000007
using namespace std;
long long A[60],N,o,p;
int K;
int main(){
    //freopen("in.txt","r",stdin);
	scanf("%d",&K);
	A[0]=1;
	A[1]=2;
	REP(i,2,60)A[i]=A[i-1]*2LL;	
	REP(k,0,K){
		cin>>N;
		REP(j,0,60){
			p=j;
			o=N/A[j];
			if((o&1) && N%A[j]==0){
				break;
			}
		}
		cout<<o<<" "<<p<<endl;
	}
	return 0;
}