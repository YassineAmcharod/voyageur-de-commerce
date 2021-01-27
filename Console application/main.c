#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void fullscreen() ///function definition for fullscreen source: https://www.dreamincode.net/forums/topic/59497-run-a-c-program-in-full-screen/
{  keybd_event(VK_MENU,
				0x38,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				KEYEVENTF_KEYUP,
				0);
	keybd_event(VK_MENU,
				0x38,
				KEYEVENTF_KEYUP,
				0);
}


void ER_2A();
int Disjiksta();

typedef struct
        {
            char* nom;
            int num;
        }ville;
char VILLES [16][16]={"agadir","casablanca","dakhla","eljadida","essaouira","fes","kenitra","laayoune","marrakech","meknes","ouarzazate","oujda","rabat","tanger","tetouan","taroudant"};

int Distance_ville[16][16]={///{   ***,   agadir,    casa,   dakhla,   eljadida,   essaouira,  fes,  kenitra,    laayoune,   marrakech,  meknes,  ouarzazate,    oujda,  rabat,  tanger,  tetouan,   taroudant},
                            {/*agadir,*/    0,      511,    1173,       417,        173,        756,    596,        649,        273,      740,      375,        1099,    602,     880,      892,         81},
                            {/*casa,    */ 511,      0,     1684,       99,         351,        289,    131,        1160,       238,      229,      442,        632,      91,     369,      385,        602},
                            {/*dakhla,  */1173,     1684,     0,      1590,         1346,      1920,    1769,       524,       1446,     1913,      1548,       2272,   1775,    2053,      2065,      1268},
                            {/*eljadida, */417,      99,     1590,       0,          252,       388,    360,       1066,        197,      328,       399,       731,    190,      468,      484,        505},
                            {/*essaouira,*/173,     351,    1346,      252,           0,        640,    499,        822,        176,      580,       380,       983,    442,      720,      736,        254},
                            {/*fes,      */756,     289,    1920,      388,         640,        0,      160,        1396,       483,       60,      687,        343,    198,      303,      281,        705},
                            {/*kenitra,  */596,     131,    1769,      360,         499,        160,      0,        1245,       234,      153,      527,        503,    40,       620,      411,        597},
                            {/*laayoune, */649,     1160,    524,     1066,         822,        1396,   1245,         0,        922,     1389,      1024,       1748,   1251,     1529,     1541,       729},
                            {/*marrakech,*/273,     238,    1446,      197,         176,        483,    234,        922,         0,       467,      204,        826,    321,      598,      675,        226},
                            {/*meknes,   */740,     229,    1913,      328,         580,        60,     153,        1389,       467,        0,      652,        403,    138,      267,      258,        678},
                            {/*ourzazate,*/375,     442,    1548,      399,         380,        687,    527,        1024,       204,      652,      0,          820,    528,      811,      280,        297},
                            {/*oujda,   */1099,     632,    2272,      731,         983,        343,    503,        1748,       826,      403,      820,         0,     541,      609,      555,        1049},
                            {/*rabat,    */602,     91,     1775,      190,         442,        198,     40,        1251,       321,      138,      528,        541,     0,       278,      294,        695},
                            {/*tanger,   */880,     369,    2053,      468,         720,        303,    620,        1529,       596,      267,      811,        609,    278,      0,        57,         977},
                            {/*tetouan,  */892,     385,    2065,      494,         736,        281,    411,        1541,       675,      258,      280,        555,    294,      57,       0,          968},
                            {/*taroudant, */81,     602,    1268,      505,         254,        705,    597,         729,       226,      678,      297,        1049,   695,      977,      968,         0}};

int len;
//int* liste_ville;
int ville_pre;


