
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
#include <jsonrpccpp/client/connectors/httpclient.h>



using namespace jsonrpc;
using namespace std;

int main(){

Person dearLittleGirl("Dear Little Girl");
dearLittleGirl.setName("Little Red Riding Hood");

Person mother("Mother");

Thing cap("Little Cap of Red Velvet");
Thing cake("piece of cake");
Thing wine("bottle of wine");

 HttpClient httpclient("http://127.0.0.1:7374");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv, filler;
  filler["Location"] = "Home!";
  
 // Moving Red Riding Hood 
  try {
    myv = myClient.move("move", "Person",
			dearLittleGirl.dump2JSON(),
			filler,
			"dearlittleGirl");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myv.toStyledString() << "\n Little Red Riding Hood has been Sent." << endl; // this is printing out the transfer person's data under HomeServer when it is run


  // Moving cap
  Json::Value myvCap;
  Json::Value testVal = cap.dump2JSON();
  try {
    myvCap = myClient.move("move", "Thing",
			testVal, filler,
			"cap");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myvCap.toStyledString() << "\n The Cap has been Sent." << endl; // this is printing out the transfer person's data under HomeServer when it is run

// Moving Cake
  Json::Value myvCake;
  Json::Value testValCake = cake.dump2JSON();
  try {
    myvCake = myClient.move("move", "Thing",
			testValCake, filler,
			"cake");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myvCake.toStyledString() << "\n The Cake has been Sent." << endl; // this is printing out the transfer person's data under HomeServer when it is run

// Moving Wine
  Json::Value myvWine;
  Json::Value testValWine = wine.dump2JSON();
  try {
    myvWine = myClient.move("move", "Thing",
			testValWine, filler,
			"wine");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myvWine.toStyledString() << "\n The Wine has been Sent." << endl; // this is printing out the transfer person's data under HomeServer when it is run



  Json::Value complete;

  try {
    complete = myClient.complete();
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << complete.toStyledString() << endl; // this is printing out the transfer person's data under HomeServer when it is run
  

HttpServer httpserver(7375);
 Myhw5Server s(httpserver,
JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  
    return 0;
}

