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
  int n,x;
  string dd;
  string line;
  scanf("%d\n",&n);
  while(n--){
  	scanf("\n");
  	vector<pair<int,string> >vd;
  	getline(cin,line);
  	istringstream is(line);
  	while(is>>x)vd.push_back(mp(x,""));
  	getline(cin,line);
  	istringstream ds(line);
  	for(int i=0;ds>>dd;i++)
  		vd[i].second=dd;
  	sort(all(vd));
	for(int i=0;i<vd.sz;i++)
		cout<<vd[i].second<<endl;    	
	if(n)
		printf("\n");
  	
  }

  return 0;
}
