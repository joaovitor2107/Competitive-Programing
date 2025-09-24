#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int a, b;
  while(cin >> a >> b){
    if(a == 0 && b == 0) break;

    int a_cartas[a], b_cartas[b];
    set<int> set_a, set_b;

    for (int i = 0; i < a; i++) {
      cin >> a_cartas[i];
      set_a.insert(a_cartas[i]);
    }
    for (int i = 0; i < b; i++) {
      cin >> b_cartas[i];
      set_b.insert(b_cartas[i]);
    }

    //tem que pegar o tam do set e com o tam do set e ai poder decidir se o set
    int i = 0, j = 0, result = 0;
    while(i < a && j < b){
      if(a_cartas[i] == b_cartas[j]){
          i++, j++;
      }
      else if(a_cartas[i] != b_cartas[j]){
        if(set_b.count(a_cartas[i]) > 0){
          int temp = a_cartas[i];
          while(i < a && a_cartas[i] == temp ) i++;
        }
        else if(set_a.count(b_cartas[j]) > 0){
          int temp = b_cartas[j];
          while(j < b && b_cartas[j] == temp) j++;
        }
        else{
          result++;
          set_a.insert(b_cartas[j]);
          set_b.insert(a_cartas[i]);
          i++, j++;
        }
      }

    }

    cout << result << "\n";
    //preciso que troquem as que nao tem em nenhum, ou seja se tem uma carta a aqui, nao posso ter essa carta mais

  }

  return 0;
}
