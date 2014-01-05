/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G12 V1.02.01 [11 Oct 2011]
* Device(s)    : R5F102A8
* Tool-Chain   : CA78K0R
* Description  : This file implements main function.
* Creation Date: 04-01-2014
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_serial.h"
#include "r_cg_wdt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
#define NULL " "

//Define arrays
unsigned char Receive_data[200];
unsigned char gprmcLocked[18]="LOCK_ON_GPRMC | \r";
unsigned char gpsDataNotLocked[24]="GPS_DATA_NOT_LOCKED | \r";
unsigned char gpsDataLocked[20]="GPS_DATA_LOCKED | \r";
unsigned char gpsDataStart[13]="GPS_DATA | \r";
unsigned char gpsData[61];
unsigned char gpsDataEnd[2]="\r";

//Define variables
unsigned int i,x,j,k;

//Define user-defined methods
void clear_rx_array(char array[200]);

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    /* Start user code. Do not edit comment generated here */
     R_UART2_Start();
     R_UART1_Start();
     R_UART0_Start();
    
  //  R_UART0_Send("GET GPS ROUTINE\n\r",17);
  //  Delay(50);
       
    while (1U)
    {
     P3.1 = 0 ;
     clear_rx_array(Receive_data);
     Delay(50);
    
     R_UART1_Receive(Receive_data, 200);  
     Delay(200);
     
     for(x=0;x<=sizeof(Receive_data);x++)
     {
	     if(Receive_data[x] == '$' && Receive_data[x+1] == 'G' && Receive_data[x+2] == 'P' && Receive_data[x+3] == 'R' 
	     		&& Receive_data[x+4] == 'M' && Receive_data[x+5] == 'C')
	     {
		R_UART0_Send(gprmcLocked, 18);
     		Delay(200);
	     	P3.1 = 1;
	     	//Delay(200);
		
		if(Receive_data[x+18] == 'V')
			{
				R_UART0_Send(gpsDataNotLocked, 24);
    		 		Delay(100);
			}
		else if(Receive_data[x+18] == 'A')
			{
				R_UART0_Send(gpsDataLocked, 20);
    		 		Delay(100);
				R_UART0_Send(gpsDataStart, 13);\
				Delay(100);
				
				k=x;
				for(j=0;j<61;j++,k++)
					gpsData[j]=Receive_data[k+6];
				
				R_UART0_Send(gpsData, 61);
				Delay(500);
				R_UART0_Send(gpsDataEnd, 2);
				Delay(50);
			}
	     }
	 }//End of for loop
     }//End of while loop
  }
    /* End user code. Do not edit comment generated here */

/* Start user code for adding. Do not edit comment generated here */
void clear_rx_array(char array[])
{
	for(i=0;i<(sizeof(array));i++)
	{
		 array[i] = 0;
	}
}
/* End user code. Do not edit comment generated here */
