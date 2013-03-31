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
string voc="aeiouy";
int main(){
	//freopen("input","r",stdin);
    string text,ans;
    cin>>text;
    for(int i=0;i<text.size();i++)text[i]=tolower(text[i]);

    for(int i=0;i<text.size();i++){
        if(voc.find(text[i])!=-1)continue;
        ans+=string(1,'.')+text[i];
    }
    cout<<ans<<endl;
	return 0;
}

