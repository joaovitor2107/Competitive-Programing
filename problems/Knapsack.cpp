#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, W;
    cin >> N >> W;

    W++;
    vector<int> capacity(W, 0);
    vector<pair<int,int>> elem;

    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        elem.push_back({a,b});
    }

    int max = 0;
    for(int i = 0; i < W; i++){
        for(int j = 0; j < elem.size(); j++){
            if( (i + elem[j].first) < W && capacity[i + elem[j].first] < (elem[j].second + capacity[i])) capacity[i + elem[j].first] = elem[j].second + capacity[i];
        }
        if(capacity[i] > max) max = capacity[i];
    }

    for(auto i : capacity){
       cout << i << "\n";
    }
    cout << max << "\n";

    return 0;
}
