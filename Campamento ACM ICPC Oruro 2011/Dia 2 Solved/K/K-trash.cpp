#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define FOR(i,a,b)	for(int i=(a),_##i=(b); i<_##i ;i++)
#define F(i,n)		FOR(i,0,n)
#define ALL(v)		v.begin(),v.end()
#define S		size()
#define PB		push_back
#define MP		make_pair
typedef long long	LL;
#define x		first
#define y		second

double dist(double Ax, double Ay, double Bx, double By){
	double a = (Bx-Ax), b = (By-Ay);
	return sqrt(a*a + b*b);
}

double distLine(double Px, double Py, double Bx, double By, double Cx, double Cy){
	double U = (Px-Bx)*(Cx-Bx) + (Py-By)*(Cy-By);
	U = U/((Cx-Bx)*(Cx-Bx) + (Cy-By)*(Cy-By));
	//if(U <= 1.0 && U >= 0.0){
		double x = Bx+ U*(Cx-Bx);
		double y = By+ U*(Cy-By);
		return dist(Px, Py, x, y);
	//}
	//return min(dist(Px, Py, Bx, By), dist(Px, Py, Cx, Cy));
}

int n, k;
vector<pair<int,int> > puntos;
LL cross(pair<int,int> o, pair<int,int> a, pair<int,int> b){
	LL s = LL(b.y-o.y)*LL(a.x-o.x);
	s -= LL(a.y-o.y)*LL(b.x-o.x);
	return s;
}
bool comp(pair<int,int> a, pair<int,int> b){
	LL tmp=cross(puntos[0], a, b);
	if(tmp == 0) return dist(puntos[0].x, puntos[0].y, a.x, a.y) < dist(puntos[0].x, puntos[0].y, b.x, b.y);
	return tmp > 0LL;
}

void graham(){
	int min = 0;
	FOR(i,1,n){
		if(puntos[i].x <= puntos[min].x){
			if(puntos[i].x == puntos[min].x){
				if(puntos[i].y < puntos[min].y){
					min = i;
				}
			}
			else min = i;
		}
	}
	swap(puntos[0], puntos[min]);
	sort(ALL(puntos), comp);
	puntos.PB(puntos[0]);
	k = 2;
	for(int i=3; i<=n ;i++){
		while(cross(puntos[k], puntos[k-1], puntos[i]) > 0) k--;
		k++;
		swap(puntos[i], puntos[k]);
	}
}

int main(){
	//freopen("K.in", "r", stdin);
	//freopen("K.out", "w", stdout);
	double r;
	int a, b, cas = 1;
	scanf("%d", &n);
	while(n){
		r = 100000000.0;
		puntos.clear();
		F(i, n){
			scanf("%d %d", &a, &b);
			puntos.PB(MP(a, b));
		}
		graham();
		FOR(i, 1, k+1){
			//cout<<puntos[i].x<<" "<<puntos[i].y<<" "<<puntos[i-1].x<<" "<<puntos[i-1].y<<endl;
			double maxi = 0.0;
			F(j, puntos.S){
				double aux = distLine(puntos[j].x, puntos[j].y, puntos[i].x, puntos[i].y, puntos[i-1].x, puntos[i-1].y);
				if(aux - maxi > 1e-9) maxi = aux;
			}
			if(r - maxi > 1e-9) r = maxi;
		}
		//cout<<double(LL(r*1000))/1000.0<<" "<<double(LL(r*100))/100.0<<endl;
		if(double(LL(r*1000))/1000.0 - double(LL(r*100))/100.0 > 1e-7)
			r = double(LL(r*100))/100.0 + 0.01;
		printf("Case %d: %.2lf\n", cas++, r);
		scanf("%d", &n);
	}
}
