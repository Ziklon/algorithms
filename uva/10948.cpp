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
#define MAX 1000000
using namespace std;
bool S[1000009];
int main(){
	//freopen("in.txt","r",stdin);
	int n,a,b;
	fill(S,1);
	
	for(int i=2;i*i<=MAX;i++)
		if(S[i])
			for(int j=i*i;j<=MAX;j+=i)
				S[j]=0;
	vector<int> v;
	REP(i,2,MAX+1)if(S[i])v.push_back(i);
	
	while(scanf("%d",&n)==1 && n){
		bool ok=0;
		printf("%d:\n",n);
		for(int i=0;i<v.sz;i++){
			if(v[i]>(n/2))break;
			a=v[i];
			b=n-v[i];
			if(binary_search(all(v),b)){
				printf("%d+%d\n",a,b);
				ok=1;
				break;
			}
		}
		if(!ok)printf("NO WAY!\n");
	}
	return 0;
}