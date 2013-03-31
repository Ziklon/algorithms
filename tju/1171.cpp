#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
int N,P,Q,Z;

bool dat[1000001];
int main(){
	
	mem(dat,1);
	vector<int> v;
	v.push_back(2);
	for(int i=3;i*i<=1000001;i+=2){
		if(dat[i]){
			v.push_back(i);
			for(int j=2*i;j<=1000001;j+=i)
				dat[j]=0;
		}
	}
	while(scanf("%d\n",&N)==1){
		P=0;Q=0;
		if(N==0)break;
		for(int i=0;i<v.size() && v[i]<N;i++){
			Z=N-v[i];
			if(find(v.begin()+i,v.end(),Z)!=v.end() && abs(Z-v[i])>abs(P-Q)){
				P=v[i];
				Q=Z;
			}
		}
		if(P!=Q)
			printf("%d = %d + %d\n",N,P,Q);	
		else
			printf("Goldbach's conjecture is wrong.\n");	
	}
	return 0;
}
