/*
 * *****************************
 * Project Celty
 * Clynt Neiko J. Rupinta
 * BSCPE3A_C1
 * University of Science and Technology of Southern Philippines
 * *****************************
 */

#include "ProjectCelty.h"

void MR(int mL, int mR, double speedMultiplier_Slave){
	configMotor_L(mL, speedMultiplier_Slave);
	configMotor_R(mR, speedMultiplier_Slave);
}

void RMR(int mL, int mR, double speedMultiplier_Slave){
	configMotor_R(-mL, speedMultiplier_Slave);
	configMotor_L(-mR, speedMultiplier_Slave);
}

void face_Left(){
	stop();
	MR(-255, 255, speedMultiplier_Master);
	delay(facingDelay);
	stop();
}

void face_Right(){
	stop();
	MR(255, -255, speedMultiplier_Master);
	delay(facingDelay);
	stop();
}

void face_Back(char turn){
	switch(turn){
	case 'L':
		stop();
		MR(-255, 255, speedMultiplier_Master);
		delay(facingDelay*2);
		stop();
		break;
	case 'R':
		stop();
		MR(255, -255, speedMultiplier_Master);
		delay(facingDelay*2);
		stop();
		break;
	}
}

void rotate(char turn, double speedMultiplier_Slave){
	switch(turn){
	case 'L':
		MR(-255, 255, speedMultiplier_Slave);
		break;
	case 'R':
		MR(255, -255, speedMultiplier_Slave);
		break;
	}
}

void stop(){
	MR(0, 0, speedMultiplier_Master);
}

void configMotor_L(int mL, double speedMultiplier_Slave){
	if(mL>=0){
		analogWrite(motorL_P, mL*speedMultiplier_Slave);
		analogWrite(motorL_N, 0);
	}else{
		analogWrite(motorL_N, -mL*speedMultiplier_Slave);
		analogWrite(motorL_P, 0);
	}
}

void configMotor_R(int mR, double speedMultiplier_Slave){
	if(mR>=0){
		analogWrite(motorR_P, mR*speedMultiplier_Slave);
		analogWrite(motorR_N, 0);
	}else{
		analogWrite(motorR_N, -mR*speedMultiplier_Slave);
		analogWrite(motorR_P, 0);
	}
}
