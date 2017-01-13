#include "header.h"
void afisareBackground()
{
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    bar(0,268,300,400);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(0,0,300,268);
}
void tipNor0(int x, int y)
{
    setfillstyle(SOLID_FILL,CYAN);
    bar(x,y,x+40,y+30);
    bar(x+20,y,x+27,y-7);
    bar(x-7,y+7,x+7,y+14);
}
void tipNor1(int x, int y)
{
    setfillstyle(SOLID_FILL,CYAN);
    bar(x,y,x+30,y+20);
    bar(x+27,y+17,x+34,y+24);
}
void tipNor2(int x, int y)
{

}
void ecranSfarsitJoc()
{
    settextstyle(GOTHIC_FONT,0,2);
    outtextxy(70,120,"AI PIERDUT");
    settextstyle(GOTHIC_FONT,0,1);
    outtextxy(32,160,"Apasa tasta escape");
    outtextxy(62,180,"pentru a reveni.");
}
void navigareMeniu(int &selectie,int &pozitieSelector)
{
    afisareMeniu();
    afisarePasareMaiMica(pozitieSelector);
    if(GetAsyncKeyState( VK_DOWN ) & 0x8000)
    {
        if(pozitieSelector==95)pozitieSelector=115;
          else pozitieSelector=135;
    }
    if(GetAsyncKeyState(VK_UP) & 0x8000)
    {
        if(pozitieSelector==135)pozitieSelector=115;
          else pozitieSelector=95;
    }
    if(GetAsyncKeyState(VK_SPACE) & 0x8000)
        if(pozitieSelector==95)selectie=1;
           else if(pozitieSelector==115)selectie=2;
                   else selectie=3;
    delay(70);
    cleardevice();

}
void afisareMeniu()
{
    settextstyle(GOTHIC_FONT,0,2);
    outtextxy(46,60,"Flappy pasari");
    settextstyle(DEFAULT_FONT,0,2);
    outtextxy(24,90,"1.Start joc");
    outtextxy(24,110,"2.Instructiuni");
    outtextxy(24,130,"3.Iesi");
    settextstyle(DEFAULT_FONT,0,2);
    outtextxy(10,150,"Apasa sus/jos pentru");
    outtextxy(34,170,"a naviga si space");
    outtextxy(39,190,"pentru a selecta.");

}
void updatePasare(int &y,float &velocity,bool &caca)
{
    if(GetKeyState( VK_SPACE ) & 0x8000)velocity+=lift;
    velocity+=gravity;
    velocity*=0.6;
    y+=int(velocity);
    afisarePasare(y);
    if(y-10<=0)caca=0;
    if(y+5>height)caca=0;
    //check coliziune
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
void afisarePasareMaiMica(int y)
{
    setfillstyle(SOLID_FILL,YELLOW);
    bar(5,y-1,17,y+8);
    setfillstyle(SOLID_FILL,LIGHTRED);
    bar(17,y+2,20,y+4);
    setfillstyle(SOLID_FILL,BLUE);
    bar(12,y+2,14,y+4);
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
      meniu:
      srand(time(0));//seed random pt ca obstacolele sa fie cu adevarat random
      //calculeaza pozitia primelor 3 obstacole
      tevi[0].pozitieX=300;
      tevi[0].yDeSus=rand()%201+100;
      tevi[1].pozitieX=500;
      tevi[1].yDeSus=rand()%201+100;
      tevi[2].pozitieX=700;
      tevi[2].yDeSus=rand()%201+100;
      nori[0].pozitieX=100;
      nori[0].pozitieY=rand()%101;
      nori[0].viteza=rand()%6;
      nori[0].tip=rand()%4;
      nori[1].pozitieX=200;
      nori[1].pozitieY=rand()%101;;
      nori[1].viteza=rand()%6;
      nori[1].tip=rand()%4;
      nori[2].pozitieX=300;
      nori[2].pozitieY=rand()%101;
      nori[2].viteza=rand()%6;
      nori[2].tip=rand()%4;
      nori[3].pozitieX=400;
      nori[3].pozitieY=rand()%101;
      nori[3].viteza=rand()%6;
      nori[3].tip=rand()%4;
      while(selectie==0)
      {
          navigareMeniu(selectie,pozitieSelector);
      }
      if(selectie==1)goto startjoc;
         else if(selectie==2)goto instructiuni;
                 else goto iesire;
      instructiuni:
      //afisareInstructiuni();


      startjoc:
          score=0;
      while(pasareaEsteInViata)
      {
          afisareBackground();
          //nori
          for(int j=0;j<4;j++)
          {
              if(nor[j].pozitieX<=-30)
              {
                for(int k=j;k<3;k++)
                {
                    nori[k]=nori[k+1];
                }
                nori[3].pozitieX=400;
                nori[3].pozitieY=rand()%101;
                nori[3].viteza=rand()%6;
                nori[3].tip=rand()%4;
              }
              if(nori[j].tip==0)tipNor0(nori[j].pozitieX,nori[j].pozitieY);
                 else if(nori[j].tip==1)tipNor1(nori[j].pozitieX,nori[j].pozitieY);
                         else if(nori[j].tip==2)tipNor2(nori[j].pozitieX,nori[j].pozitieY);
                                 else tipNor3(nori[j].pozitieX,nori[j].pozitieY);
              nori[j].pozitieX-=nori[j].viteza;
          }
          //verificareDacaPrimaTeavaAIesitDePeEcran(nrtevi,tevi[]);
          if(tevi[0].pozitieX<=-30)
          {
              for(int i=0;i<2;i++)
              {
                  tevi[i]=tevi[i+1];
              }
              tevi[2].pozitieX=tevi[1].pozitieX+200;
              tevi[2].yDeSus=rand()%201+100;
          }
          for(int j=0;j<=2;j++)
          {
              tevi[j].pozitieX-=vitezaTevi;
              afisareTeava(tevi[j].pozitieX,tevi[j].yDeSus);
          }
          updatePasare(pozY,velocity,pasareaEsteInViata);
          delay(intarziere);
          cleardevice();
        }
      gameover:
          revenireLaMeniu=0;
      while(revenireLaMeniu==0)
      {
          ecranSfarsitJoc();
          delay(40);
          cleardevice();
          if((GetAsyncKeyState(VK_ESCAPE) & 0x8000))
          {
              selectie=0;
              pasareaEsteInViata=1;
              revenireLaMeniu=1;
              cleardevice();
              pozY=90;
              velocity=0;
          }
      }
      goto meniu;
      iesire:
      return 0;
  }
