#include <iostream>
#include<conio.h>
#include<windows.h>
#include <time.h>



void e_cord()
{
  //генерування  ворожих танків
         int n=5;
         for(int i=0;i<n;i++)
           {
             int x=rand() % (HEIGHT-10) + 2;
             int y=rand() % (WIDTH-2) + 2;

             if(map[x][y]==' ')
               {
             tanks[i].setX(x);
             tanks[i].setY(y);
             tanks[i].setDir(rand() % 4);
             map[x][y]=tanks[i].getViev(tanks[i].getDir());
               }
             else
               i--;
           }
}

void wall_cord()//генерація стін
{
        int n=5;
         for(int i=0;i<n;i++)//
           {
             int x=rand() % (HEIGHT-1) + 1;
             int y=rand() % (WIDTH-1) + 1;

             if(map[x][y]==' '&& map[x+1][y]==' '&& map[x-1][y]==' ' )
               {
                 wall[i].setX(x);
                 wall[i].setY(y);
                 wall[i].setTurn(0);
                 map[x][y]=static_cast<char>(wall[0].getViev(0));
                 map[x+1][y]=static_cast<char>(wall[0].getViev(0));
                 map[x-1][y]=static_cast<char>(wall[0].getViev(0));
               }

             else
               i--;
           }

         for(int i=0;i<n;i++)//
           {
             int x=rand() % (HEIGHT-1) + 1;
             int y=rand() % (WIDTH-1) + 1;

             if(map[x][y]==' '&& map[x][y+1]==' '&& map[x][y-1]==' ' )
               {
                 wall[i].setX(x);
                 wall[i].setY(y);
                 wall[i].setTurn(1);
                 map[x][y]=static_cast<char>(wall[0].getViev(0));
                 map[x][y+1]=static_cast<char>(wall[0].getViev(0));
                 map[x][y-1]=static_cast<char>(wall[0].getViev(0));
               }

             else
               i--;
           }
}

void setup()//генерація ігрового поля
{
	cout << "PRESS ARROWS  TO MOVE TANK AND SPACE TO SHOOT"<<endl;
	Sleep(2000);//

       for(int i=0;i<HEIGHT;i++)
         for(int j=0;j<WIDTH;j++)
        {
           if(i==0||j==0||i==HEIGHT-1||j==WIDTH-1)
          map[i][j]=static_cast<char>(178);

           else if(i==player.getX() && j==player.getY())
              map[i][j]=static_cast<char>(player.getViev(0));
           else
             map[i][j]=' ';

        }
       gold();
        wall_cord();
        e_cord();
        score = 0;
}
