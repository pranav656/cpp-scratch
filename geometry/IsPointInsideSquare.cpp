
#include <bits/stdc++.h>

using namespace std;

struct Coordinate
{
   double x, y;
};

double get_dot_product(Coordinate s1, Coordinate s2)
{
    double d = (s1.x * s2.x) + (s1.y * s2.y);
    return d;
}
// Based on approach here: https://math.stackexchange.com/questions/190111/how-to-check-if-a-point-is-inside-a-rectangle
void IsPointInsideSquare(Coordinate s1, Coordinate s2, Coordinate s3, Coordinate s4, Coordinate point)
{
   Coordinate  ab = {s1.x - s3.x, s1.y - s3.y};
   Coordinate  ad = {s1.x - s4.x, s1.y - s4.y}; 
   Coordinate  am = {s1.x - point.x, s1.y - point.y}; 
   double dot_am_ab = get_dot_product(am, ab);
   double dot_am_ad = get_dot_product(am, ad);
   double dot_ab_ab = get_dot_product(ab, ab); 
   double dot_ad_ad = get_dot_product(ad, ad);
   
   bool isPointInside = (dot_am_ab >= 0 && dot_am_ab <=  dot_ab_ab) && (dot_am_ad >= 0 && dot_am_ad <=  dot_ad_ad);
   cout<<isPointInside<<endl;
}

int main()
{
    Coordinate s1 = {0, 0}, s2 = {1, 1}, s3 = {1, 0}, s4 = {0, 1}, p = {1.1, 0.5};
    IsPointInsideSquare(s1, s2, s3, s4, p);
}
