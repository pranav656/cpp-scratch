
/*
Factory Design Pattern:
A dedicated class to handle class creation

Points to note: return pointer not objects in the create factory method
*/
#include <bits/stdc++.h>

using namespace std;

class Shape
{
    public:
        virtual string getName() = 0;
};

class Triangle : public Shape
{
    public:
        string getName(){return "Triangle";}

};

class Square : public Shape
{
    public:
        string getName(){return "Square";}

};

class Circle : public Shape
{
    public:
        string getName(){return "Circle";}

};

enum Type {TRIANGLE, CIRCLE, SQUARE};

class Factory
{
   public:
      Shape* create(Type T)
      {
          switch(T)
          {
             case TRIANGLE: 
                 return new Triangle();
             case CIRCLE: 
                 return new Circle();
             case SQUARE: 
                 return new Square();
          }
      }
};

int main()
{
   vector<Shape*> shapes;
   Factory f;
   shapes.push_back(f.create(SQUARE));
   shapes.push_back(f.create(TRIANGLE)); 
   shapes.push_back(f.create(CIRCLE));  
   for (Shape* s : shapes)
   {
       cout<<s->getName()<<endl;
   }
   return 0;
}
