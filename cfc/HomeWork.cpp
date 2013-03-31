/*
ID: winftc2
PROG: milk
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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

bool orden(pair<char,int> p,pair<char,int> q){
  return p.second<q.second;
}

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
    string text;
    int num;
    cin>>text>>num;
    map<char,int>M;
    REP(i,0,text.sz)
      M[text[i]]++;
    vector<pair<char,int> >v(all(M));
    sort(all(v),orden);
    vector<bool> vis(26,0);
    for(int i=0;i<v.sz;i++){
      if((num-v[i].second)>=0){
        vis[v[i].first-'a']=1;
        num-=v[i].second;
      }
    }
    string ans="";
    num=0;
    set<char>S;
    REP(i,0,text.sz){
      if(!vis[text[i]-'a']){
        ans+=text[i];
        S.insert(text[i]);
      }
    }
    cout<<S.sz<<endl;
    cout<<ans<<endl;
    
   //system("pause");
   return 0;
}
