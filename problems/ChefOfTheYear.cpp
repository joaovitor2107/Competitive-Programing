#include <bits/stdc++.h>
using namespace std;
int main(){

    int n,m;
    cin >> n >> m;
    string a1, a2;
    unordered_map<string, int> cnt;
    unordered_map<string, int> prs;
    unordered_map<string,string>prs_cnt;
    pair<int, string> res_prs;
    pair<int, string> res_cnt;

    res_prs = {0, " "};
    res_cnt = {0, " "};

    for(int i = 0; i < n; i++){
        cin >> a1 >> a2;
        cnt[a2] = 0;
        prs_cnt[a1] = a2;
        prs[a1] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> a1;
        cnt[prs_cnt[a1]]++;
        prs[a1]++;
        if(res_prs.first < prs[a1] || res_prs.first == prs[a1] && res_prs.second > a1){
            res_prs.first = prs[a1];
            res_prs.second = a1;
        }

        if(cnt[prs_cnt[a1]] > res_cnt.first || res_cnt.first == cnt[prs_cnt[a1]] && res_cnt.second > prs_cnt[a1]){
            res_cnt.first = cnt[prs_cnt[a1]];
            res_cnt.second = prs_cnt[a1];
        }

    }

    cout << res_cnt.second << "\n";
    cout << res_prs.second << "\n";

    return 0;
}
