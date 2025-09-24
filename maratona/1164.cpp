#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int tests;
  cin >> tests;
  for (int count = 0 ; count < tests; count++) {

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i < n; i++) {
      if(n % i == 0) sum += i;
    }
    if(sum == n) printf("%d eh perfeito\n", n);
    else printf("%d nao eh perfeito\n", n);
  }

  return 0;
}
