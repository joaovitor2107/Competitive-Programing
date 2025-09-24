#include <bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    char s;
    int x,y;

    unordered_map<int,bitset<20000>> mp;

    bitset<20000> res(0);
    for(int i = 0; i<q; i++){
       cin >> s >> x >> y;
       if(s == '+'){
           mp[x].set(y);
       }
       if(s == '-'){
           mp[x].reset(y);
       }
       if(s == 'v'){
           res = (mp[x] | mp[y]);
           cout << res.count() << "\n";
       }
       if(s == '^'){
           res = (mp[x] & mp[y]);
           cout << res.count() << "\n";
       }
       if(s == '!'){
           res = (mp[x] ^ mp[y]);
           cout << res.count() << "\n";
       }
       if(s == '\\'){
           res = (~mp[y] & mp[x]);
           cout << res.count() << "\n";
       }

    }

    return 0;
}
