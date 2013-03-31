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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;
int N,M,ok,i;
int A[550];
int main(){

	ios::sync_with_stdio(false);
	while(cin>>N){
		if(N==-1)break;
		
		for(i=1;i<=N;i++)cin>>A[i];
		ok=1;
		while(ok){
			ok=0;
			for(i=1;i<=N;i++){
				if(A[i]==i){					
					ok=1;
					A[i]=0;
					for(int j=1;j<i;j++)A[j]+=1;
					break;	
				}			
			}
		}
		ok=1;
		for(i=1;i<=N;i++)if(A[i]!=0)ok=0;
		 
		if(ok==1)cout<<"S"<<endl;
		else cout<<"N"<<endl;
	} 	
	return 0;
}
