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
int T[20][20],N;

int main(){
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=1;j<=5;j++){			
			int cur=((j-1)) + j;
			for(int k=1;k<=j;k++){
				int next=((k-1))+k;
				cin>>T[cur][next];	
			}				
		}
	
		
		for(int j=3;j<=9;j+=2){			
			for(int k=2;k<=j;k+=2){
				T[j][k]=(T[j-2][k-1]-(T[j][k-1]+T[j][k+1]))/2;
				T[j-1][k-1]=T[j][k-1]+T[j][k];
				T[j-1][k]=T[j][k]+T[j][k+1];		
			}
		}
		for(int j=1;j<=9;j++){
			for(int k=1;k<=j;k++){
				if(k>1)cout<<" ";
				cout<<T[j][k];
			}
			cout<<endl;
		}		
	} 	
	return 0;
}
