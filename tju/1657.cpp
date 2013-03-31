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
string text;
int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   while(getline(cin,text)){
		char cur=text[0];
		int cn=0;
		text=text+"}";
		REP(i,0,text.sz){
			if(text[i]!=cur){
				if(cn>1)
					printf("%d%c",min(cn,9),cur);
				else{
					if(cur=='1')
						printf("%c%d",cur,1);
					else
						printf("%d%c%d",1,cur,1);	
				}			
				cur=text[i];
				cn=1;
			}else{
				cn++;
			}
		}
		printf("\n");
	}
   //system("pause");
   return 0;
}
