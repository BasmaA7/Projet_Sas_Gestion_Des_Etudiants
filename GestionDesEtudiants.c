#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 1000
#define MAX_DEPARTEMENTS 100

struct Etudiant {
    int numero_unique;
    char nom[50];
    char prenom[50];
    char date_naissance[11];
    char departement[100];
    float note_generale;
};

struct Departement {
    char nom_departement[100];
    int nb_etudiants;
    struct Etudiant etudiants[MAX_ETUDIANTS];
};

struct Etudiant list_etudiants[MAX_ETUDIANTS];
struct Departement liste_departements[MAX_DEPARTEMENTS];

int nb_departements = 0;
int nb_etudiants = 0;
int prochain_id_etudiant = 1; 

// CRUD Département
void ajouter_departement() {
    if (nb_departements >= MAX_DEPARTEMENTS) {
        printf("Capacité maximale des départements atteinte.\n");
        return;
    }

    struct Departement depart;
    printf("Entrez le nom du département : ");
    scanf("%s", depart.nom_departement);
    depart.nb_etudiants = 0;

    liste_departements[nb_departements++] = depart;
    printf("Département ajouté avec succès.\n");
}

void supprimer_departement() {
    if (nb_departements == 0) {
        printf("Aucun département à supprimer.\n");
        return;
    }

    char nom[100];
    printf("Entrez le nom du département à supprimer : ");
    scanf("%s", nom);

    int i;
    for (i = 0; i < nb_departements; i++) {
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
}

void afficher_departement() {
    if (nb_departements == 0) {
        printf("Aucun département à afficher.\n");
        return;
    }
    for (int i = 0; i < nb_departements; i++) {
        printf("\nDépartement %d:\n", i + 1);
        printf("Nom du département: %s\n", liste_departements[i].nom_departement);
       
        printf("Nombre d'étudiants: %d\n", liste_departements[i].nb_etudiants);
    }
}

// CRUD Étudiant




int verifier_departement_existe(char departement[]) {
    for (int i = 0; i < nb_departements; i++) {
        if (strcmp(liste_departements[i].nom_departement, departement) == 0) {
            return 1;
        }
    }
    return 0; 
}

void ajouter_etudiant() {
    if (nb_etudiants >= MAX_ETUDIANTS) {
        printf("Capacité maximale des étudiants atteinte.\n");
        return;
    }

    struct Etudiant nouveau_etudiant;

    nouveau_etudiant.numero_unique = prochain_id_etudiant++;

    printf("Entrez le nom : ");
    getchar(); 
    fgets(nouveau_etudiant.nom, sizeof(nouveau_etudiant.nom), stdin);
    nouveau_etudiant.nom[strcspn(nouveau_etudiant.nom, "\n")] = '\0';

    printf("Entrez le prénom : ");
    fgets(nouveau_etudiant.prenom, sizeof(nouveau_etudiant.prenom), stdin);
    nouveau_etudiant.prenom[strcspn(nouveau_etudiant.prenom, "\n")] = '\0';

    printf("Entrez la date de naissance (jj/mm/aaaa) : ");
    fgets(nouveau_etudiant.date_naissance, sizeof(nouveau_etudiant.date_naissance), stdin);
    nouveau_etudiant.date_naissance[strcspn(nouveau_etudiant.date_naissance, "\n")] = '\0';

    char departement[100];
    int departement_valide = 0;

    while (!departement_valide) {
        printf("Entrez le département : ");
        fgets(departement, sizeof(departement), stdin);
        departement[strcspn(departement, "\n")] = '\0';

        if (verifier_departement_existe(departement)) {
            strncpy(nouveau_etudiant.departement, departement, sizeof(nouveau_etudiant.departement) - 1);
            nouveau_etudiant.departement[sizeof(nouveau_etudiant.departement) - 1] = '\0';
            departement_valide = 1;
        } else {
            printf("Département non trouvé. Voici la liste des départements existants :\n");
            afficher_departement(); 
        }
    }

    printf("Entrez la note générale : ");
    scanf("%f", &nouveau_etudiant.note_generale);

    list_etudiants[nb_etudiants++] = nouveau_etudiant;
    printf("Étudiant ajouté avec succès. ID unique : %d\n", nouveau_etudiant.numero_unique);
}


void afficher_etudiants() {
    if (nb_etudiants == 0) {
        printf("Aucun étudiant à afficher.\n");
        return;
    }

    for (int i = 0; i < nb_etudiants; ++i) {
        printf("\nÉtudiant %d:\n", i + 1);
        printf("Numéro unique: %d\n", list_etudiants[i].numero_unique);
        printf("Nom: %s\n", list_etudiants[i].nom);
        printf("Prénom: %s\n", list_etudiants[i].prenom);
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


void modifier_etudiant() {
    if (nb_etudiants == 0) {
        printf("Aucun étudiant à modifier.\n");
        return;
    }

    int numero_unique;
    printf("Entrez le numéro unique de l'étudiant à modifier : ");
    scanf("%d", &numero_unique);
    getchar();
   int i;
    for ( i = 0; i < nb_etudiants; i++) {
        if (list_etudiants[i].numero_unique == numero_unique) {
            break;
        }
    }

    if ( i == nb_etudiants) {
        printf("Étudiant non trouvé.\n");
        return;
    }

    printf("Modifier les informations de l'étudiant ID %d :\n", list_etudiants[i].numero_unique);

    char var_modificateur[50];

    // Modifier le nom
    printf("Entrez le nouveau nom ((click  Entrée pour conserver l'ancien) : ");
    fgets(var_modificateur, sizeof(var_modificateur), stdin);
    if (var_modificateur[0] != '\n') {
      var_modificateur[strcspn(var_modificateur, "\n")] = '\0';
        strcpy(list_etudiants[i].nom, var_modificateur);
    }

    // Modifier le prénom
    printf("Entrez le nouveau prénom ((click  Entrée pour conserver l'ancien) : ");
    fgets(var_modificateur, sizeof(var_modificateur), stdin);
    if (var_modificateur[0] != '\n') {
        var_modificateur[strcspn(var_modificateur, "\n")] = '\0';
        strcpy(list_etudiants[i].prenom, var_modificateur);
    }

    // Modifier la date de naissance
    printf("Entrez la nouvelle date de naissance (jj/mm/aaaa) (click Entrée pour conserver l'ancienne) : ");
    fgets(var_modificateur, sizeof(var_modificateur), stdin);
    if (var_modificateur[0] != '\n') {
        var_modificateur[strcspn(var_modificateur, "\n")] = '\0';
        strcpy(list_etudiants[i].date_naissance, var_modificateur);
    }

    // Modifier le département
    printf("Entrez le nouveau département ((click  Entrée pour conserver l'ancien) : ");
    fgets(var_modificateur, sizeof(var_modificateur), stdin);
    if (var_modificateur[0] != '\n') {
        var_modificateur[strcspn(var_modificateur, "\n")] = '\0';
        strcpy(list_etudiants[i].departement, var_modificateur);
    }

    printf("Informations de l'étudiant mises à jour avec succès.\n");
}








//  Calcul de la moyenne générale
void moyenne_generale() {
    if (nb_etudiants == 0) {
        printf("Aucun étudiant pour calculer la moyenne.\n");
        return;
    }

    float somme = 0;
    for (int i = 0; i < nb_etudiants; i++) {
        somme += list_etudiants[i].note_generale;
    }
    printf("Moyenne générale de l'université : %.2f\n", somme / nb_etudiants);
}

//  Les statistiques
void statistiques() {
    printf("Nombre total d'étudiants inscrits : %d\n", nb_etudiants);

    float seuil;
    printf("Entrez le seuil pour afficher les étudiants ayant une note supérieure ou égale à : ");
    scanf("%f", &seuil);

    printf("Étudiants ayant une note >= %.2f :\n", seuil);
    for (int i = 0; i < nb_etudiants; i++) {
        if (list_etudiants[i].note_generale >= seuil) {
            printf("Numéro: %d, Nom: %s, Prénom: %s, Département: %s, Note: %.2f\n",
                   list_etudiants[i].numero_unique,
                   list_etudiants[i].nom,
                   list_etudiants[i].prenom,
                   list_etudiants[i].departement,
                   list_etudiants[i].note_generale);
        }
    }

    // Afficher les 3 meilleurs étudiants
    if (nb_etudiants > 0) {
        struct Etudiant top_3[MAX_ETUDIANTS];
        memcpy(top_3, list_etudiants, sizeof(list_etudiants));

        for (int i = 0; i < nb_etudiants - 1; i++) {
            for (int j = i + 1; j < nb_etudiants; j++) {
                if (top_3[i].note_generale < top_3[j].note_generale) {
                    struct Etudiant temp = top_3[i];
                    top_3[i] = top_3[j];
                    top_3[j] = temp;
                }
            }
        }

        printf("Top 3 étudiants avec les meilleures notes :\n");
        for (int i = 0; i < 3 && i < nb_etudiants; i++) {
            printf("Numéro: %d, Nom: %s, Prénom: %s, Département: %s, Note: %.2f\n",
                   top_3[i].numero_unique,
                   top_3[i].nom,
                   top_3[i].prenom,
                   top_3[i].departement,
                   top_3[i].note_generale);
        }
    }
}


void rechercher_par_nom() {
    if (nb_etudiants == 0) {
        printf("Aucun étudiant à rechercher.\n");
        return;
    }

    char nom[50];
    printf("Entrez le nom de l'étudiant à rechercher : ");
    getchar(); 
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0'; 
    int trouve = 0;
    for (int i = 0; i < nb_etudiants; i++) {
        if (strcmp(list_etudiants[i].nom, nom) == 0) {
            printf("\nÉtudiant trouvé:\n");
            printf("Numéro unique: %d\n", list_etudiants[i].numero_unique);
            printf("Nom: %s\n", list_etudiants[i].nom);
            printf("Prénom: %s\n", list_etudiants[i].prenom);
            printf("Date de naissance: %s\n", list_etudiants[i].date_naissance);
            printf("Département: %s\n", list_etudiants[i].departement);
            printf("Note générale: %.2f\n", list_etudiants[i].note_generale);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun étudiant trouvé avec le nom donné.\n");
    }
}








// Menus
void menuDepartement() {
    int choixDepartement;

    do {
        printf("\n=== Menu Gestion des Départements ===\n");
        printf("1. Ajouter un département\n");
        printf("2. Supprimer un département\n");
        printf("3. Afficher les départements\n");
        printf("4. Calculer la moyenne générale de chaque département\n");
        printf("0. Retour au menu principal\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choixDepartement);

        switch (choixDepartement) {
            case 1:
                ajouter_departement();
                break;
            case 2:
                supprimer_departement();
                break;
            case 3:
                afficher_departement();
                break;
            case 0:
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }

    } while (choixDepartement != 0);
}

void menuEtudiant() {
    int choixEtudiant;

    do {
        printf("\n=== Menu Gestion des Étudiants ===\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Supprimer un étudiant\n");
        printf("3. Afficher les étudiants\n");
        printf("4. Modifier les informations des étudiants\n");
        printf("5. Voir les statistiques\n");
        printf("6. Rechercher sur un etudiant \n");
        printf("0. Retour au menu principal\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choixEtudiant);

        switch (choixEtudiant) {
            case 1:
                ajouter_etudiant();
                break;
            case 2:
                supprimer_etudiant();
                break;
            case 3:
                afficher_etudiants();
                break;
            case 4:
                modifier_etudiant();
                break;
            case 5:
                statistiques();
                break;
            case 6:
                rechercher_par_nom();
                break;
            case 0:
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }

    } while (choixEtudiant != 0);
}

// Menu principal
int main() {
    int choixPrincipal;

    do {
        printf("\n=== Menu Principal ===\n");
        printf("1. Gestion des départements\n");
        printf("2. Gestion des étudiants\n");
        printf("0. Quitter\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choixPrincipal);

        switch (choixPrincipal) {
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

    } while (choixPrincipal != 0);

    return 0;
}
