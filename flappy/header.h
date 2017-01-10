
#include <graphics.h>
#include <iostream>
struct teava
{
    int pozitieX;
    int yDeSus;
};
void afisarePasare(int y);
void updatePasare(int &y, float &velocity);
void updateTeava(int pozX);
void afisareTeava(int pozX, int pozY);
void afisareMeniu();
void verificaDacaMaiFaciOTeava(int &nrtevi,unsigned int &framecount,teava tevi[]);
void verificareDacaPrimaTeavaAIesitDePeEcran(int &nrtevi, teava tevi[]);
int height=400;
int lenght=300;
int pasareAxaX=90;
float gravity=3.4;
int lift=-23;
float velocity=0;
unsigned int framecount=0;
int vitezaTevi=4;
teava tevi[2];
