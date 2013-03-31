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

using namespace std;
int sum(int N){
	int ans=0;
	while(N>0){
		ans+=N%10;
		N/=10;
	}
	return ans;
}
bool isSmith(int N){
	int S=sum(N);
	int A=0;
	for(int i=2;i*i<=N;i++){
		while(N%i==0){
			A+=sum(i);
			N/=i;
		}
	}
	if(A==0)return 0;
	if(N>1)A+=sum(N);
	return A==S;
}


int main(){
    //freopen("in.txt","r",stdin);
	int N;
	
	while(cin>>N && N>0){
		N++;
		while(!isSmith(N))N++;
		
		cout<<N<<endl;
		
	}	
	return 0;
}