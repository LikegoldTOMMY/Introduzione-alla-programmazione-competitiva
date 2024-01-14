/*
Autore: Tommaso Ulian
Data: 14/01/2024
Problema: Codeforces 1914 A
Rating: 800
Tags: Implementation, Strings
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
 
void solve(){
    string s;
    int n;
    cin >> n >>s;
    vector<int> a(26,0);
    for(int i = 0; i < s.length(); i++){
        a[s[i] - 'A'] ++;
    }
    int count = 0;
    for(int i = 0; i< 26; i++){
        if(a[i] >= i+1)count++;
    }
    cout << count << endl;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
 
	
    return 0;
}