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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long memo[6000];

bool isHumble(long long n){
  for(int i=7;i>=2 && n>1;i--){
    while(n%i==0)
		 n/=i;
	}
	return n<=1;
}
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int n;
  mem(memo,-1);
  long long p=2;
  for(int i=2;i<5843;i++){
    while(!isHumble(p))p++;
    memo[i]=p++;
	}
	while(cin>>n){
		if(n==0)break;
		printf("The %dst humble number is %d\n",n,memo[n]);
  }		 
  return 0;
}

