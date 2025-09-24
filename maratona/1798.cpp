#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, t;
  cin >> n >> t;
  vector<float> length(n);
  vector<float> value(n);
  float maior = 0;
  for (int i = 0; i < n; i++) {
    cin >> length[i] >> value[i];
    if (value[i] / length[i] > maior) {
      maior = (t / length[i]) * value[i];
    }
  }

  cout << maior << "\n";

  return 0;
}
