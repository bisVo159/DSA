#include<iostream>
using namespace std;

class Human{
   public:
   int height;
   int weight;
private:
int age;
   public:
   int getage(){
    return this->age;
   }
   void setweight(int w){
    this->weight=w;
   }
};

/*class Male:public Human{
      public:
      string color;

      void sleep(){
        cout<<"Male sleeping "<<endl;
      }
};*/

/*class Male:protected Human{
   public:
      string color;

      void sleep(){
        cout<<"Male sleeping "<<endl;
      }
     int getheight(){
      return this->height;
     }   
};*/
class Male:private Human{
   public:
      string color;

      void sleep(){
        cout<<"Male sleeping "<<endl;
      }
     int getheight(){
      return this->height;
     }   
};



int main(){
    // Public mode Inheritance
   /* Male obj1;
    cout<<obj1.age<<endl;
    cout<<obj1.weight<<endl;
    cout<<obj1.height<<endl;
    cout<<obj1.color<<endl;
    obj1.setweight(84);
    cout<<obj1.weight<<endl;
    obj1.sleep();*/

    //Protected mode inheritence
    /*Male m1;
   cout<<m1.getheight()<<endl;*/

   //Private mode inheritance
    Male m1;
   cout<< m1.getheight()<<endl;
    return 0;
}