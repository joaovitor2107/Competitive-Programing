#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int n;
  cin >> n;
  int xi[n];
  int xf[n];
  int yi[n];
  int yf[n];

  int max_x = 1;
  int max_y = 1;
  for (int i = 0; i < n; i++) {
    cin >> xi[i];
    cin >> xf[i];
    if(xf[i] > max_x)  max_x = xf[i];
    cin >> yi[i];
    cin >> yf[i];
    if (yf[i] > max_y)  max_y = yf[i];
  }

  bool matrix[max_x][max_y];

for (int i = 0; i < max_x; i++) {
    for (int j = 0; j < max_y; j++) {
        matrix[i][j] = false;
    }
}

  int result = 0;
  for (int h = 0; h < n; h++) {
    for (int i = xi[h] - 1; i < xf[h] - 1; i++) {
      for (int j = yi[h] - 1; j < yf[h] - 1; j++) {
        if(matrix[i][j] == false) result++;
        matrix[i][j] = true;
      }
    }
  }

  for (int i = 0; i < max_x; i++) {
    for (int j = 0; j < max_y; j++) {
        printf("%d", matrix[i][j]);
    }
    printf("\n");
}


  printf("%d\n", result);


  return 0;
}
