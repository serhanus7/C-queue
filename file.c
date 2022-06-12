#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct elemt{
        char nom[20];
        char prenom[20];
        int age;
        struct elemt* suivant;
        }perso;
typedef struct liste{
        perso* tete;
        perso* queue;
        }file;
/*************Fonction d'ajout***********/
file ajouter(file f){
     perso* nv=malloc(sizeof(perso));
     fflush(stdin);
     printf("Donner le nom:\n");
     scanf("%s",nv->nom);
     printf("Donner le prenom:\n");
     scanf("%s",nv->prenom);
     printf("Donner l'age:\n");
     scanf("%i",&(nv->age));
     nv->suivant=NULL;
     
     if(f.tete==NULL && f.queue==NULL){
            f.tete=f.queue=nv;
            
            }
     else{
            (f.queue)->suivant=nv;
            f.queue=nv;
          }
     return f;
     }
/************Fonction afficher***********/
void afficher(file f){
     perso* parcours;
     if(f.tete==NULL) printf("La file est vide !!\n");
     else{
          parcours=f.tete;
          while(parcours!=NULL){
                          printf("Nom= %s | Prenom= %s | Age= %i\n",parcours->nom,parcours->prenom,parcours->age);
                          parcours=parcours->suivant;
                          }
          }
     }
/************Fonction compter***********/        
int compter(file f){
    int c=0;
    perso* parcours=f.tete;
    while(parcours){
                    c++;
                    parcours=parcours->suivant;
                    }
    return c;
    }
/************Fonction afficher-compter***********/
int compter2(file f,char N[20],char P[20]){
    int c=0;
    perso* parcours=f.tete;
    while(strcmp(parcours->nom,N)!=0 && strcmp(parcours->prenom,P)!=0 && parcours){
                    c++;
                    parcours=parcours->suivant;
                    }
    return c;
    }
/************Fonction compter***********/ 
file supprimer(file f){
     perso *temp;
     if(f.tete==NULL) printf("la file est vide\n");
     
     else{

          if(f.tete==f.queue) {
                    temp=f.tete;
                    f.tete=f.queue=NULL;
                    free(temp);
                    
          }
          else{
               temp=f.tete;
              f.tete=(f.tete)->suivant;
              free(temp); 
               }
          return f;
          }
     
     }
/****************************************/
int main(){
    file F;
    F.tete=NULL;
    F.queue=NULL;
    char nom[20],prenom[20];
    int option;
    system("color 0a");
    do{
    //do{
        printf("/*******************************/\n");
        printf("1 - Ajouter une personne.\n");
        printf("2 - Afficher la file.\n");
        printf("3 - Compter les elements de la file.\n");
        printf("4 - Compter les precedents d'une personne.\n");
        printf("5 - Supprimer une personne.\n");
        printf("6 - Quiter.\n");
        printf("/*******************************/\n\n");
        scanf("%i",&option);
    //}while(option!=1 ||option!=2 ||option!=3 ||option!=4 ||option!=5);
    
    switch(option){
            case 1 :
                F=ajouter(F);
                break;
            case 2 :
                afficher(F);
                break;
            case 3 :
                printf("Le nombre des personnes dans la file est :%i\n",compter(F));
                break;    
            case 4:
                printf("Doner le nom et le prenom.\n");
                scanf("%s%s",nom,prenom);
                printf("Le nombre des personnes qui precedent ce personne est :%i\n",compter2(F,nom,prenom)); 
                break;
            case 5 :
                
                F=supprimer(F);
                break;
    }
    }while(option!=6);
   
    system("pause");
    return 0;    
}







