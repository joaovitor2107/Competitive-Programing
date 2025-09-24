#include <bits/stdc++.h>
using namespace std;

bool checksize(char x, char y){
  if((x == 'D' && y == 'E') || (x == 'E' && y == 'D')) return true;
  return false;
}

int main(int argc, char *argv[]) {

  int n;
  while(cin >> n){

    vector<int> num(n);
    vector<char> size(n);
    int ocurrences = 0;

    for (int i = 0; i < n; i++) {
      cin >> num[i] >> size[i];


      for(int j = 0; j < i; j++){
        if(num[j] == num[i] && checksize(size[j], size[i])){
          ocurrences++;
          num[j] = 1;
          num[i] = 1;
          size[j] = 'O';
          size[i] = 'O';
        }
      }

    }

    printf("%d\n", ocurrences);
  }

  return 0;
}
