/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
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
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
vector<string> split(string s){
  vector<string> v;
  s=s+",";
  int j=0;
  for(int i=0;i<s.sz;i++){
    if(s[i]==','){
      v.push_back(s.substr(j,i-j+1));
      j=i+1;
    }
  }
  sort(all(v));
  return v;
}
int gets(string a, string b){
  vector<string> va=split(a);
  vector<string> vb=split(b);
  int pts=0;
  for(int i=0;i<va.sz;i++)if(va[i]==vb[i])pts++;
  return pts;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string line;
    vector<string> v;
    while(getline(cin,line)){
        if(line=="#")break;
        if(line[0]!='e'){
          v.push_back(line);
          continue;
        }
        int win=0;
        int pts=0;
        for(int i=0;i<v.sz;i++){
          int aux=0;
          for(int j=0;j<v.sz;j++){
            aux+=gets(v[i],v[j]);
          }
          if(aux>pts){
            win=i+1;
            pts=aux;
          }
        }
        printf("%d\n",win);
        v.clear();
    }
    
    //system("pause");
    return 0;
}
