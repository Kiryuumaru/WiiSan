/*
 * *****************************
 * Project Celty
 * Clynt Neiko J. Rupinta
 * BSCPE3A_C1
 * University of Science and Technology of Southern Philippines
 * *****************************
 */

#include "ProjectCelty.h"

String ap_ssid = "lann2";
String ap_pass = "kimochiwarui";

String tcp_ssid = "lann";
String tcp_pass = "qwertyuiop";
int tcp_port = 80;

int espMode = 0;

void setup(){
	Serial.begin(9600);
	pinMode(espIndicator, OUTPUT);
	pinMode(motorL_N, OUTPUT);
	pinMode(motorL_P, OUTPUT);
	pinMode(motorR_N, OUTPUT);
	pinMode(motorR_P, OUTPUT);
	digitalWrite(espIndicator, LOW);
	delay(2000);
	if(espMode==0){
		server_init(ap_ssid, ap_pass, 9600);
	}else{
		tcp_init(tcp_ssid, tcp_pass, tcp_port, 9600);
	}
}

void loop() {
	runServer(100);
}
