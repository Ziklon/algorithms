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
#define sz size()
#define MAX 5000
using namespace std;
struct node{
	string name;
	int base;
	int size;
	int dime;
	vector<pair<int,int> >bound;
};

node A[MAX];

int main(){
	freopen("in.txt","r",stdin);
	char buff[124];
	int N,R,x,y;
	scanf("%d %d\n",&N,&R);
	map<string,int> M;
	string line;
	REP(i,0,N){
		node p;
		getline(cin,line);
		istringstream is(line);
		is>>p.name>>p.base>>p.size>>p.dime;
		while(is>>x>>y)		
			p.bound.push_back(make_pair(x,y));
		
		//cout<<p.dime<<endl;
		M[p.name]=i;
		A[i]=p;
	}
	

	
	REP(i,0,R){
		getline(cin,line);
		istringstream is(line);
		string name;
		is>>name;
		
		int index=M[name];
		
		int tam=A[index].dime;

		vector<int> V(tam),C(tam+1);
		
		REP(j,0,tam){
			is>>V[j];
			
		}
			
		C[tam]=A[index].size;
		for(int j=tam-1;j>=1;j--){
			C[j]=C[j+1]*(A[index].bound[j].second-A[index].bound[j].first+1);
		}
		

		C[0]=A[index].base;
		REP(j,1,tam+1)
			C[0]-=(C[j]*A[index].bound[j-1].first);
		
		int ans=C[0];
		REP(j,1,tam+1)
			ans+=(V[j-1]*C[j]);
		
		//cerr<<" hello "<<V.sz<<endl;
		printf("%s[%d",name.c_str(),V[0]);
		
		REP(j,1,V.sz)printf(", %d",V[j]);
		printf("] = %d\n",ans);		
	}
	
	
	return 0;
}