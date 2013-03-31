#include <ctime>
#include <numeric>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <queue>
using namespace std ;
int main()
{
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    map<string,int>m;
        m["LU"]=0;
        m["MA"]=1;
        m["MI"]=2;
        m["JU"]=3;
        m["VI"]=4;
        m["SA"]=5;
        m["DO"]=6;
    for(int cases=0;cases<n;cases++){
        int t;
        cin>>t;
        bool ok[t][7][24];
        memset(ok,0,sizeof(ok));
        string aux;
        getline(cin,aux);
        for(int i=0;i<t;i++){
            getline(cin,aux);
            string s;int a,b;
            istringstream is(aux);
            while(is>>s>>a>>b){
                for(int j=a;j<b;j++){
                    ok[i][m[s]][j]=1;  
                }
            }
        }
        int q;
        cin>>q;
        cout<<"Caso #"<<cases+1<<":";
        getline(cin,aux);
        for(int i=0;i<q;i++){
            string s;int a,b;
            cin>>s>>a>>b;
            bool can[t];
            memset(can,1,sizeof(can));
            for(int j=a;j<b;j++){
                for(int k=0;k<t;k++){
                    if(ok[k][m[s]][j]==0){
                        can[k]=0;    
                    }
                }
            }
            int cont=0;
            for(int j=0;j<t;j++)if(can[j])cont++;
            if(2*cont>=t)cout<<" Si";
            else cout<<" No";
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}
