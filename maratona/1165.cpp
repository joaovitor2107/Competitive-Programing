#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {

    int x;
    cin >> x;

    int isprime = 0;
    for (int j = 2; j < x; j++) {
      if(x % j == 0) isprime++;
    }

    if(isprime != 0) printf("%d nao eh primo\n", x);
    else printf("%d eh primo\n", x);

  }

  return 0;
}
