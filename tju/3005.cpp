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
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
typedef long long ll;
string cad;
int nc;
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int N=GI;
  double M,dev;
  nc=1;
  while(N--){
  	cin>>M>>cad;
  	if(cad=="kg"){
		dev=M*2.2046;
		printf("%d %0.4f lb",nc++,dev);	
	}
	if(cad=="l"){
		dev=M*0.2642;
		printf("%d %0.4f g",nc++,dev);	
	}
	if(cad=="lb"){
		dev=M*0.4536;
		printf("%d %0.4f kg",nc++,dev);	
	}
	if(cad=="g"){
		dev=M*3.7854;
		printf("%d %0.4f l",nc++,dev);	
	}
	printf("\n");
  }
  return 0;
}
