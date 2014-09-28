#include <cstdio>
#include <iostream>
#include <set>
#include <vector>


using namespace std;
int n;
string s ;
int main() {
    
    //freopen("in.txt", "r", stdin);
    while(cin >> n) {
        if(n == 0)break;
        cin >> s;
        set<char> S;
        int need = 0;
        
        vector<bool> seen(256,0);
        
        
        for(int i=0;i<s.size();++i){
            char c = s[i];
            if(seen[s[i]])continue;
        
            if(S.count(c)){
                S.erase(c);
                continue;
            }else{
                if(S.size() < n)S.insert(c);
                else {
                    seen[c]=1;
                    need++;
                }
            }           
        }
        if(need==0)cout<<"All customers tanned successfully."<<endl;
        else cout<<need<<" customer(s) walked away."<<endl;
        
    }
    return 0;
}
