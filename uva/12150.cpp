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
int n;
int N,x,y,ok,z;
int B[1<<10];
int main(){
	ios::sync_with_stdio(false);
	

	while(cin>>N && N){
		for(int i=0;i<N;i++){
			B[i]=-1;
		}
		ok=1;
		for(int i=0;i<N;i++){
			cin>>x>>y;
			z=i+y;
			if(z>=0 && z<N && B[z]==-1){
				B[z]=x;	
			}else{
				ok=0;
			}
						
		}
		
		if(ok==0) cout<<-1<<endl;
		else{
			for(int i=0;i<N;i++){
				if(i)cout<<" ";
				cout<<B[i];
				
			}
			cout<<endl;
		}
				
	}
	return 0;
}

