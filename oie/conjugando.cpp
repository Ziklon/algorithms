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
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  string line;
  cin>>line;
  if(line.substr(line.sz-2)=="ar"){
  		cout<<"yo "<<line.substr(0,line.sz-2)<<"o"<<endl;
  		cout<<"tu "<<line.substr(0,line.sz-1)<<"s"<<endl;
  		cout<<"el "<<line.substr(0,line.sz-1)<<endl;
  		cout<<"nosotros "<<line.substr(0,line.sz-1)<<"mos"<<endl;
  		cout<<"vosotros "<<line.substr(0,line.sz-1)<<"is"<<endl;
  		cout<<"ellos "<<line.substr(0,line.sz-1)<<"n"<<endl;
	}
  return 0;
}
