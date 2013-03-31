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

int main(){
	//freopen("input","r",stdin);
	string text;
	cin>>text;
    bool oka=1;
    bool okb=islower(text[0]);
    for(int i=0;i<text.size();i++)if(islower(text[i]))oka=0;
    for(int i=1;i<text.size();i++)okb=okb&&isupper(text[i]);

    if(oka || okb){

        if(okb){
            cout<<(char)toupper(text[0]);
            for(int i=1;i<text.size();i++)cout<<(char)tolower(text[i]);
            cout<<endl;
        }else{
            for(int i=0;i<text.size();i++)cout<<(char)tolower(text[i]);
            cout<<endl;
        }
    }else
        cout<<text<<endl;

	return 0;
}

