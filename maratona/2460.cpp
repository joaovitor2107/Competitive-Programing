#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  vector<int> fila;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x;
    fila.push_back(x);
  }

  int h;
  cin >> h;

  set<int> valores_remover;
  for(int i = 0; i < h; i++){
    cin >> x;
    valores_remover.insert(x);
  }

  vector<int> resultado;
  for(int i = 0; i < n; i++){
    if(valores_remover.find(fila[i]) == valores_remover.end()){
      cout << fila[i] << " ";
    }
  }



  return 0;
}
