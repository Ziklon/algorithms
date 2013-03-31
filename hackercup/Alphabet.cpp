#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz size()
using namespace std;

string line,aux,text;
string ans="HACKERCUP";
int nums[]={1,1,2,1,1,1,2,1,1};

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int nC,W,H,mW;
	scanf("%d\n",&nC);
	REP(c,0,nC){
		getline(cin,line);
		int peki=1<<29;
		vector<int> v(26,0);
		for(int i=0;i<line.sz;i++){
			if(isalpha(line[i]))
				v[line[i]-'A']++;
		}
		for(int i=0;i<ans.sz;i++){
			int dd=v[ans[i]-'A']/nums[i];
			peki=min(peki,dd);
		}
		
		printf("Case #%d: %d\n",c+1,peki);
		
		
	}
	return 0;

}