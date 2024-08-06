// #include "ThingSpeak.h"
// #include <WiFi.h>  // Include the WiFi library for ESP32

// //------- WI-FI details ----------//
// const char* ssid = "EDRK"; // Replace with your WiFi SSID
// const char* password = "EDRK2912"; // Replace with your WiFi password
// //--------------------------------//

// //----------- Channel details ----------------//
// unsigned long Channel_ID = 2582103; // Your ThingSpeak Channel ID
// const char* myWriteAPIKey = "WSYK1ZD3WFD7XI6T"; // Your ThingSpeak Write API Key
// //-------------------------------------------//

// const int Field_Number_1 = 1;
// String value = "";
// int value_1 = 0;
// WiFiClient client;

// void setup() {
//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA); // Set WiFi mode to station (client) mode
//   ThingSpeak.begin(client); // Initialize ThingSpeak client

//   connectToWiFi(); // Connect to WiFi network
// }

// void internet() {
//   if (WiFi.status() != WL_CONNECTED) {
//     while (WiFi.status() != WL_CONNECTED) {
//       WiFi.begin(ssid, password);
//       delay(5000);
//     }
//   }
// }

// void loop() {
//   internet(); // Ensure WiFi connection is maintained
//   if (Serial.available() > 0) {
//     delay(100);
//     while (Serial.available() > 0) {
//       value = Serial.readString();
//       if (value[0] == '*') {
//         if (value[2] == '#') {
//           value_1 = value[1] - '0'; // Convert char to int
//         }
//       }
//     }
//     upload(); // Upload data to ThingSpeak
//   }
// }

// void connectToWiFi() {
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
//   WiFi.begin(ssid, password); // Connect to WiFi network

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println();
//   Serial.println("WiFi connected");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// void upload() {
//   int writeSuccess = ThingSpeak.writeField(Channel_ID, Field_Number_1, value_1, myWriteAPIKey);

//   if (writeSuccess) {
//     Serial.println("Data sent to ThingSpeak successfully");
//   } else {
//     Serial.println("Error uploading data to ThingSpeak");
//   }

//   delay(15000); // Delay before next update (ThingSpeak has a limit on updates per channel)
//   value = ""; // Clear the value variable
// }


// #include <WiFi.h>
// #include "ThingSpeak.h"

// const char* ssid = "ERRAMURI"; // Replace with your WiFi SSID
// const char* pass = "Kumari#1979r"; // Replace with your WiFi password

// unsigned long Channel_ID = 2582103; // Your ThingSpeak Channel ID
// const char* myWriteAPIKey = "WSYK1ZD3WFD7XI6T"; // Your ThingSpeak Write API Key
// const int Field_Number_1 = 1;

// WiFiClient client;

// void setup() {
//   Serial.begin(115200);
  
//   // Initialize Wi-Fi connection
//   connectWiFi();
  
//   // Initialize ThingSpeak
//   ThingSpeak.begin(client);
// }

// void loop() {
//   // Ensure Wi-Fi connection is maintained
//   connectWiFi();
  
//   // Check for serial data
//   if (Serial.available() > 0) {
//     delay(100);
    
//     // Read serial data until '#' character
//     String value = Serial.readStringUntil('#');
    
//     // Check if the received data starts with '*'
//     if (value.startsWith("*")) {
//       // Extract the integer value after '*'
//       int value_1 = value.substring(1, 2).toInt();
      
//       // Print parsed value to Serial (optional)
//       Serial.print("Parsed value: ");
//       Serial.println(value_1);
      
//       // Upload data to ThingSpeak
//       uploadToThingSpeak(value_1);
//     }
//   }
  
//   delay(100); // Adjust delay as needed
// }

// void connectWiFi() {
//   // Connect to Wi-Fi if not already connected
//   if (WiFi.status() != WL_CONNECTED) {
//     Serial.println("Connecting to WiFi...");
//     WiFi.begin(ssid, pass);
    
//     while (WiFi.status() != WL_CONNECTED) {
//       delay(500);
//       Serial.print(".");
//     }
    
//     Serial.println();
//     Serial.println("WiFi connected");
//     Serial.print("IP address: ");
//     Serial.println(WiFi.localIP());
//   }
// }

