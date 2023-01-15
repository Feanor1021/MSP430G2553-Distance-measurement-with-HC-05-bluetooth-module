#ifndef __LCD_H
#define __LCD_H

#ifdef __cplusplus
 extern "C" {
#endif

// LCD ba�lant�s�nda kullan�lacak pinlerin tan�mlamalar�
#define LCD_DATA_PORT			P1OUT
#define LCD_DATA_PORT_DIR		P1DIR
#define LCD_DATA_PORT_SEL		P1SEL
#define LCD_DATA_PORT_SEL2		P1SEL2
#define LCD_CONTROL_PORT    	        P2OUT
#define LCD_CONTROL_PORT_DIR            P2DIR
#define LCD_CONTROL_PORT_SEL	        P2SEL
#define LCD_CONTROL_PORT_SEL2	        P2SEL2
#define LCD_RS_BIT			BIT7
#define LCD_EN_BIT			BIT6

// LCD s�rme i�leminde kullan�lan makrolar
#define	EN_AC_KAPA()     LCD_EN(1),LCD_EN(0)
#define	LCD_RS(x)       ( (x) ? (LCD_CONTROL_PORT |= LCD_RS_BIT) : (LCD_CONTROL_PORT &= ~LCD_RS_BIT) )
#define LCD_EN(x)       ( (x) ? (LCD_CONTROL_PORT |= LCD_EN_BIT) : (LCD_CONTROL_PORT &= ~LCD_EN_BIT) )

// LCD k�t�phanesinde kullan�lan fonksiyon prototipleri
void LCD_Komut_Yaz(unsigned char);  // LCD ye komut g�ndermeye yarar
void LCD_Temizle(void);       		// LCD ekran� temizler
void LCD_Yazi_Yaz(const char*);    	// LCDye string ifade yazar
void LCD_Git_XY(char,char);      	// LCDde sat�r ve s�tun olarak istenilen yere gider
void LCD_Ayarla(void);           	// LCD ba�lang��ayarlar� yap�l�r
void LCD_Karakter_Yaz(char);        // LCDye tek karakter yazmak i�in kullan�l�r.

#ifdef __cplusplus
}
#endif

#endif /*__LCD_H */
