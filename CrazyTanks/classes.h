class GameObject
{
protected:
  int x,y;

public:
  void setX(int X)
  {
    x=X;
  }
  void setY(int Y)
  {
    y=Y;
  }

  int getX()
  {
    return x;
  }
  int getY()
  {
    return y;
  }

};
class Tank: public GameObject
{
protected:
  bool alive;
  int HP,direction;

  public:

  bool getAlive()
  {
    return alive;
  }
  void setAlive(int al)
  {
    alive=al;
  }

 int getHP()
  {
    return HP;
  }
  void setHP(int hp)
  {
    HP=hp;
  }

  int getDir()
   {
     return direction;
   }
   void setDir(int dir)
   {
     direction=dir;
   }

};

class Player: public Tank
{
  bool move;
  int viev[4];

public:
Player()
{
  alive=1;
  move=0;
  HP=3;
  direction=0;
  x=18;
  y=18;//
  viev[0]=202;
  viev[1]=185;
  viev[2]=204;
  viev[3]=203;
}

bool getMove()
 {
   return move;
 }
 void setMove(bool mv)
 {
   move=mv;
 }


 int getViev(int i)
  {
    return viev[i];
  }


};

class Enemy : public Tank
{

  int move_count;
  int  viev[5];

public:
  Enemy()
  {
    alive=1;
    HP=1;
    viev[0]=193;
    viev[1]=180;
    viev[2]=195;
    viev[3]=194;
  }


  int getMove()
   {
     return move_count;
   }
   void setMove(int mv)
   {
     move_count=mv;
   }


   int getViev(int i)
    {
      return viev[i];
    }
  };


class Wall: public GameObject
{

  int viev[2];
  bool turn;


public:
Wall()
{
  viev[0]=178;
  viev[1]=177;
}

  int getViev(int i)
   {
     return viev[i];
   }

 bool getTurn()
   {
     return turn;
   }
 void setTurn(bool tr)
 {
  turn=tr;
 }

};


class Base: public GameObject
{

  int viev[3];
  int locx_tresure;
  int locy_tresure;

public:
Base()
{
  viev[0]=178;
  viev[1]=177;
  viev[2]=157;
  x=17;
  y=15;
  locx_tresure=x+1;
  locy_tresure=y;
}

  int getViev(int i)
   {
     return viev[i];
   }


  int getLocx()
   {
     return locx_tresure;
   }
   void setLocx(int mv)
   {
     locx_tresure=mv;
   }


   int getLocy()
    {
      return locy_tresure;
    }
    void setLocy(int mv)
    {
      locy_tresure=mv;
    }
};

class Bullet: public GameObject
{

  int time;
  int direction;

  public:


  int getTime()
   {
     return time;
   }
   void setTime(int mv)
   {
   time=mv;
   }


   int getDir()
    {
      return direction;
    }
    void setDir(int mv)
    {
      direction=mv;
    }

};

