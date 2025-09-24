#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int b, i;
  cin >> b >> i;
  vector<pair<int, int>> programas_baixados;
  map<int,int> baixar;

  for (int i = 0; i < b; i++) {
    int x,y;
    cin >> x >> y;
    programas_baixados.push_back({x, y});
  }


  for (int h = 0; h < i; h++) {
    int x, y;
    cin >> x >> y;

    bool aux=false;
    for (int j=0; j < b; j++) {
      if(programas_baixados[j].first == x) aux=true;
      if(programas_baixados[j].first == x && programas_baixados[j].second < y) {

        if(baixar.find(x) == baixar.end() || baixar[x] < y){
          baixar[x] = y;
        }
      }
    }
    if(aux == false) baixar[x] = y;
  }

  for(const auto& pair : baixar){
    cout << pair.first << " " << pair.second << "\n";
  }

  return 0;
}

