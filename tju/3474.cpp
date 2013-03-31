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
using namespace std;
int num;
char op;
string expre,line;
int getRan(char c){
	if(c=='+' || c=='-')return 1;
	return 2;
}

int go(int a, int b, char c){
	if(c=='+')return a+b;
	if(c=='-')return a-b;
	if(c=='/')return a/b;
	if(c=='*')return a*b;
	return 0;
	
}

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(getline(cin,line)){
		vector<int> nums;
		vector<char> opr;
		istringstream is(line);
		is>>num;
		nums.push_back(num);
		while(is>>op>>num){
			opr.push_back(op);
			nums.push_back(num);
		}
		
		while(nums.sz>1){
			int ubi=0;
			int mx=0;
			REP(i,0,opr.sz){
				if(getRan(opr[i])>mx){
					ubi=i;
					mx=getRan(opr[i]);
				}
			}
			int aux=go(nums[ubi],nums[ubi+1],opr[ubi]);
			opr.erase(opr.begin()+ubi);
			nums.erase(nums.begin()+ubi);
			nums.erase(nums.begin()+ubi);
			nums.insert(nums.begin()+ubi,aux);
			
		}
		cout<<nums[0]<<endl;
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
