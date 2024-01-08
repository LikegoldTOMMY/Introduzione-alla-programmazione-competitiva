/*
Autore: Tommaso Ulian
Data: 06/01/2024
Problema: Codeforces 1913 C
Rating: 1300
Tags: Binary Search, Bitmasks, Brute force, Greedy
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

/*
Per il primo tipo di query memorizziamo tutte le potenze di 2 in un array di dimensione 30.
Per il secondo tipo di query controlliamo nell array partendo dalla potenza di due più grande
alla più piccola, se la potenza di 2 è minore del numero, tolgo al numero quante volte riesco 
quella potenza di due. Quindi ad esmpio se il numero è 12 e ho immagazzinato 5 volte 2^1 allora
rimovo da 12 5*2^1 e ottengo poi 2. Se alla fine ottengo 0 allora posso creare il numero con le
potenze di 2 immagazzinate. 
E' importante calcolare le potenze di 2 usando il bitshift, e non la funzione pow().
Quindi 1 << x calcola 2 alla x semplicemente manipolando i bit.
*/

void solve(){
    vector<int> v(30,0);
    int m;
    cin >> m;
    int ma = 0;
    while(m--){
        int a;
        int n;
        cin >> a >> n;
        if( a == 1){
            ma = max(ma,n);
            v[n]++;
        }
        else{
            for(int i = ma; i >= 0; i--){
                int ct = n/(1<<i);
                ct = min(ct,v[i]);
                n -= ct*(1<<i);
            }
            if(n == 0)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
 
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    solve();
 
	
    return 0;
}