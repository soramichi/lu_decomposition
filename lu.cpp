// useful info
// http://akita-nct.jp/yamamoto/lecture/2004/5E/linear_equations/text/html/node4.html

#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 4

double A[SIZE][SIZE];
double L[SIZE][SIZE];
double U[SIZE][SIZE];

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

  // initialize the matrices
  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
      A[i][j] = (rand()%9) + 1;
      L[i][j] = 0;
      U[i][j] = 0;

      // set the diagonal elements of L to 1
      if(i==j)
	L[i][j] = 1;
    }
  }

  printf("A: ------------------------\n");
  print(A);
    
  for(int j=0; j<SIZE; j++){
    for(int i=0; i<=j; i++){
      double sum = 0;

      for(int k=0; k<i; k++){
	sum += L[i][k] * U[k][j];
      }

      U[i][j] = A[i][j] - sum;
    }

    for(int i=j+1; i<SIZE; i++){
      double substituted = 0;

      for(int k=0; k<j; k++){
	substituted += L[i][k] * U[k][j];
      }

      //printf("substituted = %.3f, U[%d][%d] = %.3f", substituted, i, i, U[i][i]);
      L[i][j] = (A[i][j] - substituted) / U[j][j];
    }
  }


  printf("L: ------------------------\n");
  print(L);
  printf("U: ------------------------\n");
  print(U);
  printf("L * U: ------------------------\n");
  mul(L, U);
  
  return 0;
}
