/* 

Strategy pattern (Behavioral):
Helps you to swap algorithms during run-time.

In this example, you use a levelling strategy (game use-case)

*/

#include<iostream>
using namespace std;

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual int attack(int base) = 0;
};

class Level1Strategy : public Strategy
{
public:
   int attack(int point) override
   {
       return point*2;
   }
};

class Level2Strategy : public Strategy
{
public:
   int attack(int point) override
   {
       return point*3;
   }
};

class Player 
{
   public: 
    Player(Strategy* s) {
        currentStrategy = s;
    }
    int attack(int point) {
        return currentStrategy->attack(point);
    }
   private:
      Strategy* currentStrategy;
};

int main()
{
  Level1Strategy l1;
  Level2Strategy l2;
  Player P1(&l1);
  cout<<P1.attack(10)<<endl;
  Player P2(&l2);
  cout<<P2.attack(10)<<endl;
}
