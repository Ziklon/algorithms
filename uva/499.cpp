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
#define f(i,j,k) for(int i=j;j<k;i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  string line;
  while(getline(cin,line)){
      vector<int> M(256,0);
      int mx=0;
      for(int i=0;i<line.sz;i++){
         M[line[i]]++;
         if(isalpha(line[i]))
            mx=max(mx,M[line[i]-0]);
      }
      for(char cur='A';cur<='z';cur++){
         if(isalpha(cur) && M[cur-0]==mx)
            printf("%c",cur);
      }
      printf(" %d\n",mx);
  }
  return 0;
}
