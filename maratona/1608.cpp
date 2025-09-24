#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int t;
  cin >> t;

  for (int j = 0; j < t; j++) {
    int d, i, b;
    cin >> d >> i >> b;
    vector<int> prices(i);
    for (int x = 0; x < i; x++) {
      cin >> prices[x];
    }

    int max_cakes;

    for (int y = 0; y < b; b++) {
      int q;
      cin >> q;

      int cost = 0;
      for (int z = 0; z < q; z++) {
        int quant, index;
        cin >> index >> quant;
        cost += prices[index] * quant;
      }

      if (cost > 0) {
        max(max_cakes, (d / cost));
      }
    }

    cout << max_cakes << "\n";
  }

  return 0;
}
