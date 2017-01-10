
#include <ctime>
#include <graphics.h>
#include <iostream>
struct teava
{
    int pozitieX;
    int yDeSus;
};
void afisarePasare(int yy);
void updatePasare(int &yy, float &velocityy);
void updateTeava(int pozzX);
void afisareTeava(int pozzX, int pozzY);
void afisareMeniu();
void navigareMeniu(int &selectiee, int &pozitieSelectorr);
void ecranSfarsitJoc();
void afisarePasareMaiMica(int yy);
void verificaDacaMaiFaciOTeava(int &nrtevii,unsigned int &framecountt,teava ttevi[]);
void verificareDacaPrimaTeavaAIesitDePeEcran(int &nrtevii, teava ttevi[]);
int height=400;
int lenght=300;
int pasareAxaX=90;
float gravity=3.4;
int lift=-23;
float velocity=0;
unsigned int framecount=0;
int vitezaTevi=4;
teava tevi[2];
int intarziere=45;
