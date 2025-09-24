#include <bits/stdc++.h>
using namespace std;


bool can_divide(vector<int>&vec, int k, int max){



    return true;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    int max = 0;

    for(int i=0; i < n; i++){
        cin >> vec[i];
        if(vec[i] > max) max = vec[i];
    }



    return 0;
}
