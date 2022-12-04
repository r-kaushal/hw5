#ifndef _PERSON_H_
#define _PERSON_H_

#include "ecs36b_Common.h"
 #include "GPS_DD.h"
#include "JvTime.h"

class Person{
    public:
    string name;
    GPS_DD homeLocation;
    GPS_DD currentLocation;
    Person(std::string, GPS_DD);
    Person();
    Person(string);
    JvTime since_when;
   void setName(string name); string getName();
   void setHome(GPS_DD); GPS_DD getHome();
   void setLocation(GPS_DD); GPS_DD getLocation();
   Json::Value dump2JSON();
   void JSON2Object(Json::Value);
    
};

#endif