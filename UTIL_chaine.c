/*FONCTION LOGIQUE DE PROGRAMME_ LOGIC PROGRAM FUNCTIONS ___ DEFINITIONS*/
/* DOC_STRING DE UTIL_chaine
___FRANCAIS__
==================================
Titre       : UTIL_chaine
Auteur      : MARRAKCHI Ghassen
Référence   : ANSI C99
Type        : Definition de fonctions
Description : (LIRECHAINEFORMAT, LONGUEURFICHIER, IMPORTCHAINE, LIRECARACTERE, INITIALISER, VERIFICATION)
==================================
___ENGLISH__
==================================
Title       : UTIL_chaine
Author      : Ghassen MARRAKCHI
Reference   : ANSI C99
Type        : Functions Definitions
Description : (LIRECHAINEFORMAT, LONGUEURFICHIER, IMPORTCHAINE, LIRECARACTERE, INITIALISER, VERIFICATION)
==================================
*/


/*INCLUSION*/
#include "UTIL_chaine.h"        //FONCTIONS UTILITAIRES_ UTILITIES FUNCTIONS
#include "INC_standard.h"       //INCLUSION BIBLIOTHEQUES STANDARD_ STANDARD LIBS INCLUSION
#include "CONST_francais.h"     //LETTRE DE FRANCAIS CONSTANTES_ FRENCH CONSTANT LETTERS



char* LIRECHAINEFORMAT(char* chaine)
{
    /*DOC_STRING DE LIRECHAINEFORMAT
    __FRANCAIS_
    ---------------------------
    PARAMETRES     : - chaine: pointeur sur chaine.
    RETOUR         : - pointeur sur chaine.
    FONCTIONNEMENT : Lit une chaine saisie par l'utilisateur et la renvoie en majuscule et dépourvue d'espaces et de retour de ligne
    ---------------------------
    __ENGLISH_
    ---------------------------
    PARAMETERS     : - chaine: String Pointer.
    RETURN         : - String pointer.
    OPERATION      : Read a string written by the user, return it without spaces and back lines.
    ---------------------------
    */

    /*VARAIABLES_LIRECHAINEFORMAT*/
    int compt=0;
    char *chaineInter= NULL;
    char caractereLu='\0';

    chaineInter= (char*)calloc(10, sizeof(char));       //ALLOCATION DE CHAINE INTERMEDIAIRE_ INTERMEDIARY STRING ALLOCATION
    if (chaineInter == NULL)    //ERREUR_ ERROR
    {
        printf("FONCTION: LIRECHAINEFORMAT/ LIGNE: %d/ ERREUR ALLOCATION chaineInter\n", __LINE__);
        return NULL;
    }

    do
    {
        caractereLu=getchar();
        if ((caractereLu != '\40') && (caractereLu != EOF))     //EXCLUSION DE L'ESPACE_ SPACE EXCLUSION
        {
            *(chaineInter + compt)= toupper(caractereLu);
            compt++;
        }
    }while((caractereLu != EOF) && (*(chaineInter + compt-1) != '\n') && (compt < 9));

    --compt;
    *(chaineInter + compt)='\0';    //EXCLUSION DU RETOUR A LA LIGNE_ BACK LINE EXCLUSION

    chaine=(char*)calloc((strlen(chaineInter)+1),sizeof(char));     //ALLOCATION DE CHAINE DE RETOUR_ RETURN STRING ALLOCATION
    if (chaine == NULL)     //ERREUR_ ERROR
    {
        printf("FONCTION: LIRECHAINEFORMAT/ LIGNE: %d/ ERREUR ALLOCATION chaine\n", __LINE__);
        return NULL;
    }

    strcpy(chaine, chaineInter);

    /*NETTOYAGE DE MEMOIRE_ MEMORY CLEANING*/
    free(chaineInter);
    chaineInter=NULL;

    return chaine;
}

int LONGUEURFICHIER(FILE* fichier)
{
    /*DOC_STRING DE LONGUEURFICHIER
    __FRANCAIS_
    ---------------------------
    PARAMETRES     : - fichier: Pointeur sur fichier.
    RETOUR         : - entier.
    FONCTIONNEMENT : retourne le nombre de caractères existants dans le fichier pointé par "fichier".
    ---------------------------
    __ENGLISH_
    ---------------------------
    PARAMETERS     : - fichier: File pointer.
    RETURN         : - integer.
    OPERATION      : Returns how many Characters in the file pointed by "fichier" stream.
    ---------------------------
    */

    /*VARIABLES_ LONGUEURFICHIER*/
    int nbCar=0;
    char caractere='\0';

    while(caractere != EOF)     //CONDITION AUX LIMITES_ LIMIT CONDITIONS
    {
        caractere=fgetc(fichier);
        nbCar++;    //NOMBRE DE CARACTERE_ CHARACTER OCCURENCE
    }

    return --nbCar;
}

