#include <stdio.h>
#include <string.h>




#define MAX_ETUDIANTS 1000
#define MAX_DEPARTEMENTS 100
char etudians[];


struct Etudiants {
    int numero_unique;
    char nom_complaite[50];
    char date_naissance[11];
    char departement[100];
    float note_generale;
} ;
struct Departements{
char nom_departement[100];
int capacite;
int nb_etudiants;
struct Etudiants etudiants[MAX_ETUDIANTS];

};


//lister les etudiants dans un tableau

list_etudiants[MAX_ETUDIANTS];
liste_departements[MAX_DEPARTEMENTS];
int nb_departements=0;

int nb_etudiants=0;
//Crud Departement
void ajouter_departement(){

if (nb_departements >= MAX_DEPARTEMENTS) {
    printf("Capacité maximale des départements atteinte.\n");
        return;
    }
struct Departements depart;
printf("Enter le nom de departement :");
scanf("%s",depart.nom_departement);
printf("Enter le nom de departement :");
scanf("%s",depart.capacite);
printf("Enter le  nombre_etudiants :");
scanf("%d",depart.nb_etudiants);


}

void supprimer_departement() {
    if (nb_departements == 0) {
        printf("Aucun département à supprimer.\n");
        return;
    }

    char nom[100];
    printf("Entrez le nom du département à supprimer : ");
    scanf("%s", nom);


    for (int i=0; i < nb_departements; i++) {
        if (strcmp(liste_departements[i].nom_departement, nom) == 0) {
            break;
        }
    }

    if (i == nb_departements) {
        printf("Département non trouvé.\n");
        return;
    }

    for (int j = i; j < nb_departements - 1; j++) {
        liste_departements[j] = liste_departements[j + 1];
    }
    nb_departements--;
    printf("Département supprimé avec succès.\n");


void afficher_departement(){
if (nb_departements == 0) {
        printf("Aucun departement à afficher.\n");
        return;
    }
    for (int i = 0; i < nb_departements; i++    ) {
        printf("\ Departements %d:\n", i + 1);"
        printf("Nom Departement: %s\n", liste_departements[i].nom_departement]);
        printf("capacite: %d\n", liste_departements[i].capacite);
        printf("Nombre d'etuduant: %s\n", liste_departements[i].nb_etudiants);
    }

}



//****************************

    for (int i = 0; i < nb_departements; i++) {
        printf("ID: %d, Nom: %s, Capacité: %d\n",
               liste_departements[i].id,
               liste_departements[i].nom_departement,
               liste_departements[i].capacite);
    }
}
//Crud Etudiante
void ajouter_etudiant() {
    if (nb_etudiants >= MAX_ETUDIANTS) {
        printf("Capacité maximale des étudiants atteinte.\n");
        return;
    }

    struct Etudiant nouveau_etudiant;

    nouveau_etudiant.numero_unique = prochain_id++;
    printf("Entrez le nom complet : ");
    scanf("%s", nouveau_etudiant.nom_complet);

    printf("Entrez la date de naissance (jj/mm/aaaa) : ");
    scanf("%s", nouveau_etudiant.date_naissance);

    printf("Entrez le département : ");
    scanf("%s", nouveau_etudiant.departement);

    printf("Entrez la note générale : ");
    scanf("%f", &nouveau_etudiant.note_generale);

    list_etudiants[nb_etudiants++] = nouveau_etudiant;
    printf("Étudiant ajouté avec succès.\n");
}

     struct Etudiants nouveau_Etudiant;

     printf("Entrez le nom compléte: ");
     fgets(nouveau_Etudiant.nom,sizeof(nouveau_Etudiant.nom_complet),stdin);

   printf("Entrez la date de naissance (jj/mm/yy) : ");
    fgets(nouveau_Etudiant.telephone,sizeof(nouveau_Etudiant.date_naissance),stdin);

      printf("Entrez l'adresse e-mail : ");
    fgets(nouveau_Etudiant.email,sizeof(nouveau_Etudiant.email),stdin);
    puts(nouveau_Etudiant.email);

    list_etudiants[nb_etudiants++] = nouveau_Etudiant;
    printf("Etudiant ajouté avec succès.\n");

}
void afficher_etudiants() {
    if (nb_etudiants == 0) {
        printf("Aucun étudiant à afficher.\n");
        return;
    }

    for (int i = 0; i < nb_etudiants; ++i) {
        printf("\nÉtudiant %d:\n", i + 1);
        printf("Numéro unique: %d\n", list_etudiants[i].numero_unique);
        printf("Nom complet: %s\n", list_etudiants[i].nom_complet);
        printf("Date de naissance: %s\n", list_etudiants[i].date_naissance);
        printf("Département: %s\n", list_etudiants[i].departement);
        printf("Note générale: %.2f\n", list_etudiants[i].note_generale);
    }
}

