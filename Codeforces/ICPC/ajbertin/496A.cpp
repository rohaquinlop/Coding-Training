//A
#include <bits/stdc++.h>

using namespace std;
vector<int> nums,restas;

int main(){
    int n, aux1, mx, resta1, resta2, ant;
    
    while(cin>>n){
        mx = INT_MAX;
        nums = vector<int>();
        restas = vector<int>();
        for (int i = 0; i < n; i++){
            cin >> aux1;
            nums.push_back(aux1);
            if(i > 0)
                restas.push_back(aux1 - ant);
            ant = aux1;
        }

        for (int i = 0; i < n; i++){
            int mn1, mn2;
            bool flag1 = true, flag2 = true;
            if(i + 2 < n){
                resta1 = nums[i + 2] - nums[i]; 
                flag1 = false;
            }
            if(i - 2 >= 0){
                resta2 = nums[i] - nums[i - 2];
                flag2 = false;
            }

            mn1 = 0;
            mn2 = 0;
            
            for (int j = 0; j < restas.size(); j++){
                if( j != i && j != i + 1 && i + 2 < n)
                    mn1 = max(mn1, restas[j]);
                if( j != i - 1 && j != i - 2 && i - 2 >= 0)
                    mn2 = max(mn2, restas[j]);
            }

            resta1 = max(resta1, mn1);
            resta2 = max(resta2, mn2);

            if(flag1) resta1 = INT_MAX;
            if(flag2) resta2 = INT_MAX;

            mx = min( resta1, min(resta2, mx));
            
        }
        cout << mx << endl;
    }
    
    return 0;
}