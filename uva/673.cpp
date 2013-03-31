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
#include <stack>
#include <set>
#include <map>
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define sz size()

using namespace std;


int main(){
	//freopen("in.txt","r",stdin);
	int N;
	scanf("%d",&N);
	string line;
	getline(cin,line);
	while(N--){
		getline(cin,line);
		stack<char> pila;
		bool ok=1;		
		REP(i,0,line.sz){
			if(!ok)break;
			if(line[i]=='(' || line[i]=='[')
				pila.push(line[i]);
			else{
				ok=0;
				if(pila.sz>0){
					char cur=pila.top();					
					if(line[i]==')' && cur=='(')ok=1;
					if(line[i]==']' && cur=='[')ok=1;
					pila.pop();
				}
			}
			
		}
		if(pila.sz!=0)ok=0;
		if(ok)printf("Yes\n");
		else printf("No\n");
	}
	
	
	
	return 0;
}