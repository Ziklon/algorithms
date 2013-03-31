/*
  Sample solution for NCPC 2009: Flight planning
  Author: Marcus Isaksson
*/

#include <iostream>
#include <vector>

using namespace std;

const int MaxCities=5000;

typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<Vi> Mi;

int n;
Mi adj; // Adjacency lists
int forbidX,forbidY; // Forbidden flight

bool allowed(int x, int y) {
  return !((x==forbidX && y==forbidY) || (x==forbidY && y==forbidX));
}

Vb vis;

// Finds the diameter and height of the subtree below x.
int dfs(int x, int &h) {
  h=0;
  if (vis[x]) return 0;
  vis[x]=true;

  int mxDiam=0;
  int h2=0;
  for (int i=0; i<adj[x].size(); i++) {
    int y=adj[x][i];
    if (allowed(x,y)) {
      int hy;
      mxDiam=max(mxDiam, dfs(y,hy));
      if (hy>h) {
        h2=h;
        h=hy;
      } else if (hy>h2) {
        h2=hy;
      }
    }
  }
  mxDiam=max(mxDiam, h+h2);
  h++;
  return mxDiam;
}

// Finds the diameter of the tree rooted at r.
int treeDiam(int r) {
  vis=Vb(n+1);
  int h;
  return dfs(r,h);
}

// Finds the height of the tree rooted at r.
int treeHeight(int r) {
  vis=Vb(n+1);
  int h;
  dfs(r,h);
  return h;
}

int findMidElement(int r) {
  int d=treeDiam(r);
  Vb inTree=vis;
  for(int i=1; i<=n; i++) {
    if (inTree[i] && (treeHeight(i)-1)==(d+1)/2) return i;
  }
  return -1;
}

int main() {
  cin >> n;
  adj=Mi(n+1);
  for(int i=0; i<n-1; i++) {
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int minDiam=1000000000;
  int bestX=-1,bestY=-1;
  int bestNX=-1,bestNY=-1;

  for(int x=1; x<=n; x++) {
    for (int i=0; i<adj[x].size(); i++) {
      int y=adj[x][i];
      if (x<y) {
        forbidX=x;
        forbidY=y;

        int d1=treeDiam(x);
        int d2=treeDiam(y);

        int newDiam=max(d1,max(d2,(d1+1)/2 + 1 + (d2+1)/2));
        if (newDiam < minDiam) {
          minDiam=newDiam;
          bestX=x;
          bestY=y;
        }
      }
    }
  }

  forbidX=bestX; forbidY=bestY;
  bestNX=findMidElement(bestX);
  bestNY=findMidElement(bestY);
  
  cout << minDiam << endl;
  cout << bestX << " " << bestY << endl;
  cout << bestNX << " " << bestNY << endl;
}
