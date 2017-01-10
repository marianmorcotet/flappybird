
#include <graphics.h>
#include <iostream>
struct teava
{
    int viteza=4;
    int pozitieX;
    int yDeSus;
};
void afisarePasare(int y);
void updatePasare(int &y, float &velocity);
void updateTeava(int pozX);
void afisareTeava(int pozX, int pozY);
void afisareMeniu();
int height=400;
int lenght=300;
int pasareAxaX=90;
float gravity=3.4;
int lift=-23;
float velocity=0;
unsigned int framecount=0;
teava tevi[2];
