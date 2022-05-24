#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void dot(double *prediction, double *X, double **W, double *b, int row, int column) {
for (int i=0;i<row;i++) {
prediction[i]=0;
for (int j=0;j<column;j++) {
prediction[i]=prediction[i]+W[i][j]*X[j];
}
prediction[i]=prediction[i]+b[i];
}
}

// NE PAS oublier de free le prediciton.



//ligne:10
//col:512
/*
void dot2(double *prediction, double *X, double **W, double *b, int ligne, int col) {
for (int i;i<ligne;i++) {
prediction[i]=0;
for (int j;j<column;j++) {
prediction[i]=prediction[i]+W[i][j]*X[j];
}
prediction[i]=prediction[i]+b[i];
}
}

*/














