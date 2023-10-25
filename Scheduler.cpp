// Problem link: https://csacademy.com/ieeextreme-practice/task/scheduler
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

long long M = 1'000'000'007;

long long pwr(long long x, long long y) { // Calculates X to the power Y
    if (y == 0) return 1;
    long long half = pwr(x, y/2);
    half *= half; // becomes full power (or - 1)
    half %= M;
    if(y % 2 == 1) {
        return (half * x) % M;
    }
    else {
        return half;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for(int i = 0; i < n;i++){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    if(m == 1) {
        long long ans = 0;
        for(long long x: v){
            ans += pwr(2, x);
            ans %= M;
        }
        cout << ans;
    }
    else {
        cout << pwr(2, v[0]);
    }
	return 0;
}

/*

2 ^ X -> 
result = 1;
for (int i=0;i<x;i++)  -> O(n)
    result *= 2;

** Only for powers of 2
(1 << X) = 1 * 2^X   -> O(1)


(expression) % M => [0 - M-1]
*/