// void uploadToThingSpeak(int value_1) {
//   // Write data to ThingSpeak channel
//   ThingSpeak.writeField(Channel_ID, Field_Number_1, value_1, myWriteAPIKey);
  
//   Serial.println("Data sent to ThingSpeak");
  
//   delay(15000); // ThingSpeak update interval (15 seconds)
// }

#include "ThingSpeak.h"
#include <WiFi.h>

//------- WI-FI details ----------//
const char* ssid = "EDRK"; // Replace with your WiFi SSID
const char* password = "EDRK2912"; // Replace with your WiFi password
//--------------------------------//

//----------- Channel details ----------------//
unsigned long Channel_ID = 2582103; // Your ThingSpeak Channel ID
const char* myWriteAPIKey = "WSYK1ZD3WFD7XI6T"; // Your ThingSpeak Write API Key
//-------------------------------------------//

const int Field_Number_1 = 1;
String value = "";
int value_1 = 0;
WiFiClient  client;

void setup() {
  Serial.begin(9600);
  delay(1000); // Delay to let serial monitor start
  Serial.println("Starting setup...");
  
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  
  internet();
}

void loop() {
  internet();
  value_1=random(1,4);
  Serial.print("Naveen");
  Serial.print(Serial.readString());
  Serial.print(Serial.available());
  if (Serial.available() > 0) {
    delay(100);
    while (Serial.available() > 0) {
      value = Serial.readString();
      if (value[0] == '*') {
        if (value[2] == '#') {
          Serial.print("Received value: ");
          Serial.println(value_1);
        }
      }
    }
  }
  
  upload();
}

void internet() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      delay(5000);
    }
    Serial.println("WiFi connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void upload() {
  Serial.println("Uploading to ThingSpeak...");
  ThingSpeak.writeField(Channel_ID, Field_Number_1, value_1, myWriteAPIKey);
  delay(15000); // Delay between updates
  value = "";
  Serial.println("Upload complete.");
}


// #include "ThingSpeak.h"
// #include <WiFi.h>  // Use WiFi.h for ESP32

// //------- WI-FI details ----------//
// const char* ssid = "ERRAMURI"; // Replace with your WiFi SSID
// const char* password = "Kumari#1979r"; // Replace with your WiFi password
// //--------------------------------//

// //----------- Channel details ----------------//
// unsigned long Channel_ID = 2582103; // Your ThingSpeak Channel ID
// const char* myWriteAPIKey = "WSYK1ZD3WFD7XI6T"; // Your ThingSpeak Write API Key
// //-------------------------------------------//

// const int Field_Number_1 = 1;
// String value = "";
// int value_1 = 0;
// WiFiClient client;

// void setup() {
//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA);
//   ThingSpeak.begin(client);
//   internet();
// }

// void loop() {
//   internet();
//   if (Serial.available() > 0) {
//     delay(100);
//     while (Serial.available() > 0) {
//       value = Serial.readString();
//       if (value[0] == '*') {
//         if (value[2] == '#') {
//           value_1 = value[1] - 0x30;
//         }
//       }
//     }
//   }
//   Serial.println(Serial.available());
//   Serial.println(value[1]);
//   Serial.println(value[2]);
//   Serial.println(value_1);
//   upload();
// }

// void internet() {
//   if (WiFi.status() != WL_CONNECTED) {
//     while (WiFi.status() != WL_CONNECTED) {
//       WiFi.begin(ssid, password);
//       delay(5000);
//     }
//   }
// }

// void upload() {
//   ThingSpeak.writeField(Channel_ID, Field_Number_1, value_1, myWriteAPIKey);
//   delay(15000);
//   value = "";
// }



// #include <ESP8266WiFi.h>

// // Replace with your network credentials
// const char* ssid     = "ERRAMURI";
// const char* password = "Kumari#1979r";

// void setup() {
//   // Start the Serial communication to send messages to the computer
//   Serial.begin(115200);
//   delay(10);

//   // Start WiFi
//   Serial.println();
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
  
//   // Connect to the WiFi
//   WiFi.begin(ssid, password);

//   // Wait until the connection has been confirmed before continuing
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   // We're connected to the WiFi network
//   Serial.println("");
//   Serial.println("WiFi connected");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// void loop() {
//   // Nothing happens here
// }


