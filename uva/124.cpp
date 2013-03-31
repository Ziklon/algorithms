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
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
vector<char> G[27];
map<char,int>M;
bool vis[27];
vector<char>  topo;
void topologicSort(char node){
    vis[M[node]]=1;
    for(int i=0;i<G[M[node]].sz;i++){
        char cur=G[M[node]][i];
        if(!vis[M[cur]])
          topologicSort(cur);
        
    }
    topo.push_back(node);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int nv=0;
    string cad,text;
    while(getline(cin,cad)){
       M.clear();
       fill(vis,0);
       getline(cin,text);
       vector<char> v,va;
        if(nv>0)printf("\n");
       for(int i=0;i<26;i++)G[i].clear();
       
       for(int i=0;i<cad.sz;i++)
          if(isalpha(cad[i])){
            M[cad[i]]=v.sz;
            v.push_back(cad[i]);
            
          }
       for(int i=0;i<text.sz;i++)
          if(isalpha(text[i]))
            va.push_back(text[i]);
            
      
       for(int i=0;i+1<va.sz;i+=2)
          G[M[va[i]]].push_back(va[i+1]);
               
        topo.clear();
       sort(all(v));
       for(int i=0;i<v.sz;i++)
          if(!vis[M[v[i]]])
            topologicSort(v[i]);
      reverse(all(topo));
       for(int i=0;i<topo.sz;i++)cout<<topo[i]<<" ";
       cout<<endl;
       
    }

    //system("pause");
    return 0;
}
