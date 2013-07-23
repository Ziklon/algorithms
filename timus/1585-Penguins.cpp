#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
int N;
string cad;
map<string,int> M;
string kinds[]={"Emperor Penguin","Macaroni Penguin","Little Penguin"};
int main(){
    scanf("%d\n",&N);
    while(N--){
        getline(cin,cad);
        M[cad]++;
    }
    int cnt=0;
    string ans;
    for(int i=0;i<3;i++)if(M[kinds[i]]>cnt){
        ans=kinds[i];
        cnt=M[kinds[i]];
    }
    printf("%s\n",ans.c_str());
    return 0;
}

