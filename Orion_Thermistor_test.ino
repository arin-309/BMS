#include<FlexCAN_T4.h>
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> Can0;

void setup(void){
Can0.begin();
Can0.setBaudRate(500000);
Can0.enableFIFO();
Can0.enableFIFOInterrupt();
Can0.onReceive(canSniff);
Can0.mailboxStatus();
}

void canSniff(const CAN_message_t &msg){
  if ( msg.id == 0x1838F380)
  {
  Serial.print(" ID: "); Serial.print(msg.id, HEX);
  Serial.print(" | ");
  Serial.print(msg.buf[0]);
  Serial.print(msg.buf[1]);
  Serial.print(" | ");
  Serial.print(msg.buf[2]);
  Serial.print(" | ");
  Serial.print(msg.buf[3]);
  Serial.print(" | ");
  Serial.print(msg.buf[4]);
  Serial.print(" | ");
  Serial.print(msg.buf[5]);
  Serial.print(" | ");
  Serial.print(msg.buf[6]);
  Serial.print(" | ");
  Serial.print(msg.buf[7]);    
  Serial.println();
  }

}

void loop(){
Can0.events();
}