#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
bool in_dq(int id){
    for(auto i : dq){
        if(id == i) return true;
    }
    return false;
}

int main(){

    int n, k;
    cin >> n >> k;

    int id;
    int tam = 0;
    for(int i = 0; i < n; i++){
        cin >> id;
        if(!dq.empty() && in_dq(id)) continue;

        if(tam == k){
            dq.pop_back();
            dq.push_front(id);
        }
        else{
            dq.push_front(id);
            tam++;
        }

    }

    cout << tam << "\n";
    for(int i = 0; i < tam; i++){
        cout << dq.front();
        dq.pop_front();
        if(i < tam - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
