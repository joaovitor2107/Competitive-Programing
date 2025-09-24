#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int collum;
  cin >> collum;

  char operation;
  cin >> operation;

  float matrix[12][12];

  for (int i = 0 ; i < 12; i++){
    for (int j = 0 ; j < 12; j++){
      cin >> matrix[i][j];
    }
  }


  float result = 0;
  for(int i = 0; i < 12; i++){
    result += matrix[i][collum];
  }


    if(operation == 'S'){
      printf("%.1f\n", result);
    }
    else if(operation == 'M'){
      result /= 12;
      printf("%.1f\n", result);
    }

  return 0;
}