void supprimer_etudiant() {
    if (nb_etudiants == 0) {
        printf("Aucun étudiant à supprimer.\n");
        return;
    }

    int numero_unique;
    printf("Entrez le numéro unique de l'étudiant à supprimer : ");
    scanf("%d", &numero_unique);

    int i;
    for (i = 0; i < nb_etudiants; i++) {
        if (list_etudiants[i].numero_unique == numero_unique) {
            break;
        }
    }

    if (i == nb_etudiants) {
        printf("Étudiant non trouvé.\n");
        return;
    }

    for (int j = i; j < nb_etudiants - 1; j++) {
        list_etudiants[j] = list_etudiants[j + 1];
    }
    nb_etudiants--;
    printf("Étudiant supprimé avec succès.\n");
}



//********************





void calculer_moyenne_generale() {
    if (nb_etudiants == 0) {
        printf("Aucun étudiant pour calculer la moyenne.\n");
        return;
    }

    float somme = 0;
    for (int i = 0; i < nb_etudiants; i++) {
        somme += liste_etudiants[i].note_generale;
    }
    printf("Moyenne générale de l'université : %.2f\n", somme / nb_etudiants);
}



//Statistique 

void statistiques(){
//Afficher le nombre d'étudiants dans chaque département.
    printf("Nombre total d'étudiants inscrits : %d\n", nb_etudiants);
    
    
    
//Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil.

    float seuil;
    printf("Entrez le seuil pour afficher les étudiants ayant une note supérieure ou égale à : ");
    scanf("%f", &seuil);

    printf("Étudiants ayant une note >= %.2f :\n", seuil);
    for (int i = 0; i < nb_etudiants; i++) {
        if (liste_etudiants[i].note_generale >= seuil) {
            printf("Numéro: %d, Nom: %s, Prénom: %s, Département: %s, Note: %.2f\n",
                   liste_etudiants[i].numero_unique,
                   liste_etudiants[i].nom,
                   liste_etudiants[i].prenom,
                   liste_etudiants[i].departement,
                   liste_etudiants[i].note_generale);
        }
    }
    
    //Afficher les 3 étudiants ayant les meilleures notes.
    
    
    
    
    
    
    
    //Afficher le nombre d'étudiants ayant réussi dans chaque département (ceux ayant une note supérieure ou égale à 10/20).

}










//Menu ****************
void menuDepartement() {
    int choixDepartement;

    do {
        printf("\n=== Menu Gestion des Départements ===\n");
        printf("1. Ajouter un département\n");
        printf("2. Supprimer un département\n");
        printf("3. Afficher les départements\n");
        printf("4. Calculer la moyenne generale de chaque département\n");
        printf("0. Retour au menu principal\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choixDepartement);

        switch(choixDepartement) {
            case 1:
                printf("Ajouter un département (fonction non implémentée)\n");
                ajouter_departement();
                break;
            case 2:
                printf("Supprimer un département (fonction non implémentée)\n");
                supprimer_departement();
                break;
            case 3:
                printf("Afficher les départements (fonction non implémentée)\n");
                afficher_departement();
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
        printf("4. Modifier les informations des étudiants\n");
        printf("5.Voir le menude de statistique ") ;
        printf("0. Retour au menu principal\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choixEtudiant);

        switch(choixEtudiant) {
            case 1:
                printf("Ajouter un étudiant \n");
                ajouter_etudiant();
                
                break;
            case 2:
                printf("Supprimer un étudiant\n");
                supprimer_etudiant()
                break;
            case 3:
                printf("Afficher les étudiants \n");
                afficher_etudiants
                break;
                 case 4:
                printf("Modifier les étudiants \n");
                break;
                 case 5:
                printf("Voir le statistique \n");
                statistiques();
                break;
            case 0:
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }

    } while(choixEtudiant != 0);
}
//****************

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


