
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


 HttpClient httpclient("http://127.0.0.1:7374");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv, filler;
  filler["Location"] = "Home!";
/*
  try {
    myv = myClient.move("move", "Person",
			dearLittleGirl.dump2JSON(),
			filler,
			"dearlittleGirl");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myv.toStyledString() << endl; // this is printing out the transfer person's data under HomeServer when it is run
  
  Json::Value complete;

  try {
    complete = myClient.complete();
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << complete.toStyledString() << endl; // this is printing out the transfer person's data under HomeServer when it is run
   */
    HttpServer httpserver(7376);
 Myhw5Server s(httpserver,
JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
    cout << " \n The following is data received from the Forest Server. (Will show after running the forest server and the home server.)" << endl;
  getchar();

  s.StopListening();
   return 0;




}