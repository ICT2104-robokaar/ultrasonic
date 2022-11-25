# ultrasonic - MSP432/Ultrasonic HC-SR04

<h2>Folder/Files:</h2>
<br>
<b>Ultrasonic_Filter_MovingAverage</b> folder, contains the ultrasonic code, that uses average filter algorithm to populate the accurate distance.
<br>
<b>Ultrasonic_Filter_Average</b> folder, contains the ultrasonic code, that uses average filter algorithm to populate the accurate distance.
<br>
<b>Ultrasonic_Group_Integration</b> folder, we separate and reconstruct our original ultrasonic code into Sensor.c and Sensor.h files for group integration purposes. We will create method to calculate distance and pass the value when mapping team needed it.


<h2>Description:</h2>
Our team uses <b>3 ultrasonics</b>. Left , Front and Right of the robot car <br>
Each Ultrasonic Sensor has <b>4 pins</b>. Vcc, GND, Trigger and Echo pins. <br>
<h4>Ultrasonic one (Left side of the robot car)</h4>
vcc:3.3v
Trigger: 3.6
Echo: 3.7
GND:GND 

<h4>Ultrasonic Two (Front the robot car) </h4><br>
vcc:3.3v
Trigger: 6.6
Echo: 6.7
GND:GND 

<h4>Ultrasonic Three (Right side of the robot car) </h4><br>
vcc:3.3v
Trigger: 4.6
Echo: 4.7
GND:GND 
<br>
The sensor gets triggered by supplying 10 microsecond wide pulse. <br>
The sensor generates a pulse from the echo pin with a period proportional to the distance of the obstacle from sensor. <br>
MSP432 board is connected to a computer via USB <br>

# Accelerometer - Rasberry Pico/Accelerometer MPU6050 I2C

<h2>Folder/Files:</h2>
<br>
<b>Accelerometer</b> folder, contains the Accelerometer code, that uses moving average filter algorithm to get the relevant axis and calculate the hump distance.

<h2>Description:</h2>
For PICO/Accelerometer we will be using 
<br>
(PICO)GP4:SDA(Accelerometer)
<br>
(PICO)GP5:SCL(Accelerometer)
<br>
(PICO)GND:GND(Accelerometer)
<br>
(PICO)3V3:VCC(Accelerometer)

<b>
Master: Pico
<br>
Slave : Accelerometer
<br>
