#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

int main(){
	int cn=1;
	map<string,int>M;
	for(int i=0;i<26;i++){
		string aux=string(1,'a'+i);
		M[aux]=cn++;
	}
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++){
			string aux=string(1,'a'+i)+string(1,'a'+j);
			M[aux]=cn++;
		}
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++)
			for(int k=j+1;k<26;k++){
				string aux=string(1,'a'+i)+string(1,'a'+j)+string(1,'a'+k);
				M[aux]=cn++;
			}
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++)
			for(int k=j+1;k<26;k++)
				for(int l=k+1;l<26;l++){
					string aux=string(1,'a'+i)+string(1,'a'+j)+string(1,'a'+k)+string(1,'a'+l);
					M[aux]=cn++;
				}
	
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++)
			for(int k=j+1;k<26;k++)
				for(int l=k+1;l<26;l++)
					for(int m=l+1;m<26;m++){
						string aux=string(1,'a'+i)+string(1,'a'+j)+string(1,'a'+k)+string(1,'a'+l)+string(1,'a'+m);
						M[aux]=cn++;
					}
	string line="";
	
	while(cin>>line){
		cout<<M[line]<<endl;	
	}				
	
	return 0;
}



