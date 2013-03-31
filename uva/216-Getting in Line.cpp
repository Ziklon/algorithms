#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define INF 1e10
using namespace std;
typedef long long ll;

int N;
vector<pair<int,int> >v;
double dis[8][8];

int main(){
	ios::sync_with_stdio(false);
	int NC=1;
	while(cin>>N && N){
		v.resize(N);
		for(int i=0;i<N;i++)cin>>v[i].first>>v[i].second;
		
		vector<int> vi(N),tmpv;
		for(int i=0;i<N;i++)vi[i]=i;
		
		for(int i=0;i<8;i++)for(int j=0;j<i;j++){
			dis[i][j]=dis[j][i]=hypot(v[i].first-v[j].first,v[i].second-v[j].second)+16;
		}
		
		double ans=INF;
		do{
			double cost=0;
			for(int i=1;i<N;i++)cost+=dis[vi[i-1]][vi[i]];			
			if(cost<ans){
				tmpv=vi;
				ans=cost;
			}			
		}while(next_permutation(vi.begin(),vi.end()));
		
		printf("**********************************************************\n");
		printf("Network #%d\n",NC++);
		vi=tmpv;
		for(int i=1;i<N;i++){
			int p=vi[i-1];
			int q=vi[i];
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",v[p].first,v[p].second,v[q].first,v[q].second,dis[p][q]);
		}
			
		printf("Number of feet of cable required is %.2f.\n",ans);	
	}		
	
			
	return 0;
}
