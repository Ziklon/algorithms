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
long long nums[60005],N;

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  memset(nums,0,sizeof(nums));
  for(int i=1;i<=60000;i++)
  	for(int j=2*i;j<=60000;j+=i)
  		nums[j]+=i;
  cout<<"PERFECTION OUTPUT"<<endl;;  
  while(cin>>N){
	if(N==0)break;
	printf("%5d  ",N);
	if(nums[N]==N)
		cout<<"PERFECT"<<endl;
	else if(nums[N]>N)
			cout<<"ABUNDANT"<<endl;
			else
			cout<<"DEFICIENT"<<endl;		
  }
  cout<<"END OF OUTPUT"<<endl;  
  //system("pause");
  return 0;
}
