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

using namespace std;
#define MOD 128
#define sz size()

long long toi(string s){
   istringstream is(s);
   long long ans;
   is>>ans;
   return ans;
}
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int N,tm,kk;
   long long ans=0,aux;
   string othe;
   cin>>N;
   cin.get();
   for(int i=0;i<N;i++){
      getline(cin,othe);
      if(othe.sz>7)
         othe=othe.substr(othe.sz-7);
      aux=toi(othe);
      ans=(ans+(aux%MOD))%MOD;
   }
   cout<<ans<<endl;
   return 0;
}
