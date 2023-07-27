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
   double defense() { return armor_ + leather_penalty_;}

   protected:
   static constexpr double club_penalty_ = -1;
   static constexpr double leather_penalty_ = -1;
};

// This class is templatized so that
// you can have special units specific to 
// each subtype (like special knight, special ogre)
template <typename U>
class SpecialUnit : public U
{
   public:
   SpecialUnit(U&& unit, double strength_bonus, double armor_bonus) : 
   U(unit), strength_bonus_(strength_bonus), armor_bonus_(armor_bonus)
   {}

   private:
   double strength_bonus_;
   double armor_bonus_;
   
};

int main()
{
    
}
