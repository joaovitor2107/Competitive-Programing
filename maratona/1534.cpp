#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int n;
  while(cin >> n){
    int matrix[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          matrix[i][j] = 3;
        }
    }


    int j = 0;
    for(int i = 0; i < n; i++) {
      matrix[i][j] = 1;
      j++;
    }


    j = n - 1;
    for(int i = 0; i < n; i++) {
      matrix[i][j] = 2;
      j--;
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        printf("%d",matrix[i][j]);
      }
      printf("\n");
    }

  }


  return 0;
}