// #include <WiFi.h>

// // Replace with your network credentials
// const char* ssid     = "EDRK";
// const char* password = "EDRK2912";

// void setup() {
//   // Start the Serial communication to send messages to the computer
//   Serial.begin(115200);
//   delay(10);

//   // Start WiFi
//   Serial.println();
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
  
//   // Connect to the WiFi
//   WiFi.begin(ssid, password);

//   // Wait until the connection has been confirmed before continuing
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   // We're connected to the WiFi network
//   Serial.println("");
//   Serial.println("WiFi connected");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// void loop() {
//   // Nothing happens here
// }


// #include <WiFi.h>
// #include "ThingSpeak.h"

// //------- WI-FI details ----------//
// const char* ssid = "ERRAMURI"; // Replace with your WiFi SSID
// const char* password = "Kumari#1979r"; // Replace with your WiFi password
// //--------------------------------//

// //----------- Channel details ----------------//
// unsigned long Channel_ID = 2582103; // Your ThingSpeak Channel ID
// const char* myWriteAPIKey = "WSYK1ZD3WFD7XI6T"; // Your ThingSpeak Write API Key
// //-------------------------------------------//

// const int Field_Number_1 = 1;
// String value = "";
// int value_1 = 0;
// WiFiClient  client;

// void setup() {
//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA);
//   ThingSpeak.begin(client);
//   internet();
// }

// void loop() {
//   internet();
//   if (Serial.available() > 0) {
//     delay(100);
//     while (Serial.available() > 0) {
//       value = Serial.readString();
//       if (value[0] == '*') {
//         if (value[2] == '#') {
//           value_1 = value[1] - 0x30;
//         }
//       }
//     }
//   }
//   upload();
// }

// void internet() {
//   if (WiFi.status() != WL_CONNECTED) {
//     while (WiFi.status() != WL_CONNECTED) {
//       WiFi.begin(ssid, password);
//       delay(5000);
//     }
//   }
// }

// void upload() {
//   ThingSpeak.writeField(Channel_ID, Field_Number_1, value_1, myWriteAPIKey);
//   delay(15000);
//   value = "";
// }


// #include "ThingSpeak.h"
// #include <WiFi.h>

// //------- WI-FI details ----------//
// const char* ssid = "ERRAMURI"; // Replace with your WiFi SSID
// const char* password = "Kumari#1979r"; // Replace with your WiFi password
// //--------------------------------//

// //----------- Channel details ----------------//
// unsigned long Channel_ID = 2540620; // Your Channel ID
// const char * myWriteAPIKey = "KDQMABWOKXFDNAJK"; // Your ThingSpeak write API key
// //-------------------------------------------//

// const int Field_Number_1 = 1;
// String value = "";
// int value_1 = 0;
// WiFiClient client;

// void setup() {
//   Serial.begin(115200);
//   delay(1000); // Delay to let serial monitor start
//   Serial.println("Starting setup...");
  
//   WiFi.mode(WIFI_STA);
//   ThingSpeak.begin(client);
  
//   internet();
// }

// void loop() {
//   internet();
  
//   if (Serial.available() > 0) {
//     delay(100);
//     while (Serial.available() > 0) {
//       value = Serial.readString();
//       if (value[0] == '*') {
//         if (value[2] == '#') {
//           value_1 = value[1] - 0x30;
//           Serial.print("Received value: ");
//           Serial.println(value_1);
//         }
//       }
//     }
//   }
  
//   upload();
// }

// void internet() {
//   if (WiFi.status() != WL_CONNECTED) {
//     Serial.println("Connecting to WiFi...");
//     while (WiFi.status() != WL_CONNECTED) {
//       WiFi.begin(ssid, password);
//       delay(5000);
//     }
//     Serial.println("WiFi connected.");
//     Serial.print("IP address: ");
//     Serial.println(WiFi.localIP());
//   }
// }

// void upload() {
//   Serial.print("Uploading value to ThingSpeak: ");
//   Serial.println(value_1);  // Print the value being uploaded
//   ThingSpeak.writeField(Channel_ID, Field_Number_1, value_1, myWriteAPIKey);
//   delay(15000); // Delay between updates
//   value = "";
//   Serial.println("Upload complete.");
// }
