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

string line,aux;

bool check(vector<int>&v, int& W,int &H, int &F){
	int p=0;
	int i=0;
	
	while(i<v.sz){
		int k=0;
		for(;i<v.sz;i++){
			int m=k+(v[i]*F);			
			if(m>W)break;
			k=m+F;
		}
		p++;
	}
	return(p*F<=H);
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int nC,W,H,mW;
	scanf("%d\n",&nC);
	REP(i,0,nC){
		getline(cin,line);
		istringstream is(line);
		is>>W>>H;
		vector<int> words;
		mW=0;
		while(is>>aux){
			words.push_back(aux.sz);
			mW=max(mW,(int)aux.sz);			
		}
		int peki=0;	
		REP(j,0,100000){
			if(mW*j<=W && check(words,W,H,j))
				peki=max(peki,j);
			else
				break;
		}
		printf("Case #%d: %d\n",i+1,peki);
		
		
		
	}
	return 0;

}