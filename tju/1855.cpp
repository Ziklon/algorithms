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
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int zeros(string& res){
	int dev=0;
	for(int i=0;i+1<res.sz;i++)
			if(res[i]=='0' && res[i+1]=='0')
				dev++;
	return dev;	
}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  string res="",aux;
  int N,dev;
  unsigned long long zeros[1001];
  memset(zeros,0,sizeof(zeros));
  zeros[2]=1;
  zeros[3]=1;
  for(int i=4;i<=1000;i++){
	zeros[i]=zeros[i-1]+2*zeros[i-2];		
  }
  while(cin>>N){			
		cout<<zeros[N]<<endl;				
   }
  //system("pause");
  return 0;
}
