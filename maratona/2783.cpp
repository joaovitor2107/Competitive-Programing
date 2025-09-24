#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {


  int N, C, M;
  cin >> N;
  cin >> C;
  cin >> M;


  map<int, bool> x;
  for (int i = 0; i < C; i++) {
    int temp;
    cin >> temp;
    x[temp] = true;
  }

  int result = C;
  for (int i = 0 ;i < M; i++) {
    int y;
    cin >> y;
    for (int j = 0; j < C; j++){
      if(x.count(y) > 0 && x[y] == true) {
        result--;
        x[y] = false;
        }
    }
  }

  printf("%d", result);

  return 0;
}
