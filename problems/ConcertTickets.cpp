#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<int> ms;
    int price;
    for(int i = 0; i < n; i++){
        cin >> price;
        ms.insert(price);
    }

    int pay;
    for(int i = 0; i < m; i++){
        cin >> pay;
        if(ms.empty()){
            cout << -1 << "\n";
            continue;
        }
        auto it = ms.upper_bound(pay);
        if(it == ms.begin()){
            cout << -1 << "\n";
        }
        else{
            it--;
            cout << *it << "\n";
            ms.erase(it);
        }

    }

    return 0;
}
