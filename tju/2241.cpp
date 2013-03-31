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
int A[100001];
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int nC,N,a,b,k;
  scanf("%d",&nC);
  while(nC--){
	scanf("%d",&N);
	mem(A,0);
	for(int i=1;i<N;i++){
		scanf("%d %d",&a,&b);
		A[a]=b;	
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&a,&b);
		//cout<<M[b]<<endl;
		while(A[b]!=a && A[b]!=0){
			b=A[b];	
		}
		if(A[b]==a)
			printf("Yes\n");
		else
			printf("No\n");	
	}
				
		
  }
  //system("pause");
  return 0;
}
