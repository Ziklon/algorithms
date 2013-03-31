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
int dat[100001],N,dev;

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  dat[0]=0;
  dat[1]=1;
  while(cin>>N){
	if(N==0)break;
	dev=0;
	if(N==1)dev=1;
	for(int i=2;i<=N;i++){
		dat[i]=dat[i/2];
		if(i&1)
			dat[i]+=dat[(i/2)+1];
		dev=max(dev,dat[i]);		
	}
	cout<<dev<<endl;		
  } 	 
  return 0;
}
