/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
string lower(string s){
  for(int i=0;i<s.sz;i++)s[i]=tolower(s[i]);
  return s;  
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a,b;
    cin>>a>>b;
    a=lower(a);
    b=lower(b);
    if(a<b)cout<<"-1"<<endl;
    else if (a==b)
          cout<<"0"<<endl;
        else
          cout<<"1"<<endl;
    
    //system("pause");
    return 0;
}
