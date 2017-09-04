/*
 * *****************************
 * Project Celty
 * Clynt Neiko J. Rupinta
 * BSCPE3A_C1
 * University of Science and Technology of Southern Philippines
 * *****************************
 */

#ifndef _ProjectCelty_H_
#define _ProjectCelty_H_
#include "Arduino.h"
#include "SoftwareSerial.h"

#define DEBUG true

//Pins
const int motorL_N = 5;
const int motorL_P = 6;
const int motorR_N = 9;
const int motorR_P = 10;
const int espIndicator = 13;

//Motor configurations
const double speedMultiplier_Master = 0.4;
const double facingDelay = 500;

//Helper
void blinkIndicator();
void blinkIndicator(int times, int speed);
void graveError();

//ESP11
void startESP11Serial(int baud);
void client_SendDummy(String data, int connectionId, int timeout);
void checkESP11();
String server_ReadResponse();
String server_ReadRequest(int refreshTime);
String server_SendCommand(String command, int timeout, bool debug);
void client_SendData(String data, int connectionId, int timeout);
void client_SendHTML(String webPage, int connectionId, int timeout);
void client_OpenConnection(int connectionId, int dataLength, int timeout);
void client_CloseConnection(int connectionId);

//ESPServer
void tcp_init(String ssid, String pass, int port, int baud);
void server_init(String ssid, String pass, int baud);
void runServer(int refreshTime);

//ESPWebpage
void clientWebPage_init(int connectionId);

//Motor
void MR(int mL, int mR, double speedBase);
void RMR(int mL, int mR, double speedBase);
void face_Left();
void face_Right();
void face_Back(char turn);
void rotate(char turn, double speedBase);
void stop();
void configMotor_L(int mL, double speedBase);
void configMotor_R(int mR, double speedBase);


#endif /* _ProjectCelty_H_ */
