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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
#define MAX 100005
using namespace std;
int m,k,n,nu,x;
char buff[24];
vector<int> fav;
int A[105],mx;
int B[105];
int R[105];


int get(vector<int> v, int n){
	int ans=0;
	sort(all(v));
	for(int i=1;i<=m;i++){
		if(n==0)return 0;
		if(!binary_search(all(fav),i) && !binary_search(all(v),i)==0){
			n--;
		}		
	}
	return n;
}


void solve(){
	scanf("%d %d",&m,&k);
	fav.resize(k);
	REP(i,0,k)scanf("%d",&fav[i]);
	
	sort(all(fav));
	scanf("%d",&n);
	mx=0;
	REP(i,0,n){
		scanf("%s",buff);
		scanf("%d",&nu);
		int cn=0;
		int zero=0;
		vector<int> tmp;
		REP(j,0,nu){
			scanf("%d",&x);
			tmp.push_back(x);	
			if(x==0)
				zero++;
			else if(binary_search(all(fav),x)){
				cn++;
			}			
		}
		sort(all(tmp));
				
		mx=max(mx,cn);
		A[i]=cn+get(tmp,zero);
		B[i]=zero;
		mx=max(mx,A[i]);
		int no=0;
				
	}
	int rt=0;
	
	
	REP(i,0,n){
		int a=min(k-A[i],B[i]);
		if(A[i]+a>=mx){
			R[i]=2;
			rt=max(rt,A[i]+a);
		}
	}
	
	REP(i,0,n){
		if(A[i]==rt)
			printf("0\n");
		else if(R[i]==2)
			printf("2\n");
		else printf("1\n");	
	}
	
}
int main(){
	freopen("E:/input.txt","r",stdin);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	solve();	
	return 0;
}