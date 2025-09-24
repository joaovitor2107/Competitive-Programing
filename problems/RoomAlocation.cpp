#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    int rooms = 0;
    vector<int> res(N);
    vector<pair<int,pair<int,int>>> cust(N);
    int di, dl;

    for(int i = 0; i < N; i++){
        cin >> di >> dl;
        cust[i] = {di, {dl, i}};
    }

    sort(cust.begin(), cust.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> u_rooms;
    priority_queue<int, vector<int>, greater<int>> free_rooms;


    for(int i = 0; i < N; i++){
        while(!u_rooms.empty() && u_rooms.top().first < cust[i].first){
            free_rooms.push(u_rooms.top().second);
            u_rooms.pop();
        }
        if(free_rooms.empty()){
            rooms++;
            u_rooms.push({cust[i].second.first, rooms});
            res.push_back(rooms);
            res[cust[i].second.second] = rooms;
        }
        else{
            res[cust[i].second.second] = free_rooms.top();
            u_rooms.push({cust[i].second.first, free_rooms.top()});
            free_rooms.pop();
        }
    }

    cout << rooms << "\n";
    for(int i=0; i < N; i++){
        cout << res[i];
        if(i < N-1) cout << " ";
    }

    cout << "\n";

    return 0;
}
