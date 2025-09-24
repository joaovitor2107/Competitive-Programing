#include <bits/stdc++.h>
using namespace std;

#define MAX 200000
vector<int> uni(MAX, -1);


int checkParent(int x){
    if(uni[x] == -1 || uni[x] == x) return x;
    // porque nao retornar x = checkparent(uni[x])
    return uni[x] = checkParent(uni[x]);
}

void group(int u, int v){
    if(uni[u] == -1){
        uni[u] = u;
    }
    else{
        u = checkParent(u);
    }
    uni[checkParent(v)] = u;
}

bool find(int u, int v){
    if(checkParent(u) == checkParent(v)) return true;
    return false;
}

int main() {

    int N, Q;
    cin >> N >> Q;
    for(int i = 0; i < Q; i++){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            group(u, v);
        }
        else{
            if(find(u,v)) cout << 1 << endl;
            else cout << 0 << "\n";
        }
    }

    return 0;
}
