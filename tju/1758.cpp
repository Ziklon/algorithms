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
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  double A;
  int L;
  while(cin>>A>>L){
	double mini=1e+30;
	int X,Y;
	for(int D=1;D<=L;D++){
		int N=(int)(A*D);
		for(int B=max(1,N-2);B<=min(N+2,L);B++){
			double C=((double)B)/D;
			if(abs(C-A)<mini){
				mini=abs(C-A);
				X=B;
				Y=D;	
			}	
		}	
	}
	cout<<X<<" "<<Y<<endl;
  }
  //system("pause");
  return 0;
}
