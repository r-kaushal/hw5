#include "Thing.h"
#include "ecs36b_Common.h"

Thing::Thing(Person owner, string description,string thingName, GPS_DD location)
{
  this->description = description;
  this->owner = owner;
  this->thingName = thingName;
  this->location = location;
}
Thing::Thing(string thingName)
{
  this->thingName = thingName;
}
Thing::Thing()
{
  this->thingName = "";
}
void Thing:: setOwner(Person p1){
  this->owner = p1;
}

void Thing:: setLocation(string location){
  this->location = GPS_DD(location);
}

void Thing:: setName(string Name){
  this->thingName = Name;
}

Json::Value Thing::dump2JSON()
{

  Json::Value result {};
  if(this->thingName!="")
    result["Thing Name"] = this->thingName;

  // Json::Value jv_result;
  // if(this->owner.name!=""){
  // jv_result = (this->owner).dump2JSON();
  // result["Owner"] = jv_result;
  // }
  
  // jv_result = (this->location).dump2JSON();
  // result["Location"] = jv_result;

  // std::cout << jv_result.toStyledString() << std::endl;

  return result;
}

void Thing:: JSON2Object(Json::Value jsonVal){
  this->setName((jsonVal["Thing Name"].asString()));
  // Json::Value temp = jsonVal["Owner"];
  // this->owner = Person(temp["Name"].asString());
  // this->location = GPS_DD(jsonVal["Location"].asString());
}
