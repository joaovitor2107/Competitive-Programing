#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){

    int N;
    cin >> N;
    vector<long long> vec(N);
    priority_queue<int> pq;
    long long res;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        pq.push(x);
        if(i >= 2){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long c = pq.top();
            res = a*b*c;
            pq.push(a);
            pq.push(b);

            vec[i] = res;
        }
    }


    for(int i = 0; i < N; i++){
        if(i < 2) cout << -1 << "\n";
        else{
            cout << vec[i] << "\n";
        }
    }

    return 0;
}
