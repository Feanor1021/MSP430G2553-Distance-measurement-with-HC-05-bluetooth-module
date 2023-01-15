#include "muhtas1.h"

void    WD_OSCAL_AND_INITS(void)
{
  WDTCTL = WDTPW + WDTHOLD;
  LCD_Ayarla();
  P1DIR |= GREENL+YELLOWL;
  P2DIR |= REDL;
   P1OUT &= ~(GREENL+YELLOWL);
  P2OUT |= REDL;
  if (CALBC1_1MHZ == 0xFF)
  {
    while (1);
  }
  DCOCTL = 0;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;
  Uart_Init();
  __bis_SR_register(GIE);
}

void    Uart_Init(void)
{  
  P1SEL = BIT1 + BIT2;//RX-TX
  P1SEL2 = BIT1 + BIT2;//RX-TX
  UCA0CTL1 |= UCSSEL_2;
  UCA0BR0 = 26;
  UCA0BR1 = 0;
  UCA0MCTL = UCBRF_0 + UCBRS_0;
  UCA0CTL1 &=~ UCSWRST;
  IE2 |= UCA0RXIE;
}

void    putc(const unsigned c)
{
  while (!(IFG2&UCA0TXIFG));//Wait till tx is free
    UCA0TXBUF = c;
}

void    TX(const char *s)
{
  while (*s)
    putc(*s++);
}

char    *Get_RSSI(char *a, int index)
{
  char *b = (char *)malloc(sizeof(char)*5);
  if(!b)
      return NULL;
    ft_strlcpy(b, a + index + 22, 5);
    return (b);
}

void    Re_Arrange(char *a, char *Device_val, int *flag)
{
   *flag=0;
   ft_memset(a,0,80);
   free(Device_val);
}

char    *Calculate_Dist(char *HexRssi)
{
  int ref_db = -55;
  int current_db;
  float n=0;
  float distance;

  current_db = ft_hex2_dec(HexRssi)-65535;
  free(HexRssi);
  n = (ref_db - current_db) / (10*1.8);
  distance = 100*pow(10,n);
  Led_Control(distance);
  return (ft_ftoa(distance));
}

void    Led_Control(float distance)
{
  if (distance < 100)
  {
    P1OUT&=~GREENL;
    P1OUT&=~YELLOWL;
    P2OUT|=REDL;
  }
  else if (distance >= 100 && distance < 200)
  {
    P1OUT&=~GREENL;
    P1OUT|=YELLOWL;
    P2OUT&=~REDL;
  }
  else
  {
    P1OUT|=GREENL;
    P1OUT&=~YELLOWL;
    P2OUT&=~REDL;
  }
}