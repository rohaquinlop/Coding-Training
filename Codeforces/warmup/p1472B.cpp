#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Step{
public:
	int i;
	int sumA;
	int sumB;

	Step(int _i, int _sumA, int _sumB){
		this->i = _i;
		this->sumA = _sumA;
		this->sumB = _sumB;
	}

};

bool solve(vector<int> v, int n){
	queue<Step> q;
	q.push(Step(0, 0, 0));

	int arr[203][203] = {0};

	while(!q.empty()){
		Step s = q.front();
		q.pop();

		if(s.i == n){
			if( s.sumA == s.sumB )
				return true;
		}
		else{
			if( !arr[s.sumA+v[s.i]][s.sumB] and !arr[s.sumB][s.sumA+v[s.i]] ){
				q.push( Step(s.i+1, s.sumA+v[s.i], s.sumB) );
				arr[s.sumA+v[s.i]][s.sumB]++;
			}
			if( !arr[s.sumA][s.sumB+v[s.i]] and !arr[s.sumB+v[s.i]][s.sumA] ){
				q.push( Step(s.i+1, s.sumA, s.sumB+v[s.i]) );
				arr[s.sumA][s.sumB+v[s.i]]++;
			}
		}
	}


	return false;
}

int main(){
	int t, n, i;

	cin >> t;

	while(t--){
		cin >> n;

		vector<int> v(n);

		for(i = 0; i < n; i++) cin >> v[i];

		if( solve(v, n) ) cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;
}