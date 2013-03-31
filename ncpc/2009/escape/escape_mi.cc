/*
  Sample solution for NCPC 2009: Speedy Escape
  Author: Marcus Isaksson
*/

#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MaxInts=100;
const int MaxRoads=5000;
const int MaxRoadLen=100;
const double Inf=1e50;

int n,m,e;
int b,p;
int E[MaxInts]; // List of exits
double speed[2] = {0, 160}; // Brothers, police speed
double D[MaxInts][MaxInts]; // D[u][v]=distance between intersections u and v.
double P[MaxInts]; // P[u]=earliest time the police can be intersection u
double B[MaxInts]; // B[u]=earliest time the brothers can be intersection u without getting caught, given their fixed speed.

void computeP() {
  for (int u=0; u<n; u++) P[u]=Inf;
  priority_queue<pair<double,int> > Q;
  Q.push(make_pair(0,p));

  while (!Q.empty()) {
    double t=-Q.top().first;
    int u=Q.top().second;
    Q.pop();
    if (P[u]<Inf) continue;
    P[u]=t;
    for (int v=0; v<n; v++)
      if (D[u][v]!=Inf) {
        double t2=t+D[u][v]/speed[1];
        if (t2<P[v]) Q.push(make_pair(-t2,v));
      }
  }
}

void computeB() {
  for (int u=0; u<n; u++) B[u]=Inf;
  priority_queue<pair<double,int> > Q;
  Q.push(make_pair(0,b));

  while (!Q.empty()) {
    double t=-Q.top().first;
    int u=Q.top().second;
    Q.pop();
    if (B[u]<Inf) continue;
    B[u]=t;
    for (int v=0; v<n; v++)
      if (D[u][v]!=Inf) {
        double t2=t+D[u][v]/speed[0];
        if (t2<B[v] && t2<P[v] && t<P[u])
		  Q.push(make_pair(-t2,v));
    }
  }
}

bool canEscape(double bSpeed) {
  speed[0]=bSpeed;
  computeB();
  for (int i=0; i<e; i++)
    if (B[E[i]]<Inf) return true;
  return false;
}

int main() {
  cin >> n >> m >> e;

  for (int i=0; i<=n; i++)
    for (int j=0; j<=n; j++) D[i][j]=Inf;
    
  for (int i=1; i<=m; i++) {
    int a,b,l;
    cin >> a >> b >> l;
    a--; b--;
    D[a][b]=D[b][a]=l;
  }

  for (int i=0; i<e; i++) {
    cin >> E[i];
    E[i]--;
  }

  cin >> b >> p;
  b--; p--;

  double lo=0; // Brothers can't escape at this speed
  double hi=speed[1]*MaxRoads*MaxRoadLen*2; // Brothers can escape at this speed unless the police station blocks their access to the highway, in case which it is impossible.

  computeP();

  if (!canEscape(hi)) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  for (int i=0; i<100; i++) {
    double mid=(hi+lo)/2;
    if (canEscape(mid))
      hi=mid;
    else
      lo=mid;
  }

  cout.precision(12);
  cout << lo << endl;
  
  return 0;
}
