// https://www.hackerrank.com/challenges/rectangle-area/

#include <iostream>
using namespace std;

/*
 * Create classes Rectangle and RectangleArea
 */
 
// Enter your code here.
// --------------------------------------------------------- //
class Rectangle 
{
public:
    void display()
    {
        cout << width << " " << height << endl;
    }
    int width, height;
};

class RectangleArea : public Rectangle
{
public:
    void display()
    {
        cout << width * height << endl;
    }
    void read_input()
    {
        cin >> width >> height;
    }
};
// --------------------------------------------------------- //

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}