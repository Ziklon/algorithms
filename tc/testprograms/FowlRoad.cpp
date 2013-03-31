#include <vector>
#include <list>
#include <map>
#include <set>
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

using namespace std;

class FowlRoad {
public:
	int crossings(int, vector <int>, vector <int>);
};

int FowlRoad::crossings(int roadY, vector <int> bobX, vector <int> bobY) {
	int dev=0;
	int ant=bobY[0];
	bool ism=ant<roadY;
	for(int i=1;i<bobY.size();i++){
		if(ism){
			if(bobY[i]>roadY){
				dev++;
				ism=0;
			}
		}else
			if(bobY[i]<roadY){
				dev++;
				ism=1;
			}
	
	}
	return dev;
}


double test0() {
	int p0 = 6;
	int t1[] = {3,7,9,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-3,8,8,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	FowlRoad * obj = new FowlRoad();
	clock_t start = clock();
	int my_answer = obj->crossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 10;
	int t1[] = {3,7,9,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-3,8,8,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	FowlRoad * obj = new FowlRoad();
	clock_t start = clock();
	int my_answer = obj->crossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 0;
	int t1[] = {3,2,5,6,9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,0,0,2,-88};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	FowlRoad * obj = new FowlRoad();
	clock_t start = clock();
	int my_answer = obj->crossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 0;
	int t1[] = {3,2,5,6,9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-2,0,0,2,-88};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	FowlRoad * obj = new FowlRoad();
	clock_t start = clock();
	int my_answer = obj->crossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
