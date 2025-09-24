#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

  int x1[2];
  int y1[2];
  int x2[2];
  int y2[2];

  cin >> x1[0] >> y1[0] >> x1[1] >> y1[1];
  cin >> x2[0] >> y2[0] >> x2[1] >> y2[1];

  if((y1[0] <= y2[1] && y1[1] >= y2[0] || y1[0] >= y2[1] && y1[1] <= y2[0]) && (x1[0] <= x2[1] && x1[1] >= x2[0] || x1[0] >= x2[1] && x1[1] <= x2[0])){
    cout << "1" << "\n";
    return 0;
  }

  cout << "0" << "\n";


  return 0;
}
