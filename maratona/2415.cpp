#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int n;
  cin >> n;

  int x, prev;
  int curr = 1;
  int result = 0;

  for (int i = 0; i < n; i++) {
    cin >> x;
    if(x == prev) curr++;
    else{
      prev = x;
      if(result < curr) result = curr;
      curr = 1;
    }
  }

  if(result < curr) result = curr;
  printf("%d\n", result);


  return 0;
}
