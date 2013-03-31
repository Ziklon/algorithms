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
using namespace std;

#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

class EllysDirectoryListing {
public:vector <string> getFiles(vector <string> files) {	
		int index=-1;
		REP(i,0,files.sz-2){
			if(files[i]=="."|| files[i]==".." ){
				index=i;
				break;
			}
		}
		if(index!=-1)swap(files[index],files[files.sz-1]);
		REP(i,0,files.sz)cout<<files[i]<<" ";
		cout<<endl;
		index=-1;
		REP(i,0,files.sz-2){
			if(files[i]=="."|| files[i]==".." ){
				index=i;
				break;
			}
		}
		if(index!=-1)swap(files[index],files[files.sz-2]);
		return files;

	}

};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <string> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	EllysDirectoryListing *obj;
	vector <string> answer;
	obj = new EllysDirectoryListing();
	clock_t startTime = clock();
	answer = obj->getFiles(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p1[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	vector <string> p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"ContestApplet.jnlp",".","Image.jpg","..","Book.pdf","Movie.avi"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"ContestApplet.jnlp","Movie.avi","Image.jpg","Book.pdf","..","."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"Image.jpg","..","."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Image.jpg","..","."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"..",".","Image.jpg"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Image.jpg",".",".."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"No","..","Zaphod",".","Just","very","very...","Improbable"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"No","Improbable","Zaphod","very...","Just","very",".",".."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"www.topcoder.com","Ever.tried",".","Ever.failed","..","No","Matter.","Try","Again.","Fail","Again..","Fail.Better"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"www.topcoder.com","Ever.tried","Fail.Better","Ever.failed","Again..","No","Matter.","Try","Again.","Fail","..","."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"This",".","is","tricky","test",".."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"This","test","is","tricky","..","."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
//With unused code cleaner (beta) by ahmed_aly
