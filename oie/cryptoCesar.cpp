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
  int n,k;
  string s;
  cin>>n;
  while(n--){
  	 cin>>s;
  	 s=s.substr(0,s.sz-1);
  	 k=(26+s[s.sz-1]-'R')%26;
  	 for(int i=0;i<s.sz;i++)
  	 	s[i]='A'+((26+s[i]-'A'-k)%26);
  	cout<<s<<endl;
  }

  return 0;
}
