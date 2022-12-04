
// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
 #include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
#include "Person.h"
#include "Thing.h"
#include <time.h>
#include "GPS_DD.h"
#include "hw5server.cpp"
#include "hw5client.h"


using namespace jsonrpc;
using namespace std;

int main(){

   HttpClient httpclient("http://127.0.0.1:7376");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv, filler;
  filler["Location"] = "Grandma's Home";

    HttpServer httpserver(7374);
 Myhw5Server s(httpserver,
JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)

    cout << " \n The following is data received from the Home Server. (Will show after running the Home Server)" << endl;

  while(!s.completed){
    s.StartListening();
  }
      s.StopListening();

  cout << " \n The following will be sent to the Grandma Home Server" << endl;
  for(auto i = s.Person_Map.begin(); i != s.Person_Map.end(); i++){

    try {
    myv = myClient.move("move", "Person",
			s.Person_Map[i->first]->dump2JSON(),
			filler,
			"dearlittleGirl");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myv.toStyledString() << endl; // this is printing out the transfer person's data under HomeServer when it is run
  
  }


  for(auto i = s.Thing_Map.begin(); i != s.Thing_Map.end(); i++){

    try {
    myv = myClient.move("move", "Thing",
			s.Thing_Map[i->first]->dump2JSON(),
			filler,
			"cap");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myv.toStyledString() << endl; // this is printing out the transfer thing's data under HomeServer when it is run
  
  }






return 0;
}

