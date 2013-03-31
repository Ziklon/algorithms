#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int main(){
	vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(1);
	v.push_back(10);
	v.push_back(8);
	int mx=0;
	for(int i=0;i<v.size();i++)
		mx=max(mx,v[i]);
   
   for(int i=1;i<=mx;i++){
		for(int j=0;j<v.size();j++){
			if(v[j]>mx-i)
				cout << "*";
			else
				cout << " ";
		}
		cout<<endl;
	}
	system("pause");
		
}
