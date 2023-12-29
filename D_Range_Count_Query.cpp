#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int query(int l, int r, int x, vector<int> v){
    
    auto first = v.begin()+l-1;
    auto second = v.begin()+r;
    vector<int> p(first,second);
    sort(p.begin(),p.end());
    for(auto y:p)cout << y << " ";
    cout << endl;
    int start = distance(v.begin(), upper_bound(v.begin(),v.end(),x));
    int finish = distance(v.begin(), lower_bound(v.begin(),v.end(),x));
    
    return ;
}
int main(){
    int n; cin >> n;
    vector<int> v;
    while(n--){int x; cin >> x; v.push_back(x);}
    int q; cin >> q;
    while(q--){
        int l,r,x; cin >> l >> r >> x;
        cout << query(l,r,x,v) << endl;
    }
    return 0;
}