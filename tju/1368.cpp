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
char buff[256];
string text[]={"`1234567890-=","QWERTYUIOP[]\\",
	"ASDFGHJKL;'","ZXCVBNM,./"};
int main(){
    //freopen("in.txt","r",stdin);
	REP(i,0,256)buff[i]=i;
	REP(i,0,4){
		REP(j,1,text[i].sz){
			buff[text[i][j]]=text[i][j-1];
		}
	}
	
	string line="";
	while(getline(cin,line)){
		REP(i,0,line.sz)
			line[i]=buff[line[i]];
		printf("%s\n",line.c_str());
	}
	return 0;
}