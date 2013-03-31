#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
 
int a,num[120000],n,ans[120000],sz;
 
int main(){ 
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
	while (scanf("%d",&n) == 1){
    multiset<int> S;
    multiset<int>::iterator it;
    map<int,int> P;
    int x;
    for(a=0;a<n;a++) {
      scanf("%d",&x);
      S.insert(x);
      it = S.lower_bound(x);
      if (it==S.begin()) P[x]=-1; else { --it; P[x]=*it; ++it; }
      if (++it != S.end()) S.erase(it);
    }
    x=S.size();
		printf("%d\n",x);
	}
	return 0;
}
