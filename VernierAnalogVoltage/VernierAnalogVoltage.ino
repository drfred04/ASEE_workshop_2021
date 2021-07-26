/*
 *  VernierAnalogVoltage (v 2015.06)
 *  Reads a Vernier analog (BTA) sensor connected to pin A0 of the Arduino. This
 *  sketch displays the raw voltage reading on the Serial Monitor. As written, the 
 *  reading will be displayed every half second. Change the variable TimeBetweenReadings
 *  to change the rate.
 *    
 *  See www.vernier.com/arduino for more information.
 *  
 *  This sketch has been modified from its original form. CKF 2019
 */

// This variable will indicate how many readings have been made. It starts at zero. 
int ReadingNumber=0; 

/*  
 *  This variable will be used to estimate when each meadurement is made.
 *  It provides the size of the delay between measurements in milliseconds
 */
int TimeBetweenReadings = 500;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Label the columns of data coming out.
  Serial.print("Time (s)"); // Time each measurement is made
  Serial.print("\t");
  Serial.print("Bin #"); // Bin number for the digital voltage
  Serial.print("\t");
  Serial.println("Voltage (V)"); // Data converted to voltage
}
void loop() {
  int Count;      //This is the voltage bin number returned by the Arduino
  float Voltage;  //This is the voltage represented by the bin number in Count

  // Estimate the time that the data is taken and print this out
  Serial.print(ReadingNumber/1000.0*TimeBetweenReadings); 
  Serial.print("\t");
  
  // Read the voltage bin number from the A0 pin
  Count = analogRead(A0);
  Serial.print(Count);
  Serial.print("\t");
  
  // Convert the bin number to the corresponding voltage
  Voltage = Count / 1023 * 5.0;// convert from count to raw voltage
  Serial.println(Voltage);
  
  // Wait the indicated number of milliseconds before making the next measurement
  delay(TimeBetweenReadings);// delay in between reads for stability
  
  // increase the reading indicator by 1 (the "++" on the end of the variable does this)
  ReadingNumber++;
}
