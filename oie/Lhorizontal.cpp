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
  int m,n,dev=0;
  string line;
  cin>>m>>n;
  for(int i=0;i<m;i++){
  	cin>>line;
  	int cn=0;
  	for(int j=0;j<n;j++){
		if(line[j]=='-')
			cn++;
		else{
			if(cn>1)dev++;
			cn=0;
		}
	}
	if(cn>1)dev++;
  }
  cout<<dev<<endl;
  return 0;
}
