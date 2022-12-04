#include "GPS_DD.h"

GPS_DD::GPS_DD(string name, string objectsNear, bool inWoods){
  this->locationName = name;
  this->objectsNear = objectsNear;
  this->inWoods = inWoods;
}
GPS_DD::GPS_DD(string name, bool inWoods){
  this->locationName = name;
  this->inWoods = inWoods;
}

GPS_DD::GPS_DD(){
  this->locationName = "Somewhere";
  this->objectsNear = "";
  this->inWoods = "";
}

GPS_DD::GPS_DD(string Name){
  this->locationName = Name;
}

void GPS_DD::setLocationName(string name){
  this->locationName = name;
}

/*
void GPS_DD::dump
(void)
{
  std::cout << "[GPS_DD] dump-begin" << std::endl;
  std::cout << "latitude       = " << this->latitude << std::endl;
  std::cout << "longitude      = " << this->longitude << std::endl;
  std::cout << "[GPS_DD] dump-end" << std::endl;
  return;
}
*/ 

Json::Value
GPS_DD::dump2JSON()
{
  Json::Value result;
  if (this->locationName != "")
  result["Location Name"] = this->locationName;
  return result;
}




