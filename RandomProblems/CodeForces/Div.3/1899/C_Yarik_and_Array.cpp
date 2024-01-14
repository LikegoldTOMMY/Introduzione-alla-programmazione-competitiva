/*
Autore: Tommaso Ulian
Data: 14/01/2024
Problema: Codeforces 1899 C
Rating: 1100
Tags: Greedy, dp, two pointers
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

vector<int> v;
int n;

bool even(int x){
    return (x%2 +2)%2;
}

void solve(){
    cin >> n;
    v.clear();
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int currentSum = v[0];
    int maxSum = v[0];
    for (int i = 1; i < v.size(); ++i) {
        currentSum = max(v[i], (currentSum + v[i]));
        if(even(v[i]) == even(v[i-1])){currentSum = v[i];}

        maxSum = max(maxSum, currentSum);
    }

    cout<<maxSum << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
