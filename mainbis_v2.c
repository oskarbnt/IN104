//MAIN bis
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <fftw3.h>
#include <math.h>
#include <complex.h>
//#include "creation_csv.c"
#include "read_array.c"
#include "dot.c"
#include <math.h>
#include "wave.c"
#include "stft.c"
#include "moyenne.c"
#include "creation_csv.c"
#include "fichier_nom.c"





int main(int argc, char **argv) {


//on recupère deux tableau b et W de 2 fichiers CSV:
//On commence par initialiser les zones de stockage pour b et w.
int nb_colonne=514;
int nb_ligne=10;
double** W_value= malloc(nb_ligne*sizeof(double*));
double** B_value=malloc(nb_ligne*sizeof(double*));
for(int i=0; i<nb_colonne;i++){
W_value[i]=malloc(nb_colonne*sizeof(double));
}
B_value[0]=malloc(nb_colonne*sizeof(double));


//On transforme les csv en vecteur et matrices:
char file_name1[]="path to w";
char file_name2[]="path to b";
read_array(file_name1, W_value);
read_array(file_name2, B_value);




//Puis on les multiplie:
//nb d'echantillion stft
   int windowSize=512;
   int hop_size = 512; 
   long int length = 661794;   
   long int cols = ((length/(windowSize/2)));
   long int rows = (windowSize/2)+1;
   long int samples=cols*rows;
   long int sample_freq =22050;
 
 
 
//on recupère le nom du fichier qu'on souhaite predire.
char* nom_audio=argv[1];
int k=0; //Quel type de musique.


// donne un tableau "data_wave" qui represente le fichier audio.
double* Data_wave= malloc(length*sizeof(double));
wave_function(nom_audio, Data_wave,length); 
   
// donne magnitude qui represente les frequence du fichier audio.
double* magnitude=malloc(samples*sizeof(double));
stft(&Data_wave[0], samples, windowSize, hop_size, &magnitude[0], sample_freq, length);

// On recupère le vecteur contenant les sigma et mu.
double moyenne_ecart[rows*2+1]; //515
moyenne (&magnitude[0], &moyenne_ecart[0], samples, rows, cols, k);


//On verifie qu'on a les bonnes valeurs pour sigma_mu:
for (int i=0; i<5; i++){
printf("On a: moyenne_ecart(%d)= %f\n",i, moyenne_ecart[i]);
}


double* prediction=malloc(nb_ligne*sizeof(double));
//fonction qui renvoie: prediction=W*X+B.
dot(prediction, &moyenne_ecart[0], W_value, B_value[0], nb_ligne, nb_colonne);

for (int k=0; k<10;k++) {
printf("prediction [%d]=%f\n",k, prediction[k]);
}







/*
//On verifie qu'on a les bonnes valeurs:
for (int i=0; i<5; i++){
printf("On a: B(%d)= %f\n",i, B_value[0][i]);
for (int j=0; j<5; j++){
printf("On a: W(%d,%d)= %f\n",i, j, W_value[i][j]);
}
}
*/




//On cherche l'argmax pour la prediction:
double max=-10;
for (int k=0; k<10;k++) {
if (prediction[k]>max){max=prediction[k];}
}
printf("la valeur max est: %f\n", max);










//On conclue:
if (max<0) {char* style="reggae"; printf("le style musical de cette musique est: %s\n",style);}
else if (max<=1.8) {char* style="metal";printf("le style musical de cette musique est: %s\n",style);}
else if (max<=2.5) {char* style="classical";printf("le style musical de cette musique est: %s\n",style);}
else if (max<=3.5) {char* style="disco";printf("le style musical de cette musique est: %s\n",style);}
else if (max<=4.5) {char* style="hiphop";printf("le style musical de cette musique est: %s\n",style);}
else if (max<=5.5) {char* style="rock";printf("le style musical de cette musique est: %s\n",style);}
else if (max<=6.5) {char* style="pop";printf("le style musical de cette musique est: %s\n",style);}
else if (max<=9.5) {char* style="jazz";printf("le style musical de cette musique est: %s\n",style);}
else if (max<=14.5) {char* style="blues";printf("le style musical de cette musique est: %s\n",style);}
else {char* style="country";printf("le style musical de cette musique est: %s\n",style);}









//On libères ces valeurs.
for(int i=0; i<1000;i++){
free(W_value[i]);
}
free(B_value[0]);
free(B_value);
free(W_value);
free(prediction);
free(magnitude);
free(Data_wave);
}
















