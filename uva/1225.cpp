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
#define MAX 5000
using namespace std;
int N,T;

int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d\n",&N);
	REP(i,0,N){
		scanf("%d",&T);
		vector<int> v(10,0);
		REP(j,0,T+1){
			int k=j;
			while(k){
				v[k%10]++;
				k/=10;
			}			
		}
		printf("%d",v[0]);
		REP(j,1,10)printf(" %d",v[j]);
		printf("\n");
	}
	return 0;
}