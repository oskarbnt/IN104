//Main
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <fftw3.h>
#include <math.h>
#include "wave.c"
#include "stft.c"
#include "moyenne.c"
#include "creation_csv.c"
#include "fichier_nom.c"





int main(int argc, char **argv)
{
// fenetre concatenation. On prend 512 pour avoir un vecteur encodé de taille raisonnable.
  int windowSize = 512; 
  int hop_size = 512; 
//nb d'echantillion stft
   long int length = 661794;   
   long int cols = ((length/(windowSize/2)));
   long int rows = (windowSize/2)+1;
   long int samples=cols*rows;
   long int sample_freq =22050;
   printf("sample: %ld. \n", samples);

//On ouvre le fichier csv ou on stocke ces informations.
FILE* csv_file = fopen("file", "a+"); 


//Il faut traité tous les style de musique:
for (int k=0; k<10; k++) { //10
//Il faut traité tout les fichiers audio de cette catégorie.
for (int p=0; p<100; p++) { //100

printf("on est à l'étape: %d %d\n",k,p);

//on détermine le nom du fichier audio correspondant.
char* nom_audio= malloc(19*sizeof(char));
nom_audio=fichier_nom(k,p,nom_audio);


// donne un tableau "data_wave" qui represente le fichier audio.
 double* Data_wave= malloc(length*sizeof(double));
 wave_function(nom_audio, Data_wave,length); 
 
 // donne magnitude qui represente les frequence du fichier audio.
 double* magnitude=malloc(samples*sizeof(double));
 stft(&Data_wave[0], samples, windowSize, hop_size, &magnitude[0], sample_freq, length);

for (int i=0; i<5; i++) {
printf("magnitude[%d]: %f\n",i,magnitude[i]);
}




// On creer le vecteur Moyenne qui contient la moyenne et ecart_type de magnitude.
// taille de moyenne_ecart est de rows*2+1, 
// car ca commence par k et puis il y a pour chaque ligne une moyenne et un ecart type.
double moyenne_ecart[rows*2+1]; 
moyenne (&magnitude[0], &moyenne_ecart[0], samples, rows, cols, k);
  
for (int i=0; i<5; i++) {
printf("moyenne[%d]: %.2f\n",i,moyenne_ecart[i]);
}
 
// On ajoute au fichier csv le vecteur moyenne_ecart pour le fichier audio consideré.
creation_csv(csv_file, &moyenne_ecart[0], rows);
   
  
   free(nom_audio);
   free(Data_wave);
   free(magnitude);
   }   
   }
   
   

  fclose(csv_file); // ferme le fichier csv.
  return 0; 
}
























