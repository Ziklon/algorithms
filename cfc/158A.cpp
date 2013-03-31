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
using namespace std;
vector<int> v(5,0);
int n,t;
vector<int> aux;
int main(){
    //clock_t start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
    int ans=0,num;
    REP(i,0,n){
        scanf("%d",&num);
        v[num]++;
    }
	
    ans=v[4];
	int kk=min(v[1],v[3]);
    ans+=kk;
    v[1]-=kk;
    v[3]-=kk;
    kk=v[2]/2;
    ans+=kk;
    v[2]-=kk*2;

	int tt=v[1]+v[2]+v[3];
	
	while(tt>0){
		aux.clear();
		if(v[3])aux.push_back(3);
		REP(i,0,v[2]){
			aux.push_back(2);
			if(i==1)break;
		}
		REP(i,0,v[1]){
			aux.push_back(1);
			if(i==3)break;
		}
		int dif=5;
		int submask=0;
		for(int mask=1;mask<(1<<aux.sz);mask++){
			int ps=0;
			if(__builtin_popcount(mask)>4)continue;
			for(int i=0;i<aux.sz;i++){
				if(mask&(1<<i))
					ps+=aux[i];
			}
			if(ps<=4 && (4-ps)<dif){
				dif=4-ps;
				submask=mask;
			}			
		}
	
		for(int i=0;i<aux.sz;i++){
			if(submask&(1<<i)){
				v[aux[i]]--;
			
			}
		}

		ans++;		
		tt=v[1]+v[2]+v[3];
	}
	
    
    cout<<ans<<endl;
	

	
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
