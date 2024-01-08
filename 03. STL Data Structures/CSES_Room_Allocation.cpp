/*
Autore: Tommaso Ulian
Data: 05/01/2024
Problema: CSES Room Allocation
Tags: Data Structures, Sortings
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

struct ComparePairs {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first > b.first; 
    }
};

void solve(){
    int n; cin >> n;
    vector<pair<int,pair<int,int>>> v;
    int i = 0;
    while(n--){
        int a, d; cin >> a >> d;
        v.push_back({a,{d,i}});
        i++;
    }
    sort(v.begin(),v.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> q;
    vector<int> ans(v.size());
    set<int> free = {1};
    int m = 0;
    for(int i = 0; i < v.size(); i++){
        int a = v[i].first;
        int d = v[i].second.first;
        int pos = v[i].second.second;
        while(!q.empty() && q.top().first < a){
            free.insert(q.top().second);
            q.pop();
        }
        int room;
        if(free.size() == 0)room = q.size()+1;
        else{
            room = *free.begin();
            free.erase(free.begin());
        }
        q.push({d,room});
        
        ans[pos] = room;
        m = max(m, room);
    }
    cout << m << endl;
    for(int x: ans)cout << x << " ";
}
int main(){
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
