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

int main(){
	//freopen("in.txt","r",stdin);
	string line;
	while(cin>>line){
		if(line=="#")break;
		if(next_permutation(all(line)))
			printf("%s\n",line.c_str());
		else
			printf("No Successor\n");
	}
	return 0;
}