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
int N,peki,p;
string buff;
string A[10]={"abc","def","ghi","jkl","mno","pqrs",
	"tuv","wxyz"," ",""};
int main(){
	//freopen("in.txt","r",stdin);
	cin>>N;
	getline(cin,buff);
	
	
	REP(i,0,N){
		getline(cin,buff);	
		peki=0;
		REP(j,0,buff.sz){
			REP(k,0,9){
				p=A[k].find(buff[j]);
				if(p!=-1){
					peki+=(p+1);
					break;
				}
			}
		}
		printf("Case #%d: %d\n",(i+1),peki);
	}
	return 0;
}