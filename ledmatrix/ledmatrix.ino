#include "LedControl.h"

/*
 pin 2 is connected to the DataIn 
 pin 4 is connected to the CLK 
 pin 3 is connected to LOAD 
 ***** Please set the number of devices you have *****
 */
LedControl lc=LedControl(5,7,6,4);

const int addr0 = 0;  
const int addr1 = 1; 
const int addr2 = 2; 
const int addr3 = 3; 

void setup() {
  /*The MAX72XX is in power-saving mode on startup*/
  lc.shutdown(addr0,false);
  lc.shutdown(addr1,false);
  lc.shutdown(addr2,false);
  lc.shutdown(addr3,false);
  
  /* Set the brightness to max values */
  lc.setIntensity(addr0,8);
  lc.setIntensity(addr1,8);
  lc.setIntensity(addr2,8);
  lc.setIntensity(addr3,8);
  
  /* and clear the display */
  lc.clearDisplay(addr0);
  lc.clearDisplay(addr1);
  lc.clearDisplay(addr2);
  lc.clearDisplay(addr3);

  lc.setRow(addr0, 1, B01000000);
  lc.setRow(addr1, 1, B10000000);
  lc.setRow(addr2, 1, B00000001);
  lc.setRow(addr3, 1, B01010101);
  
//  lc.setRow(addr3, 3, 255);
  
  // turn on all LEDs for a test
//  for(int row=0;row<8;row++) {
//    lc.setRow(addr0, row, 255);
//    lc.setRow(addr1, row, 255);
//    lc.setRow(addr2, row, 255);
//    lc.setRow(addr3, row, 255);
//    delay(100);
//  }
  delay(300);
}

//void showNeutral() {
//  byte left[8] = {
//B00000000,
//B00111100,
//B01000010,
//B01011010,
//B01011010,
//B01000010,
//B00111100,
//B00000000};
//
//  displayEmotion(left, left);
//}
//
//void showAnger() {
//  byte left[8] = {
//B00000000,
//B00000000,
//B01111110,
//B01011010,
//B01011010,
//B00100100,
//B00011000,
//B00000000};
//  byte right[8] = {
//B00000000,
//B00000000,
//B01111110,
//B01011010,
//B01011010,
//B00100100,
//B00011000,
//B00000000};
//
//  displayEmotion(left, right);
//}
//
//void showSadness() {
//  byte left[8] = {
//B00000000,
//B00001100,
//B00010010,
//B00111010,
//B01011010,
//B01000010,
//B00111100,
//B00000000};
//  byte right[8] = {
//B00000000,
//B00110000,
//B01001000,
//B01011100,
//B01011010,
//B01000010,
//B00111100,
//B00000000};

//  displayEmotion(left, right);
//}
//
//void displayEmotion(byte left[8], byte right[8]) {
//  lc.clearDisplay(addrL);
//  lc.clearDisplay(addrR);
//  for(int row=0;row<8;row++) {
//    lc.setRow(addrL,row,left[row]);
//    lc.setRow(addrR,row,right[row]);
//  }
//}

void loop() {
//  showNeutral();
//  delay(4000);
//  showAnger();
//  delay(4000);
//  showSadness();
//  delay(4000);
}
