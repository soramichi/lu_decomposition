#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 2

double L[SIZE][SIZE];
double L_inv[SIZE][SIZE];

void print(double M[][SIZE]){
  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
      printf("%.3f ", M[i][j]);
    }
    printf("\n");
  }
}

void mul(double A[][SIZE], double B[][SIZE]){
  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
      double multiplied = 0.0;
      for(int k=0; k<SIZE; k++){
	multiplied += A[i][k] * B[k][j];
      }
      printf("%.3f ", multiplied);
    }
    printf("\n");
  }  
}

int main(){
  srand(time(NULL));

  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
      L[i][j] = (j>=i ? (rand()%9) + 1 : 0);
      L_inv[i][j] = 0;
    }
  }

  print(L);

  for(int n=0; n<SIZE; n++){
    for(int i=n; i>=0; i--){
      double numerator = (i==n ? 1 : 0);
      
      for(int j=n; j>=i; j--){
	numerator += L[i][j] * L_inv[i][j];
      }
      
      //printf("L[%d][%d] = %.3f\n", i, n, L[i][n]);
      L_inv[i][n] = numerator / L[i][n];
    }
  }

  printf("---------------------------------------\n");
  print(L_inv);
  printf("---------------------------------------\n");
  mul(L, L_inv);
  
  return 0;
}
