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
  int nC;
  scanf("%d\n",&nC);
  string line="",res,s;
  while(nC--){
	getline(cin,line);
	stringstream ss(line);
	res="";
	vector<string> vs;
	while(ss>>s){
		reverse(all(s));
		vs.pb(s);	
	}
	bool ok=0;
	int p=0;
	for(int i=0;i<line.sz;i++){
		if(line[i]!=' ' && !ok){
			ok=1;
			res+=vs[p++];	
		}
		if(line[i]==' '){
			ok=0;
			res+=line[i];	
		}
	}
	cout<<res<<endl;			
  }
  //system("pause");
  return 0;
}
