/*
 * *****************************
 * Project Celty
 * Clynt Neiko J. Rupinta
 *  CPE3A_C1
 * University of Science and Technology of Southern Philippines
 * *****************************
 */

#include "ProjectCelty.h"

void blinkIndicator(){
	if(digitalRead(espIndicator)){
		digitalWrite(espIndicator, LOW);
	}else{
		digitalWrite(espIndicator, HIGH);
	}
}

void blinkIndicator(int times, int speed){
	int i;
	digitalWrite(espIndicator, LOW);
	for(i=0;i<=times;i++){
		blinkIndicator();
		delay(speed);
	}
	digitalWrite(espIndicator, LOW);
}

void graveError(){
	while(true){
		Serial.println("NEED RESTART");
		blinkIndicator(1, 500);
	}
}
