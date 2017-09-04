/*
 * *****************************
 * Project Celty
 * Clynt Neiko J. Rupinta
 * BSCPE3A_C1
 * University of Science and Technology of Southern Philippines
 * *****************************
 */

#include "ProjectCelty.h"

void tcp_init(String ssid, String pass, int port, int baud){
	blinkIndicator();
	startESP11Serial(baud);
	server_SendCommand("AT+RST\r\n",2000, DEBUG);
	server_SendCommand("AT+CWMODE=1\r\n",1000,DEBUG);
	server_SendCommand("AT+CWMODE?\r\n",1000,DEBUG);
	server_SendCommand("AT+CWJAP=\"" + ssid + "\",\"" + pass + "\"\r\n",5000,DEBUG);
	server_SendCommand("AT+CIPMUX=1\r\n",500,DEBUG);
	server_SendCommand("AT+CIFSR\r\n",500,DEBUG);
	server_SendCommand("AT+CIPSERVER=1," + String(port) + "\r\n",1000,DEBUG);
	blinkIndicator(6, 250);
	Serial.println("Waiting for client requests");
}

void server_init(String ssid, String pass, int baud){
	blinkIndicator();
	startESP11Serial(baud);
	checkESP11();
	server_SendCommand("AT+RST\r\n",1000, DEBUG);
	server_SendCommand("AT+CWMODE=2\r\n",500,DEBUG);
	server_SendCommand("AT+CWSAP=\"" + ssid + "\",\"" + pass + "\",5,3\r\n",2000,DEBUG);
	server_SendCommand("AT+CIPMODE=0\r\n",500,DEBUG);
	server_SendCommand("AT+CIPMUX=1\r\n",500,DEBUG);
	server_SendCommand("AT+CIPSERVER=1,80\r\n",1000,DEBUG);
	server_SendCommand("AT+CIFSR\r\n",500,DEBUG);
	blinkIndicator(6, 250);
	Serial.println("Waiting for client requests");
}

void runServer(int refreshTime) {
	String request = server_ReadRequest(refreshTime);
	if(request.indexOf("CTRL")>-1){
		Serial.println(request);
		int connectionId = request.charAt(0) - '0';
		Serial.println("Someone just hoocked");
		Serial.println(connectionId);
		clientWebPage_init(connectionId);
	}else{
		if(request.indexOf("ACCE")>-1){
			MR(255,255,1);
			Serial.println("ACCE");
		}
		else if(request.indexOf("DECE")>-1){
			MR(-255,-255,1);
			Serial.println("DECE");
		}
		else if(request.indexOf("LEFT")>-1){
			rotate('L',1);
			Serial.println("LEFT");
		}
		else if(request.indexOf("RIGH")>-1){
			rotate('R',1);
			Serial.println("RIGH");
		}
		else if(request.indexOf("STOP")>-1){
			stop();
			Serial.println("STOP");
		}
	}
	blinkIndicator(2, 100);
}

void clientWebPage_init(int connectionId){
	client_SendData("experimental desu", connectionId, DEBUG);
	client_CloseConnection(connectionId);
}
