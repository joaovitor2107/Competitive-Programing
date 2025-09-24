#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, x;
    cin >> n >> x;
    int a;
    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> a;
        v[i][0] = a;
        v[i][1] = i+1;
    }
    sort(v.begin(), v.end());

    long long cursum;
    int pt3 = n-1;
    for(int i = 0; i < n-2; i++){
        int pt2 = i+1;
        int pt3 = n-1;

        while(pt2 < pt3){
            cursum = v[i][0] + v[pt2][0] + v[pt3][0];

            if(cursum == x){
                cout << v[i][1] << " " << v[pt2][1] << " " << v[pt3][1] << "\n";
                return 0;
            }
            else if(cursum < x){
                pt2++;
            }
            else if(cursum > x){
                pt3--;
            }
        }
    }

    cout << "IMPOSSIBLE" << "\n";

    return 0;
}
