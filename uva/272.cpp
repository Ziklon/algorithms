#include <iostream>
#include <map>
using namespace std;

int main(){
    string text;
    int n=0;    
    while(getline(cin,text)){
        for(int i=0;i<text.size();i++){
            if(text[i]=='\"'){
                n++;
                if(n&1)
                    cout<<"``";                    
                else
                    cout<<"''";
            }else
                cout<<text[i];
        }
        cout<<endl;
    }
    return 0;  
}
