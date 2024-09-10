#include <stdio.h>

void menuDepartement() {
    int choixDepartement;
    
    do {
        printf("\n=== Menu Gestion des Départements ===\n");
        printf("1. Ajouter un département\n");
        printf("2. Supprimer un département\n");
        printf("3. Afficher les départements\n");
        printf("0. Retour au menu principal\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choixDepartement);
        
        switch(choixDepartement) {
            case 1:
                printf("Ajouter un département (fonction non implémentée)\n");
                break;
            case 2:
                printf("Supprimer un département (fonction non implémentée)\n");
                break;
            case 3:
                printf("Afficher les départements (fonction non implémentée)\n");
                break;
            case 0:
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
        
    } while(choixDepartement != 0);
}
void menuEtudiant() {
    int choixEtudiant;
    
    do {
        printf("\n=== Menu Gestion des Étudiants ===\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Supprimer un étudiant\n");
        printf("3. Afficher les étudiants\n");
        printf("0. Retour au menu principal\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choixEtudiant);
        
        switch(choixEtudiant) {
            case 1:
                printf("Ajouter un étudiant \n");
                break;
            case 2:
                printf("Supprimer un étudiant\n");
                break;
            case 3:
                printf("Afficher les étudiants \n");
                break;
            case 0:
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
        
    } while(choixEtudiant != 0);
}


int main() {
    int choix;
    
    do {
        printf("****************************************\n");
        printf("=== *****Menu Principal***** ===\n");
        printf("1. Gestion des départements\n");
        printf("2. Gestion des étudiants\n");
        printf("0. Quitter\n");
        printf("****************************************\n");

        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                menuDepartement();
                break;
            case 2:
                menuEtudiant();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
        
    } while(choix != 0);
    
    return 0;
}


