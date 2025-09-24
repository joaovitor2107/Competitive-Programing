#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int s;
  cin >> s;
  vector<int> qua(s);
  vector<int> nlo(s);
  for (int i = 0; i < s; i++) {
    cin >> qua[i];
  }
  for (int i = 0; i < s; i++) {
    cin >> nlo[i];
  }

  sort(qua.begin(), qua.end());
  sort(nlo.begin(), nlo.end());

  int win = 0;
  int x = 0;
  int y = 0;
  int aux = 0;

  while (x < s && y < s) {
    if (qua[x] < nlo[y]) {
      x++;
      win++;
      y++;
    } else {
      y++;
    }
  }

  cout << win << "\n";

  return 0;
}
