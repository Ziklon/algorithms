#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()

#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int X[22],Y[22];
int XX[102],YY[102],SS[102];
vector<int> VM[22];
bool vis[102];

int main(){
   //freopen("in2.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int K,R,M,N;
   scanf("%d %d",&K,&R);
   scanf("%d",&M);
   REP(i,0,M)
   	scanf("%d %d",&X[i],&Y[i]);
   	
   scanf("%d",&N);
   int hm,val;
   REP(i,0,N)
       scanf("%d %d %d",&XX[i],&YY[i],&SS[i]);
	int ans=0,cn;	
	REP(i,0,M)		
		REP(j,0,N)
			if(hypot(X[i]-XX[j],Y[i]-YY[j])<=R)
				VM[i].push_back(j);
	hm= 1<<M;			
	REP(mask,(1<<(K-1))-1,hm){
		if(__builtin_popcount(mask)==K){
			memset(vis,1,N);
                        cn=0;
			REP(i,0,M)				
				if(mask&(1<<i)) // lugar i 
			 		REP(j,0,VM[i].size()){
                     val=VM[i][j];
							if(vis[val]){
								cn+=SS[val]; 
								vis[val]=0;
							}
					}
			ans=max(ans,cn);			
		}
	}
	printf("%d\n",ans);
   
   //system("pause");
   return 0;
}
