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
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long num,aux,mm,k;
double rnum;
double raiz;

long long pot(int a, int b){
	long long ans=1;
	REP(i,0,b)ans*=a;
	return ans;
}


int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>num && num!=0){
		int peki=1;
		int hh;
		
		if(num>0){
			hh=sqrt(num)+1;
			for(int i=2;i<=hh;i++){
				if(peki!=1)break;
				int n=1;
				mm=0;
				while(mm<num){
					n++;
					mm=pot(i,n);
				}
				if(mm==num){
					peki=n;
				}			
			}		
		}else{
			hh=sqrt(num*-1)+1;
			//cout<<hh<<" sqrt"<<endl;
			for(int i=-2;i>=-hh;i--){
				if(peki!=1)break;
				int n=1;
				mm=0;
				while(mm>num){
					n+=2;
					mm=pot(i,n);
				}
				if(mm==num){
					peki=n;
				}
			}
		
		}
		cout<<peki<<endl;
	}
	return 0;
}
