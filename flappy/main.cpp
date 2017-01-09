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
void updateTeava(int pozX)
{
    pozX-=vitezaTevi;
    afisareTeava(pozX,)
    //http://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(20, 380); // define the range
    int rando=distr(eng);
}
void afisareTeava(int pozX, int pozY)
{
    bar(pozX,0,pozX+grosimeTevi,pozY);
    bar(pozX,pozY+distantaIntreTevi,pozX,height);
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
      int pozY=height/2;
      bool ok=1;
      while(ok)
      {
          updatePasare(pozY,velocity);
          framecount++;
          delay(35);
      }
      return 0;
  }
