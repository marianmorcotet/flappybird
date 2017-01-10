#include "header.h"
void ecranSfarsitJoc()
{
    settextstyle(GOTHIC_FONT,0,2);
    outtextxy(70,120,"AI PIERDUT");
    settextstyle(GOTHIC_FONT,0,1);
    outtextxy(36,160,"Apasa orice tasta");
    outtextxy(52,180,"pentru a reveni.");
}
void afisareMeniu()
{
    settextstyle(COMPLEX_FONT,0,2);
    outtextxy(46,60,1"Flappy pasari")
    settextstyle(DEFAULT_FONT,0,1);
    outtextxy(20,90,"1.Start joc");
    outtextxy(20,100,"2.Instructiuni");
}
void updatePasare(int &y,float &velocity,bool &caca)
{
    if(GetAsyncKeyState( VK_UP ) & 0x8000 )velocity+=lift;
    velocity+=gravity;
    velocity*=0.6;
    y+=int(velocity);
    afisarePasare(y);
    if(y-10<=0)caca=0;
    if(y+5>height)caca=0;
    if((pasareAxaX>tevi[0].pozitieX-5 || pasareAxaX+20>tevi[0].pozitieX)&&(pasareAxaX<tevi[0].pozitieX+30 || pasareAxaX+20<tevi[0].pozitieX+30))
        if(y-10<tevi[0].yDeSus || y+5>tevi[0].yDeSus+70)caca=0;
}

void afisareTeava(int pozX, int pozY)
{
    setfillstyle(SOLID_FILL,GREEN);
    bar(pozX,0,pozX+25,pozY-10);//25 grosimea tevii
    bar(pozX-5,pozY-10,pozX+30,pozY);
    bar(pozX-5,pozY+70,pozX+30,pozY+80);
    bar(pozX,pozY+80,pozX+25,height);//70 distanta intre tevi
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
      start:
      int pozY=height/2;
      bool pasareaEsteInViata=1;
      srand(time(0));
      tevi[0].pozitieX=300;
      tevi[0].yDeSus=rand()%201+100;
      tevi[1].pozitieX=500;
      tevi[1].yDeSus=rand()%201+100;
      tevi[2].pozitieX=700;
      tevi[2].yDeSus=rand()%201+100;
      std::cout<<tevi[0].yDeSus<<" "<<tevi[1].yDeSus<<" "<<tevi[2].yDeSus<<" ";
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
              tevi[2].yDeSus=rand()%201+100;
              std::cout<<tevi[2].yDeSus<<" ";
          }
          for(int j=0;j<=2;j++)
          {
              tevi[j].pozitieX-=vitezaTevi;
              afisareTeava(tevi[j].pozitieX,tevi[j].yDeSus);
          }
          updatePasare(pozY,velocity,pasareaEsteInViata);
          framecount++;
          delay(intarziere);
          cleardevice();
        }

      return 0;
  }
