// Problem link: https://csacademy.com/ieeextreme-practice/task/my-treat
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

map <string, int> counter;

int main() {
    int t;
    cin >> t;
    while(t--){
        counter.clear();
        int m; cin >> m;
        for(int i = 0; i < m; i++) {
            string name;
            cin >> name;
            int ppl ;
            cin >> ppl;
            counter[name] += ppl;
            for(int j = 0; j < ppl; j++) {
                string name2;
                cin >> name2;
                counter[name2]--;
            }
        }
        int meals = 0, days = 0;
        for(auto element : counter) {
            int x = element.second;
            if (x <= 0) continue;
            meals += x;
            days = max(days, x);
        }
        cout << meals << ' ' << days << endl;
    }
	return 0;
}

/*
Alice 1 Bob
Chuck 1 Dave
Dave 1 Eve


Alice -> need 1 meal
Chuck -> need 1 meal


Bob -> needs to pay for 1 meal
Eve -> needs to pay for 1 meal

Day 1:
Bob 1 Alice
Eve 1 Chuck
[2, 1]

-------------------------------------

Alice 2 Bob Chuck
Chuck 1 Bob
Dave 2 Alice Bob
Alice 1 Eve

Alice -> needs 2 meals
Dave -> needs 2 meals

Bob  -> needs to pay for 3 meals
Eve -> needs to pay for 1 meal

Day 1:
Bob 2 Alice Dave

Day 2:
Bob 1 Alice
Eve 1 Dave

[4, 2]
*/
