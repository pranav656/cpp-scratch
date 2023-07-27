#include<bits/stdc++.h>

using namespace std;


// Decorator pattern extends the operators
// of an existing class, it basically
// decorates the existing class implementation
// Code examples taken from Handson Design patterns with
// C++

// Basic unit of a simple game
class Unit {
   public:
   Unit(double strength, double armor) : strength_(strength),
   armor_(armor) {}
   virtual bool hit(Unit& target) { return attack() > target.defense(); }
   virtual double attack() = 0;
   virtual double defense() = 0;

   protected:
   double strength_;
   double armor_;
};


// These are decorators around the basic 
// unit 
class Knight : public Unit {
   public:
   using Unit::Unit;
   double attack() { return strength_ + sword_bonus_; }
   double defense() { return armor_ + plate_bonus_;}

   protected:
   static constexpr double sword_bonus_ = 2;
   static constexpr double plate_bonus_ = 3;
};

class Ogre : public Unit {
   public:
   using Unit::Unit;
   double attack() {return strength_ + club_penalty_;}
   double defense() {
       return armor_ + leather_penalty_;}

   protected:
   static constexpr double club_penalty_ = -1;
   static constexpr double leather_penalty_ = -1;
};

// This class is templatized so that
// you can have special units specific to 
// each subtype (like special knight, special ogre)
// and also to prevent changes to unit every single 
// time you want to add a special kind of object
template <typename U>
class SpecialUnit : public U
{
   public:
   // transfer ownership via rvalue references
   SpecialUnit(U&& unit, double strength_bonus, double armor_bonus) : 
   U(unit), strength_bonus_(strength_bonus), armor_bonus_(armor_bonus)
   {}
   double attack() {return U::attack() + strength_bonus_;}
   double defense() {return U::defense() + armor_bonus_;}   
   private:
   double strength_bonus_;
   double armor_bonus_;
   
};

int main()
{
    Knight k1(5, 6);
    Ogre o1(1, 2);
    cout<<k1.hit(o1)<<endl; // Hit succesful
    SpecialUnit<Ogre> o2(move(o1), 7, 15); //Ogre evolves
    cout<<k1.hit(o2)<<endl; // Hit fail
    SpecialUnit<Knight> k2(move(k1), 15, 20); // Knight evolves
     cout<<k2.hit(o2)<<endl; // Hit success again
    
}
