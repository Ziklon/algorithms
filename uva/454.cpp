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
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz size()
#define MAX 5000
using namespace std;
string line,cp,aux;

int P[150];
int main(){
	//freopen("in.txt","r",stdin);
	int T;
	cin>>T;
	getline(cin,line);
	getline(cin,line);
	for(int i=0;i<T;i++){
		vector<pair<string,string> > v;
		while(getline(cin,line)){
			//cout<<line<<" a"<<endl;
			if(line=="")break;
			stringstream ss(line);
			cp="";
			while(ss>>aux)cp+=aux;
			sort(cp.begin(),cp.end());			
			v.push_back(make_pair(line,cp));
		}
		sort(v.begin(),v.end());
		set<pair<int,int> >S;

		for(int j=0;j<v.sz;j++){
			
			for(int k=0;k<v.sz;k++){
				if(k==j)continue;
				if(v[j].second==v[k].second){
					S.insert(make_pair(min(j,k),max(j,k)));
				}
			}
		}
		
		foreach(S,it){
			pair<int,int> P=*it;
			printf("%s = %s\n",v[P.first].first.c_str(),v[P.second].first.c_str());
		}
		
		if((i+1)<T)printf("\n");
	
	}
	
	return 0;


}