int DETECT_ville_num(char vil_nom[16])
{

    ville v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v0;
    v0.nom="agadir";v0.num=0;
    v1.nom="casablanca";v1.num=1;
    v2.nom="dakhla";v2.num=2;
    v3.nom="eljadida";v3.num=3;
    v4.nom="essaouira";v4.num=4;
    v5.nom="fes";v5.num=5;
    v6.nom="kenitra";v6.num=6;
    v7.nom="laayoune";v7.num=7;
    v8.nom="marrakech";v8.num=8;
    v9.nom="meknes";v9.num=9;
    v10.nom="ouarzazate";v10.num=10;
    v11.nom="oujda";v11.num=11;
    v12.nom="rabat";v12.num=12;
    v13.nom="tanger";v13.num=13;
    v14.nom="tetouan";v14.num=14;
    v15.nom="taroudant";v15.num=15;

    if(strcmp(vil_nom,v1.nom)==0)return 1;if(strcmp(vil_nom,v0.nom)==0)return 0;
    if(strcmp(vil_nom,v3.nom)==0)return 3;if(strcmp(vil_nom,v4.nom)==0)return 4;
    if(strcmp(vil_nom,v5.nom)==0)return 5;if(strcmp(vil_nom,v6.nom)==0)return 6;
    if(strcmp(vil_nom,v7.nom)==0)return 7;if(strcmp(vil_nom,v8.nom)==0)return 8;
    if(strcmp(vil_nom,v9.nom)==0)return 9;if(strcmp(vil_nom,v10.nom)==0)return 10;
    if(strcmp(vil_nom,v11.nom)==0)return 11;if(strcmp(vil_nom,v12.nom)==0)return 12;
    if(strcmp(vil_nom,v13.nom)==0)return 13;if(strcmp(vil_nom,v14.nom)==0)return 14;
    if(strcmp(vil_nom,v15.nom)==0)return 15;if(strcmp(vil_nom,v2.nom)==0)return 2;

}

