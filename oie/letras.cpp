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
  int n;
  string words,dev;
  vector<string>dic;
  map<string,map<char,int> >M;
  cin>>n;
  for(int i=0;i<n;i++){
	cin>>words;
    map<char,int>mt;
    for(int x=0;x<words.sz;x++){
		words[x]=toupper(words[x]);
		mt[words[x]]++;
	}
	dic.pb(words);
	M[words]=mt;
  }
  cin>>n;
  for(int i=0;i<n;i++){
  	 cin>>words;
  	 dev="";
  	 map<char,int>X;
  	 for(int x=0;x<words.sz;x++)
		X[words[x]]++;
  	 for(int x=0;x<dic.sz;x++){
		bool ok=1;
	 	for(int j=0;j<dic[x].sz;j++){
			//cout<<dic[x][j]<<" "<<M[dic[x]][dic[x][j]]<<" "<<X[dic[x][j]]<<endl;
			if(M[dic[x]][dic[x][j]]>X[dic[x][j]])
				ok=0;
		}
		if(ok && dic[x].sz>dev.sz)
			dev=dic[x];	
	 }
	 cout<<dev<<endl;
	 
  }
  return 0;
}
