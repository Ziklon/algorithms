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

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,x,y;
  while(cin>>n>>x>>y){
	if(n==0 && x==0 && y==0)break;
  	int dev=1<<30,aux=0;
  	dev=(n-1)*x;
  	while(n>1){
		if(n&1){
			n--;
			aux+=x;
		}else{
			n/=2;
			aux+=min(y,n*x);
		}	
	}
	dev=min(dev,aux);
	cout<<dev<<endl; 	
  }

  return 0;
}
