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
string line;
bool isPal(string& s){
	for(int i=0,j=s.sz-1;i<j;j--,i++)
		if(s[i]!=s[j])
			return 0;
	return 1;	
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>line){
	bool ok=0;
	int szs=0,cn=0;
	for(int j=line.sz;j>=1&&!ok;j--){
		for(int i=0;i+j<=line.sz;i++){
			string sp=line.substr(i,j);
			if(isPal(sp)){
				ok=1;	
				szs=sp.sz;
				cn++;
			}
		}	
	}
	cout<<szs<<" "<<cn<<endl;			
  }
  //system("pause");
  return 0;
}
