#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin)*/
#include <string.h>
#include <SDL/SDL_mixer.h>




int len;
int* CHE_opt;
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

int ville_pre;
int Aide[20]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int liste_ville_visitee[16]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int existe(int k)
{int exi=0;
    for (int j=0;j<16;j++)
    {
        if (liste_ville_visitee[j]==k) {exi=1;}
    }
    return exi;
}
int min_distance(int ville_depart,int* L_V)
{
    static int i;
    liste_ville_visitee[i]= ville_depart;i++;
    int min;
    for (int x=0;x<len;x++) if (existe(L_V[x])==0) min=x;
    for (int k=0;k<len;k++)
    {int tmp=existe(L_V[k]);
         if (Distance_ville[ville_depart][L_V[k]]<Distance_ville[ville_depart][L_V[min]] && tmp!=1)
        {
            min=k;
        }
    }
    return min;
}


void Disjiksta(int* L_V)
{
    int* chemin;//[len+2];
    chemin=(int*)malloc(3*sizeof(int));
    chemin[0]=ville_pre;int ville_depart=ville_pre;
    for (int x=1;x<len+1;x++)
    {
        chemin[x]=L_V[min_distance(ville_depart,L_V)];
        ville_depart=chemin[x];
    }
    chemin[len+1]=chemin[0];//printf("\nChemin_Disjikstra:");
    //for (int r=0;r<len+2;r++) printf("||-->%d",chemin[r]);
    CHE_opt=chemin;

}

void SAYS(int* L_V)
{
    //printf("ville_pre==>%d ||len==>%d\n",ville_pre,len);

    Disjiksta(L_V);
    for (int i=0;i<len-1;i++)
        for (int j=i+2;j<len+1;j++)
        {
        if (Distance_ville[CHE_opt[i]][CHE_opt[i+1]]+Distance_ville[CHE_opt[j]][CHE_opt[j+1]]>Distance_ville[CHE_opt[i]][CHE_opt[j]]+Distance_ville[CHE_opt[i+1]][CHE_opt[j+1]])
        {
            int tmp=CHE_opt[i+1];
            CHE_opt[i+1]=CHE_opt[j];CHE_opt[j]=tmp;
        }
        }


}


//void pause();

int main(int argc, char *argv[])

