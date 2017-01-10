#include "header.h"
void afisareMeniu()
{

}
void updatePasare(int &y,float &velocity)
{
    if(GetAsyncKeyState( VK_UP ) & 0x8000 )velocity+=lift;
    velocity+=gravity;
    velocity*=0.6;
    y+=int(velocity);
    afisarePasare(y);
    if(height-y<=0)velocity=0;
    if(y>height)velocity=height;
}

void afisareTeava(int pozX, int pozY)
{
    bar(pozX,0,pozX+25,pozY);//25 grosimea tevii
    bar(pozX,pozY+60,pozX+25,height);//60 distanta intre tevi
}
void afisarePasare(int y)
{
     cleardevice();
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
      int nrtevi=0;
      int pozY=height/2;
      bool ok=1;
      while(ok)
      {
          if(nrtevi<3&&framecount==100)
          {
              tevi[nrtevi].pozitieX=300;
              tevi[nrtevi].yDeSus=rand()%381+20;
              nrtevi++;
              framecount-=100;
          }
          if(tevi[0].pozitieX<=-24)
          {
              for(int i=0;i<2;i++)
              {
                  tevi[i]=tevi[i+1];
              }
          }
          updatePasare(pozY,velocity);
          framecount++;
          delay(35);
      }
      return 0;
  }
