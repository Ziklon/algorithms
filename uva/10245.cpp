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
#define sz size()
using namespace std;
int N;
double x,y;
pair<double,double> P[10005];
double peki;
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d\n",&N)==1 && N){
		REP(i,0,N){
			scanf("%lf %lf\n",&x,&y);
			P[i]=make_pair(x,y);
		}
		sort(P,P+N);
		
		//printf("INFINITY\n");
	}
	return 0;
}