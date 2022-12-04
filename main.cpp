#include "ecs36b_Common.h"
#include "Person.h"
#include "JvTime.h"
#include "GPS_DD.h"
#include "Thing.h"
#include "Record.h"
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/json.h>
#include "ecs36b_JSON.cpp"

int main(){
    // GPS_DD littleRedLocation("Litle Red Riding Hood's home");
    Person dearLittleGirl("Dear Little Girl");
    Person grandma("Grandma");
    Thing cap("Little Cap of Red Velvet");
    dearLittleGirl.setName("Little Red Riding Hood");
    Person mother("Mother");
    Thing cake("piece of cake");
    Thing wine("bottle of wine");
    // make an object for "take them to your grandmother"

    // Setting up Grandma's location:
    GPS_DD grandma_location("Right Outside the wood");
    grandma.setLocation(grandma_location);

    // Setting up location of where Little Red Riding hood met the wolf
    GPS_DD meetup_location("Entrance of Woods");
    Person wolf("Wolf");
    wolf.setLocation(meetup_location);
    dearLittleGirl.setLocation(meetup_location);


    Thing tree1("Large Oak Tree 1"); tree1.setLocation("The Woods");
    Thing tree2("Large Oak Tree 2"); tree2.setLocation("The Woods");
    Thing tree3("Large Oak Tree 3"); tree3.setLocation("The Woods");

    char * tempTime = "2000-01-01T12:00:00+0000";

    Record r1(dearLittleGirl,cap);
    r1.setEventDescription("Little Red Riding Hood wore the cap");
    r1.setTime(tempTime);
    r1.setLocation("Home");

    tempTime = "2000-01-01T13:00:00+0000";
    Record r2(mother, dearLittleGirl, cake,wine);
    cake.setOwner(dearLittleGirl);
    r2.setEventDescription("Her mom gave her the cake and wine");
    r2.setTime(tempTime);
    r2.setLocation("Home");

    tempTime = "2000-01-01T14:00:00+0000";
    Record r3(dearLittleGirl,wolf,meetup_location);
    r3.setEventDescription("Little Red met the wolf at a particular spot in the wood");
    r3.setTime(tempTime);
    r3.setLocation("Forest");


    tempTime = "2000-01-01T15:00:00+0000";
    Record r4(grandma,grandma_location,tree1,tree2,tree3);

    r4.setTime(tempTime);
    r4.setLocation("Grandma's Home");
    r4.setEventDescription("Grandma was at her own home right outside of the wood and there were three large oak trees nearby");


      cout << "\n \n OLD DUMP2JSONS (HW2 BASICALLY) \n " << "-----------------------------------------------------------------------" << "\n" ;

    
     cout << r1.dump2JSON() << "\n" << "-----------------------------------------------------------------------" << "\n" ;
     cout << r2.dump2JSON() << "\n" << "-----------------------------------------------------------------------" << "\n" ;
     cout << r3.dump2JSON() << "\n" << "-----------------------------------------------------------------------" << "\n" ;
     cout << r4.dump2JSON() << "\n" << "-----------------------------------------------------------------------" << "\n" ;
     





    cout << "\n \n NEW DUMP2JSONS, USING NEW FUNCTION JSON2OBJECT \n " << "-----------------------------------------------------------------------" << "\n" ;

    char event1JsonName[12] = "Event1.JSON";
    Json::Value event1  = r1.dump2JSON();
    myJSON2File(event1JsonName, &event1);
    Json::Value event1Read;
    myFile2JSON(event1JsonName,&event1Read);

    Record r1_NEW = Record();
    r1_NEW.JSON2Object(event1Read);
    cout << r1_NEW.dump2JSON();

    cout << "\n" << "-----------------------------------------------------------------------" << "\n" ;

    char event2JsonName[12] = "Event2.JSON";
    Json::Value event2  = r2.dump2JSON();
    myJSON2File(event2JsonName, &event2);
    Json::Value event2Read;
    myFile2JSON(event2JsonName,&event2Read);

    Record r2_NEW = Record();
    r2_NEW.JSON2Object(event2Read);
    cout << r2_NEW.dump2JSON();

    cout << "\n" << "-----------------------------------------------------------------------" << "\n" ;

    char event3JsonName[12] = "Event3.JSON";
    Json::Value event3  = r3.dump2JSON();
    myJSON2File(event3JsonName, &event3);
    Json::Value event3Read;
    myFile2JSON(event3JsonName,&event3Read);

    Record r3_NEW = Record();
    r3_NEW.JSON2Object(event3Read);
    cout << r3_NEW.dump2JSON();


    cout << "\n" << "-----------------------------------------------------------------------" << "\n" ;

    char event4JsonName[12] = "Event4.JSON";
    Json::Value event4  = r4.dump2JSON();
    myJSON2File(event4JsonName, &event4);
    Json::Value event4Read;
    myFile2JSON(event4JsonName,&event4Read);

    Record r4_NEW = Record();
    r4_NEW.JSON2Object(event4Read);
    cout << r4_NEW.dump2JSON();

    cout << "\n" << "-----------------------------------------------------------------------" << "\n" ;





    return 0;


}