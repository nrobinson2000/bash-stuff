#include "Particle.h"

SYSTEM_MODE(MANUAL);

String readString = "";

void parseCommand(String command)
{
  if (command == "r")
  {
    for (size_t i = 0; i < 100; i++) {
      Serial.println("Waddup "+String(millis()));
    }
    Serial.println("EOF");
  }
}


void setup()
{
  Serial.begin(9600);
}

void loop()
{


  while (Serial.available()) // While receiving characters over serial...
  {
    delay(3); // Necessary delay
    char c = Serial.read(); // Read the character
    readString += c; // Add the character to the string
  }

  readString.trim();

  if (readString.length() > 0) // If a string has been read...
  {
    Serial.println("Received: " + readString); // Send the parsed string to Serial for debugging
    parseCommand(readString); // Do something with the string...
    readString = ""; // Clear the string
  }

}

