/*
 * *****************************
 * Project Celty
 * Clynt Neiko J. Rupinta
 * BSCPE3A_C1
 * University of Science and Technology of Southern Philippines
 * *****************************
 */

#include "ProjectCelty.h"

SoftwareSerial ESP11 = SoftwareSerial(2,3);
char* ipd = (char *)"+IPD,";

void startESP11Serial(int baud){
	ESP11.begin(baud);
}

void client_SendDummy(String data, int connectionId, int timeout){
	client_SendData(data, connectionId, timeout);
	client_CloseConnection(connectionId);
}

void checkESP11(){
	String response = server_SendCommand("AT\r\n",1000,DEBUG);
	if(response.indexOf("OK")==-1) graveError();
}

String server_ReadResponse(){
	String response = "";
	while(ESP11.available()) {
		char data = ESP11.read();
		if(data=='\n') break;
		response += data;
	}
	return response;
}

String server_ReadRequest(int refreshTime){
	if((ESP11.available())&&(ESP11.find(ipd))){
		return server_ReadResponse();
	}else{
		delay(refreshTime);
	}
	return "NONE";
}

String server_SendCommand(String command, int timeout, bool debug) {
	String response = "";
	ESP11.print(command);
	unsigned long int time = millis();
	while((time+timeout) > millis()) {
		while(ESP11.available()) {
			char c = ESP11.read();
			response+=c;
		}
	}
	if(debug) {
		Serial.print(response);
	}
	return response;
}

String server_SendCommand(char command, int timeout, bool debug) {
	String response = "";
	ESP11.print(command);
	unsigned long int time = millis();
	while((time+timeout) > millis()) {
		while(ESP11.available()) {
			char c = ESP11.read();
			response+=c;
		}
	}
	if(debug) {
		Serial.print(response);
	}
	return response;
}

void client_SendData(String data, int connectionId, int timeout){
	String cipSend = "AT+CIPSEND="; cipSend += connectionId; cipSend += ","; cipSend += data.length(); cipSend += "\r\n";
	server_SendCommand(cipSend,500,DEBUG);
	server_SendCommand(data,timeout,DEBUG);
}

void client_SendHTML(String webPage, int connectionId, int timeout){
	String html = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
	client_SendData(html + webPage, connectionId, timeout);
}

void client_OpenConnection(int connectionId, int dataLength, int timeout){
	String cipSend = "AT+CIPSEND="; cipSend += connectionId; cipSend += ","; cipSend += dataLength; cipSend += "\r\n";
	server_SendCommand(cipSend,timeout,DEBUG);
}

void client_CloseConnection(int connectionId){
	String cipSend = "AT+CIPCLOSE="; cipSend += connectionId; cipSend += "\r\n";
	String response;
	do{
		response = server_SendCommand(cipSend,100,DEBUG);
	}while(response.indexOf("busy")!=-1);
}