void main()
{
    fullscreen();
    int i,j,menu1,menu2;
    printf("\n"
           "\n"
           "\n\n"
            "\t\t\t\t\t###############################################\n"
            "\t\t\t\t\t############# VOYAGEUR DE COMMERCE ############\n"
            "\t\t\t\t\t###                                         ###\n"
            "\t\t\t\t\t###                                         ###\n"
            "\t\t\t\t\t###         OOOOOOOOO       OOOOOOOOO       ###\n"
            "\t\t\t\t\t###         O       O           O           ###\n"
            "\t\t\t\t\t###         O       O           O           ###\n"
            "\t\t\t\t\t###         O                   O           ###\n"
            "\t\t\t\t\t###         O   OOOOO           O           ###\n"
            "\t\t\t\t\t###         O       O           O           ###\n"
            "\t\t\t\t\t###         OOOOOOOOO       OOOOOOOOO       ###\n"
            "\t\t\t\t\t###                                         ###\n"
            "\t\t\t\t\t###                                         ###\n"
            "\t\t\t\t\t###############################################\n"
            "\t\t\t\t\t###############################################\n");

    printf("\n"
           "\n");      printf("\t\t\t\t\t\t\t tap to continue  \n");
    printf("\n"
            "\n"
            "\n"
            "\n"
            "\t\t\t\t\t                                         ||||| ER-2A |||||\n");
            getch();
            system("cls");
            printf("\n"
                    "\n");
        H:
     printf("\n"
            "\n\n\n"
            "\t\t\t\t\t ---------------------- MENU ----------------------\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t|                1_ COMMENCER TSP/VDC              |\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t|                  2_ PRINCIPE DU PROBLEME         |\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t|                    3_ QUITTER                    |\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t|                                                  |\n"
            "\t\t\t\t\t --------------------------------------------------\n"
            "\n"
            "\t\t\t\t\t                   Votre reponse : ");
            scanf("\n%d",&i);
            system("cls");

    switch (i)
    {
    case 1:R:
     printf("\n"
            "\n"
            "\n"
            "\n"
            "\t\t\t\t\t ---------------- MODES D'INSERTION -------------------\n"
            "\t\t\t\t\t|                                                      |\n"
            "\t\t\t\t\t|                 1_ VILLE DE DEPART                   |\n"
            "\t\t\t\t\t|                                                      |\n"
            "\t\t\t\t\t|                   2_ VILLES A PARCOURIR              |\n"
            "\t\t\t\t\t|                                                      |\n"
            "\t\t\t\t\t|                     3_ CHEMIN A SUIVRE               |\n"
            "\t\t\t\t\t|                                                      |\n"
            "\t\t\t\t\t|                       4_    RETOUR                   |\n"
            "\t\t\t\t\t|                                                      |\n"
            "\t\t\t\t\t ------------------------------------------------------\n"
            "\n"
            "\n"
            "\t\t\t\t\t                       Votre reponse :  ");
            scanf("\n%d",&j);
            system("cls");
            switch (j)
            {
            case 1:
                M:
                menu1=1;
                printf("\n\n\n\t\tLISTE = [ agadir, casablanca , dakhla , eljadida , essaouira , fes , kenitra , laayoune ,\n\t\t\t marrakech , meknes , ouarzazate , oujda , rabat , tanger , tetouan , taroudant ]\n");
                printf("\n\t\tQu'elle est la ville de depart que vous souhaitez choisir parmi la liste proposee ci-dessus :\n\n\n\t=====>>");
                char ville[16];
                scanf("%s",ville);
                for (int i=0;i<16;i++)
                {   char c[16];strcpy(c,VILLES[i]);
                    if (strcmp(ville,c)==0){ville_pre=DETECT_ville_num(ville);system("cls");goto R;}}
                printf("\t Non Valide");getch();
                system("cls");goto M;

            case 2:
                menu2=1;
                printf("\n\n\n\t\tLISTE = [ agadir, casablanca , dakhla , eljadida , essaouira , fes , kenitra , laayoune ,\n\t\t\t marrakech ,"
                        "meknes , ouarzazate , oujda , rabat , tanger , tetouan , taroudant ]\n");                printf("\n\t\tQu'elles sont les villes que vous souhaitez parcourir parmi la liste proposee ci-dessus :\n");
                printf("\n\t***** choisir un a un en tapant entree pour comfirmer , tapez exit pour finaliser l'insertion*****\n");
                int Aide[20]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
                E:
                printf("\n\n\n\t =====>>");
                char villes[16];
                scanf("%s",villes);char* d="exit";if (strcmp(villes,d)==0) {system("cls");goto R;}
                for (int i=0;i<16;i++)
                {   char cs[16];strcpy(cs,VILLES[i]);
                    if (strcmp(villes,cs)==0)
                        {printf("\t Valide");
                            static int it;it++;len=it;
                            int liste_ville_tmp[it];
                            Aide[it-1]=DETECT_ville_num(villes);
                            /*for (int r=0;Aide[r]!=-1;r++) liste_ville_tmp[r]=Aide[r];
                            liste_ville=liste_ville_tmp;//*/
                            goto E;}
                            //liste_ville=realloc(liste_ville,sizeof(int)*it);len=it;
                            //liste_ville[it-1]=DETECT_ville_num(villes);goto E;
                       //for (int r=0;r<len;r++) printf("\t%d",liste_ville[r]);goto E;}
                        }
                printf("\t Non Valide");/*getch();system("cls");*/goto E;

            case 3:
                if (menu1!=1 || menu2!=1) {printf("\n\t\t Les informations fournies sont incompletes");getch();system("cls");goto R;}
                else{
                printf("\n"
                       "\n"
                       "\t\t\t\t\t             @@@@@@@@@@@     @@@@@@@@@    @@@@@@@@@@@\n"
                       "\t\t\t\t\t             @               @                 @\n"
                       "\t\t\t\t\t             @               @                 @\n"
                       "\t\t\t\t\t             @               @@@@@@@@@         @\n"
                       "\t\t\t\t\t             @     @@@@@     @                 @\n"
                       "\t\t\t\t\t             @         @     @                 @\n"
                       "\t\t\t\t\t             @@@@@@@@@@@     @@@@@@@@@         @\n"
                       "\n"
                       "\n");

                printf("\n"
                       "\n"
                       "\t\t\t\t\t        @@@@@@@     @@@@@@@   @@@@@@@   @@@@@      @     @ \n"
                       "\t\t\t\t\t        @     @     @         @     @   @     @     @   @\n"
                       "\t\t\t\t\t        @  @@@@     @         @     @   @     @      @ @\n"
                       "\t\t\t\t\t        @  @        @@@@@@@   @@@@@@@   @     @       @\n"
                       "\t\t\t\t\t        @   @       @         @     @   @     @       @ \n"
                       "\t\t\t\t\t        @    @      @         @     @   @     @       @\n"
                       "\t\t\t\t\t        @     @     @@@@@@@   @     @   @@@@@         @ \n");
                getch();
                system("cls");
                int liste_ville[len];
                for (int r=0;r<len;r++) liste_ville[r]=Aide[r];
                ER_2A(liste_ville);//getch();main();
                break;}
            case 4:
                goto H;
                break;
            }
        break;
    case 2:
        printf("\n"
               "\n"
               "\n"
               "\n"
               "\t\t\t--------------------------------- PRINCIPE DU PROGRAMME ----------------------------------\n\n\n");
        printf("\t\t\t LE PROGRAMME CONSISTE A TROUVER LE CHEMIN MINIMAL QUE UNE PERSONNE PEUT PARCOURIR POUR "
               "\n\t\t\t VISITER UNE LISTE DE VILLES ET REVENIR A SA VILLE DE DEPART ."
               "\n\n\n\t\t\t\t\t\t\t press to return");
        getch();system("cls");goto H;
        break;
    case 3:
        exit(EXIT_SUCCESS);
        break;}

}
