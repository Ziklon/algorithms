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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int N;
  while(cin>>N){
    if(N==0)break;
    vector<int> v(N,0);
    int dev=1<<30;
    for(int i=0;i<N;i++)
      cin>>v[i];
    for(int i=0;i<(1<<N);i++){
      int a=0,b=0;
      for(int j=0;j<v.sz;j++){
        if((i&(1<<j))!=0)
          a+=v[j];
        else
          b+=v[j];
      }
      dev=min(dev,abs(b-a));      
    }
    cout<<dev<<endl;  
  }
  return 0;
}

