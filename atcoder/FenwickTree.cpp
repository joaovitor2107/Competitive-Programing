#include <bits/stdc++.h>
using namespace std;

#define MAX 500002
vector<long long int> tree;

void make(int N){
    for(int i = 1; i < N; i++){
        // next power of 2
        int p = i + (i & -i);
        if(p < N) tree[p] += tree[i];
    }
}


long long int sum(long long int i){
    long long int sum = 0;
    while(i > 0){
        sum += tree[i];
        // remove the lsb
        i -= i & -i;
    }
    return sum;
}


void add(long long int i, long long int k, int N){
    while(i < N){
        tree[i] += k;
        i += i & -i;
    }
}


int main(){

    int N,Q;
    cin >> N >> Q;
    vector<long long int> arr(MAX, 0);
    N++;

    for(int i = 1; i < N; i++){
        cin >> arr[i];
    }
    tree = arr;
    make(N);

    for(int i = 0; i < Q; i++){
        long long int q, a0,a1;
        cin >> q >> a0 >> a1;
        if(q == 0){
            add(a0 + 1, a1, N);
        }
        if(q == 1){
            long long int x;
            if(a0 == 0){
                x = sum(a1);
            }else{
                x = sum(a1) - sum(a0);
            }
            cout << x << "\n";
        }

    }

    return 0;
}
