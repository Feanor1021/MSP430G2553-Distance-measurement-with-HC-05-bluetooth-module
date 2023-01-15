#ifndef MUHTAS1_H
#define MUHTAS1_H

#include "io430.h"
#include "intrinsics.h"
#include "stdlib.h"
#include "libft.h"
#include "math.h"
#include "LCD.h"

#define GREENL  BIT0
#define YELLOWL BIT3
#define REDL    BIT0

//Set and init functions
void    WD_OSCAL_AND_INITS(void);
void    Uart_Init(void);
void    Re_Arrange(char *a, char *Device_val, int *flag);
void    Led_Control(float distance);

//TX-RX functions
void    TX(const char *s);
void    putc(const unsigned c);

//RSSI calculation
char    *Get_RSSI(char *a, int index);
char    *Calculate_Dist(char *HexRssi);

#endif