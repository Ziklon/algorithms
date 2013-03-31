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



int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int Xa,Xb,Ya,Yb,nC,a,b,c;
	cin>>Xa>>Ya>>Xb>>Yb;
	cin>>nC;
	vector<pair<double,pair<int,int> > > v;
	REP(i,0,nC){
		cin>>a>>b>>c;
		v.push_back(make_pair(c,make_pair(a,b)));
	}
	sort(v.rbegin(),v.rend());
	
	int peki=0;
	double dis;
	REP(i,Xa,Xb+1){	
	
		REP(j,Yb,Ya+1){
			bool ok=1;
			REP(k,0,nC){
				dis=hypot(i-v[k].second.first,j-v[k].second.second);
				if(i==3 && j==4)cout<<dis<<" "<<v[k].first<<endl;
				if(dis<=v[k].first){					
					ok=0;
					break;
				}
			}
			
			if(ok){
				//(2,5), (3,5), (4,4), (4,5).
				//cout<<i<<" "<<j<<endl;
			}
			peki+=ok;
		}
	}
	
	cout<<peki<<endl;
	
	return 0;

}