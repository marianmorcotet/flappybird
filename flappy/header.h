
#include <graphics.h>
#include <iostream>
#include <random>
int height=400;
int lenght=300;
int pasareAxaX=90;
float gravity=3.4;
int lift=-23;
float velocity=0;
void afisarePasare(int y);
void updatePasare(int &y, float &velocity);
void afisareMeniu();
unsigned int framecount=0;
int pozitieTevi[2];
int nrTevi=0;
int grosimeTevi=25;
int distantaIntreTevi=50;
int vitezaTevi=10;
