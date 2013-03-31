#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;
typedef long long ll;

string lower(string s){
    string ans;
    for(int i=0;i<s.size();i++)ans+=(char)tolower(s[i]);
    return ans;
}
int main(){
	//freopen("input","r",stdin);
	string a,b;
	cin>>a>>b;
	a=lower(a);
	b=lower(b);
    if(a==b)cout<<0<<endl;
    else{
        if(a<b)cout<<-1<<endl;
        else cout<<1<<endl;
    }


}

