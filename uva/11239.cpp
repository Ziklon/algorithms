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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
bool orden(pair<string,set<string> > p , pair<string,set<string> >q){
	if(p.second.sz!=q.second.sz)return p.second.sz>q.second.sz;
	return p.first<q.first;	
}
int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   string line,cur;
   
   while(1){
	   vector<string>v;
		while(getline(cin,line)){
			if(line=="1" || line=="0")break;	
			v.push_back(line);
		}
		if(line=="0")break;
		map<string,set<string> >M;
		for(int i=0;i<v.sz;){
			int j=i,cn=0;
			for(j=i+1;j<v.sz;j++){
				if(isupper(v[j][0]))
					break;	
				M[v[i]].insert(v[j]);
			}
			i=j;			
		}
		foreach(M,it){
			set<string>s;
			foreach((*it).second,mt){
				string cur=*mt;
				foreach(M,at){
					if((*at).second.count(cur)>0){
						(*at).second.erase(cur);
						s.insert(cur);
					}
				}
			}
			foreach(s,at)(*it).second.erase((*at));
		}
		vector<pair<string,set<string> > >vp(all(M));
		sort(all(vp),orden);
		for(int i=0;i<vp.sz;i++)
			printf("%s %d\n",vp[i].first.c_str(),vp[i].second.sz);
		
	}
   return 0;
}
