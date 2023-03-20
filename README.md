# MSP430G2553 Distance Measurement with HC-05 Bluetooth Module

This project is a distance measurement system using an MSP430G2553 microcontroller and an HC-05 Bluetooth module. The system measures the distance using a photoresistor and transmits the data to a mobile device via Bluetooth.

## Components
- MSP430G2553 Microcontroller
- HC-05 Bluetooth Module
- 16x2 LCD Display

![MSP430G2553](https://www.ti.com/content/dam/ticom/images/products/ic/microcontrollers/msp/evm-board/msp-exp430g2et-board-horizontal.png:small)


There are the main components, you can find the others in altium file.

## Usage
1. Clone this repository to your local machine.
2. Open the project in IAR Studio.
3. Connect the MSP430G2553 LaunchPad to your computer.
4. Change the desired MAC adress to find in the code. (Also look at Calibration step)
5. Build and flash the code to the LaunchPad.
6. Connect MSP430 micro controller to your PCB.
7. Power on the system.
8. It will automatically inquire the device you need to find.
10. You will start receiving distance measurements in real-time!

## Code Explanation
The code starts by initializing the necessary GPIO pins and UART communication. You need to enter the Mac adress of the desired device. Than it will inquire that device, once it found it, will displays the distance on the LCD display. The code also includes error handling for cases where the Bluetooth module fails to connect.

## Calibration
To calibration, you will need to measure the RSSI value in one meter. You have to change this value in code. This value will use in a formula that mesure the distance. Don't forget that you have to mesure this one meter RSSI value environment spesific. 

![Distance formula](https://itbackyard.com/wp-content/uploads/2018/05/genericlogdistance.jpg)