char* IMPORTCHAINE()
{
    /*DOC_STRING DE IMPORTACHAINE
    __FRANCAIS_
    ---------------------------
    PARAMETRES     : <Aucun>
    RETOUR         : - Pointeur sur chaine
    FONCTIONNEMENT : Cherche et renvoie un mot au hasard d'un fichier dictionnaire.
    ---------------------------
    __ENGLISH_
    ---------------------------
    PARAMETERS     : <None>
    RETURN         : - String Pointer
    OPERATION      : Search and returns a word read from a reference file.
    ---------------------------
    */

    /*VARIABLES_ IMPORTCHAINE*/
    int nbreCarDico=0, curseur=0;
    char *chaine=NULL, *chaineInter=NULL;
    char caractere='\0';
    FILE *fichierDico=NULL;

    fichierDico=fopen("texte.txt", "rt");       //OUVERTURE DE FICHIER_ FILE OPENING
    if (fichierDico == NULL)    //ERREUR_ ERROR
    {
        printf("FONCTION: IMPORTCHAINE/ LIGNE: %d/ ERREUR DE L'OUVERTURE DU FICHIER fichierDico\n", __LINE__);
        return NULL;
    }

    nbreCarDico=LONGUEURFICHIER(fichierDico);   //NOMBRE DE CARACTERES DANS LE FICHIER_ CHARACTER OCCURENCE INTO THE FILE
    rewind(fichierDico);

    srand(time(NULL));
    curseur = rand()% nbreCarDico;      //NUMERO ALEATOIRE_ RANDOM NUMBER
    fseek(fichierDico, curseur, SEEK_SET);

    if (curseur == 0)   //CAS DE DEBUT DE FICHIER_ CASE OF FILE BEGINING
    {
        fgets(chaineInter, 19, fichierDico);
    }
    else
    {
        while(1)
        {
            caractere=fgetc(fichierDico);
            if (caractere == '\n')      //EXCLUSION DU RETOUR A LA LIGNE_ BACK LINE EXCLUSION
                break;
            fseek(fichierDico, -2 , SEEK_CUR);
            curseur=ftell(fichierDico);
            if (curseur == 0)           //DEBUT DE FICHIER_ FILE BEGINING
                break;
        }

        chaineInter=(char*)calloc(20, sizeof(char));
        if (chaineInter == NULL)    //ERREUR_ ERROR
        {
            printf("FONCTION: IMPORTCHAINE/ LIGNE: %d/ ERREUR DE L'ALLOCATION DE chaineInter\n", __LINE__);
            return NULL;
        }

        fgets(chaineInter, 19, fichierDico);
        if ((strchr(chaineInter, '\n'))!= NULL)
        {
           * (strchr(chaineInter, '\n'))='\0';
        }

        chaine=(char*)calloc((strlen(chaineInter) +1), sizeof(char));   //CHAINE DE RETOUR_ RETURN STING
        if (chaine == NULL)     //ERREUR_ ERROR
        {
            printf("FONCTION: IMPORTCHAINE/ LIGNE: %d/ ERREUR DE L'ALLOCATION DE chaine\n", __LINE__);
            return NULL;
        }

        strcpy(chaine, chaineInter);

        /*NETTOYAGE DE MEMOIRE_ MEMORY CLEANING*/
        free(chaineInter);
        chaineInter=NULL;
    }

    return chaine;
    }

char LIRECARACTERE()
{
    /*DOC_STRING DE LIRECARACTERE
    __FRANCAIS_
    ---------------------------
    PARAMETRES     : <Auncun>
    RETOUR         : - Caractere: Ecrit par l'utilisateur.
    FONCTIONNEMENT : 1- Lit le premier caractère saisi.
                     2- Vide le buffer.
    ---------------------------
    __ENGLISH_
    ---------------------------
    PARAMETERS     : <None>
    RETURN         : - Character: Written by the user.
    OPERATION      : 1- Read the first Character written.
                     2- Clean the Buffer.
    ---------------------------
    */

    /*VARIABLES_ LIRECARACTERE*/
    char caractere;

    printf("Donnez un caract%cre :_", eg);
    caractere=getchar();

    while((getchar() != '\n') && (getchar() != EOF));           //VIDER LE BUFFER_ BUFFER CLEANING
    caractere=toupper(caractere);   //FORMATTAGE DE CARACTERE_ CHARACTER FORMATTING

    return caractere;
}

