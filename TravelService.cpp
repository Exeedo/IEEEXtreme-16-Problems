// Problem link: https://csacademy.com/ieeextreme-practice/task/travel-service
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

long long s, c;
vector<long long> f, r;
long long dp[10005];
vector<vector<long long>> dp_vector;

long long cal(int idx, int fuel) { 
    // Time: O(1) * O(n*n) states
    // Memory: O(n*n)
    if (idx == s) {
        return 0;
    }
    long long ans = dp_vector[idx][fuel];
    if (ans != -1) return ans;
    ans = 1e18;
    if (fuel >= f[idx + 1])
        ans = min(ans, cal(idx + 1, fuel - f[idx + 1]));
    ans = min(ans, cal(idx + 1, c - f[idx + 1]) + (r[idx] * (c - fuel)) + 500);
    dp_vector[idx][fuel] = ans;
    return ans;
}

long long cal2(int idx) { 
    // Time: O(n) per state * O(n) states
    // Memory: O(n)
    if(idx == s) return 0;
    long long ans = dp[idx];
    if ( ans != -1) return ans;
    ans = 1e18;
    long long dist = 0;
    for(int i = idx + 1; i <= s; i++) {
        dist += f[i];
        if (dist > c) break;
        long long cost = dist * r[i] + 500;
        if (i== s) cost = 0;
        ans = min(ans, cost + cal2(i));
    }
    
    dp[idx] = ans;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> s >> c;
        dp_vector.resize(s+1);
        for(auto &x: dp_vector) x = vector<long long>(c, -1);
        f.resize(s + 1);
        r.resize(s + 1);
        cin >> r[0];
        f[0] = 0;
        for(int i = 1; i <= s; i++)
            cin >> f[i] >> r[i];
        // cout << cal(0, 0) - 500 << endl;
        cout << cal2(0) + r[0] * c << endl;
    }
    return 0;
}