{
    int menu1=0,menu2=0;


    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*fleche=NULL, *sapin = NULL, *agadir=NULL,*casa =NULL,*dakhla =NULL,*eljadida =NULL,*essaouira =NULL,*fes =NULL, *kenitra =NULL,*laayoune =NULL,*marrakech =NULL,*meknes =NULL,*ouarzazate =NULL,*oujda =NULL,*rabat =NULL,*tanger =NULL,*taroudant =NULL,*tetouan =NULL;
    SDL_Rect positionFond, positionSapin ,positionFleche;
    positionFond.x = 0;
    positionFond.y = 0;
    positionSapin.x = 0;
    positionSapin.y = 0;
    SDL_Init(SDL_INIT_VIDEO );
    //ecran = SDL_SetVideoMode(640, 480, 32, SDL_FULLSCREEN);
    (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1); //Initialisation de l'API Mixer
    SDL_WM_SetIcon(IMG_Load("images/christmas_PNG3743.png"), NULL);
    ecran = SDL_SetVideoMode(1343, 699, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("S.A.Y.S", NULL);
    imageDeFond = IMG_Load("images/Maroc.jpg");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    /* les images des villes
    SDL_Surface *agadir = IMG_Load("images/0.jpg");
    SDL_Surface *casa = IMG_Load("images/1.jpg");
    SDL_Surface *dakhla = IMG_Load("images/2.jpg");
    SDL_Surface *eljadida = IMG_Load("images/3.jpg");
    SDL_Surface *essaouira = IMG_Load("images/4.jpg");
    SDL_Surface *fes = IMG_Load("images/5.jpg");
    SDL_Surface *kenitra = IMG_Load("images/6.jpg");
    SDL_Surface *laayoune = IMG_Load("images/7.jpg");
    SDL_Surface *marrakech = IMG_Load("images/8.jpg");
    SDL_Surface *meknes = IMG_Load("images/9.jpg");
    SDL_Surface *ouarzazate = IMG_Load("images/10.jpg");
    SDL_Surface *oujda = IMG_Load("images/11.jpg");
    SDL_Surface *rabat = IMG_Load("images/12.jpg");
    SDL_Surface *tanger = IMG_Load("images/13.jpg");
    SDL_Surface *taroudant = IMG_Load("images/14.jpg");
    SDL_Surface *tetouan = IMG_Load("images/15.jpg");*/

    /*sapin = IMG_Load("images/done.png");
    SDL_BlitSurface(sapin, NULL, ecran, &positionSapin);*/
    SDL_Flip(ecran);
    int continuer = 1;
    SDL_Event event;

    Mix_AllocateChannels(32); //Allouer 32 canaux
    Mix_Volume(1, MIX_MAX_VOLUME/2); //Mettre à mi-volume le post 1
    Mix_Chunk *son;//Créer un pointeur pour stocker un .WAV
    Mix_Chunk *son2;
    son = Mix_LoadWAV("clic0.wav"); //Charger un wav dans un pointeur
    son2 = Mix_LoadWAV("clic1.wav");
    Mix_VolumeChunk(son, MIX_MAX_VOLUME/3); //Mettre un volume pour ce wav
    Mix_VolumeChunk(son2, MIX_MAX_VOLUME/3);


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                {
                Mix_PlayChannel(1, son, 0);//Joue le son 1 sur le canal 1 ; le joue une fois (0 + 1
                H:
                imageDeFond = IMG_Load("images/Maroc1.jpg");
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_Flip(ecran);
                SDL_Event event;
                while (continuer)
                {
                    SDL_WaitEvent(&event);
                    switch(event.type)
                    {
                        case SDL_QUIT:
                            continuer = 0;
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                           {
                            if(566<event.button.x&&event.button.x<872&&554<event.button.y&&event.button.y<640)
                            {
                                Mix_PlayChannel(1, son, 0);
                                continuer = 0;
                                    break;
                            }
                            if (566<event.button.x&&event.button.x<872&&438<event.button.y&&event.button.y<522)
                            {
                                        Mix_PlayChannel(1, son, 0);
                                        imageDeFond = IMG_Load("images/Maroc3.jpg");
                                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                        SDL_Flip(ecran);
                                        SDL_Event event;
                                        while (continuer)
                                        {
                                            SDL_WaitEvent(&event);
                                            switch(event.type)
                                            {
                                                case SDL_QUIT:
                                                    continuer = 0;
                                                    break;
                                                case SDL_MOUSEBUTTONDOWN:
                                                    {
                                                     Mix_PlayChannel(1, son2, 0);
                                                     goto H;
                                                    }

                                            }

                                        }

                            }
                            if (566<event.button.x&&event.button.x<872&&323<event.button.y&&event.button.y<410)
                            {
                                A:
                                Mix_PlayChannel(1, son, 0);
                                imageDeFond = IMG_Load("images/Maroc2.jpg");
                                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                SDL_Flip(ecran);
                                SDL_Event event;
                                while (continuer)
                                {
                                SDL_WaitEvent(&event);
                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        continuer = 0;
                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                                            if (10<event.button.x&&event.button.x<190&&30<event.button.y&&event.button.y<170)
                                            {
                                                Mix_PlayChannel(1, son2, 0);
                                                goto H;
                                            }
                                            if (566<event.button.x&&event.button.x<872&&323<event.button.y&&event.button.y<410)
                                                {
                                                    Mix_PlayChannel(1, son, 0);
                                                    imageDeFond = IMG_Load("images/Maroc4.jpg");
                                                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                                    SDL_Flip(ecran);
                                                    SDL_Event event;
                                                    while (continuer)
                                                    {
                                                        SDL_WaitEvent(&event);
                                                        switch(event.type)
                                                        {
                                                            case SDL_QUIT:
                                                                continuer = 0;
                                                                break;
                                                            case SDL_MOUSEBUTTONDOWN:
                                                                {
                                                                    char* ville;
                                                                    //switch(event.key.keysym.sym)
                                                                    {
                                                                        if(45<event.button.x&&event.button.x<330&&260<event.button.y&&event.button.y<335)
                                                                            {ville="agadir";
                                                                            menu1=1;
                                                                            ville_pre=0;goto A;
                                                                            break;}
                                                                        if(370<event.button.x&&event.button.x<650&&260<event.button.y&&event.button.y<335)
                                                                            {ville="casa";
                                                                            menu1=1;
                                                                            ville_pre=1;goto A;
                                                                            break;}
                                                                        if(695<event.button.x&&event.button.x<970&&260<event.button.y&&event.button.y<335)
                                                                            {ville="dakhla";
                                                                            menu1=1;
                                                                            ville_pre=2;goto A;
                                                                            break;}
                                                                        if (1020<event.button.x&&event.button.x<1290&&260<event.button.y&&event.button.y<335)
                                                                            {ville="eljadida";
                                                                            menu1=1;
                                                                            ville_pre=3;goto A;
                                                                            break;}
                                                                        if (45<event.button.x&&event.button.x<330&&372<event.button.y&&event.button.y<447)
                                                                            {ville="essaouira";
                                                                            menu1=1;
                                                                            ville_pre=4;goto A;
                                                                            break;}
                                                                        if (370<event.button.x&&event.button.x<650&&372<event.button.y&&event.button.y<447)
                                                                            {ville="fes";
                                                                            menu1=1;
                                                                            ville_pre=5;goto A;
                                                                            break;}
                                                                        if (695<event.button.x&&event.button.x<970&&372<event.button.y&&event.button.y<447)
                                                                            {ville="kenitra";
                                                                            menu1=1;
                                                                            ville_pre=6;goto A;
                                                                            break;}
                                                                        if (1020<event.button.x&&event.button.x<1290&&372<event.button.y&&event.button.y<447)
                                                                            {ville="laayoune";
                                                                            menu1=1;
                                                                            ville_pre=7;goto A;
                                                                            break;}
                                                                        if (45<event.button.x&&event.button.x<330&&484<event.button.y&&event.button.y<559)
                                                                            {ville="marrakech";
                                                                            menu1=1;
                                                                            ville_pre=8;goto A;
                                                                            break;}
                                                                        if (370<event.button.x&&event.button.x<650&&484<event.button.y&&event.button.y<559)
                                                                            {ville="meknes";
                                                                            menu1=1;
                                                                            ville_pre=9;goto A;
                                                                            break;}
                                                                        if (695<event.button.x&&event.button.x<970&&484<event.button.y&&event.button.y<559)
                                                                            {ville="ouarzazate";
                                                                            menu1=1;
                                                                            ville_pre=10;goto A;
                                                                            break;}
                                                                        if (1020<event.button.x&&event.button.x<1290&&484<event.button.y&&event.button.y<559)
                                                                            {ville="oujda";
                                                                            menu1=1;
                                                                            ville_pre=11;goto A;
                                                                            break;}
                                                                        if (45<event.button.x&&event.button.x<330&&596<event.button.y&&event.button.y<671)
                                                                            {ville="rabat";
                                                                            menu1=1;
                                                                            ville_pre=12;goto A;
                                                                            break;}
                                                                        if (370<event.button.x&&event.button.x<650&&596<event.button.y&&event.button.y<671)
                                                                            {ville="tanger";
                                                                            menu1=1;
                                                                            ville_pre=13;goto A;
                                                                            break;}
                                                                        if (695<event.button.x&&event.button.x<970&&596<event.button.y&&event.button.y<671)
                                                                            {ville="tetouan";
                                                                            menu1=1;
                                                                            ville_pre=14;goto A;
                                                                            break;}
                                                                        if (1020<event.button.x&&event.button.x<1290&&596<event.button.y&&event.button.y<671)
                                                                            {ville="taroudant";
                                                                            menu1=1;
                                                                            ville_pre=15;goto A;
                                                                            break;}


                                                                    }


                                                                }

                                                        }
                                                    }

                                                }
                                            if (566<event.button.x&&event.button.x<872&&438<event.button.y&&event.button.y<522)
                                                {
                                                    Mix_PlayChannel(1, son, 0);
                                                    imageDeFond = IMG_Load("images/Maroc5.jpg");
                                                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                                    SDL_Flip(ecran);
                                                    SDL_Event event;
                                                    char* villes;
                                                    while (continuer)
                                                    {

                                                        SDL_WaitEvent(&event);
                                                        switch(event.type)
                                                        {
                                                            imageDeFond = IMG_Load("images/Maroc5.jpg");
                                                            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                                            case SDL_QUIT:
                                                                continuer = 0;
                                                                break;
                                                            case SDL_MOUSEBUTTONDOWN:
                                                                        {if(460<event.button.x&&event.button.x<860&&610<event.button.y&&event.button.y<710)
                                                                                goto A;
                                                                        if(45<event.button.x&&event.button.x<330&&180<event.button.y&&event.button.y<255)
                                                                            {villes="agadir";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=0;
                                                                            positionSapin.x = 100;
                                                                            positionSapin.y = 160;
                                                                            }
                                                                        if(370<event.button.x&&event.button.x<650&&180<event.button.y&&event.button.y<255)
                                                                            {villes="casa";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=1;
                                                                            positionSapin.x = 400;
                                                                            positionSapin.y = 160;
                                                                            }
                                                                        if(695<event.button.x&&event.button.x<970&&180<event.button.y&&event.button.y<255)
                                                                            {villes="dakhla";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=2;
                                                                            positionSapin.x = 700;
                                                                            positionSapin.y = 160;
                                                                            }
                                                                        if (1020<event.button.x&&event.button.x<1290&&180<event.button.y&&event.button.y<255)
                                                                            {villes="eljadida";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=3;
                                                                            positionSapin.x = 1000;
                                                                            positionSapin.y = 160;
                                                                            }
                                                                        if (45<event.button.x&&event.button.x<330&&292<event.button.y&&event.button.y<367)
                                                                            {villes="essaouira";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=4;
                                                                            positionSapin.x = 100;
                                                                            positionSapin.y = 290;
                                                                            }
                                                                        if (370<event.button.x&&event.button.x<650&&292<event.button.y&&event.button.y<367)
                                                                            {villes="fes";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=5;
                                                                            positionSapin.x = 400;
                                                                            positionSapin.y = 290;
                                                                            }
                                                                        if (695<event.button.x&&event.button.x<970&&292<event.button.y&&event.button.y<367)
                                                                            {villes="kenitra";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=6;
                                                                            positionSapin.x = 700;
                                                                            positionSapin.y = 290;
                                                                            }
                                                                        if (1020<event.button.x&&event.button.x<1290&&292<event.button.y&&event.button.y<367)
                                                                            {villes="laayoune";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=7;
                                                                            positionSapin.x = 1000;
                                                                            positionSapin.y = 290;
                                                                            }
                                                                        if (45<event.button.x&&event.button.x<330&&404<event.button.y&&event.button.y<479)
                                                                            {villes="marrakech";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=8;
                                                                            positionSapin.x = 100;
                                                                            positionSapin.y = 400;
                                                                            }
                                                                        if (370<event.button.x&&event.button.x<650&&404<event.button.y&&event.button.y<479)
                                                                            {villes="meknes";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=9;
                                                                            positionSapin.x = 400;
                                                                            positionSapin.y = 400;
                                                                            }
                                                                        if (695<event.button.x&&event.button.x<970&&404<event.button.y&&event.button.y<479)
                                                                            {villes="ouarzazate";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=10;
                                                                            positionSapin.x = 700;
                                                                            positionSapin.y = 400;
                                                                            }
                                                                        if (1020<event.button.x&&event.button.x<1290&&404<event.button.y&&event.button.y<479)
                                                                            {villes="oujda";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=11;
                                                                            positionSapin.x = 1000;
                                                                            positionSapin.y = 400;
                                                                            }
                                                                        if (45<event.button.x&&event.button.x<330&&516<event.button.y&&event.button.y<591)
                                                                            {villes="rabat";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=12;
                                                                            positionSapin.x = 100;
                                                                            positionSapin.y = 517;
                                                                            }
                                                                        if (370<event.button.x&&event.button.x<650&&516<event.button.y&&event.button.y<591)
                                                                            {villes="tanger";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=13;
                                                                            positionSapin.x = 400;
                                                                            positionSapin.y = 517;
                                                                            }
                                                                        if (695<event.button.x&&event.button.x<970&&516<event.button.y&&event.button.y<591)
                                                                            {villes="tetouan";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=14;
                                                                            positionSapin.x = 700;
                                                                            positionSapin.y = 517;
                                                                            }
                                                                        if (1020<event.button.x&&event.button.x<1290&&516<event.button.y&&event.button.y<591)
                                                                            {villes="taroudant";
                                                                            menu2=1;
                                                                            len+=1;
                                                                            Aide[len-1]=15;
                                                                            positionSapin.x = 1000;
                                                                            positionSapin.y = 517;
                                                                            }
                                                                        }




                                                        Mix_PlayChannel(1, son, 0);

                                                        sapin = IMG_Load("images/done1.png");
                                                        SDL_BlitSurface(sapin, NULL, ecran, &positionSapin);
                                                        SDL_Flip(ecran);
                                                        }
                                                }
                                                }
                                            if(566<event.button.x&&event.button.x<872&&554<event.button.y&&event.button.y<640)
                                                {
                                                    if (menu1!=1 || menu2!=1)
                                                    {
                                                        Mix_PlayChannel(1, son2, 0);
                                                        imageDeFond = IMG_Load("images/Maroc6.jpg");
                                                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                                        SDL_Flip(ecran);
                                                        SDL_Event event;
                                                        while (continuer)
                                                        {
                                                            SDL_WaitEvent(&event);
                                                            switch(event.type)
                                                            {
                                                                case SDL_QUIT:
                                                                    continuer = 0;
                                                                     break;
                                                                case SDL_MOUSEBUTTONDOWN:
                                                                    goto A;

                                                            }

                                                        }
                                                    }
                                                    else
                                                    {
                                                        positionSapin.x = 30;
                                                        positionSapin.y = 200;
                                                        Mix_PlayChannel(1, son, 0);
                                                        imageDeFond = IMG_Load("images/Maroc7.jpg");
                                                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                                        SDL_Flip(ecran);
                                                        SDL_Event event;
                                                        /*int liste_ville[len];
                                                        for (int r=0;r<len;r++) liste_ville[r]=Aide[r];
                                                        SAYS(liste_ville);*/
                                                        while (continuer)
                                                        {
                                                            SDL_WaitEvent(&event);
                                                            switch(event.type)
                                                            {
                                                                case SDL_QUIT:
                                                                    {continuer = 0;
                                                                     break;}
                                                                case SDL_KEYDOWN:
                                                                    {
                                                                      Mix_PlayChannel(1, son, 0);
                                                                      imageDeFond = IMG_Load("images/Maroc8.jpg");
                                                                      SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

                                                                      /*agadir = IMG_Load("images/0.jpg");
                                                                      SDL_BlitSurface(agadir, NULL, ecran, &positionSapin);*/

                                                                      int liste_ville[len];
                                                                      for (int r=0;r<len;r++)
                                                                      {
                                                                          if(Aide[r]!=ville_pre) liste_ville[r]=Aide[r];
                                                                      }
                                                                      SAYS(liste_ville);

                                                                      for (int r=0;r<len+2;r++)
                                                                      {

                                                                          if(positionSapin.x > 1000)
                                                                          {positionSapin.x = 30;positionSapin.y+=120;}

                                                                          if(CHE_opt[r]==0)
                                                                          {
                                                                            agadir = IMG_Load("images/0.png");
                                                                            SDL_BlitSurface(agadir, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==1)
                                                                          {
                                                                            casa = IMG_Load("images/1.png");
                                                                            SDL_BlitSurface(casa, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==2)
                                                                          {
                                                                            dakhla = IMG_Load("images/2.png");
                                                                            SDL_BlitSurface(dakhla, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==3)
                                                                          {
                                                                            eljadida = IMG_Load("images/3.png");
                                                                            SDL_BlitSurface(eljadida, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==4)
                                                                          {
                                                                            essaouira = IMG_Load("images/4.png");
                                                                            SDL_BlitSurface(essaouira, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==5)
                                                                          {
                                                                            fes = IMG_Load("images/5.png");
                                                                            SDL_BlitSurface(fes, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==6)
                                                                          {
                                                                            kenitra = IMG_Load("images/6.png");
                                                                            SDL_BlitSurface(kenitra, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==7)
                                                                          {
                                                                            laayoune = IMG_Load("images/7.png");
                                                                            SDL_BlitSurface(laayoune, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==8)
                                                                          {
                                                                            marrakech = IMG_Load("images/8.png");
                                                                            SDL_BlitSurface(marrakech, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==9)
                                                                          {
                                                                            meknes = IMG_Load("images/9.png");
                                                                            SDL_BlitSurface(meknes, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==10)
                                                                          {
                                                                            ouarzazate = IMG_Load("images/10.png");
                                                                            SDL_BlitSurface(ouarzazate, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==11)
                                                                          {
                                                                            oujda = IMG_Load("images/11.png");
                                                                            SDL_BlitSurface(oujda, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==12)
                                                                          {
                                                                            rabat = IMG_Load("images/12.png");
                                                                            SDL_BlitSurface(rabat, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==13)
                                                                          {
                                                                            tanger = IMG_Load("images/13.png");
                                                                            SDL_BlitSurface(tanger, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==14)
                                                                          {
                                                                            tetouan = IMG_Load("images/15.png");
                                                                            SDL_BlitSurface(tetouan, NULL, ecran, &positionSapin);
                                                                          }
                                                                          if(CHE_opt[r]==15)
                                                                          {
                                                                            taroudant = IMG_Load("images/14.png");
                                                                            SDL_BlitSurface(taroudant, NULL, ecran, &positionSapin);
                                                                          }

                                                                          positionSapin.x+=320;
                                                                      }
                                                                      if(len<6)
                                                                      {positionFleche.x = 320;
                                                                      positionFleche.y = 200;
                                                                      for (int r=0;r<len+1;r++)
                                                                      {
                                                                         fleche = IMG_Load("images/17.png");
                                                                         SDL_BlitSurface(fleche, NULL, ecran, &positionFleche);
                                                                         positionFleche.x+=320;
                                                                         if(positionFleche.x>970){positionFleche.x=20;positionFleche.y+=120;}
                                                                      }}
                                                                      SDL_Flip(ecran);
                                                                      SDL_Event event;
                                                                      while (continuer)
                                                                      {
                                                                          SDL_WaitEvent(&event);
                                                                          switch(event.type)
                                                                          {
                                                                              case SDL_QUIT:
                                                                                    {continuer = 0;
                                                                                    break;}
                                                                              case SDL_MOUSEBUTTONDOWN:
                                                                                     if (10<event.button.x&&event.button.x<190&&30<event.button.y&&event.button.y<170)
                                                                                        {
                                                                                                Mix_PlayChannel(1, son2, 0);
                                                                                                menu1=0,menu2=0;
                                                                                                CHE_opt=NULL;
                                                                                                len=0;
                                                                                                for(int i=0;i<20;i++)
                                                                                                     Aide[i]=-1;
                                                                                                for(int i=0;i<16;i++)
                                                                                                    liste_ville_visitee[i]=-1;
                                                                                                continuer = 0;
                                                                                                //goto H;
                                                                                        }
                                                                          }

                                                                      }


                                                                    }
                                                                     //goto H;
                                                                     //says
                                                            }

                                                        }
                                                    }
                                                }
                                }



                                }
                            }
                            }
                    }

                }
                }
        }




    }

    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(sapin);
    SDL_FreeSurface(fleche);
    SDL_FreeSurface(agadir);
    SDL_FreeSurface(dakhla);
    SDL_FreeSurface(casa);
    SDL_FreeSurface(eljadida);
    SDL_FreeSurface(essaouira);
    SDL_FreeSurface(fes);
    SDL_FreeSurface(kenitra);
    SDL_FreeSurface(laayoune);
    SDL_FreeSurface(marrakech);
    SDL_FreeSurface(meknes);
    SDL_FreeSurface(ouarzazate);
    SDL_FreeSurface(oujda);
    SDL_FreeSurface(rabat);
    SDL_FreeSurface(tanger);
    SDL_FreeSurface(taroudant);
    SDL_FreeSurface(tetouan);
    Mix_FreeChunk(son);//Libération du son 1
    Mix_FreeChunk(son2);//Libération du son 1
    Mix_CloseAudio(); //Fermeture de l'API
    SDL_Quit();
    return EXIT_SUCCESS;

}

