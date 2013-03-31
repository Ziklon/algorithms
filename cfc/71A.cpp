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
    int N;
	//freopen("input","r",stdin);
    cin>>N;
    for(int i=0;i<N;i++){
        string text;
        cin>>text;
        int M=text.size();
        if(text.size()<=10)
            cout<<text<<endl;
        else{
            cout<<text[0]<<(M-2)<<text[M-1]<<endl;
        }
    }
	return 0;
}

