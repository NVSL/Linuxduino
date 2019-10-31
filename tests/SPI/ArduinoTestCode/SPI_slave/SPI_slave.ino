#include <SPI.h>

void SPIsetBitOrder(uint8_t bitOrder) 
{
    if (bitOrder == LSBFIRST) SPCR |= _BV(DORD);
    else SPCR &= ~(_BV(DORD));
}

void SPIsetDataMode(uint8_t dataMode) 
{
    SPCR = (SPCR & ~SPI_MODE_MASK) | dataMode;
}

void setup (void)
{
  Serial.begin (115200);   // debugging

  // have to send on master in, *slave out*
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  
  // turn on SPI in slave mode
  SPCR |= _BV(SPE);

  SPDR = 0;
  
  // Select SPI MODE
  SPIsetDataMode(SPI_MODE3);
  SPIsetBitOrder(MSBFIRST);

  // now turn on interrupts
  SPI.attachInterrupt();

  Serial.println("SPI setup done");
}  // end of setup


// SPI interrupt routine
ISR (SPI_STC_vect)
{
  byte c = SPDR;  // grab byte from SPI Data Register
  
  // For every byte recieved return x
  // E.g. (Hello, word!)->(xxxxxxxxxxx)
  SPDR = 'x';

  Serial.print((char)c); //debug
  
}

// main loop - wait for flag set in interrupt routine
void loop (void)
{

}
