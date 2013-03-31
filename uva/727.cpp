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
#define MOD 1000000007
using namespace std;
int K,N;
string text;
string operadors="+/-*";

bool cmp(pair<int,int> p, pair<int,int>q){
	if(p.first!=q.first)return p.first>q.first;
	return p.second<q.second;
}
void go(int p, int q){

	
	vector<pair<int,int> > v;
	int index=0;
	int a=0;
	//cout<<text.substr(p,q-p+1)<<endl;
	REP(i,p,q+1){
		if(text[i]=='(')a++;
		if(text[i]==')')a--;
		index=operadors.find(text[i]);		
		if(index>=0 && a==0){
			v.push_back(make_pair(index%2,i));
		}
	}
	sort(all(v),cmp);
	
	if(v.sz==0){
		cout<<text.substr(p,q-p+1);
	}else{
		index=v[0].second;
		if(text[p]=='(' && text[index-1]==')')
			go(p+1,index-2);
		else
			go(p,index-1);
		
		if(text[index+1]=='(' && text[q]==')')
			go(index+2,q-1);
		else
			go(index+1,q);
		
		cout<<text[v[0].second];
	}
}
int main(){
    freopen("in.txt","r",stdin);
	//(3*5/2*6/(3+2)*5)+4
	//35*2/6*32+/5*4+
	scanf("%d\n",&K);
	string line;
	REP(k,0,K){
		text="";
		if(k>0)cout<<endl;
		while(getline(cin,line)){
			if(line=="")break;
			text+=line;
		}		
		go(0,text.sz-1);
		cout<<endl;
	}
	return 0;
}