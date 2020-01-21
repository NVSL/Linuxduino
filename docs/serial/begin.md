## Serial.begin()

## Syntax 
```
Serial.begin(baud) // Only available with setSerial()
Serial.begin(baud, config) // Only available with setSerial()
Serial.begin(serialPort, baud)
Serial.begin(serialPort, baud, config) 
``` 
See [setSerial()](/serial/getset).

## Parameters

***serialPort***:   


***baud***:   

*Avaiable baud rate speeds*:   

50   
75   
110   
134   
150   
200   
300   
600   
1200   
1800   
2400   
9600   
19200   
38400   
57600   
115200   
230400   
460800   
500000   
576000   
921600   
1000000   
1152000   
1500000   
2000000   
2500000   
3000000   
3500000   
4000000

default = 9600

***config***:   

*Available serial port data transmission configurations*

**SERIAL_5N1**: Opens serial as -> data: 5 bits, partiy: None, stop bits: 1 bit    
**SERIAL_6N1**: Opens serial as -> data: 6 bits, partiy: None, stop bits: 1 bit   
**SERIAL_7N1**: Opens serial as -> data: 7 bits, partiy: None, stop bits: 1 bit   
**SERIAL_8N1**: Opens serial as -> data: 8 bits, partiy: None, stop bits: 1 bit   
**SERIAL_5N2**: Opens serial as -> data: 5 bits, partiy: None, stop bits: 2 bit   
**SERIAL_6N2**: Opens serial as -> data: 6 bits, partiy: None, stop bits: 2 bit   
**SERIAL_7N2**: Opens serial as -> data: 7 bits, partiy: None, stop bits: 2 bit   
**SERIAL_8N2**: Opens serial as -> data: 8 bits, partiy: None, stop bits: 2 bit   
**SERIAL_5E1**: Opens serial as -> data: 5 bits, partiy: Even, stop bits: 1 bit   
**SERIAL_6E1**: Opens serial as -> data: 6 bits, partiy: Even, stop bits: 1 bit   
**SERIAL_7E1**: Opens serial as -> data: 7 bits, partiy: Even, stop bits: 1 bit   
**SERIAL_8E1**: Opens serial as -> data: 8 bits, partiy: Even, stop bits: 1 bit   
**SERIAL_5E2**: Opens serial as -> data: 5 bits, partiy: Even, stop bits: 2 bit   
**SERIAL_6E2**: Opens serial as -> data: 6 bits, partiy: Even, stop bits: 2 bit   
**SERIAL_7E2**: Opens serial as -> data: 7 bits, partiy: Even, stop bits: 2 bit   
**SERIAL_8E2**: Opens serial as -> data: 8 bits, partiy: Even, stop bits: 2 bit   
**SERIAL_5O1**: Opens serial as -> data: 5 bits, partiy: Odd, stop bits: 1 bit   
**SERIAL_6O1**: Opens serial as -> data: 6 bits, partiy: Odd, stop bits: 1 bit   
**SERIAL_7O1**: Opens serial as -> data: 7 bits, partiy: Odd, stop bits: 1 bit   
**SERIAL_8O1**: Opens serial as -> data: 8 bits, partiy: Odd, stop bits: 1 bit   
**SERIAL_5O2**: Opens serial as -> data: 5 bits, partiy: Odd, stop bits: 2 bit   
**SERIAL_6O2**: Opens serial as -> data: 6 bits, partiy: Odd, stop bits: 2 bit   
**SERIAL_7O2**: Opens serial as -> data: 7 bits, partiy: Odd, stop bits: 2 bit   
**SERIAL_8O2**: Opens serial as -> data: 8 bits, partiy: Odd, stop bits: 2 bit  

default = SERIAL_8N1

## Example

### Javascript 

### C++