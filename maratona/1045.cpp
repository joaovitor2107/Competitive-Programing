#include <bits/stdc++.h>
using namespace std;

#define SWAP(x,y) if(1){float temp = x; x = y; y = temp;}

int main(int argc, char *argv[]) {


  float A, B, C;
  cin >> A >> B >> C;
  if(A < B) SWAP(A,B);
  if(A < C) SWAP(A,C);


  if(A >= B + C){
    printf("NAO FORMA TRIANGULO\n");
    return 0;
  }
  if(A*A == B*B + C*C) printf("TRIANGULO RETANGULO\n");
  if(A*A > B*B + C*C) printf("TRIANGULO OBTUSANGULO\n");
  if(A*A < B*B + C*C) printf("TRIANGULO ACUTANGULO\n");
  if(A == B && B == C) printf("TRIANGULO EQUILATERO\n");
  if((A == B && C != B) || (B == C && C != A) || (A == C && C != B)) printf("TRIANGULO ISOSCELES\n");

  
  return 0;
}
