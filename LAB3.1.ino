#define F_CPU 16000000UL

#include  <avr/io.h>
#include  <util/delay.h>
void spi_init (void)
{
    // Set MOSI, SCK, Reset as Output
    DDRB = 0b00101110; 
    // Enable SPI, Set as Master
    // Clock = 1 MHz, F/16, Mode 0
    SPCR = 0b01010001;
  
    // Reset
    PORTB = PORTB & 0b11111101;
    _delay_ms(100);
    PORTB = PORTB | 0b00000010;
    // CS
    PORTB = PORTB & 0b11111011;
    _delay_ms(10);
    PORTB = PORTB | 0b00000100;
}
void spi_putc(char data)
{
    char busy;  
    // Load data into the buffer
    SPDR = data;
    //Wait until transmission complete
    do { busy = SPSR & 0b10000000; }
    while(busy==0);   
} 
void max7219_init(void)
{
  max7219_wr(0x0C,0x00);
  max7219_wr(0x09,0x00);
  max7219_wr(0x0A,0x0F);
  max7219_wr(0x0B,0x07);
  max7219_wr(0x0C,0x01);
  for(int i = 0;i<8;i++){
    max7219_wr(i+1,0);
    }
}
  
void max7219_wr(char addr, char data)
{
  char var ;
   PORTB = PORTB & 0b111111011; // PB2 = 0
    spi_putc(addr);
    spi_putc(data);
    // SS = 1; 
    PORTB = PORTB | 0b00000100; // PB2 = 1      
  

}

int main(void)
{
  spi_init();  
  max7219_init();
  while(1) {
    //C
    max7219_wr(0x01,0b11111111);
    max7219_wr(0x02,0b10000000);
    max7219_wr(0x03,0b10000000);
    max7219_wr(0x04,0b10000000);
    max7219_wr(0x05,0b10000000);
    max7219_wr(0x06,0b10000000);
    max7219_wr(0x07,0b10000000);
    max7219_wr(0x08,0b11111111);
    _delay_ms(2000);
    //H
    max7219_wr(0x01,0b01000001);
    max7219_wr(0x02,0b01000001);
    max7219_wr(0x03,0b01000001);
    max7219_wr(0x04,0b01000001);
    max7219_wr(0x05,0b01111111);
    max7219_wr(0x06,0b01000001);
    max7219_wr(0x07,0b01000001);
    max7219_wr(0x08,0b01000001);
    _delay_ms(2000);
    //A
    max7219_wr(0x01,0b00011000);
    max7219_wr(0x02,0b00100100);
    max7219_wr(0x03,0b01000010);
    max7219_wr(0x04,0b10000001);
    max7219_wr(0x05,0b11111111);
    max7219_wr(0x06,0b10000001);
    max7219_wr(0x07,0b10000001);
    max7219_wr(0x08,0b10000001);
    _delay_ms(2000);
    //T
    max7219_wr(0x01,0b00000000);
    max7219_wr(0x02,0b11111111);
    max7219_wr(0x03,0b00011000);
    max7219_wr(0x04,0b00011000);
    max7219_wr(0x05,0b00011000);
    max7219_wr(0x06,0b00011000);
    max7219_wr(0x07,0b00011000);
    max7219_wr(0x08,0b00011000);
    _delay_ms(2000);
    //C
    max7219_wr(0x01,0b11111111);
    max7219_wr(0x02,0b10000000);
    max7219_wr(0x03,0b10000000);
    max7219_wr(0x04,0b10000000);
    max7219_wr(0x05,0b10000000);
    max7219_wr(0x06,0b10000000);
    max7219_wr(0x07,0b10000000);
    max7219_wr(0x08,0b11111111);
    _delay_ms(2000);
    //H
    max7219_wr(0x01,0b01000001);
    max7219_wr(0x02,0b01000001);
    max7219_wr(0x03,0b01000001);
    max7219_wr(0x04,0b01000001);
    max7219_wr(0x05,0b01111111);
    max7219_wr(0x06,0b01000001);
    max7219_wr(0x07,0b01000001);
    max7219_wr(0x08,0b01000001);
    _delay_ms(2000);
    //A
    max7219_wr(0x01,0b00011000);
    max7219_wr(0x02,0b00100100);
    max7219_wr(0x03,0b01000010);
    max7219_wr(0x04,0b10000001);
    max7219_wr(0x05,0b11111111);
    max7219_wr(0x06,0b10000001);
    max7219_wr(0x07,0b10000001);
    max7219_wr(0x08,0b10000001);
    _delay_ms(2000);
    //N
    max7219_wr(0x01,0b10000001);
    max7219_wr(0x02,0b11000001);
    max7219_wr(0x03,0b10100001);
    max7219_wr(0x04,0b10010001);
    max7219_wr(0x05,0b10001001);
    max7219_wr(0x06,0b10000101);
    max7219_wr(0x07,0b10000011);
    max7219_wr(0x08,0b10000001);
    _delay_ms(2000);
    //U
    max7219_wr(0x01,0b00000000);
    max7219_wr(0x02,0b10000001);
    max7219_wr(0x03,0b10000001);
    max7219_wr(0x04,0b10000001);
    max7219_wr(0x05,0b10000001);
    max7219_wr(0x06,0b10000001);
    max7219_wr(0x07,0b10000001);
    max7219_wr(0x08,0b01111110);
    _delay_ms(2000);
    //N
    max7219_wr(0x01,0b10000001);
    max7219_wr(0x02,0b11000001);
    max7219_wr(0x03,0b10100001);
    max7219_wr(0x04,0b10010001);
    max7219_wr(0x05,0b10001001);
    max7219_wr(0x06,0b10000101);
    max7219_wr(0x07,0b10000011);
    max7219_wr(0x08,0b10000001);
    _delay_ms(2000);
    //T
    max7219_wr(0x01,0b00000000);
    max7219_wr(0x02,0b11111111);
    max7219_wr(0x03,0b00011000);
    max7219_wr(0x04,0b00011000);
    max7219_wr(0x05,0b00011000);
    max7219_wr(0x06,0b00011000);
    max7219_wr(0x07,0b00011000);
    max7219_wr(0x08,0b00011000);
    _delay_ms(2000);
  }
}

