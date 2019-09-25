#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char** argv) {
    int nombreSaisi = 0, nombreMystere = 0, compteurCoups = 0, continuerPartie = 1, nombreJoueurs = 1, nombreMaximum = 100, niveauDifficulte = 1;
    const int MIN = 1;

    printf("Bienvenue dans ce mini-jeu de plus ou moins\n");
    printf("Vous souhaitez jouer... donc bon jeu\n\n");

    do {
        do {
            printf("Choisissez le niveau de difficulté :\n");
            printf("1. Entre 1 et 100\n");
            printf("2. Entre 1 et 1000\n");
            printf("3. Entre 1 et 10000\n");
            scanf("%d", &niveauDifficulte);
        } while ( (niveauDifficulte < 1) || (niveauDifficulte > 3) );

        switch(niveauDifficulte) {
            case 1:	nombreMaximum = 100;	break;
            case 2:	nombreMaximum = 1000;	break;
            case 3:	nombreMaximum = 10000;	break;
        }

        do {
            printf("Voulez-vous jouer contre l'ordinateur ou à deux ?\n");
            printf("1. Contre l'ordinateur\n");
            printf("2. À deux\n");
            scanf("%d", &nombreJoueurs);
        } while ( (nombreJoueurs < 1) || (nombreJoueurs > 2) );

        if (1 == nombreJoueurs) {
            srand( time(NULL) );
            nombreMystere = ( rand() % (nombreMaximum - MIN + 1) ) + MIN;
        } else {
            do {
                printf("Choisissez un nombre entre %d et %d :\n", MIN, nombreMaximum);
                scanf("%d", &nombreMystere);
            } while ( (nombreMystere < MIN) || (nombreMystere > nombreMaximum) );
        }

        do {
            compteurCoups++;

            printf("Quel est le nombre ? ");
            scanf("%d", &nombreSaisi);

            if (nombreSaisi > nombreMystere) {
                printf("C'est moins !\n\n");
            } else if (nombreSaisi < nombreMystere) {
                printf("C'est plus !\n\n");
            } else {
                printf ("Bravo, vous avez trouvé le nombre mystère en %d coups !!!\n\n", compteurCoups);
                compteurCoups = 0;
            }
        } while (nombreSaisi != nombreMystere);

        do {
            printf("Voulez-vous rejouer ?\n");
            printf("0. Non\n");
            printf("1. Oui\n");
            scanf("%d", &continuerPartie);
        } while ( (continuerPartie < 0) || (continuerPartie > 1) );
    } while (continuerPartie);

    return 0;
}
