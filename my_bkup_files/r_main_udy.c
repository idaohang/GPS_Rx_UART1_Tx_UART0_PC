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
* Creation Date: 08-12-2013
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
#define NULL ""

unsigned char Receive_data[30],debug_msg_1[6];
unsigned char TX_data;
unsigned char TX_data1[17] = "Nothing to Read\n\r";
unsigned char temp_var[70];
char *test;
__boolean flag;
unsigned int i;
MD_STATUS  sts ;
//extern volatile __boolean flag ;

void clear_rx_array(char array[100]);
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
    
    while (1U)
    {
     P3.1 = 0 ;
     clear_rx_array(Receive_data);
     Delay(50);
     
     if(rx_buf != "")
     {
        R_UART1_Receive(Receive_data, 30);
     }
     Delay(200);
     test = strstr((char *)Receive_data, "we");
     if(test)
     //for(i=0;i<sizeof(Receive_data);i++)    
     {
         P3.1 = 1;
	 //if(Receive_data[i]!= NULL)
         R_UART1_Send(Receive_data, 30);
         
	 //Delay(200);     
//       for(i=0;i<(sizeof(Receive_data));i++)
//       {
//         debug_msg_1[i]= Receive_data[i];
//       }
//       R_UART0_Send(debug_msg_1, 80);
        }
     
    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void clear_rx_array(char array[])
{
	for(i=0;i<(sizeof(array));i++)
	{
		 array[i] = 0;
	}
}
/* End user code. Do not edit comment generated here */
