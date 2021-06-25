//AC
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string name;
    set<string> names;
    while(cin >> n){
        
        for (int i = 0; i < n; i++){
            cin >> name;
            if(names.find(name) == names.end())
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
            names.insert(name);
        }
    }
    
    return 0;
}