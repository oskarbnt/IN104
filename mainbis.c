//MAIN bis



#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <fftw3.h>
#include <math.h>
#include "creation_csv.c"
#include "read_array.c"




int main(int argc, char **argv) {


//on recupère deux tableau b et W de 2 fichiers CSV:
//On commence par initialiser les zones de stockage pour b et w.
int vect_size=5000;
double** W_value= malloc(vect_size*sizeof(double*));
double** B_value=malloc(vect_size*sizeof(double*));
for(int i=0; i<vect_size;i++){
W_value[i]=malloc(vect_size*sizeof(double));
B_value[i]=malloc(vect_size*sizeof(double));
}



//On transforme les csv en vecteur et matrices:
char file_name1[]="path to w";
char file_name2[]="path to b";
read_array(file_name1, W_value);
read_array(file_name2, B_value);


//Puis on les multiplie:








//On verifie qu'on a les bonnes valeurs:
for (int i=0; i<5; i++){
for (int j=0; j<5; j++){
printf("On a: W(%d,%d)= %f\n",i, j, W_value[i][j]);
}
}



//On libères ces valeurs.
//free(b_value);
for(int i=0; i<1000;i++){
free(W_value[i]);
free(B_value[i]);
}
free(B_value);
free(W_value);
}
















