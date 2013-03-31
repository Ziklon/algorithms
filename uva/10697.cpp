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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
#define EPS 1e-8
using namespace std;
int N;
struct Point{
	double x,y;
	Point(){}
	Point(double _x, int _y){
		x=_x;
		y=_y;
	}		
};
bool operator <(const Point &p, const Point &q){
	if(p.x!=q.x)return p.x<q.x;
	return p.y<q.y;
}
double dist(const Point &p, const Point &q){
	return hypot(p.x-q.x,p.y-q.y);
}
Point operator +(const Point &p, const Point &q){
	return Point(p.x+q.x,p.y+q.y);
}
Point operator -(const Point &p, const Point &q){
	return Point(p.x-q.x,p.y-q.y);
}
Point operator /(const Point &p, double k){
	return Point(p.x/k,p.y/k);
}


void solve(){
	scanf("%d",&N);
	double x,y,d;
	int i,j,k;
	for(int t=0;t<N;t++){
		vector<Point> v(3);
		for(i=0;i<3;i++){
			cin>>x>>y;
			v[i]=Point(x,y);
		}
		sort(v.begin(),v.end());
		vector<Point> ans;
		
		Point p;
		p=(v[0]+v[1]+v[2])/3.0;
		d=dist(v[0],p);
		bool  ok=1;
		bool eq=0;
		for(int u=0;u<3;u++){
			if(fabs(d-dist(p,v[u]))>EPS)
					ok=0;
		}
		if(ok)ans.push_back(p);		
		for(i=0;i<3;i++)for(j=i+1;j<3;j++){
			if(dist(v[i],v[j])<EPS)eq=1;
			x=(v[i].x+v[j].x)/2.0;
			y=(v[i].y+v[j].y)/2.0;
			p=Point(x,y);
			d=dist(p,v[i]);
			ok=1;
			for(int u=0;u<3;u++){
				if(fabs(d-dist(p,v[u]))>EPS)
					ok=0;
			}			
			if(ok)ans.push_back(p);		
		}
		
		
		if(ans.sz==1 && eq==0){
			if(ans[0].x<EPS)ans[0].x=0;
			if(ans[0].y<EPS)ans[0].y=0;			
			printf("The equidistant location is (%.01f, %.01f).\n",ans[0].x,ans[0].y);
		}
		else if(ans.sz==0 && eq==0)printf("There is no possible location.\n");
		else printf("There is an infinity of possible locations.\n");
		
		
		
		
	
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

