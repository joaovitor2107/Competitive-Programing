#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

    int n, m;
    cin >> n >> m;
    queue<pair<int,int>> q;
    int aux,pos;
    for(int i = 0; i < n; i++){
        cin >> aux;
        q.push({aux, i + 1});
    }

    while(!q.empty()){
        aux = q.front().first;
        pos = q.front().second;
        if((aux - m) <= 0) q.pop();
        else{
            q.push({aux - m, pos});
            q.pop();
        }
    }

    cout << pos << "\n";


    return 0;
}
