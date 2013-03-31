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
long long N,dev,A,M,aux;

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  cin>>N;
  A=N;
  M=1;
  stringstream ss;
  string res;
  for(int i=9;i>1 && N>1;i--){
	if(N%i==0 && N>1){
		ss<<i;
		N/=i;
		i++;		
	}		
  }
  if(A==1)
  	cout<<1<<endl;
  else if(A<10)
  	cout<<1<<A<<endl;
  else{
	res=ss.str();
	reverse(all(res));
	if(N==1)		
	  cout<<res<<endl;
	else
		cout<<-1<<endl;		
  }	
  return 0;
}
