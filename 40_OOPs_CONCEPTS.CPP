#include <iostream>
#include <string.h>
//#include"HERO.CPP"
using namespace std;
class Hero
{
  // properties
private:
  int health;

public:
  char *name;
  char level;
 static int timetocomplete;

  Hero()
  {
    cout << "Simple Constructor called" << endl;
    name = new char[100];
  }

  // Parameterised constructor

  Hero(int health)
  {
    cout << "this-> " << this << endl;
    this->health = health;
  }

  Hero(int health, char level)
  {
    this->level = level;
    this->health = health;
  }

  // Copy Constructor
  /*Hero(Hero& temp){
   cout<<"Copy constructor called"<<endl;
   this->health=temp.health;
   this->level=temp.level;
  }*/
  //Deep Copy
  Hero(Hero& temp){
    char *ch=new char[strlen(temp.name)+1];
    strcpy(ch,temp.name);
    this->name=ch;
   cout<<"Copy constructor called"<<endl;
   this->health=temp.health;
   this->level=temp.level;
  }

  void print()
  {
    cout << endl;
    cout << "[ Name: " << this->name << ", ";
    cout << "health: " << this->health << ", ";
    cout << "level: " << this->level << " ]" << endl;
  }

  int gethealth()
  {
    return health;
  }
  char getlevel()
  {
    return level;
  }
  void sethealth(int h)
  {
    health = h;
  }
  void setlevel(char ch)
  {
    level = ch;
  }
  void setname(char name[])
  {
    strcpy(this->name, name);
  }
  //Destructor
  ~Hero(){
    cout<<"Destructor bhi called "<<endl;
  }

  static int random(){
    return timetocomplete;
  }
};
int Hero::timetocomplete=5;

int main()
{
  //static keyword
 cout<<Hero::timetocomplete<<endl;
 cout<<Hero::random()<<endl;
  //Not necessary
  /*Hero a;
  cout<<a.timetocomplete<<endl;
  Hero b;
  b.timetocomplete=10;
  cout<<a.timetocomplete<<endl;
  cout<<b.timetocomplete<<endl;/

  // creation of object
  /* Hero ramesh;
   cout<<"sizeof ranesh "<<sizeof(ramesh)<<endl;
   cout<<"ramesh health is "<<ramesh.gethealth()<<endl;*/
  // use setter
  // ramesh.sethealth(70);
  // ramesh.health=70;
  //  ramesh.level='A';
  // cout<<"health is "<<ramesh.health<<endl;
  // cout<<"health is "<<ramesh.gethealth()<<endl;
  // cout<<"level is "<<ramesh.level<<endl;
  // cout<<"size : "<<sizeof(ramesh)<<endl;

  // Static allocation
  /* Hero a;
   a.sethealth(80);
   a.setlevel('B');
    cout<<"level is "<<a.level<<endl;
   cout<<"health is "<<a.gethealth()<<endl;
   //Dynamic memory allocation
   Hero* b=new Hero;
   b->setlevel('A');
   b->sethealth(70);
   cout<<"level is "<<(*b).level<<endl;
   cout<<"health is "<<(*b).gethealth()<<endl;

    cout<<"level is "<<b->level<<endl;
   cout<<"health is "<<b->gethealth()<<endl;*/

  // Object created statically
  /* Hero ramesh(10);
    cout<<"Address of ramesh "<<&ramesh<<endl;
  ramesh.print();
    //dynamically
   // Hero *h=new Hero;
    Hero *h=new Hero(11);
    h->print();

    Hero temp(22,'B');
    temp.print();*/

  // Copy constructor
  /*  Hero S(70,'C');
    S.print();

    Hero R(S);
     R.print();*/

  // Shallow copy
 /* Hero hero1;
  hero1.sethealth(12);
  hero1.setlevel('D');
  char name[7] = "Babbar";
  hero1.setname(name);
 // hero1.print();*/

//Shallow Copy
  // Use default copy constructor
   /*Hero hero2(hero1);
   //Hero hero2=hero1;
   hero2.print();
   hero1.name[0]='G';
   hero1.print();
   hero2.print();*/

   //Deep Copy
  /* Hero hero2(hero1);
   //hero2.print();
   hero1.name[0]='G';
   hero1.print();
   hero2.print();

   //Copy Assignment Operator
   hero1=hero2;
    hero1.print();
      hero2.print();*/

      //Destructor
      /*Hero a;
      Hero* b=new Hero;
      //manually destructor call
      delete b;*/

  return 0;
}