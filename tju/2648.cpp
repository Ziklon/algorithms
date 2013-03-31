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
  bool prime[10000];
  int nC=0;
  int A,B;
  memset(prime,1,sizeof prime);
  prime[0]=0;
  prime[1]=0;
  for(int i=2;i*i<=9999;i++)
  	if(prime[i])
  		for(int j=i*2;j<=9999;j+=i)
  			prime[j]=0;
  cin>>nC;
  for(int i=0;i<nC;i++){
  	cin>>A>>B;
  	set<int> S;
  	int dev=-1;
  	queue<pair<int,int> >Q;
  	Q.push(make_pair(A,0));
  	S.insert(A);
  	while(!Q.empty()){
	  pair<int,int> P=Q.front();
	  Q.pop();
	  if(P.first==B){
		dev=P.second;
		break;
	  }
	  string ind=tos(P.first);
	  for(int x=0;x<ind.sz;x++){
	  	for(int y=0;y<=9;y++){
			if(ind[x]=='0'+y)continue;
			 string aux=ind;
			 aux[x]='0'+y;
			 int d=toi(aux);
			 if(prime[d] && S.count(d)==0){
				Q.push(make_pair(d,P.second+1));
				S.insert(d);		
			}
		}
	  }	
	}
	if(dev==-1)cout<<"Impossible"<<endl;
	else cout<<dev<<endl;
  	
  }
  //system("pause");
  return 0;
}
