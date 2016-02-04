#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 4

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

  // for each iteration, calc L_inv[1:subsize][1:subsize],
  // assuming that L_inv[1:subsize-1][1:subsize-1] is already calculated
  // useful info: http://www.juen.ac.jp/math/nakagawa/balinalg.pdf
  for(int subsize=0; subsize<SIZE; subsize++){
    // calc the last column (j==subsize)
    for(int i=subsize; i>=0; i--){
      double numerator = (i==subsize ? 1 : 0);
      
      for(int k=0; k<=subsize; k++){
	numerator -= L[i][k] * L_inv[k][subsize];;
      }

      L_inv[i][subsize] = numerator / L[i][i];
    }
  }

  printf("---------------------------------------\n");
  print(L_inv);
  printf("---------------------------------------\n");
  mul(L, L_inv);
  
  return 0;
}
