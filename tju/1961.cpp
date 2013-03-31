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
string tos(int t){stringstream st; st<<t;return st.str();}
int S,N,n;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  while(cin>>S>>N){
    if(N==0)break;
    vector<int> v;
    for(int i=0;i<N;i++){
      cin>>n;
      v.pb(n);
    }
    vector<string> b;
    sort(rall(v));
    for(int i=0;i<(1<<N);i++){
      vector<int> tmp;
      for(int j=0;j<(int)v.sz;j++){
        if((i&(1<<j))!=0)
          tmp.pb(v[j]);
      }
      int dev=accumulate(all(tmp),0);
      if(dev==S){
        string str="";
        for(int j=0;j<(int)tmp.sz;j++){
          str+="+"+tos(tmp[j]);
        }
        str=str.substr(1);
        if(!cpresent(b,str))b.pb(str);
      }
    }
    printf("Sums of %d:\n",S);
    sort(rall(b));
    for(int i=0;i<(int)b.sz;i++){     
      cout<<b[i]<<endl;
    }
    if(b.sz==0)cout<<"NONE"<<endl;  
  } 
  return 0;
}

