#include "muhtas1.h"

int     i;
char    BUFF[80]={0};
  
int     main( void )
{
  int     flag=0;
  char    *HexRssi;
  WD_OSCAL_AND_INITS();

  while (1)
  {
    while (!(flag = ft_strnstr(BUFF, "1819:D6:8BC2F9", 80)))
    {
      i = 0;
      TX("AT+INQ\r\n");
      __delay_cycles(1500000);
      TX("AT+INQC\r\n");
    }
    LCD_Temizle();
    LCD_Yazi_Yaz("Distance:");
    LCD_Git_XY(1,10); 
    HexRssi = Get_RSSI(BUFF, flag);
    HexRssi = Calculate_Dist(HexRssi);
    LCD_Yazi_Yaz(HexRssi);
    Re_Arrange(BUFF,HexRssi,&flag);
  }
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void RX_ISR(void)
{
    BUFF[i] = UCA0RXBUF;
    i++;
}