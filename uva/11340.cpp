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
  int n,k,l;
  scanf("%d\n",&n);
  string line;
  while(n--){
  	scanf("%d\n",&k);
  	int res=0;
  	map<char,int>M;
  	for(int i=0;i<k;i++){
	  char cc;
	  int dd;
	  scanf("%c %d\n",&cc,&dd);
	  M[cc]=dd;
	}
	scanf("%d\n",&l);
	for(int i=0;i<l;i++){
      getline(cin,line);
      for(int j=0;j<line.sz;j++)
      	res+=M[line[j]];
    }
    double cents=res/100.0;
    printf("%0.2f$\n",cents);
  }

  return 0;
}
