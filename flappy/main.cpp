#include "header.h"

void godMode(int x, int y)
{
    setfillstyle(SOLID_FILL,YELLOW);
    bar(x,y,x+10,y+10);
}
void speedTime(int x, int y)
{
    setfillstyle(SOLID_FILL,RED);
    bar(x,y,x+10,y+10);
}
void slowTime(int x, int y)
{
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(x,y,x+10,y+10);
}
void afisarePauza()
{
    settextstyle(GOTHIC_FONT,0,2);
    outtextxy(100,60,"PAUZA");
    outtextxy(10,90,"Esc pentru a reveni.");
}
void afisareInstructiuni(bool &afisareinstructiuni)
{
    settextstyle(DEFAULT_FONT,0,2);
    outtextxy(1,50,"Apasa usor space");
    outtextxy(1,70,"pentru a sari si");
    outtextxy(1,90,"tine apasat pentru");
    outtextxy(1,110,"a sari mai tare.");
    outtextxy(1,160,"Exista 3 power-up-uri");
    outtextxy(1,180,"GodMode,SpeedTime si");
    outtextxy(1,200,"SlowTime, cred ca e ");
    outtextxy(1,220,"evident ce fac.");
    outtextxy(1,260,"Esc in timpul jocului");
    outtextxy(1,280,"pentru pauza.");
    outtextxy(1,320,"Apasa escape atunci");
    outtextxy(1,340,"cand esti gata.");
    if((GetAsyncKeyState(VK_ESCAPE) & 0x8000))
    {
       afisareinstructiuni=0;
       selectie=0;
       pozitieSelector=95;
       cleardevice();
    }
    delay(70);
    cleardevice();
}
void afisareBackground()
{
    setfillstyle(SOLID_FILL,BROWN);
    bar(0,268,300,400);
    setfillstyle(SOLID_FILL,CYAN);
    bar(0,0,300,268);
}
void tipNor0(int x, int y)
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(x,y,x+40,y+30);
    bar(x+20,y,x+30,y-6);
    bar(x-6,y+3,x,y+14);
}
void tipNor1(int x, int y)
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(x,y,x+30,y+20);
    bar(x+27,y+17,x+38,y+27);
    bar(x+13,y-6,x+20,y);
}
void tipNor2(int x, int y)
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(x,y,x+36,y+27);
    bar(x-9,y-6,x+3,y+3);
    bar(x+10,y-5,x+18,y);
    bar(x+30,y+27,x+40,y+33);
}
void tipNor3(int x,int y)
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(x,y,x+26,y+24);
    bar(x+21,y+21,x+28,y+28);
    bar(x+6,y-6,x+18,y);
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
    if((GetAsyncKeyState( VK_DOWN ) & 0x8000)&& pozitieSelector<155)
    {
        Beep(333,200);
        pozitieSelector+=20;
    }
    if((GetAsyncKeyState(VK_UP) & 0x8000)&&pozitieSelector>95)
    {
        Beep(333,200);
        pozitieSelector-=20;
    }
    if(GetAsyncKeyState(VK_SPACE) & 0x8000){Beep(333,200);
        if(pozitieSelector==95)selectie=1;
           else if(pozitieSelector==115)selectie=2;
                   else if(pozitieSelector==135)selectie=3;
                           else selectie=4;}
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
    outtextxy(24,130,"3.HighScore");
    outtextxy(23,150,"4.Iesi");
    settextstyle(DEFAULT_FONT,0,2);
    outtextxy(10,190,"Apasa sus/jos pentru");
    outtextxy(34,210,"a naviga si space");
    outtextxy(39,230,"pentru a selecta.");

}
void updatePasare(int &y,float &velocity,bool &caca)
{
    if(GetKeyState( VK_SPACE ) & 0x8000)velocity+=lift;
    velocity+=gravity;
    velocity*=0.6;
    y+=int(velocity);
    afisarePasare(y);
    if(y-10<=0){caca=0;Beep(777,500);}
    if(y+5>height){caca=0;Beep(777,500);}
    //check coliziune
    if((pasareAxaX>tevi[0].pozitieX-9 || pasareAxaX+20>tevi[0].pozitieX)&&(pasareAxaX<tevi[0].pozitieX+30 || pasareAxaX+20<tevi[0].pozitieX+30))
        if(y-10<tevi[0].yDeSus || y+5>tevi[0].yDeSus+70){caca=0;Beep(777,500);delay(300);}
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
void afisarePowerUp(powerup as)
{
    if(as.tip==0)godMode(as.x,as.y);
       else if(as.tip==1)slowTime(as.x,as.y);
               else if(as.tip==2)speedTime(as.x,as.y);
}

  int main()
  {
      initwindow(lenght,height);
      std::ofstream f("highscore.txt");
      std::ifstream g("highscore.txt");


      meniu:
      srand(time(0));//seed random pt ca obstacolele sa fie cu adevarat random
      //calculeaza pozitia primelor 3 obstacole
      tevi[0].pozitieX=300;
      tevi[0].yDeSus=rand()%201+100;
      tevi[1].pozitieX=500;
      tevi[1].yDeSus=rand()%201+100;
      tevi[2].pozitieX=700;
      tevi[2].yDeSus=rand()%201+100;
      sansapowerup=0;
      if(sansapowerup==0)
      {
          jmeker.x=707;
          jmeker.tip=1;
          jmeker.y=tevi[2].yDeSus+35;
      }
      nori[0].pozitieX=80;
      nori[0].pozitieY=rand()%161;
      nori[0].viteza=rand()%5+1;
      nori[0].tip=rand()%4;
      nori[1].pozitieX=160;
      nori[1].pozitieY=rand()%161;;
      nori[1].viteza=rand()%5+1;
      nori[1].tip=rand()%4;
      nori[2].pozitieX=240;
      nori[2].pozitieY=rand()%161;
      nori[2].viteza=rand()%5+1;
      nori[2].tip=rand()%4;
      nori[3].pozitieX=320;
      nori[3].pozitieY=rand()%161;
      nori[3].viteza=rand()%5+1;
      nori[3].tip=rand()%4;
      nori[4].pozitieX=400;
      nori[4].pozitieY=rand()%161;
      nori[4].viteza=rand()%5+1;
      nori[4].tip=rand()%4;
      nori[5].pozitieX=480;
      nori[5].pozitieY=rand()%161;
      nori[5].viteza=rand()%5+1;
      nori[5].tip=rand()%4;
      afisareHighScore=1;
            selectie=0;
      while(selectie==0)
      {
          navigareMeniu(selectie,pozitieSelector);
      }
      if(selectie==1)goto startjoc;
         else if(selectie==2)goto instructiuni;
                 else if(selectie==3) goto highscore;
                         else goto iesire;



      highscore:
          g>>max1;
          while(g>>max2)
          {
              if(max2>max1)max1=max2;
          }
          f<<max1;
          max3[0]=max1+'0';
          settextstyle(DEFAULT_FONT,0,2);
          while(afisareHighScore)
          {
          outtextxy(1,100,"Cel mai Jmeker:");
          outtextxy(1,120,max3);
          if(GetKeyState(VK_ESCAPE) & 0x8000)afisareHighScore=0;
          }
          goto meniu;



      instructiuni:
          while(afisareinstructiuni)
          {
              afisareInstructiuni(afisareinstructiuni);
          }
          goto meniu;



      startjoc:
          score=0;
      while(pasareaEsteInViata)
      {
          afisareBackground();
          framecount++;
          //nori
          for(int j=0;j<6;j++)
          {
              if(nori[j].pozitieX<=-30)
              {
                for(int k=j;k<6;k++)
                {
                    nori[k]=nori[k+1];
                }
                nori[5].pozitieX=480;
                nori[5].pozitieY=rand()%161;
                nori[5].viteza=rand()%5+1;
                nori[5].tip=rand()%4;
              }
              if(nori[j].tip==0)tipNor0(nori[j].pozitieX,nori[j].pozitieY);
                 else if(nori[j].tip==1)tipNor1(nori[j].pozitieX,nori[j].pozitieY);
                         else if(nori[j].tip==2)tipNor2(nori[j].pozitieX,nori[j].pozitieY);
                                 else tipNor3(nori[j].pozitieX,nori[j].pozitieY);
              nori[j].pozitieX-=nori[j].viteza;
          }


          //power up
          if(framecount==140 || jmeker.x<0)
          {
              framecount=0;
              sansapowerup=rand()%6;
              if(sansapowerup==0)
              {
                jmeker.x=707;
                jmeker.y=tevi[2].yDeSus+35;
              }

          }
          jmeker.x-=jmeker.viteza;
          afisarePowerUp(jmeker);
          std::cout<<jmeker.x<<" "<<jmeker.y<<std::endl;


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
          if((GetAsyncKeyState(VK_ESCAPE) & 0x8000))
          {
              pauza=1;
              cleardevice();
              while (pauza)
              {
                  delay(80);
                  afisarePauza();
                  delay(100);
                  if((GetAsyncKeyState(VK_ESCAPE) & 0x8000))pauza=0;
              }
          }
          updatePasare(pozY,velocity,pasareaEsteInViata);


          //score
          if(tevi[0].pozitieX==90)score++;
          int i=0;
          int scr=score;
          if(score<=9)scorul[0]=score+'0';
            else
            {
                scorul[0]=score/10+'0';
                scorul[1]=score%10+'0';
            }
           settextstyle(DEFAULT_FONT,0,2);
           outtextxy(270,30,scorul);

           // gata score


          delay(intarziere);
          cleardevice();
        }
        f<<score<<" ";
          revenireLaMeniu=0;
      while(revenireLaMeniu==0)
      {
          ecranSfarsitJoc();
          settextstyle(DEFAULT_FONT,0,2);
          outtextxy(1,200,"Ai facut");
          outtextxy(130,200,scorul);

          if((GetAsyncKeyState(VK_ESCAPE) & 0x8000))
          {
              selectie=0;
              pasareaEsteInViata=1;
              revenireLaMeniu=1;
              cleardevice();
              pozY=200;
              velocity=0;
              afisareinstructiuni=1;
              afisareHighScore=1;
          }
      }
      goto meniu;
      iesire:
      return 0;
  }
