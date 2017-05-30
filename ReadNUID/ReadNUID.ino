/*
 * --------------------------------------------------------------------------------------------------------------------
 * Example sketch/program showing how to read new NUID from a PICC to serial.
 * --------------------------------------------------------------------------------------------------------------------
 * This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid
 * 
 * Example sketch/program showing how to the read data from a PICC (that is: a RFID Tag or Card) using a MFRC522 based RFID
 * Reader on the Arduino SPI interface.
 * 
 * When the Arduino and the MFRC522 module are connected (see the pin layout below), load this sketch into Arduino IDE
 * then verify/compile and upload it. To see the output: use Tools, Serial Monitor of the IDE (hit Ctrl+Shft+M). When
 * you present a PICC (that is: a RFID Tag or Card) at reading distance of the MFRC522 Reader/PCD, the serial output
 * will show the type, and the NUID if a new card has been detected. Note: you may see "Timeout in communication" messages
 * when removing the PICC from reading distance too early.
 * 
 * @license Released into the public domain.
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno           Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];
byte car1[4];
byte car2[4];
byte car3[4];
boolean spot1 = false;
boolean spot2 = false;
boolean spot3 = false;

void setup() { 
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  // * LED setup pins
    pinMode(2, OUTPUT);   
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);

  //Serial.println(F("This code scan the MIFARE Classsic NUID."));
  //Serial.print(F("Using the following key:"));
  //printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
  Serial.println("Garage is OPEN");
}

void clr() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW); 
}
void segment(char number) {
  const int m = 2; //Middle
  const int ol = 3; //top left
  const int o = 4; //top
  const int lor = 5; //top right
  const int ul = 6; //down left
  const int u = 7; //down
  const int ur = 8; //down right 
  //Begin switch
  switch (number) {
    
    case '2':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(u, HIGH);
    break;
    
    case '3':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(u, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ur, HIGH);
    break;
    
    case '1':
    clr();
    digitalWrite(lor, HIGH);
    digitalWrite(ur, HIGH);
    break;
    
    case '4':
    clr();
    digitalWrite(ol, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ur, HIGH);
    break;
    
    case '5':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(u, HIGH);
    break;
    
    case '6':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(u, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(ur, HIGH);
    break;
    
    case '7':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ur, HIGH);
    break;
    
    case '8':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(u, HIGH);
    break;
    
    case '9':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(u, HIGH);
    break;
    
    case '0':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(u, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(ul, HIGH);
    break;
  
    case 'a':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(ul, HIGH);
    break;  
    
    default:
    clr();
    break;
    
    case 'b':
    clr();
    digitalWrite(u, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(ol, HIGH);
    break;  
    
    case 'c':
    clr();
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(u, HIGH);
    digitalWrite(o, HIGH);
    break;
    
    case 'd':
    clr();
    digitalWrite(u, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(lor, HIGH);
    break;
    
    case 'e':
    clr();
    digitalWrite(u, HIGH);
    digitalWrite(o, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(ol, HIGH);
    break;
    
    case 'f':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    break;
    
    case 'g':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(u, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    break;
    
    case 'h':
    clr();
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(m, HIGH);
    break;
    
    case 'i':
    clr();
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    break;
    
    case 'j':
    clr();
    digitalWrite(lor, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(u, HIGH);
    digitalWrite(ul, HIGH);
    break;
    
    case 'k':
    clr();
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(u, HIGH);
    digitalWrite(m, HIGH);
    break;
    
    case 'l':
    clr();
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(u, HIGH);
    break;
    
    case 'm':
    clr();
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(o, HIGH);
    break;
    
    case 'n':
    clr();
    digitalWrite(ur, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(m, HIGH);
    break;
    
    case 'o':
    clr();
    digitalWrite(m, HIGH);
    digitalWrite(u, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(ur, HIGH);
    break;
    
    case 'p':
    clr();
    digitalWrite(m, HIGH);
    digitalWrite(o, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ul, HIGH);
    break;
    
    case 'q':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ur, HIGH);
    break;
    
    case 'r':
    clr();
    digitalWrite(o, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(ul, HIGH);
    break;
    
    case 's':
    segment('5');
    break;
    
    case 't':
    segment('7');
    break;
    
    case 'u':
    clr();
    digitalWrite(u, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(lor, HIGH);
    break;
    
    case 'v':
    clr();
    digitalWrite(u, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(ur, HIGH);
    break;
    
    case 'w':
    clr();
    digitalWrite(u, HIGH);
    digitalWrite(m, HIGH);
    digitalWrite(ul, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(lor, HIGH);
    break;
    
    case 'x':
    segment('h');
    break;
    
    case 'y':
    clr();
    digitalWrite(u, HIGH);
    digitalWrite(ur, HIGH);
    digitalWrite(lor, HIGH);
    digitalWrite(ol, HIGH);
    digitalWrite(m, HIGH);
    break;
    
    case 'z':
    segment('2');
    break;
  }
}


void loop() {

  // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  boolean isCar1 = true && spot1;
  boolean isCar2 = true && spot2;
  boolean isCar3 = true && spot3;
  int x;
  for(x=0; x<4 && isCar1; x++) {
    if(rfid.uid.uidByte[x] != car1[x]) {
      isCar1 = false;
      break;
    }
  }
  for(x=0; x<4 && isCar2; x++) {
    if(rfid.uid.uidByte[x] != car2[x]) {
      isCar2 = false;
      break;
    }
  }
  for(x=0; x<4 && isCar3; x++) {
    if(rfid.uid.uidByte[x] != car3[x]) {
      isCar3 = false;
      break;
    }
  }

  if(isCar1) {
    Serial.println("Car1 leaving");
    printHex(car1, 4);
    spot1 = false;
    for(x=0; x<4; x++) {
      car1[x] = 0xFF;
    }
    segment('1');
    delay(500);
    clr();
    /*segment('L');
    delay(500);
    clr();
    segment('E');
    delay(500);
    clr();
    segment('F');
    delay(500);
    clr();
    segment('T');
    clr();
    */
  } else if(isCar2) {
    Serial.println("Car2 leaving");
    printHex(car2, 4);
    spot2 = false;
    for(x=0; x<4; x++) {
      car2[x] = 0xFF;
    }
  } else if(isCar3) {
    Serial.println("Car3 leaving");
    printHex(car3, 4);
    spot3 = false;
    for(x=0; x<4; x++) {
      car3[x] = 0xFF;
    }
  } else {
    if(!spot1) {
      Serial.println(F("A new car is going to take spot1"));
      printHex(rfid.uid.uidByte, rfid.uid.size);
      spot1 = true;
      for(x=0; x<4; x++) {
        car1[x] = rfid.uid.uidByte[x];
      }
      /*segment('c');
      delay(500);
      clr();
      segment('a');
      delay(500);
      clr();
      segment('r');
      delay(500);
      clr();*/
      segment('1');
      delay(500);
      clr();
    } else if(!spot2) {
      Serial.println(F("A new car is going to take spot2"));
      printHex(rfid.uid.uidByte, rfid.uid.size);
      spot2 = true;
      for(x=0; x<4; x++) {
        car2[x] = rfid.uid.uidByte[x];
      }
      /*segment('c');
      delay(500);
      segment('a');
      delay(500);
      segment('r');
      delay(500);
      segment('2');
      delay(500);*/
    } else if(!spot3) {
      Serial.println(F("A new car is going to take spot3"));
      printHex(rfid.uid.uidByte, rfid.uid.size);
      spot3 = true;
      for(x=0; x<4; x++) {
        car3[x] = rfid.uid.uidByte[x];
      }
      /*segment('c');
      delay(500);
      segment('a');
      delay(500);
      segment('r');
      delay(500);
      segment('3');
      delay(500);*/
    } else {
      Serial.println(F("Garage Full, come back later"));
      /*segment('f');
      delay(500);
      segment('u');
      delay(500);
      segment('l');
      delay(500);
      segment('l');
      delay(500);*/
    }
  }

 

  
  /*
  if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) {
    Serial.println(F("A new card has been detected."));
    

    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    Serial.println(F("The NUID tag is:"));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
    Serial.print(F("In dec: "));
    printDec(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
  }
  else {
    Serial.println(F("Card read previously."));
    printHex(rfid.uid.uidByte, rfid.uid.size);
  }
  */
  

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}


/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/**
 * Helper routine to dump a byte array as dec values to Serial.
 */
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
