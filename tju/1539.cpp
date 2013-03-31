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
string text,pal,cat="'!,.; ",rev;
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   while(getline(cin,text)){
     pal="";
     if(text=="THE END.")break;
     REP(i,0,text.sz){
       if(cat.find(string(1,text[i]))==-1){
          pal+=tolower(text[i]);  
        }    
     }    
     rev=pal;
     reverse(all(rev));
     if(rev==pal)
      printf("Yes\n");
     else 
      printf("No\n");   
   
   }
   return 0;
}
