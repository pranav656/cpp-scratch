
/*
Adapter Design Pattern (Structural design pattern):
Typically used for data conversions. When two classes have to
interact with each other and the data formats are not compatible
adapter can be used to make them compatible with each other.

Let's say one class operates in 2-D and the other interface acts
 in 3-D and they have to interact with each other. In such cases,
adapeter can be used to convert the 2-D interaction into a 3D interaction
compatible with the other class

*/
#include <bits/stdc++.h>

using namespace std;

typedef enum {US, GERMAN} ChargeType;

class IndianPlug
{
   public:
      virtual void indian_charge(ChargeType type) = 0;
};

class USAPlug
{
   public:
      void us_charge()
      {
          cout<<"Charging on US socket"<<endl;
      }
};

class GermanPlug
{
   public:
      void german_charge()
      {
          cout<<"Charging on German socket"<<endl;
      }
};

class Adapter : public IndianPlug, USAPlug, GermanPlug
{
   public:
      void indian_charge(ChargeType type)
      {
          if(type == ChargeType::US)
          {
              us_charge();
          }
          else if (type == ChargeType::GERMAN)
          {
              german_charge();
          }
      }
};

int main()
{
   unique_ptr<IndianPlug> plugAdapter = make_unique<Adapter>();
   plugAdapter->indian_charge(ChargeType::US);
   plugAdapter->indian_charge(ChargeType::GERMAN); 
   return 0;
}