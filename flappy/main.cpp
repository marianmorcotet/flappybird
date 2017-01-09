#include "header.h"
void afisareMeniu()
{
    outtextxy(midx,midy,"FLAPPY BIRDS");
}
void updatePasare(int &y,float &velocity)
{
    if(GetAsyncKeyState( VK_UP ) & 0x8000 )velocity+=lift;
    velocity+=gravity;
    velocity*=0.8;
    y+=int(velocity);
    afisarePasare(y);
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
      afisareMeniu();
  }
