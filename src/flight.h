#ifndef FLIGHT_H
#define FLIGHT_H

#include "attribute_type.h"
#include <string>
#include <functional>
using namespace std;


union valueType
{
    int intValue;
    double doubleValue;
    string stringValue;
    // value() {memset(this, 0, sizeof(*this));}
};

struct
{
    enum attributeType type;
    union valueType value;
    // Filter() {memset(this, 0, sizeof(*this));}
} typedef Filter;

class Flight
{
    int dayMonth;
    int dayWeek;
    string carrier;
    int originId;
    int destId;
    int depDelay;
    int arrDelay;
    double distance;
    double flightTime;

public:
    Flight(int dayMonth, int dayWeek, string carrier, int originId, int destId, int depDelay, int arrDelay, double distance, double flightTime);
    Flight(double distance, double flightTime);

    int getDayMonth();
    int getDayWeek();
    string getCarrier();
    int getOriginId();
    int getDestId();
    int getDepDelay();
    int getArrDelay();
    double getDistance();
    double getFlightTime();

    // void *getGetter(string attribute);
    // static std::function<void *(Flight *)> getGetter(string attribute);
    static enum attributeType getAttributeType(string attribute);
    static std::function<int(Flight *)> getIntGetter(string attribute);
    static std::function<double(Flight *)> getDoubleGetter(string attribute);
    static std::function<string(Flight *)> getStringGetter(string attribute);

    string toString();

    string toCSV();
};

#endif