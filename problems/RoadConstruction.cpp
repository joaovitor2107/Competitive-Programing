#include <bits/stdc++.h>
using namespace std;

int groups;
int bigger = 0;

int ufind(vector<int> &uni, int x){
    if(uni[x] == 0) return x;
    else return uni[x] = ufind(uni, uni[x]);
}

void add(vector<int>&uni, int a, int b, vector <int>& gsize){
    int aroot = ufind(uni, a);
    int broot = ufind(uni, b);
    if(aroot != broot){
        groups--;
        gsize[aroot] += gsize[broot];
        bigger = max(bigger, gsize[aroot]);
        uni[broot] = aroot;
    }
}


int main(){

    int n,m;
    cin >> n >> m;
    groups = n;
    int a,b;
    vector <int> uni(n+1, 0);
    vector <int> gsize(n+1, 1);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        add(uni, a, b, gsize);
        cout << groups << ' ' << bigger << "\n";
    }

    return 0;
}
