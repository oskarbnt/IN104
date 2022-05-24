#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <fftw3.h>
#include <math.h>




void creation_csv (FILE* fp,double* moyenne_ecart, int rows) {
// Ecriture de la moyenne et de l'écart type du fichiers audio considéré.
for (int i=0; i<rows+1; i++) {
fprintf(fp,"%.2f; %.2f; ", moyenne_ecart[2*i], moyenne_ecart[2*i+1]);
}
//On effectue un retour à la ligne après avoir retranscrit tout les info du fichier audio considéré.
fprintf(fp,"\n");
}



