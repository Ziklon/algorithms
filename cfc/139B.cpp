#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
using namespace std;
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
struct node{
	int w,h,p;
	
};
int main(){
	//freopen("in.txt","r",stdin);
	int n,m;
	cin>>n;
	vector<node> v,u;
	REP(i,0,n){
		node p;
		cin>>p.w>>p.h>>p.p;
		v.push_back(p);
	}
	cin>>m;
	REP(i,0,m){
		node p;
		cin>>p.w>>p.h>>p.p;
		u.push_back(p);
	}
	int ans=0;
	REP(i,0,n){
		int anc=(v[i].w*2) + (v[i].h*2);
		int alt=v[i].p;
		int cost=1<<29;
		REP(j,0,m){
		    if(u[j].w>=alt){
				int nd=((u[j].w)/alt)*u[j].h;
				int mx=nd;
				int cnt=(anc+mx-1)/mx;
				int val=cnt*u[j].p;
				cost=min(val,cost);
			}
			//cout<<mx<<endl;
		}
		ans+=cost;
	}
	cout<<ans<<endl;
	return 0;

}	