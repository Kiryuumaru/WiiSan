/*
 * *****************************
 * Project Celty
 * Clynt Neiko J. Rupinta
 * BSCPE3A_C1
 * University of Science and Technology of Southern Philippines
 * *****************************
 */

#include "ProjectCelty.h"
/*
File file;

File getFile(String temp) {
	file = SD.open(temp);
	if(file) {
		file.close();
	}else {
		Serial.println("getFile: error opening " + temp);
	}
	return file;
}

String getContent(File temp) {
	String content = "";
	if(temp) {
		while(temp.available()) {
			content += (char)temp.read();
		}
		temp.close();
	}else {
		Serial.println("getContent: error opening " + temp);
	}
	return content;
}

int fileContentLength(File temp) {
	int i = 0;
	if(!temp){
		temp = SD.open(temp.name());
	}
	if(temp) {
		while(temp.available()) {
			temp.read();
			i++;
		}
		file.close();
	}else {
		Serial.println("fileContentLength: error opening " + temp);
	}
	return i;
}

void saveTemp(String dump) {
	file = SD.open(dumpFile, FILE_WRITE);
	if(file) {
		file.println(dump);
		file.close();
	}else {
		Serial.println("saveTemp: error opening " + dumpFile);
	}
}

void saveTemp(char dump) {
	file = SD.open(dumpFile, FILE_WRITE);
	if(file) {
		file.print(dump);
		file.close();
	}else {
		Serial.println("saveTemp: error opening " + dumpFile);
	}
}

String getTemp() {
	file = SD.open(dumpFile);
	if(file) {
		return getContent(file);
	}else {
		Serial.println("getTemp: error opening " + dumpFile);
	}
	clearTemp();
	return "";
}

void clearTemp(){
	if(SD.exists(dumpFile)) {
		SD.remove(dumpFile);
	}
}

void sdCard_init() {
	pinMode(10, OUTPUT);
	Serial.print("Initializing SD card...");
	if(!SD.begin(chipSelect)) {
		Serial.println("initialization failed!");
		graveError();
	}
	Serial.println("initialization done.");
}*/

