#include "Application.h"
unsigned char welcome[7]="welcome";
unsigned char ATPDUText[10] = "AT+CMGF=1\r";
unsigned char ATCommandSendSMS[8] = "AT+CMGS=";
//unsigned char RecpNo[16]="\"+919940819208\"\r";
unsigned char RecpNo[16]="\"+919786092886\"\r";
unsigned char SMSData[11]="SMS DATA";
unsigned const char ctrlz[]={0x1A};
unsigned char alert=0x00;

void Delay(unsigned int delay){
	unsigned int i=0, j=0, k=0;
	for(i=0;i<delay;i++){
		for(j=0;j<100;j++)
			for(k=0;k<100;k++);
	}
}