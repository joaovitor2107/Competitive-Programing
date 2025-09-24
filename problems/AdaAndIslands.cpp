#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<char>> &mx, int n, int m, vector<vector<bool>>&visited){

    if(!visited[i][j]){
        visited[i][j] = true;
        int sum = 1;

        if(i - 1 >= 0){
            if(mx[i-1][j] == '#') sum += dfs(i-1, j, mx, n, m, visited);
        }

        if(i + 1 < n){
            if(mx[i+1][j] == '#') sum += dfs(i+1, j, mx, n, m, visited);
        }

        if(j - 1 >= 0){
            if(mx[i][j-1] == '#') sum += dfs(i, j-1, mx, n, m, visited);
        }

        if(j + 1 < m){
            if(mx[i][j+1] == '#') sum += dfs(i, j+1, mx, n, m, visited);
        }

        return sum;
    }

    return 0;
}

int greatest(int a, int b){
    if(a == 0){
        return b;
    }
    return greatest(b%a, a);
}

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    int n,m;
    for(int h = 0; h < t; h++){
        cin >> n >> m;

        vector<vector<char>> mx(n, vector<char>(m));
        vector<vector<bool>>visited(n, vector<bool>(m, false));



        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               cin >> mx[i][j];
            }
        }


        long long int mult = n*m;
        long long aux;
        long long int final_res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mx[i][j] == '#' && !visited[i][j]){
                   aux = (dfs(i, j, mx, n, m, visited));
                   final_res += aux*aux;
                }
            }
        }

        long long g;
        if(final_res == 0) cout << "0" ;
        else if(final_res%(mult) == 0) cout << (long long int)(final_res/(mult));
        else{
            g = greatest(final_res, mult);
            cout << (final_res)/g << " / " << (mult)/g ;
        }

    }

    return 0;
}
