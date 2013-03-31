/*
ID: winftc
PROG: test
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
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
bool ispal(string str){
   string aux=str;
   reverse(all(aux));
   return aux==str;
}
int main(){
   //freopen("in.in","r",stdin);
   //freopen("out.out","w",stdout);
   cout<<ispal("wrwrrbbbwww")<<endl;
   cout<<ispal("wwwbbwrwrrb")<<endl;
   cout<<ispal("wwwbbwrwrrb")<<endl;
   system("pause");
   return 0;
}
