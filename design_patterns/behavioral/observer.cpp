
/*
Observer Design Pattern (Structural design pattern):
You have a subject that is being observed by a list of 
observers.

*/
#include <bits/stdc++.h>

using namespace std;

class Observer
{
   public:
      Observer(string _name) : o_name(_name)
      {}
      void OnNotify()
      {
          cout<<o_name<<" observer has been notified"<<endl;
      }
    private:
        string o_name;
};

class Subject
{
   public:
        void AddObserver(shared_ptr<Observer>& o)
        {
            observers.push_back(o);
        }
        void Notify()
        {
            for(auto& o: observers)
            {
                o->OnNotify();
            }
        }
    private:
        vector<shared_ptr<Observer>> observers;
};

int main()
{
   shared_ptr<Observer> o1 = make_shared<Observer>("observer1");
   shared_ptr<Observer> o2 = make_shared<Observer>("observer2");
   shared_ptr<Subject> s1 = make_shared<Subject>();
   s1.get()->AddObserver(o1);
   s1.get()->AddObserver(o2); 
   s1.get()->Notify();
   return 0;
}
