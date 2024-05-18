#include <iostream>
#include <complex>
#include <functional>

using namespace std;

template<typename T>
class Operator {
public:
    virtual T operate (T& a, T& b) = 0;
    virtual ~Operator() {}
};

template<typename T>
class Addition : public Operator<T>
{
public:
    T operate(T& a, T&b) override
    {
        return a + b;
    }
};

template<typename T>
class Subtraction : public Operator<T>
{
public:
    T operate(T& a, T&b) override
    {
        return a - b;
    }
};

template<typename T>
class Multiplication : public Operator<T>
{
public:
    T operate(T& a, T&b) override
    {
        return a * b;
    }
};

template<typename T>
class Division : public Operator<T>
{
public:
    T operate(T& a, T&b) override
    {
        if(b == 0) throw "Divide by 0";
        return a / b;
    }
};

int main()
{
    int choice;
    cout << "Choose data type (1. Integer, 2. Floating Point, 3. Complex): ";
    cin >> choice;
    if(choice == 1)
    {
        int num1, num2;
        cout << "Enter first number:" << endl;
        cin >> num1;
        char op;
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;
        cout << "Enter second number:" << endl;
        cin >> num2;
        Operator<int>* operation = nullptr;
        switch(op)
        {
            case '+' :
                operation = new Addition<int>();
                break;
            case '-' :
                operation = new Subtraction<int>();
                break;
            case '*':
                operation = new Multiplication<int>();
                break;
            case '/':
                operation = new Multiplication<int>();
                break;
            default:
                cout << "Invalid Operator!" << endl;
                return 1;
        }
        try
        {
            cout<<"Result: "<< operation->operate(num1, num2)<<endl;
        }
        catch(...)
        {
            cout<<"error"<<endl;        
        }
        
    }
    else if (choice == 2)
    {
     // Floating point types   
    }
    else if (choice == 3)
    {
    //complex types
    }
    else
    {
        
    }
    return 0;
}
