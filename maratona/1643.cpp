#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> fibs;
  fibs.push_back(1);
  fibs.push_back(2);
  while (true) {
    int aux = fibs[fibs.size() - 1] + fibs[fibs.size() - 2];
    if (aux >= 25000)
      break;
    fibs.push_back(aux);
  }

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int km, mile, ixi;
    ixi = fibs.size() - 1;
    mile = 0;
    cin >> km;
    while (km > 0) {
      if (km >= fibs[ixi]) {
        km -= fibs[ixi];
        if (ixi > 0)
          mile += fibs[ixi - 1];
      }
      ixi--;
    }

    cout << mile << "\n";
  }

  return 0;
}
