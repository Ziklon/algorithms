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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define oo 1<<30
using namespace std;


struct node{
	int index, solve, penal;
	node(){}
	node(int _ind, int _sol, int _penal){
		index=_ind;
		solve=_sol;
		penal=_penal;
	}
};

int T,P,A,S;
vector<vector<pair<int,int> > >v;
vector<node>score;
bool cmp(node p, node q){
	if(p.solve!=q.solve)return p.solve>q.solve;
	if(p.penal!=q.penal)return p.penal<q.penal;
	return p.index<q.index;
}

bool check(int error){
	vector<node> temp(T);
	REP(i,0,v.sz){
		int penalTi=0;
		int solve=0;
		REP(j,0,P){
			if(v[i][j].second){
				solve++;
				penalTi+=(v[i][j].second+((20)*(v[i][j].first-1)));
			}else{
				penalTi+=(v[i][j].second+((20)*(v[i][j].first)));				
			}		
		}
		temp[i]=node(i,solve,penalTi);			
	}
	sort(all(temp),cmp);
	REP(i,0,temp.sz)if(temp[i].index!=score[i].index)return 0;
	
	return 1;
}

void solve(){
	
	while(scanf("%d %d",&T,&P) && T){
		v.resize(T);
		score.resize(T);
		REP(i,0,T){
			int penalTi=0;
			int solve=0;
			REP(j,0,P){
				scanf("%d/%d",&A,&S);
				v[i].push_back(make_pair(A,S));
				
				if(v[i][j].second){
					solve++;
					penalTi+=(v[i][j].second+((20)*(v[i][j].first-1)));
				}else{
					penalTi+=(v[i][j].second+((20)*(v[i][j].first)));				
				}
			}
			score[i]=node(i,solve,penalTi);	
		}
		sort(all(score),cmp);
		
		int low=20;
		int hih=1<<28;
		cout<<check(25)<<endl;
		while(low<hih){
			int mid=(low+hih+1)/2;
			if(check(mid))
				low=mid;
			else
				hih=mid-1;
		
		}
		printf("%d %d\n",20,low);
		
	}
	
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

