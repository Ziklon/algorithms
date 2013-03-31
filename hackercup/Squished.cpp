#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz size()
#define MOD 4207849484LL
using namespace std;
int nC,M,T;
long long peki,ah,res;
string cad,aux;

long long dp[1001][1001];
bool check(string s){
	int num=0;	
	REP(i,0,s.sz)num=num*10+(s[i]-'0');
	return num>=1&&num<=M;
}

long long combi(){
	REP(i,0,1001){
		dp[i][0]=1;
		dp[i][i]=1;
	}
	REP(i,1,1001){
		REP(j,1,i){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
		}
	}
}
int Tam(int M){
	if(M>=1 && M<10)return 1;
	if(M>=10 && M<100)return 2;
	return 3;
	
}


int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);	
	scanf("%d",&nC);
	fill(dp,0);
	combi();
	
	REP(i,0,nC){
		cin>>M>>cad;
		peki=0;
		T=cad.sz;
		map<pair<int,int> ,int >Mapa;
		REP(j,1,T+1){
			for(int k=0;k+j<=cad.sz;k++){
				aux=cad.substr(k,j);
				int ned=2-(k==0|| k+j==cad.sz);
				if(!check(aux)){
					Mapa[make_pair(aux.sz,ned)]++;
				}
			}			
		}
		
		REP(j,1,T){			
			ah=(dp[T-1][j])%MOD;
			int dig=T-j;
			res=0;
			foreach(Mapa,it){
				pair<int,int> p=it->first;
				int rep=it->second;
				if(p.first<=dig){
					res+=(dp[T-1-p.first-1-p.second][j-p.second]);
				}
			}				
			peki+=max(ah-res,0LL);
			peki%=MOD;		
			
		}
		printf("Case #%d: %lld\n",i+1,peki);
		
				
	}
	return 0;

}