#ifndef _APPLICATION_H
#define _APPLICATION_H


extern unsigned char welcome[7];
extern unsigned char ATPDUText[10];
extern unsigned char ATCommandSendSMS[8];
extern unsigned char RecpNo[16];
extern unsigned char SMSData[11];
extern unsigned const char ctrlz[];
extern unsigned char alert;

// Initializing user defined methods
void Delay(unsigned int);
//void InitialiseUarts();

#endif