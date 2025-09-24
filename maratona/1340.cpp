#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main(int argc, char *argv[]) {

  int n;
  while(cin >> n){
    int x,y;
    stack<int> pilha;
    queue<int> fila;
    priority_queue<int> pq;
    bool pilha_flag = true, fila_flag = true, pq_flag = true, impossible = false;

    for (int i = 0; i < n; i++) {


      cin >> y >> x;

      if(y == 1){
        pilha.push(x);
        fila.push(x);
        pq.push(x);
      }

      if(y == 2){
        if(pilha.top() != x){
          pilha_flag = false;
        }
        pilha.pop();

        if(fila.front() != x){
          fila_flag = false;
        }
        fila.pop();

        if(pq.top() != x){
          pq_flag = false;
        }
        pq.pop();
      }
    }

    if((pilha_flag + fila_flag + pq_flag) >= 2){
      cout << "not sure" << "\n";
    }
    else if((pilha_flag + fila_flag + pq_flag) == 0){
      cout << "impossible" << "\n";
    }
    else if(pilha_flag){
      cout << "stack" << "\n";
    }
    else if(fila_flag){
      cout << "queue" << "\n";
    }
    else if(pq_flag){
      cout << "priority queue" << "\n";
    }


  }

  return 0;
}
