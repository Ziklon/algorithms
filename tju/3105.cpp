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
bool arr[1000001];
vector<int> v;
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  mem(arr,1);
  arr[0]=0;
  arr[1]=0;
  for(int i=2;i<=1000000;i++)
  	if(arr[i]){
		v.pb(i);
		for(int j=2*i;j<=1000000;j+=i)
			arr[j]=0;		
	}
	int nC,nk;
	cin>>nC;
	while(nC--){
		cin>>nk;
		nk--;
		cout<<v[nk]<<endl;	
	}
  //system("pause");
  return 0;
}
