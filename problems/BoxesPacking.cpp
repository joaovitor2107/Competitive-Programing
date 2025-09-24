#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int a; // é um lado de um cubo
    int size = 1;

    map<int,int> mp;
    for(int i=0; i < n; i++){
        cin >> a;
        if(mp.find(a) == mp.end()){
            mp[a] = 1;
        }
        else{
            mp[a]++;
            size = max(mp[a] ,size);
        }
    }

    cout << size << "\n";

    return 0;
    }
