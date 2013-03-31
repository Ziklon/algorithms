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
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int GH[35];
int FIND(int x){ 
    if(GH[x]!=x)
        GH[x]=FIND(GH[x]);
    return GH[x];

}
void UNION(int x,int y){ 
    GH[FIND(x)] =FIND(y);
}

int N,nC;
string L;
char M='A';

int main(){
  //freopen("/home/ziklon/in","r",stdin);
  //freopen("/home/ziklon/out","w",stdout);
  scanf("%d\n",&N);
  while(N--){
        for(int i=0;i<27;i++) GH[i]=i;
  	getline(cin,L);
  	M=L[0];
        set<int>S;
  	while(getline(cin,L)){
		if(L=="")break;
                UNION(L[0]-'A',L[1]-'A');
                S.insert(L[0]-'A');
                S.insert(L[1]-'A');
                
	}
        int dev=0;
        for(int i=0;i<=M-'A';i++)
            if(GH[i]==i)
                dev++;
        cout<<dev<<endl;
        if(N)
            cout<<endl;
        
  }
  //system("pause");
  return 0;
}
