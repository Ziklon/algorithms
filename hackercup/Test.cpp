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
#define MOD 4207849484
using namespace std;

int main(){
	string txt="abcde";
	int vec=0;
	stringstream ss;
	string aux,xx;
	set<string>S;
	for(int i=0;i<txt.sz;i++){
		for(int j=i;j<txt.sz;j++){
			for(int k=j;k<txt.sz;k++){				
				aux=txt.substr(0,i)+"#"+
					txt.substr(i,j-i)+"#"+
					txt.substr(j,k-j)+"#"+
					txt.substr(k);
				REP(o,0,aux.sz)if(aux[o]=='#'){
					aux[o]=' ';
				}
				stringstream ss(aux);
				ss>>aux;
				while(ss>>xx)aux+='#'+xx;				
				S.insert(aux);				
			}
		}
	}
	cout<<S.sz<<endl;
	foreach(S,it){
		cout<<*it<<endl;
	}
	return 0;
}