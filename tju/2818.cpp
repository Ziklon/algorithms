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
int di[4]={1,0,-1,0};
int dj[4]={0,1,0,-1};
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int X,Y,A,B;
  int M,N;
  int p=0;
  int dev=0;
  while(scanf("%d %d",&A,&B)==2){
	p=0;
	X=0;
	Y=0;
	N=1;
	dev=1;
	while(1){
		if(X==A && B==Y)break;
		M=2;
		for(;M--;p++){
			p=(p%4);
			//cout<<"ppp  "<<p<<endl;
			for(int i=0;i<N;i++){
				if(X==A && Y==B)break;				
				X+=di[p];
				Y+=dj[p];
				dev++;
					
			}
		}
		N++;	
	}
	cout<<dev<<endl;
	
		
  }
  //system("pause");
  return 0;
}
