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
long long M,N,lo,up,mid,aux,P;


int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>M;
	REP(i,0,M){
		cin>>N;
		lo=0;
		P=2*N;
		//cout<<P<<endl;
		up=2*sqrt(N);
		for(int j=0;j<200;j++){
			mid=(lo+up)/2;
			aux=(mid*mid)+mid;
			if(aux<=P && aux>0){
				lo=mid;
			}else{
				up=mid;
			}
		}
		cout<<lo<<endl;
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
