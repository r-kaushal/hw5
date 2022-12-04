#ifndef _GPS_H_
#define _GPS_H_

#include "ecs36b_Common.h"

class GPS_DD
{
  public:
  string locationName = "somewhere";
  string objectsNear;
  bool inWoods;
  Json::Value dump2JSON();
  GPS_DD(string, string, bool);
  GPS_DD();
  GPS_DD(string);
  GPS_DD(string, bool);
  void setLocationName(string);
};

#endif /* _GPS_H_ */
