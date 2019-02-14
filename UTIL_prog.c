/*FONCTION D'INFORMATION SUR PROGRAMME_ PROGRAM INFORMATIONS FUNCTIONS ___ DEFINITION*/
/* DOC_STRING DE UTIL_prog
___FRANCAIS__
==================================
Titre       : Utilitaires
Auteur      : MARRAKCHI Ghassen
Référence   : ANSI C99
Type        : Jeu
Description : (INFOPROGINT, REGLES)
==================================
___ENGLISH__
==================================
Title       : Utilities
Author      : Ghassen MARRAKCHI
Reference   : ANSI C99
Type        : Game
Description : (INFOPROGINT, REGLES)
==================================
*/

/*INCLUSION*/
#include "UTIL_prog.h"                  //FONCTIONS UTILITAIRES DU PROGRAMME_ PROGRAM UTILITIES FUNCTIONS
#include "CONST_francais.h"             //LETTRE DE FRANCAIS CONSTANTES_ FRENCH CONSTANT LETTERS
#include "INC_standard.h"               //INCLUSION BIBLIOTHEQUES STANDARD_ STANDARD LIBS INCLUSION


void INFOPROGINT(void)
{
    /*DOC_STRING DE INFOPROGINT
    __FRANCAIS_
    ---------------------------
    PARAMETRES     : <Aucun>
    RETOUR         : <Aucun>
    FONCTIONNEMENT : Affiche les informations sur la création du programme.
    ---------------------------
    __ENGLISH_
    ---------------------------
    PARAMETERS     : <None>
    RETURN         : <None>
    OPERATION      : Shows all the program creating informations.
    ---------------------------
    */

    printf("___FRANCAIS__\n");
    printf("==================================\n");
    printf("Titre       : JeuPendu\n");
    printf("Auteur      : MARRAKCHI Ghassen\n");
    printf("Référence   : ANSI C99\n");
    printf("Type        : Jeu\n");
    printf("Description : Description : L'UTILISATEUR essaie de deviner le mot lettre par lettre \n\t\t\
           avec possibilit%c de dix echecs\n", ea);
    printf("==================================\n");
    printf("___ENGLISH__\n");
    printf("==================================\n");
    printf("Title       : Hanged Game\n");
    printf("Author      : Ghassen MARRAKCHI\n");
    printf("Reference   : ANSI C99\n");
    printf("Type        : Game\n");
    printf("Description : THE USER tries to guess the word letter by letter.\n\t\t\
           Only ten fails are allowed.\n");
    printf("==================================\n");
}

void REGLES(void)
{
    /*DOC_STRING DE REGLES
    __FRANCAIS_
    ---------------------------
    PARAMETRES     : <Aucun>
    RETOUR         : <Aucun>
    FONCTIONNEMENT : Affiche les regles du jeu.
    ---------------------------
    __ENGLISH_
    ---------------------------
    PARAMETERS     : <None>
    RETURN         : <None>
    OPERATION      : Shows all the Game Rules.
    ---------------------------
    */
    printf("\n___FRANCAIS__REGLES_\n");
    printf("-L'Utilisateur saisi une lettre; Si elle existe elle sera afficher dans la chaine,\n");
    printf("                                une diminution de score d'une unit%c sinon.\n", ea);
    printf("-L'Utilisateur a 10 possibilit%cs de donner une fausse lettre.\n", ea);
    printf("-L'utilisateur aura la possibilit%c de jouer tant qu'il le veut.\n", ea);
    printf("-L'utilisateur doit repondre par \"oui\" en repondant à une question pos%ce par le programme;\n", ea);
    printf("    Autres reponse sera compter comme une r%cponse négative.\n", ea);
    printf("___ENGLISH__RULES_\n");
    printf("-The User will write one letter; If the letter exists in the word it will be shown inside,\n");
    printf("                                If not, the score will be decreased by one.\n");
    printf("-The User will have only ten allowed fails.\n");
    printf("-The User can play as many times as he wants.\n");
    printf("-The User Must answer the program by \"oui\" if he wants, All other answers are understood as a negative answer.\n");
    printf("----\n");
}

