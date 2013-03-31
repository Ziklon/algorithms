#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}


long long length(string& name){
	long long dev=0;
	for(int j=0;j<name.sz;j++)
		dev+=(name[j]-'A'+1);
	return dev;	
}
long long dev=0,A,N;
int main(){
  freopen("costo.txt","r",stdin);
  freopen("out.txt","w",stdout);
  string name;
  N=1;
  vector<string> vs;
  while(cin>>name)vs.pb(name);
  sort(all(vs));
  dev=0;  
  for(int i=0;i<vs.sz;i++){
    A=length(vs[i]);
	dev=dev+(A*N);
	N++;	
  }
  cout<<dev<<endl;
  system("pause");
  return 0;
}
