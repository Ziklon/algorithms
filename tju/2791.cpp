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
string vowerl="aeiou";
bool isv(char c){
  return vowerl.find(string(1,c))!=-1;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    char line[50];
    string name;
    scanf("%d\n",&n);
    REP(i,0,n){
      scanf("%s\n",line);
      name=line;
      if(isv(name[0]))
        printf("%scow\n",line);
      else{
        name=name.substr(1)+name[0];
        printf("%sow\n",name.c_str());
      }
    }
    //system("pause");
    return 0;
}
