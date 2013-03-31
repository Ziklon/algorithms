#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

char tol(char c){
	c=tolower(c);
	return c;
}
bool isV(char c){
	c=tolower(c);
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return 1;
	return 0;
}
class Pronunciation {
public:string canPronounce(vector <string> words) {	
		string dev="";
		for(int i=0;i<words.sz&&dev=="";i++){
			for(int j=0;j<words[i].sz;j++){
				if(!isV(words[i][j])){
					int x=j,c=0;
					while(x<words[i].sz&&!isV(words[i][x])){
						x++;c++;
					}
					if(c>=3){
						dev=words[i];
						break;
					}
				}else{
					int x=j;
					while(x+1<words[i].sz&&isV(words[i][x]) && isV(words[i][x+1])){
						if(tol(tol(words[i][x]))!=tol(tol(words[i][x+1]))){
							dev=words[i];
							break;
						}
						x++;
					}			
				}
			}
		}
		return dev;		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Pronunciation *obj;
	string answer;
	obj = new Pronunciation();
	clock_t startTime = clock();
	answer = obj->canPronounce(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"All","of","these","are","not","difficult"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"The","word","REALLY","is","really","hard"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "REALLY";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"TRiCKy"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "TRiCKy";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"irresistable","prerogative","uttermost","importance"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"Aa"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
