#include <vector>
#include <map>
#include <set>
#include <queue>
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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
string dat[101];
int ord[101],res[101];

bool orden(int a, int b){
	if(ord[a]!=ord[b])
		return ord[a]<ord[b];
	return a<b;
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int M,n,m,ax;
  scanf("%d\n",&M);
  while(M--){
	scanf("\n");
  	scanf("%d %d\n",&n,&m);
  	char line[n+2];
  	for(int i=0;i<m;i++){
		scanf("%s\n",line);
		dat[i]=line;
		ax=0;
		for(int j=0;j<n;j++)
			for(int k=j+1;k<n;k++)
				if(dat[i][j]>dat[i][k])
					ax++;
		ord[i]=ax;
		res[i]=i;
	}
	sort(res,res+m,orden);
	for(int i=0;i<m;i++)
		printf("%s\n",dat[res[i]].c_str()); 
	if(M)
		printf("\n");	
  	
  }
  

  return 0;
}
