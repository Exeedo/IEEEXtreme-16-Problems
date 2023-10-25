// Problem link: https://csacademy.com/ieeextreme-practice/task/scheduler-redux
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

long long M = 1'000'000'007;

long long pwr(long long x, long long y) { // Calculates X to the power Y
    if (y == 0) return 1;
    long long half = pwr(x, y/2);
    half *= half; // full power (- 1)
    half %= M;
    if(y % 2 == 1) {
        return (half * x) % M;
    }
    else {
        return half;
    }
}

vector<long long> workers[21];
vector<long long> jobs;

bool cmp(vector<long long> &w1, vector<long long> &w2) {
    // return true when w1 < w2
    for (int i = 0; i < w1.size() && i < w2.size() ; i++){
        if(w1[i] != w2[i]) {
            return w1[i] < w2[i];
        }
    }
    return w1.size() < w2.size();
}
// 8, 7, 5, 2
// 8, 7, 5

void push(int idx, long long job) {
    if(workers[idx].empty()){
        workers[idx].push_back(job);
        return;
    }
    while (!workers[idx].empty() && workers[idx].back() == job) {
        workers[idx].pop_back();
        job ++;
    }
    workers[idx].push_back(job);
}

int main() {
    int n,m;
    cin >> n >> m;
    jobs.resize(n);
    for(int i =0 ; i < n; i ++) {
        cin >> jobs[i];
    }
    if(m == 1) {
        long long ans = 0;
        for (long long job : jobs) {
            ans += pwr(2, job);
            ans %= M;
        }
        cout << ans;
        return 0;
    }
    sort(jobs.rbegin(), jobs.rend());
    int cur = 0, maximum = 0;
    workers[0].push_back(jobs[0]);
    cur = 1;
    for(int i = 1; i < n ; i ++) {
        // workers[cur].push_back(jobs[i]);
        push(cur, jobs[i]);
        if (!cmp(workers[cur], workers[maximum])) {
            maximum = cur;
            cur += 1;
            cur %= m;
        }
    }
    long long ans = 0;
    for (long long job : workers[maximum]) {
        ans += pwr(2, job);
        ans %= M;
    }
    cout << ans;
	return 0;
}
