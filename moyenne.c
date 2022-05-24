#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include<math.h>



// Fonction qui calcule la moyenne et ecart type de chaque ligne.




void sigma_mu(double *vect,int size_vect,double *moyenne,double* ecart_type){
int i=0;
double somme=0;
double somme2=0;
while (i<size_vect) {
somme=somme+vect[i];
somme2=somme2+vect[i]*vect[i];
i=i+1;
}

*moyenne=somme/size_vect;
*ecart_type=pow((somme2/size_vect)-pow((somme/size_vect),2),0.5);
//pow(somme2/size_vect-(pow((somme/size_vect),2)),0.5);
}







void moyenne (double* magnitude,double* moyenne_ecart, int sample,int rows, int cols, int k) {


double vecteur[cols];
double moyenne;
double ecart_type;

//On initialise la première valeur de moyenne-ecart.
moyenne_ecart[0]=k;

// On realises ces operation pour chaque colonne de magnitude.
for (int i=1; i<rows+1; i++) {
	for (int j=1; j<cols+1;j++) {
	vecteur[j]=magnitude[(j-1)*rows+(i-1)]; // avant: i*cols+j
	}
	sigma_mu(&vecteur[0], cols, &moyenne,&ecart_type);
	moyenne_ecart[2*(i-1)+1]=moyenne;
	moyenne_ecart[2*(i-1)+2]=ecart_type;
  }

}
































