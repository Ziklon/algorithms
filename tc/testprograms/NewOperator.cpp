#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath> 
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctime> 
using namespace std; 
typedef long long ll;
#define INF 1<<21
bool vis[INF];
#define MAX_N 1000005
#define MAX_ANS 5000

int sum[MAX_N],prod[MAX_N],prod3[MAX_N],smaller[MAX_N],first[MAX_N];

void do_init(){
	for(int i=1;i<MAX_N;i++){
		int tmp=i;
		int ansprod=1;
		int suma=0;
		int small=10;
		vector<int> v;
		while(tmp){
			v.push_back(tmp%10);
			suma+=tmp%10;
			small=min(small,tmp%10);
			ansprod*=(tmp%10);
			tmp/=10;
		}

		first[i]=v[v.size()-1];
		smaller[i]=small;
		sum[i]=suma;
		prod[i]=ansprod;
		prod3[i]=1;
		sort(v.rbegin(),v.rend());
		
		//cout<<i<<endl;
		for(int j=0;j<3 && j<v.size();j++)prod3[i]*=v[j];		
	}
}
int get(int x, int y){
	return 5*prod3[x]+first[x]*sum[y]+smaller[y];
}

class NewOperator {
public:
	int minimumCount(int x, int goal) {
		vector<int> best(MAX_N,INF);
		vector<vector<int> > seq(MAX_ANS);
		do_init();	
		seq[0].push_back(x);
		if(x==goal)return 0;
		
						
		for(int dist=1;dist<MAX_ANS;dist++){
			for(int d1=0;d1<dist;d1++){
				int d2=dist-d1-1;
				for(int i=0;i<seq[d1].size();i++)
					for(int j=0;j<seq[d2].size();j++){
						int X=seq[d1][i];
						int Y=seq[d2][j];
						int Z=get(X,Y);
						if(best[Z]>dist){
							seq[dist].push_back(Z);
							best[Z]=dist;							
						}					
					}			
			}		
		}
		if(goal>=MAX_N)return -1;
		if(best[goal]==INF)return -1;				
		return best[goal];
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	NewOperator *obj;
	int answer;
	obj = new NewOperator();
	clock_t startTime = clock();
	answer = obj->minimumCount(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 13;
	p1 = 13;
	p2 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 374;
	p1 = 465;
	p2 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 374;
	p1 = 469;
	p2 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 374;
	p1 = 659;
	p2 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 374;
	p1 = 1024;
	p2 = 8;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 654321;
	p1 = 12;
	p2 = 10;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 654321;
	p1 = 1234567;
	p2 = -1;
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
