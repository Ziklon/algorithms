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
int A;
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  vector<long long> ones;
  long long N=1,C=1;
	ones.pb(1);
  while(N+C<=2147516417){
	N=N+C;
	ones.pb(N);
	C++;	
  }
  int nC;
  scanf("%d",&nC);
  for(int i=0;i<nC;i++){
	scanf("%d",&A);
	if(binary_search (ones.begin(), ones.end(), A))
		printf("1");
	else
		printf("0");
	if(i+1!=nC)
		printf(" ");	
  }
  //system("pause");
  return 0;
}
