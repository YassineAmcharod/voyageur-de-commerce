#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
        {
            char* nom;
            int num;
        }ville;

extern int len;
extern int* liste_ville;
extern int ville_pre;
extern int Distance_ville[16][16];
int liste_ville_visitee[16]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

char* DETECT_ville_nom(int k)
{

    ville v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v0;
    v0.nom="agadir";v0.num=0;
    v1.nom="casablanca";v1.num=1;
    v2.nom="dakhla";v2.num=2;
    v3.nom="eljadida";v3.num=3;
    v4.nom="essaouira";v4.num=4;
    v5.nom="fes";v5.num=5;
    v6.nom="kenitra";v6.num=6;
    v7.nom="laayoune";v6.num=7;
    v8.nom="marrakech";v7.num=8;
    v9.nom="meknes";v9.num=9;
    v10.nom="ouarzazate";v10.num=10;
    v11.nom="oujda";v11.num=11;
    v12.nom="rabat";v12.num=12;
    v13.nom="tanger";v13.num=13;
    v14.nom="tetouan";v14.num=14;
    v15.nom="taroudant";v15.num=15;

    if(v1.num==k) return v1.nom; if(v0.num==k) return v0.nom;
    if(v3.num==k) return v3.nom; if(v4.num==k) return v4.nom;
    if(v5.num==k) return v5.nom; if(v6.num==k) return v6.nom;
    if(v7.num==k) return v7.nom; if(v8.num==k) return v8.nom;
    if(v9.num==k) return v9.nom; if(v10.num==k) return v10.nom;
    if(v11.num==k) return v11.nom; if(v12.num==k) return v12.nom;
    if(v13.num==k) return v13.nom; if(v14.num==k) return v14.nom;
    if(v15.num==k) return v15.nom; if(v2.num==k) return v2.nom;

}



int existe(int k)
{printf("\nExiste K=%d",k);int exi=0;
    for (int j=0;j<16;j++)
    {
        if (liste_ville_visitee[j]==k) {printf("\nOUI_Existe");exi=1;}
    }
    return exi;
}
int min_distance(int ville_depart)
{
    static int i;printf("\nmin_distance_ville_depart=%d",ville_depart);
    liste_ville_visitee[i]= ville_depart;i++;printf("\nListe_ville_visitee:");for (int r=0;r<16;r++) printf("||-->%d",liste_ville_visitee[r]);
    int min;
    for (int x=0;x<len;x++) if (existe(liste_ville[x])==0) min=x;
    for (int k=0;k<len;k++)
    {printf("\nliste_ville[k]=%d",liste_ville[k]);int tmp=existe(liste_ville[k]);
         if (Distance_ville[ville_depart][liste_ville[k]]<Distance_ville[ville_depart][liste_ville[min]] && tmp!=1)
        {
            min=k;printf("\nMIN=%d",min);
        }
    }
    return min;
}

///Liste_ville:||-->8||-->0||-->12||-->6||-->7||-->2||-->11


int* Disjiksta()
{   int* chemin;chemin=calloc(len+2,sizeof(int));
    chemin[0]=ville_pre;int ville_depart=ville_pre;
    for (int x=1;x<len+1;x++)
    {   printf("\nDisjikstra_ville_depart=%d",ville_depart);
        chemin[x]=liste_ville[min_distance(ville_depart)];
        ville_depart=chemin[x];
    }
    chemin[len+1]=chemin[0];printf("\nChemin_Disjikstra:");
    for (int r=0;r<len+2;r++) printf("||-->%d",chemin[r]);
    return chemin;
}

void ER_2A()/// prob au niveau de pointeur liste_ville ou C_opt
{
    printf("ville_pre==>%d ||len==>%d\n",ville_pre,len);
    int* C_opt;//C_opt= (int*)calloc(len+2,sizeof(int));
    printf("\nListe_ville:");
    for (int r=0;r<len;r++) printf("||-->%d",liste_ville[r]);
    C_opt=Disjiksta();printf("\nChemin_EA_2A:");
    for (int r=0;r<len+2;r++) printf("||-->%d",C_opt[r]);printf("\n");
    for (int i=0;i<len-1;i++)
        for (int j=i+2;j<len+1;j++)
    {
        if (Distance_ville[C_opt[i]][C_opt[i+1]]+Distance_ville[C_opt[j]][C_opt[j+1]]>Distance_ville[C_opt[i]][C_opt[j]]+Distance_ville[C_opt[i+1]][C_opt[j+1]])
        {printf("\n\t62");
            int tmp=C_opt[i+1];
            C_opt[i+1]=C_opt[j];C_opt[j]=tmp;
        }
    }
    printf("\n\tChemin Solution=[ ");
    for (int r=0;r<len+1;r++) printf("%d-->",C_opt[r]);
    printf("%d ]",C_opt[len+1]);
    printf("\n\tChemin Solution=[ ");
    for (int r=0;r<len+1;r++) printf("%s-->",DETECT_ville_nom(C_opt[r]));
    printf("%s ]",DETECT_ville_nom(C_opt[len+1]));
    //return C_opt;
}
