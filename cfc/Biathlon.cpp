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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
int n,m,x,y;
int A[300000];
struct node{
	int x,y,p;
	node(int _x, int _y, int _p){
		x=_x;
		y=_y;
		p=_p;
	}
};

bool orden(node p, node q){
	return p.x<q.x;
}

double radio(int xc, int x, int y){
	return hypot(xc-x,y);
}

int pfind(vector<node>&v, int x,int y){
	int low=0,high=v.sz;
	while(low<high){
		int cur=(low+high)/2;
		if(radio(v[cur].x,x,y)<=v[cur].y)
			return cur;
		else{
			if(v[cur].x<x)
				low=cur;
			else
				high=cur;
		}
		
	}
	return -1;	
}
void add(vector<node>&v, int p,int x, int y){
	if(p>=0)A[v[p].p]++;
	if(p-1>=0 && radio(v[p-1].x,x,y)<=v[p-1].y)A[v[p-1].p]++;
	if(p+1<v.sz && radio(v[p+1].x,x,y)<=v[p+1].y)A[v[p+1].p]++;
}
int main(){
	scanf("%d",&n);
	vector<node>vt,vp;
	mem(A,0);
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		vt.push_back(node(x,y,i));	
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		vp.push_back(node(x,y,i));
	}
	sort(all(vt),orden);
	for(int i=0;i<vp.sz;i++){
		int p=pfind(vt,vp[i].x, vp[i].y);
		if(p>=0){
			add(vt,p,vp[i].x,vp[i].y);
		}
	}
	for(int i=0;i+1<vt.sz;i++)
		printf("%d ",A[vt[i].p]);
	printf("%d\n",A[vt[n-1].p]);
	
	return 0;

}
