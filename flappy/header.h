#include <string>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <graphics.h>
#include <iostream>
struct teava
{
    int pozitieX;
    int yDeSus;
};
struct nor
{
    int pozitieX;
    int pozitieY;
    int viteza=5;
    int tip;
};
struct powerup
{
    int x;
    int y;
    int tip;
    int viteza;
};
void afisarePowerUp(powerup asd);
void afisareInstructiuni(bool &afisare);
void afisarePasare(int yy);
void updatePasare(int &yy, float &velocityy);
void updateTeava(int pozzX);
void afisareTeava(int pozzX, int pozzY);
void afisareMeniu();
void navigareMeniu(int &selectiee, int &pozitieSelectorr);
void ecranSfarsitJoc();
void afisareScor(int xxxx, int yyy, char scc[]);
void afisarePasareMaiMica(int yy);
void calcuareScor(int pozteavaa,int &scc1,int &scc2,int &scc3,char sc[]);
void verificaDacaMaiFaciOTeava(int &nrtevii,unsigned int &framecountt,teava ttevi[]);
void verificareDacaPrimaTeavaAIesitDePeEcran(int &nrtevii, teava ttevi[]);
int height=400;
int lenght=300;
unsigned int score;
bool revenireLaMeniu;
int selectie=0;
int pozitieSelector=95;
int pozY=200;
bool pasareaEsteInViata=1;
int pasareAxaX=90;
float gravity=4.4;
int lift=-23;
float velocity=0;
unsigned int framecount=0;
int vitezaTevi=5;
teava tevi[2];
int intarziere=40;
bool oSinguraSaritura=0;
nor nori[5];
bool afisareinstructiuni=1;
bool pauza;
int sansapowerup;
powerup jmeker;
char scorul[10];
char scoorul[10];
int max1;
int max2;
char max3[1];
bool afisareHighScore=1;
