#include <iostream>
#include<conio.h>
#include<windows.h>
#include <time.h>
#include<classes.h>
using namespace std;

const int WIDTH = 30;
const int HEIGHT = 20;

char map[20][30];
int score;
clock_t t1;
Bullet bullet;
Bullet e_bullet[5];
Player player;
Enemy tanks[5];
Base base;
Wall wall[5];
Wall wall2[5];
int cycle=0;

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
void gold()
{
  map[base.getX()+1][base.getY()+1]=static_cast<char>(178);
   map[base.getX()][base.getY()+1]=static_cast<char>(178);
    map[base.getX()][base.getY()]=static_cast<char>(178);
     map[base.getX()][base.getY()-1]=static_cast<char>(178);
      map[base.getX()+1][base.getY()-1]=static_cast<char>(178);

      map[base.getLocx()][base.getLocy()]='$';

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

void hit(int z)//знищення ворожого танку
{
  tanks[z].setAlive(0);
  tanks[z].setX(-1);
  tanks[z].setY(-1);
  score++;
}

void wall_damage(int x,int y)//
{

 if(map[x][y]==static_cast<char>(178) && 1< x && y<WIDTH-1 && 1<y && x<HEIGHT-1)
    {

     map[x][y]='#';

   }
  else if(map[x][y]=='#')
    {
      map[x][y]=' ';
    }
  if(map[x][y]=='$')
   {
     player.setAlive(0);
   }

}

void shoot()//вистріл гравця
{
  bullet.setX(player.getX());
  bullet.setY(player.getY());
  bullet.setDir(player.getDir());
  bullet.setTime(1);
  switch (player.getDir())
  {
  case 2:

      for(int i=0;i<10;i++)
        {
          for(int z=0;z<5;z++)

            if(player.getX()==tanks[z].getX() && player.getY()-i==tanks[z].getY()  && tanks[z].getAlive())//
         {
          hit(z);
          break;
         }

          if(map[player.getX()][player.getY()-i]==static_cast<char>(178)||map[player.getX()][player.getY()-i]=='#')
            {
              wall_damage(player.getX(),player.getY()-i);
            break;
            }

          if(map[player.getX()][player.getY()-i]=='$')
            {
              player.setAlive(0);
            }

        }
          break;

  case 3:for(int i=0;i<10;i++)
        {
          for(int z=0;z<5;z++)

            if(player.getX()==tanks[z].getX() && player.getY()+i ==tanks[z].getY() && tanks[z].getAlive())
         {
           hit(z);
           break;
         }

          if(map[player.getX()][player.getY()+i]==static_cast<char>(178)||map[player.getX()][player.getY()+i]=='#')
            {
              wall_damage(player.getX(),player.getY()+i);
            break;
            }
          if(map[player.getX()][player.getY()+i]=='$')
            {
              player.setAlive(0);

            }

        }

          break;

  case 1:
      for(int i=0;i<10;i++)
              {
                for(int z=0;z<5;z++)

                  if(player.getX()-i==tanks[z].getX() && player.getY()==tanks[z].getY() && tanks[z].getAlive())//
               {
                 hit(z);
                 break;
               }

               if(map[player.getX()-i][player.getY()]==static_cast<char>(178)||map[player.getX()-i][player.getY()]=='#')
                 {
                   wall_damage(player.getX()-i,player.getY());
                 break;
                 }
               if(map[player.getX()-1][player.getY()]=='$')
                 {
                   player.setAlive(0);

                 }
              }
          break;

  case 4:
      for(int i=0;i<10;i++)
              {
                for(int z=0;z<5;z++)

                if(player.getX()+i==tanks[z].getX() &&player.getY()==tanks[z].getY() && tanks[z].getAlive())
               {
                 hit(z);
                 break;
               }

                if(map[player.getX()+i][player.getY()]==static_cast<char>(178)||map[player.getX()+i][player.getY()]=='#')
                  {
                    wall_damage(player.getX()+i,player.getY());
                  break;
                  }
                if(map[player.getX()+1][player.getY()]=='$')
                  {
                    player.setAlive(0);
                  }
              }
          break;
  }

}

void e_shoot_dir()//візуалізація пострілу противника
{

for(int z=0;z<5;z++)
  if(e_bullet[z].getTime()>0)
  {

  switch (e_bullet[z].getDir())
  {
  case 3:

      for(int i=0;i<5;i++)
        {
          if(map[e_bullet[z].getX()+i][e_bullet[z].getY()]==static_cast<char>(178)||map[e_bullet[z].getX()+i][e_bullet[z].getY()]=='#'||map[e_bullet[z].getX()+i][e_bullet[z].getY()]=='$')
            {
              wall_damage(e_bullet[z].getX()+i,e_bullet[z].getY());
            break;
            }

          if(map[e_bullet[z].getX()+i][e_bullet[z].getY()]==' ')
          map[e_bullet[z].getX()+i][e_bullet[z].getY()]=static_cast<char>(120);

        }

          break;

  case 0:
      for(int i=0;i<5;i++)
        {
          if(map[e_bullet[z].getX()-i][e_bullet[z].getY()]==static_cast<char>(178)|| map[e_bullet[z].getX()-i][e_bullet[z].getY()]=='#'||map[e_bullet[z].getX()-i][e_bullet[z].getY()]=='$')
            {
              wall_damage(e_bullet[z].getX()-i,e_bullet[z].getY());
            break;
            }

          if(map[e_bullet[z].getX()-i][e_bullet[z].getY()]==' ')
         map[e_bullet[z].getX()-i][e_bullet[z].getY()]=static_cast<char>(120);

        }

          break;

  case 2:
      for(int i=0;i<5;i++)
        {
          if(map[e_bullet[z].getX()][e_bullet[z].getY()+i]==static_cast<char>(178) || map[e_bullet[z].getX()][e_bullet[z].getY()+i]=='#' ||map[e_bullet[z].getX()][e_bullet[z].getY()+i]=='$')
            {
              wall_damage(e_bullet[z].getX(),e_bullet[z].getY()+i);
            break;
            }


            if(map[e_bullet[z].getX()][e_bullet[z].getY()+i]==' ')
          map[e_bullet[z].getX()][e_bullet[z].getY()+i]=static_cast<char>(120);

        }

                 break;

  case 1:  for(int i=0;i<5;i++)
        {
          if(map[e_bullet[z].getX()][e_bullet[z].getY()-i]==static_cast<char>(178) || map[e_bullet[z].getX()][e_bullet[z].getY()-i]=='#'||map[e_bullet[z].getX()][e_bullet[z].getY()-i]=='$')
            {
              wall_damage(e_bullet[z].getX(),e_bullet[z].getY()-i);
            break;
            }

          if(map[e_bullet[z].getX()][e_bullet[z].getY()-i]==' ')
         map[e_bullet[z].getX()][e_bullet[z].getY()-i]=static_cast<char>(120);

        }

               break;
    }
  e_bullet[z].setTime(e_bullet[z].getTime()-1);
  }

}




void e_shoot(int z)//постріли противників
{
      e_bullet[z].setX(tanks[z].getX());
      e_bullet[z].setY(tanks[z].getY());
      e_bullet[z].setDir(tanks[z].getDir());
      e_bullet[z].setTime(1);

  switch (tanks[z].getDir())
  {
  case 3:
             for(int i=0;i<5;i++)
               {
               if(tanks[z].getX()+i==player.getX() &&tanks[z].getY()==player.getY())
                 {
                   player.setHP(player.getHP()-1);
                 }


               if(map[tanks[z].getX()+i][tanks[z].getY()]==static_cast<char>(178)||map[tanks[z].getX()+i][tanks[z].getY()]=='#')
                 break;
                }
          break;

  case 0:
      for(int i=0;i<5;i++)
        {
        if(tanks[z].getX()-i==player.getX() &&tanks[z].getY()==player.getY())
          {
            player.setHP(player.getHP()-1);
          }
 if(map[tanks[z].getX()-i][tanks[z].getY()]==static_cast<char>(178)||map[tanks[z].getX()-i][tanks[z].getY()]=='#')
           break;
         }

          break;

  case 2:
      for(int i=0;i<5;i++)
        {
        if(tanks[z].getX()==player.getX() &&tanks[z].getY()+i==player.getY())
          {
            player.setHP(player.getHP()-1);
          }

          if(map[tanks[z].getX()][tanks[z].getY()+1]==static_cast<char>(178)||map[tanks[z].getX()][tanks[z].getY()+1]=='#')
           break;
         }

                 break;

  case 1:        for(int i=0;i<5;i++)
        {
        if(tanks[z].getX()==player.getX() &&tanks[z].getY()-i==player.getY())
          {
            player.setHP(player.getHP()-1);
          }

          if(map[tanks[z].getX()][tanks[z].getY()-1]==static_cast<char>(178)||map[tanks[z].getX()][tanks[z].getY()-1]=='#')
           break;
         }

               break;
  }

}

void shoot_dir()//візуалізація пострілу
{
  if(bullet.getTime()>0)
    {
      switch (bullet.getDir())
      {
      case 2:
          for(int i=0;i<10;i++)
            {
              if(map[bullet.getX()][bullet.getY()-i]==static_cast<char>(178)||map[bullet.getX()][bullet.getY()-i]=='#'||map[bullet.getX()][bullet.getY()-i]=='$')
                break;

              map[bullet.getX()][bullet.getY()-i]=static_cast<char>(120);

            }

              break;

      case 3:for(int i=0;i<10;i++)
            {
              if(map[bullet.getX()][bullet.getY()+i]==static_cast<char>(178)||map[bullet.getX()][bullet.getY()+i]=='#'||map[bullet.getX()][bullet.getY()+i]=='$')
                break;

              map[bullet.getX()][bullet.getY()+i]=static_cast<char>(120);

            }

              break;

      case 1:
          for(int i=0;i<10;i++)
            {
              if(map[bullet.getX()-i][bullet.getY()]==static_cast<char>(178)||map[bullet.getX()-i][bullet.getY()]=='#'||map[bullet.getX()-1][bullet.getY()]=='$')
                break;

              map[bullet.getX()-i][bullet.getY()]=static_cast<char>(120);

            }

              break;

      case 4:
          for(int i=0;i<10;i++)
            {
              if(map[bullet.getX()+i][bullet.getY()]==static_cast<char>(178)||map[bullet.getX()+i][bullet.getY()]=='#'||map[bullet.getX()+i][bullet.getY()-i]=='$')
                break;

              map[bullet.getX()+i][bullet.getY()]=static_cast<char>(120);

            }

              break;
      }

  bullet.setTime(bullet.getTime()-1);
    }

}

void update()//оновлення ігрового поля
{
       for(int i=1;i<HEIGHT-1;i++)
         for(int j=1;j<WIDTH-1;j++)
        {

          if(i==player.getX() && j==player.getY())
             {
               if(player.getDir()!=0)
              map[i][j]=static_cast<char>(player.getViev(player.getDir()-1));//
               else
                 map[i][j]=static_cast<char>(player.getViev(0));//
             }
          else if(map[i][j]==static_cast<char>(178)||map[i][j]=='#'||map[i][j]=='$')//
            {

            continue;

            }

           else
             map[i][j]=' ';

            for(int z=0;z<5;z++)//розмічаємо ворогів
                if(tanks[z].getX()==i && tanks[z].getY()==j && tanks[z].getAlive())
                {
                   map[i][j]=tanks[z].getViev(tanks[z].getDir());//
                }

        }
       shoot_dir();
       e_shoot_dir();

}
void draw()//візуалізація ігрового поля
{
	system("cls");

	for(int i=0;i<HEIGHT;i++)
	  {
	  for(int j=0;j<WIDTH;j++)
	    {
	    cout<< map[i][j];
	    }
	  cout<<endl;
	  }

	cout << "SCORE:" << score << endl;
	cout<<"HP:"<<player.getHP()<<endl;
	clock_t t2=clock();
	cout << "Time: " << static_cast<double>((t2 - t1) / CLOCKS_PER_SEC )<< endl;//
}

void input()//введення з клавіатури
{
	if (_kbhit())
	  {
		switch (_getch())
		{
		case 72:
			if(player.getDir()==1)
			player.setMove(1);
			player.setDir(1);

			break;
		case 75:
			if(player.getDir()==2)
			player.setMove(1);
			player.setDir(2);

			break;
		case 80:
			if(player.getDir()==4)
			player.setMove(1);
			player.setDir(4);

			break;
		case 77:
			if(player.getDir()==3)
			player.setMove(1);
			player.setDir(3);

			break;
		  case 32: shoot();
			  break;

		}
	}

}

void logic()//переміщення гравця
{
	if(player.getMove()==1)
	switch (player.getDir())
	{

	case 2:
		if(map[player.getX()][player.getY()-1]==' ')
		player.setY(player.getY()-1);
		break;
	case 3:
		if(map[player.getX()][player.getY()+1]==' ')
		player.setY(player.getY()+1);
		break;
	case 1:
		if(map[player.getX()-1][player.getY()]==' ')
		player.setX(player.getX()-1);
		break;
	case 4:
		if(map[player.getX()+1][player.getY()]==' ')
		player.setX(player.getX()+1);
		break;
	default:
		break;
	}

	player.setMove(0);
}

void en_logic()//переміщення противників
{
if (cycle>10000)
    cycle=0;

    if(cycle%6==0)//швидкість ворогів
    for(int z=0;z<5;z++)
      {
    if(tanks[z].getMove()<1)
      {
        tanks[z].setDir(rand()%4);
         tanks[z].setMove(rand()%10+3);
         e_shoot(z);
      }
    else
      {
        switch(tanks[z].getDir())
          {

          case 3:{
                  if(map[tanks[z].getX()+1][tanks[z].getY()]==' ')
                    {
                   tanks[z].setX(tanks[z].getX()+1);
                    }
                  else
                    {
                      e_shoot(z);
                     tanks[z].setDir(rand()%4);

                    }

                  break;}

          case 0:{
            if(map[tanks[z].getX()-1][tanks[z].getY()]==' ')
              {
              tanks[z].setX(tanks[z].getX()-1);

              }
            else
              {
                e_shoot(z);
               tanks[z].setDir(rand()%4);

              }
                  break;}

          case 2:{
            if(map[tanks[z].getX()][tanks[z].getY()+1]==' ')
              {
             tanks[z].setY(tanks[z].getY()+1);
              }
            else
              {
                e_shoot(z);
               tanks[z].setDir(rand()%4);

              }
                  break;
            }

          case 1:{
            if(map[tanks[z].getX()][tanks[z].getY()-1]==' ')
              {
              tanks[z].setY(tanks[z].getY()-1);
              }
            else
              {
                e_shoot(z);
               tanks[z].setDir(rand()%4);
              }

                  break;}

          }

        tanks[z].setMove(tanks[z].getMove()-1);
      }
      }
    cycle++;
}


int main()
{
	srand(time(0));


	setup();
	t1 = clock();

	while (player.getAlive() && score<5)
	{
	    if(player.getHP()<1)
	      player.setAlive(0);

		update();
		draw();
		en_logic();
		input();
		logic();

		Sleep(40);
	}

	if (!player.getAlive())
	{	system("cls");
		cout << "GAME OVER ..!!" << endl;
		cout << "SCORE :" << score << endl;
		Sleep(5000);
	}

	if (score==5)
	{	system("cls");
		cout << "YOU WON!!!" << endl;
		cout << "SCORE : " << score << endl;
		Sleep(5000);
	}

    return 0;
}
