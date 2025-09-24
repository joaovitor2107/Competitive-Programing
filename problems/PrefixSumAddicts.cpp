#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

bool exists_sequence(vector<int> &ps, int n, int k){
    for(int i = k-1; i > 0 ; i--){
        ps[i] -= ps[i-1];
    }

    for(int i = 0; i < k-1; i++){
        if(k == n){
            if(ps[i] > ps[i+1]) return false;
        }
        else if(ceil(float(ps[0])/float((n-k+1))) > ps[1]){
            return false;
        }
    }

    return true;
}


int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int n, k;
        cin >> n >> k;
        vector<int> prefix_sum(k);
        for(int j = 0; j < k; j++){
            cin >> prefix_sum[j];
        }
        if(exists_sequence(prefix_sum, n, k)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

    return 0;
}
