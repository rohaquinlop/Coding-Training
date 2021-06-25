// AC
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, k, num, ans;
    char c;
    map<char, long long> power;
    priority_queue<long long> pri;

    while(cin >> n >> k){
        ans = 0;
        power = map<char, long long> ();
        pri = priority_queue<long long>();

        cin.ignore();
        for (int i = 0; i < n; i++){
            scanf("%c", &c);
            power[c]++;
        }

        for(map<char,long long>::iterator it = power.begin(); it != power.end(); it++){
            pri.push((*it).second);
        }   

        while(!pri.empty() && k > 0){
            num = pri.top();
            //cout << num << " " << k << endl;

            if(k - num >= 0){
                ans += num*num;
                k -= num;
            }else{
                ans += k*k;
                k = 0;
            }
            pri.pop();
        }    
        cout << ans << endl;
    }
    

    return 0;
}