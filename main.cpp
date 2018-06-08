#include <iostream>
#include <iomanip>

using namespace std;
//Functions
void input_data(double &length, double &thickness);
void cable_tension(double length, double thickness);

int main()
{   //Variables
    double length, thickness;

    //Calling functions
    input_data(length, thickness);
    cable_tension(length, thickness);

    return 0;
}

//Input, calcualtion, and output functions
void input_data(double &length, double &thickness)
{
    cout << "Enter the lenght of the cable in feet: ";
    cin >> length;
    cout << "Enter the thickness of the cable up to 2.0 inches: ";
    cin >> thickness;

    while (length <= 0)
    {
        cout << "\nThis is not a valid cable length." << endl;
        cout << "Enter a cable length greater than 0: " << endl;
        cin >> length;
    }
    while (thickness <= 0 || thickness > 2.0)
    {
        cout << "\nThe cable thickness must be 2.0 inches or less." << endl;
        cout << "Enter a cable thickness less than 2.0: ";
        cin >> thickness;
    }
}
//function to do the stretching / breakage calc
void cable_tension(double length, double thickness)
{
    int pounds = 0;
    double stretch = thickness * .3;
    double breakage = length * 16 / 100;
    double maxLength = breakage + length;
    double newLength = length;

    while (newLength <= maxLength)
    {
        cout << "\nThe tension applied to the cable is: " << pounds << " lbs" << endl;
        cout << "The length of the cable is: " << newLength << " feet" << endl << endl;
        newLength = newLength + stretch;
        pounds++;
    }
    cout << fixed << setprecision(2);

    cout << "\nThe tension applied to the cable is: " << pounds << " lbs" << endl;
    cout << "The length of the cable is: " << newLength << " feet" << endl << endl;
    cout << "The cable broke!" << endl;
}
