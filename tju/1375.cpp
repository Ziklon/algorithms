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
long long gcd(long long a, long long b){return __gcd(a,b);}
long long _lcm(long long a,long long b){return a*(b/gcd(a,b));}
vector<long long> v;
long long i,n,x;

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>n){
    
   //1111...111%n=(((111...111)%n*10)+1)%n
   for(i=1;;i++){
	  x=((x*10)+1)%n;
	  if(x==0)break;	  
   }
   cout<<i<<endl;
  } 
  return 0;
}

