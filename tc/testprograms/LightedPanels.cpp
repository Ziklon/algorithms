#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

int dx[]={0,0,0,1,-1,-1,1,1,-1};
int dy[]={0,1,-1,0,0,-1,1,-1,1};

void change(int i, int j, vector<string>& v){
	if(v[i][j]=='*')v[i][j]='.';
	else v[i][j]='*';
}
class LightedPanels {
public:int minTouch(vector <string> board) {	
		int ans=1<<20;
		int N=board.size();
		int M=board[0].size();
		for(int maska=0;maska<(1<<N);maska++){
			
			for(int maskb=0;maskb<(1<<M);maskb++){
				int need=0;
				vector<string> vs=board;
				for(int i=0;i<N;i++)if(maska&(1<<i))for(int j=0;j<M;j++)if(maskb&(1<<j)){
					//choose i,j;
					need++;
					for(int k=0;k<9;k++){
						int x=i+dx[k];
						int y=j+dy[k];						
						if(min(x,y)>=0 && x<N && y<M)change(x,y,vs);						
					}
				}
				bool flag=1;
				for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(vs[i][j]=='.')flag=0;
				if(flag)ans=min(ans,need);				
			}	
		}
		if(ans>=1<<20)return -1;
		return ans;		
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	LightedPanels *obj;
	int answer;
	obj = new LightedPanels();
	clock_t startTime = clock();
	answer = obj->minTouch(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"*****","*...*","*...*","*...*","*****"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {".*"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"**.","**.","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"*...","**..","..**","...*"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
