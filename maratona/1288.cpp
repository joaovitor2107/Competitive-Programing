#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> damage, vector<int> peso, int cap, int res, int n) {
  vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= cap; j++) {
      if (peso[i - 1] <= j) {
        int incluir = dp[i - 1][j - peso[i - 1]] + damage[i - 1];
        int nao = dp[i - 1][j];

        if (incluir > nao) {
          dp[i][j] = incluir;
        } else
          dp[i][j] = nao;
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][cap] >= res;
}

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> damage(n);
    vector<int> peso(n);

    for (int j = 0; j < n; j++) {
      cin >> damage[j] >> peso[j];
    }

    int cap, res;
    cin >> cap >> res;

    if (isPossible(damage, peso, cap, res, n) == true)
      cout << "Missao completada com sucesso\n";
    else
      cout << "Falha na missao\n";
  }

  return 0;
}
