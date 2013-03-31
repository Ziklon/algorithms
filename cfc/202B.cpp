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
#define INF 1<<30
using namespace std;
int N,K,M;
vector<string> pro,per;
vector<vector<string> >vs;

bool get(int p,string&s){
	REP(i,p,pro.sz)if(pro[i]==s)return 0;
	return 1;
}

int getInv(vector<string>&v){
	int ans=0;
	
	REP(i,0,v.sz)
		REP(j,i+1,v.sz){
			ans+=get(i+1,v[j]);	
		}
	return ans;	
}

bool found(vector<string>& v, int k){
	int x=0,y=0;
	while(x<v.sz && y<vs[k].sz){
		if(v[x]==vs[k][y]){
			x++;
			y++;
		}else{
			y++;
		}
	}
	return x>=v.sz;

}


void solve(){
	cin>>N;
	int P=(N*(N-1))/2;
	pro.resize(N);
	per.resize(N);
	REP(i,0,N){
		cin>>pro[i];
		per[i]=pro[i];
	}
	cin>>K;
	vs.resize(K);
	
	REP(i,0,K){
		cin>>M;
		vs[i].resize(M);
		REP(j,0,M)cin>>vs[i][j];	
	}

	
	int res=-1;
	int simi=INF;
	sort(all(per));
	
	do{
		int inv=getInv(per);
			
		REP(i,0,K){
			if(found(per,i)){
				
				if((res==-1 || inv<simi) || (res>i && inv==simi)){
					res=i;
					simi=inv;					
				}					
			}
		
		}
		
	
	}while(next_permutation(all(per)));
	
	simi=P-simi+1;
	if(res==-1)puts("Brand new problem!");
	else{
		cout<<(res+1)<<endl;
		cout<<"[:"<<string(simi,'|')<<":]"<<endl;
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

