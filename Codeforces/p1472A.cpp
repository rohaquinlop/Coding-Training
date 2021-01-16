#include<iostream>

using namespace std;


int main(){
	int t, w, h, n, a;

	cin >> t;

	while(t--){
		cin >> w >> h >> n;
		a = 1;

		while( w%2 == 0 or h%2 == 0 ){
			a *= 2;
			if(w%2 == 0){
				w /= 2;
			}
			else if(h%2 == 0){
				h /= 2;
			}
		}

		if( a >= n ){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}


	return 0;
}