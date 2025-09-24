#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int n ,d;
  while(cin >> n >> d){
    if(n == 0 && d == 0) return 0;

    string num;
    cin >> num;

    stack<int> pilha;
    int removeds = 0;

    for(int i = 0; i < n; i++) {
      int digit = num[i] - '0';

      while(!pilha.empty() && pilha.top() < (digit) && removeds < d){
        pilha.pop();
        removeds++;
      }

        pilha.push(digit);
    }

    while(removeds < d && !pilha.empty()){
      pilha.pop();
      removeds++;
    }

    string result;
    stack<int> temp;
    while(!pilha.empty()) {
      temp.push(pilha.top());
      pilha.pop();
    }

    while(!temp.empty()){
      result += to_string(temp.top());
      temp.pop();
    }


    cout << result << "\n";

  }

  // tem que criar uma pilha e add os elemento no inicio, caso achemos um elemento maior que o do topo da pilha e ainda tenhamos espaço de n - d, estouramos e substituimos



  return 0;
}
