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
int toi(string s){istringstream is(s);int x;is>>x;return x;}

string names[50];
int tama[50];
int main(){
    //freopen("in.txt","r",stdin);
	int N,a,b,c;
	string text,line;
	while(1){
		getline(cin,line);
		if(line=="-1")break;
		N=toi(line);
		set<int> S;
		REP(i,0,N){
			getline(cin,line);
			istringstream is(line);
			is>>a>>b>>c>>text;
			tama[i]=a*b*c;
			S.insert(tama[i]);
			names[i]=text;
		}
		vector<int> v(all(S));
		
		int p=0,q=0;
		REP(i,0,N)
			REP(j,0,N){
				if(i==j)continue;
				if(tama[i]==v[v.sz-1] && tama[j]==v[0]){
						p=i;
						q=j;
				}
				
			}
		printf("%s took clay from %s.\n",names[p].c_str(),names[q].c_str());
		
		
	}
   
    return 0;
}