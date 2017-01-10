#include "header.h"
void afisareMeniu()
{

}
void updatePasare(int &y,float &velocity,bool &caca)
{
    if(GetAsyncKeyState( VK_UP ) & 0x8000 )velocity+=lift;
    velocity+=gravity;
    velocity*=0.6;
    y+=int(velocity);
    afisarePasare(y);
    if(y<=0)caca=0;
    if(y>height)caca=0;
}

void afisareTeava(int pozX, int pozY)
{
    bar(pozX,0,pozX+25,pozY);//25 grosimea tevii
    bar(pozX,pozY+70,pozX+25,height);//60 distanta intre tevi
}
void afisarePasare(int y)
{
     setfillstyle(SOLID_FILL,YELLOW);
     bar(pasareAxaX,y-10,pasareAxaX+20,y+5);
     setfillstyle(SOLID_FILL,LIGHTRED);
     bar(pasareAxaX+20,y-4,pasareAxaX+25,y);
     setfillstyle(SOLID_FILL,BLUE);
     bar(pasareAxaX+15,y-5,pasareAxaX+18,y-8);
}

  int main()
  {
      initwindow(lenght,height);
      int pozY=height/2;
      bool pasareaEsteInViata=1;
      tevi[0].pozitieX=300;
      tevi[0].yDeSus=rand()%361+40;
      tevi[1].pozitieX=500;
      tevi[1].yDeSus=rand()%361+40;
      tevi[2].pozitieX=700;
      tevi[2].yDeSus=rand()%361+40;
      while(pasareaEsteInViata)
      {
          //verificareDacaPrimaTeavaAIesitDePeEcran(nrtevi,tevi[]);
          if(tevi[0].pozitieX<=-24)
          {
              for(int i=0;i<2;i++)
              {
                  tevi[i]=tevi[i+1];
              }
              tevi[2].pozitieX=tevi[1].pozitieX+200;
              tevi[2].yDeSus=rand()%361+40;
          }
          std::cout<<framecount<<" ";
          for(int j=0;j<=2;j++)
          {
              tevi[j].pozitieX-=vitezaTevi;
              afisareTeava(tevi[j].pozitieX,tevi[j].yDeSus);
          }
          updatePasare(pozY,velocity,pasareaEsteInViata);
          framecount++;
          delay(35);
          cleardevice();
        }
      return 0;
  }
