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
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   string line="",ans="";
   string vowel="aeiouy";
   cin>>line;
   REP(i,0,line.sz){
		line[i]=tolower(line[i]);
		if(vowel.find(string(1,line[i]))==-1)
			ans+=string(1,line[i]);
	}
	line="";
	REP(i,0,ans.sz){
		line+=("."+string(1,ans[i]));
	}
	cout<<line<<endl;
	
   //system("pause");
   return 0;
}
