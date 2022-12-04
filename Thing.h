
#ifndef _THING_H_
#define _THING_H_

#include "ecs36b_Common.h"
#include "Person.h"
#include "JvTime.h"
 #include "GPS_DD.h"

class Thing
{
 
 public:
  string thingName;
  string description;
  Person owner;
  
  GPS_DD location;

  Thing();
  Thing(string);
  Thing(Person, string,string,GPS_DD);
  Json::Value dump2JSON(); 
  void setLocation(string);
  void setOwner(Person);
  void JSON2Object(Json::Value); 
  void setName(string);
};

#endif 