char* INITIALISER(int taille)
{
    /*DOC_STRING DE INITIALISER
    __FRANCAIS_
    ---------------------------
    PARAMETRES     : -taille : taille de la chaine à initialiser.
    RETOUR         : -Pointeur sur chaine.
    FONCTIONNEMENT : <Simple>
    ---------------------------
    __ENGLISH_
    ---------------------------
    PARAMETERS     : -taille : Length of the String to initialize.
    RETURN         : -String Pointer.
    OPERATION      : <Simple>
    ---------------------------
    */

    /*VARIABLES_ INITIALISER*/
    int compt=0;
    char *chaineInter=NULL;

    chaineInter=(char*)calloc((taille+1), sizeof(char));    //ALLOCATION DE MEMOIRE POUR CHAINE INTERMEDIAIRE_
                                                            //MEMORY ALLOCATION FOR INTERMEDIARY STRING
    if (chaineInter == NULL)    //ERREUR_ ERROR
    {
        printf("FONCTION: INITIALISER/ LIGNE: %d/ ERREUR DE L'ALLOCATION DE chaineInter\n", __LINE__);
        return NULL;
    }

    for(compt=0;compt<taille;compt++)
        *(chaineInter + compt)='*';
    *(chaineInter + taille)='\0';   //CARACTERE DE FIN DE CHAINE_ STRING FINAL CHARACTER

    return chaineInter;
}

int VERIFICATION(char *chaine, char caractere, char* chaineInter, int *carTrouve)
{
    /*DOC_STRING DE VERIFICATION
    __FRANCAIS_
    ---------------------------
    PARAMETRES     : -chaine       : chaine de base.
                     -chaineInter : chaine Intermediaire pour vérification.
                     -caractere    : caractere saisi par l'utilisateur.
                     -cartrouve    : nombre de caractere trouvés.
    RETOUR         : -1 si le caractere existe dans la chaine.
                     -0 sinon.
    FONCTIONNEMENT : 1- Verifie l'existance du caractere dans la chaine.
                     2- Actualise la chaine Intermédiaire.
                     3- Compte le nombre de lettres trouvées.
                     4- Retourne la chaine actualisée.
    ---------------------------
    __ENGLISH_
    ---------------------------
    PARAMETERS    : -chaine       : The Basic String.
                    -chaineInter : Intermediary String for verification.
                    -caractere    : The character written by the user.
                    -cartrouve    : how many characters have been found.
    RETURN        : -1 If the Character does exist into the String "chaine".
                    -0 Else
    OPERATION     : 1- Verify if the Character appears in the string "chaine".
                    2- Updates the Intermediary String.
                    3- Counts the number of letters found.
                    4- Returns the Result String.
    ---------------------------
    */

    /*VARIABLES_ VERIFICATION*/
    int verifCar=0, compt=0;
    char *foisTrouve=NULL;

    if (strchr(chaine, caractere) == NULL) //CARACTERE INEXISTANT_ CHARACTER NOT FOUND
    {
        return verifCar;
    }
    else
    {
        foisTrouve=strchr(chaineInter, caractere);  //VERIFICATION DE L'EXISTANCE DU CARACTERE DANS "chaineInter"_
                                                    //VERIFICATION IF THE CHARACTER DOES EXIST IN "chaineInter" STRING
        for(compt=0;compt<strlen(chaineInter);compt++)
        {
            if (*(chaine + compt) == caractere)     //VERIFICATION DE L'EXISTANCE DU CARACTERE DANS "chaine"_
                                                    //VERIFICATION IF THE CHARACTER DOES EXIST IN "chaine" STRING
            {
                *(chaineInter + compt) = caractere;
                if (foisTrouve == NULL)
                {
                    (*carTrouve)++;     //MISE A JOUR DE NOMBRE LETTRE TROUVEE_ UPDATING THE NUMBER OF FOUND CHARACTERS
                }
            }
        }
        verifCar=1;     //BOOLEEN DE VERIFICATION DE DETERMINATION_ GUESSING BOOLEAN
    }

    return verifCar;
}


