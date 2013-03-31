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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
 	vector<int> v;
 	int d,t;
 	while(cin>>d){
		v.clear();
    for(int i=0;i<d;i++){
				cin>>t;
				v.push_back(t);
		}
		bool ok=1;
		for(int i=1;i<d && ok;i++){
		  if(abs(v[i-1]-v[i])<1 || abs(v[i-1]-v[i])>=d)
				ok=0;
		}
		if(ok)printf("Jolly\n");
		else
				printf("Not Jolly\n");
	
	} 
  return 0;
}

