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
#define INF 1<<30
using namespace std;
string line;
vector<string> vs;
vector<string> vi;
bool A[5000];
int n,m;
bool may(string a, string b){
	int i=0;
	int j=0;
	while(i<a.sz && a[i]=='0')i++;
	while(j<b.sz && b[j]=='0')j++;
	if(a.sz!=b.sz)return a.sz>b.sz;
	return a>b;
	
}
string lowers (string a){
	string ans;
	REP(i,0,a.sz)ans+=tolower(a[i]);
	//cout<<a<<" "<<ans<<endl;
	return ans;
}
bool ordencad(string a, string b){
	return lowers(a)<lowers(b);
}

bool orden(string a, string b){
	int i=0;
	int j=0;
	if(a[0]=='-' && b[0]!='-')return 1;
	if(a[0]!='-' && b[0]=='-')return 0;
	if(a[0]=='-' && b[0]=='-'){
		a=a.substr(1);
		b=b.substr(1);
		return may(a,b);
	}		
	while(i<a.sz && a[i]=='0')i++;
	while(j<b.sz && b[j]=='0')j++;
	a=a.substr(i);
	b=b.substr(j);	
	if(a.sz!=b.sz)return a.sz<b.sz;
	return a<b;
}
bool isInt(string s){
	int e=0;
	if(s[0]=='-')e++;
	REP(i,e,s.sz)if(!isdigit(s[i]))return 0;
	return 1;
}
string text;

void solve(){
	while(getline(cin,text)){
		if(text==".")break;
		n=text.sz;
		line=" "+text.substr(0,n-1)+",";
		vector<string> a;
		vector<string> b;
		int p;
		int cnt=0;
		//cout<<line<<endl;
		REP(i,0,line.sz){
			if(line[i]==' ')p=i;
			else if(line[i]==','){
				m=(i-1)-(p+1)+1;
				string cad=line.substr(p+1,m);
				//cout<<cad<<" ";
				if(isInt(cad)){
					b.push_back(cad);
					A[cnt++]=1;
				}else{
					a.push_back(cad);
					A[cnt++]=0;
				}
			}
		}
		sort(all(a),ordencad);
		sort(all(b),orden);
		p=0;
		int q=0;
		REP(i,0,cnt){
			if(A[i]){
				printf("%s",b[p++].c_str());
			}else{
				printf("%s",a[q++].c_str());
			}
			if(i+1<cnt)printf(", ");
			else printf(".\n");
		}
		
	
	}
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

