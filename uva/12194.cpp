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
#define x first
#define y second 
using namespace std;
typedef long long ll;
int N,ans,mid;
pair<int,int> P[1<<10];
pair<int,int> tmp;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>N && N) {
		vector<int> A;
		vector<int> B;
		
		for(int i=0;i<N;i++){
			cin>>P[i].x>>P[i].y;
			A.push_back(P[i].x);
			B.push_back(P[i].y);
		}
		
		sort(P,P+N);
		sort(all(A));
		sort(all(B));
		ans=0;
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
			int aa=0;
			if(P[i].x==P[j].x){
				mid=abs(P[i].y-P[j].y);
				if((mid&1)==0){
					mid=P[i].y+(mid/2);
					if(binary_search(all(B),mid))
						aa++;			
		
				}
			}
			if(P[i].y==P[j].y){
				mid=abs(P[i].x-P[j].x);
				if((mid&1)==0){
					mid=P[i].x+(mid/2);
					if(binary_search(all(A),mid))aa++;			
		
				}
			}			
			tmp.y=P[i].x+(P[j].x-P[i].x);
			tmp.x=P[i].y+(P[j].y-P[i].y);
			
			if(binary_search(P,P+N,tmp))aa++;			
			
			
			if(aa)ans++;
									
		}
		cout<<ans<<endl;
	} 	
	return 0;
}
