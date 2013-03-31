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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string text;
    int k,n,dif=0;
    cin>>text>>k;
    vector<int>chars(26,0);
    if(k>=text.sz){
      cout<<0<<endl;
      return 0;
    }
    
    REP(i,0,text.sz)
      chars[text[i]-'a']++;
    vector<pair<int,char> >v;
    vector<bool> vis(26,0);
    REP(i,0,26)        
        v.push_back(make_pair(chars[i],'a'+i));
        
    sort(all(v));
    n=text.sz;
    REP(i,0,26){
       if(k-v[i].first>=0){
          vis[v[i].second-'a']=1;
          k-=v[i].first;
       }else
        dif++; 
    }
    printf("%d\n",dif);
    REP(i,0,text.sz)
      if(!vis[text[i]-'a'])
        printf("%c",text[i]);       
    printf("\n");
    return 0;
    
}
