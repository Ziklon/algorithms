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

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int nC;
  while(cin>>nC){
	if(nC==0)break;
	int res=0,d,y=0;
	for(int i=0;i<nC;i++){
		cin>>d;
		int r=d-y;
		if(r>0)
			res+=(6*(abs(d-y)))+5;
		else
			res+=(4*(abs(d-y)))+5;		
		
		y=d;	
	}
	cout<<res<<endl;	
  }
  system("pause");
  return 0;
}
