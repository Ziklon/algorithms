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
int s,t;
double h,x,peki;

double eval(double x){
	return sqrt((x+1)/x)/x;
}


int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d %d\n",&s,&t)==2){
		h=(t-s)/(2.0*1000.0);
		x=s;
		peki=eval(x);
		for(int i=0;i<1000;i++){
			x=x+h;
			peki=peki+(4*eval(x));
			x=x+h;
			peki=peki+(2*eval(x));
		}
		peki=peki-(eval(x));
		peki=(peki*h)/3.0;
		printf("%.2f\n",peki);
	
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
