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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

char getDigit(char c){
  if(c>='A' && c<='C')return '2';
  if(c>='D' && c<='F')return '3';
  if(c>='G' && c<='I')return '4';
  if(c>='J' && c<='L')return '5';
  if(c>='M' && c<='O')return '6';
  if(c>='P' && c<='S')return '7';
  if(c>='T' && c<='V')return '8';
  if(c>='W' && c<='Y')return '9';
}
bool orden(pair<string,int> p, pair<string,int> q){
	return  p.first<q.first;	
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int nC=0;
  string line;  
  map<string,int> mp;
  map<string,int>::iterator it;
  vector<string> v;
  cin>>nC;
  scanf("\n");
  while(nC){
   getline(cin,line);
   string nume="";
   for(int i=0;i<line.sz;i++){
     if(isdigit(line[i]))
       nume+=line[i];
     if(line[i]>='A' && line[i]<'Z'){
       nume+=getDigit(line[i]);
     }
   }
   nume=nume.substr(0,3)+"-"+nume.substr(3);
   mp[nume]++;         
   nC--;
  }
  vector<pair<string,int> >vp(all(mp));
  sort(all(vp),orden);
  bool ok=0;
  for(int i=0;i<vp.sz;i++){
  	if(vp[i].second>1){
  		printf("%s %d\n",vp[i].first.c_str(),vp[i].second);
  		ok=1;
	}
  }
  if(!ok)printf("No duplicates.\n");
  return 0;
}
