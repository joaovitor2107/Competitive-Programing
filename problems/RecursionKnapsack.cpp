#include <bits/stdc++.h>
using namespace std;

void dp(vector<int>& capacity, vector<pair<int,int>> & elem, int init, int last, int W){
    for(int i = init; i < elem.size(); i++){
        if(elem[i].first + last < W){
            if(capacity[elem[i].first + last] < capacity[last] + elem[i].second)
                capacity[elem[i].first + last] =  capacity[last] + elem[i].second;

            dp(capacity, elem, i+1, (elem[i].first + last), W);
        }
    }
}


int main(){

    int N, W;
    cin >> N >> W;
    W++;
    vector<int> capacity(W, 0);
    vector<pair<int,int>> elem;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        elem.push_back({a,b});
    }

    dp(capacity, elem, 0, 0, W);

    int maxs = 0;
    for(auto i : capacity){
        maxs = max(maxs, i);
    }

    cout << maxs << "\n";

    return 0;
}
