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

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    map<string,int>M;
    string cur,aux;
    while(getline(cin,cur)){
      REP(i,0,cur.sz)
         if(isalpha(cur[i]))
            cur[i]=tolower(cur[i]);
         else if(!isdigit(cur[i]))
               cur[i]=' ';
         
      stringstream ss(cur);
      while(ss>>aux)
         M[aux]++;
    }
    int mx=0;
    foreach(M,it)
      mx=max(mx,it->second);
   printf("%d occurrences\n",mx);
    foreach(M,it)
      if(it->second==mx)
         printf("%s\n",it->first.c_str()); 
    //system("pause");
    return 0;
}
