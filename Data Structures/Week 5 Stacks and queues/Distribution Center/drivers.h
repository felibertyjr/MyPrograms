#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include <iomanip>
using namespace std;
class drivers
{
private:
    struct dInfo
    {
        string driver;
        string currentLocation;
        int radius;
        string status;
        dInfo *next;

        dInfo(string driverIn, string currentLocationIn, int radiusIn, string statusIn = "No", dInfo *nextIn = NULL)
        {
            driver = driverIn;
            currentLocation = currentLocationIn;
            radius = radiusIn;
            status = statusIn;
            next = nextIn;
        }
    };

    dInfo *head;

public:
    bool exists;
    drivers(){head = NULL; exists = false;};
    ~drivers();
    void addDriver(string driverIn, string currentLocationIn, int radiusIn, string statusIn);
    void printDrivers();
    void noShowDrivers();
    void validDriver(string searchDriver);//Look into adding a function that searches and validates the drivers when they call in.
};
#endif // DRIVER_H
