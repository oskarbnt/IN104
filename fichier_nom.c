#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <fftw3.h>
#include <math.h>
#include <string.h>



//Renvoie le nom du type de fichier.
char* style_musique(int i_style, int num) {
if (i_style==0) {char* style="blues"; return style;}
else if (i_style==1) {char* style="classical";return style;}
else if (i_style==2) {char* style="country";return style;}
else if (i_style==3) {char* style="disco";return style;}
else if (i_style==4) {char* style="hiphop";return style;}
else if (i_style==5) {char* style="jazz";return style;}
else if (i_style==6) {char* style="metal";return style;}
else if (i_style==7) {char* style="pop";return style;}
else if (i_style==8) {char* style="reggae";return style;}
else {char* style="rock";return style;}
}





//Donne le nom final du fichier audio.
char* fichier_nom (int i_style, int num, char* nom_musique) {

//On declare le nom du style de musique.
char* type=style_musique(i_style,num);
//je copie le type de musique obtenue dans le tableau de char nom_musique.
strcpy(nom_musique,type);

char* point=".";
char* wav="wav";
char* complement_num="000";

//On essaie de convertir num de int en char.
char raw_num[2];
if(num<10) {
raw_num[0]='0';
raw_num[1]=num+'0'; //permet de convertir num de int en char
}
 else {
 int a=num%10; //on récupère le premier term de num.
 raw_num[1]=a+'0'; // convertit a de int en char.
 int b=num/10;// on recupère le quotient de la div euclidienne. (i.e. le 2eme term de num)
 raw_num[0]=b+'0';
 }


//On va maintenant concatener ces tableau de char.
strcat(nom_musique,point);
strcat(nom_musique,complement_num);
strcat(nom_musique,raw_num);
strcat(nom_musique,point);
strcat(nom_musique,wav);
printf("On écoute le fichier: %s \n",nom_musique);
return nom_musique;
}




/*
//fonction test:
int main() {
char* nom= malloc(19*sizeof(char));
nom=fichier_nom(8,2,nom);
free(nom);
return 0;
}

*/


