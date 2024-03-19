#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
void spi_init (void)
{
   // Set MOSI, SCK, Reset as Output
   DDRB = 0b00101110;
   // Enable SPI, Set as Master
   // Clock = 1 MHz, F/16, Mode 0
   SPCR = 0b01010001;
   // Reset
   PORTB = PORTB & 0b11111101;
    __builtin_avr_delay_cycles(1600000);
   PORTB = PORTB | 0b00000010;
   PORTB = PORTB & 0b111111011; // PB2 = 0
    __builtin_avr_delay_cycles(160000);
   PORTB = PORTB | 0b00000100;   // PB2 = 1
}
void spi_putc (char data)
{
   char busy;
   // Load data into the buffer
   SPDR = data;
   // Wait until transmission complete
   do { busy = SPSR & 0b10000000; }
   while (busy ==0);
}
void max7219_wr (char addr, char data )
{
   PORTB = PORTB & 0b111111011; // PB2 = 0
   spi_putc(0b01000000);
   spi_putc(addr);
   spi_putc(data);
   // SS = 1;
   PORTB = PORTB | 0b00000100;  // PB2 = 1
 }
 int main(void)
 {
   spi_init();
   max7219_wr(0x0C, 0); //Shutdown MAX7219
   max7219_wr(0x09, 0x00); //Decode mode
   max7219_wr(0x0A, 0x0F); //Max intensity
   max7219_wr(0x0B, 0x07); //Scan Limit (8)
   max7219_wr(0x0C, 1); //Turn on MAX7219
   while(1)
  {
  //NAPHAT
  uint8_t A[8][30]={{0b11111111,0b01000001,0b00011000,0b00000000,0b01111110,0b01000001,0b00011000,0b10000001,0b00000000,0b10000001,0b00000000},
                    {0b10000000,0b01000001,0b00100100,0b01111110,0b01000000,0b01000001,0b00100100,0b11000001,0b10000001,0b11000001,0b11111111},
                    {0b10000000,0b01000001,0b01000010,0b00011000,0b01000000,0b01000001,0b01000010,0b10100001,0b10000001,0b10100001,0b00011000},
                    {0b10000000,0b01000001,0b10000001,0b00011000,0b01000000,0b01000001,0b10000001,0b10010001,0b10000001,0b10010001,0b00011000},
                    {0b10000000,0b01111111,0b11111111,0b00011000,0b01000000,0b01111111,0b11111111,0b10001001,0b10000001,0b10001001,0b00011000},
                    {0b10000000,0b01000001,0b10000001,0b00011000,0b01000000,0b01000001,0b10000001,0b10000101,0b10000001,0b10000101,0b00011000},
                    {0b10000000,0b01000001,0b10000001,0b00011000,0b01000000,0b01000001,0b10000001,0b10000011,0b10000001,0b10000011,0b00011000},
                    {0b11111111,0b01000001,0b10000001,0b00011000,0b01111110,0b01000001,0b10000001,0b10000001,0b01111110,0b10000001,0b00011000}
                    };
  for(int i = 0; i < 11; i++)
{
    for(int j = 0; j < 11; j++)
    {
        max7219_wr(0x01, (A[0][i] << j) | (A[0][i + 1] >> (11 - j)));         
        max7219_wr(0x02, (A[1][i] << j) | (A[1][i + 1] >> (11 - j)));
        max7219_wr(0x03, (A[2][i] << j) | (A[2][i + 1] >> (11 - j)));
        max7219_wr(0x04, (A[3][i] << j) | (A[3][i + 1] >> (11 - j)));
        max7219_wr(0x05, (A[4][i] << j) | (A[4][i + 1] >> (11 - j)));
        max7219_wr(0x06, (A[5][i] << j) | (A[5][i + 1] >> (11 - j)));
        max7219_wr(0x07, (A[6][i] << j) | (A[6][i + 1] >> (11 - j)));
        max7219_wr(0x08, (A[7][i] << j) | (A[7][i + 1] >> (11 - j)));
        __builtin_avr_delay_cycles(1600000);
    }
}

  }
 }
