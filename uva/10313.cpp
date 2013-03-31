#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
using namespace std;
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define sz size()
int main(){
	freopen("in.txt","r",stdin);
	vector<pair<int,int> > v;
	int sum=0;
	REP(i,0,8){
		int x;
		cin>>x;
		v.push_back(make_pair(x,i+1));
	}
	sort(all(v));
	reverse(all(v));
	stringstream ss;
	vector<int> peki;
	REP(i,0,5){
		peki.push_back(v[i].second);
		sum+=v[i].first;
	}
	sort(all(peki));
	REP(i,0,peki.sz)
		ss<<" "<<peki[i];
	cout<<sum<<endl;
	cout<<ss.str().substr(1)<<endl;
	return 0;

}