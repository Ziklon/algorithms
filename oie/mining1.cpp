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

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int N,k,aux;
  cin>>N;
  for(int i=0;i<N;i++){
  	 cin>>k;
  	 vector<int>v;
  	 int dev=0,S=0,cost=0,gan=0;
  	 for(int j=1;j<=k;j++){
	 	cin>>aux; 	 	
	 	S+=aux;
	 	cost+=j;
	 	if(S-cost>gan){
			dev=j;
			gan=S-cost;
		}	 	
	 }
	 cout<<gan<<" "<<dev<<endl;
	 
	 
  } 
  return 0;
}
