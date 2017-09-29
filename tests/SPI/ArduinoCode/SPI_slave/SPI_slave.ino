#include <SPI.h>

char buf [100];
volatile byte pos;
volatile boolean process_it;

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
  
  // get ready for an interrupt 
  pos = 0;   // buffer empty
  process_it = false;

  // now turn on interrupts
  SPI.attachInterrupt();

  Serial.println("SPI setup done");
}  // end of setup


// SPI interrupt routine
ISR (SPI_STC_vect)
{
  byte c = SPDR;  // grab byte from SPI Data Register

  Serial.print((char)c); //debug
  
  // add to buffer if room
  if (pos < sizeof buf) {
    buf [pos++] = c;
    
    // example: newline means time to process buffer
    if (c == '\n')
      process_it = true;
      
  }  // end of room available

  // Return x
  // E.g. ("Hello, word!)->(xxxxxxxxxx!)
  // Only works with on byte, not in trasfers of buffers
  //  if (c>10) {
  //    SPDR = 'x';
  //  }
}

// main loop - wait for flag set in interrupt routine
void loop (void)
{
  if (process_it) {
    buf [pos] = 0;  
    Serial.print (buf);
    SPDR = 0;
    pos = 0;
    process_it = false;
  }  // end of flag set
    
}
