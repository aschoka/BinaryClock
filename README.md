# BinaryClock


# This is an implementation of the WiringPi library available at http://wiringpi.com/ used to create a clock that displays time in a binary sequence of LEDs.

# For instructions on downloading and setting up the WiringPi library, refer to: http://wiringpi.com/download-and-install/.



# This code was written on a Raspberry Pi 3 Model B and requires 17 GPIO pins for the clock display, meaning the code can be implemented on any model of the RPi without the need to add additional GPIO pins.  

# The RaspberryPi.org site contains a guide to using the GPIO pins on the Pi Model A and B here: https://www.raspberrypi.org/documentation/usage/gpio/README.md

# A guide to using the GPIO pins on the Model A+, B+, 2B, and 3B is here: https://www.raspberrypi.org/documentation/usage/gpio-plus-and-raspi2/README.md


# In order to correctly wire the LEDs to the GPIO pins on the RPi, refer to the diagrams here: http://wiringpi.com/pins/ , or simply call "gpio readall" from the command line.  The pin numbers used in the code are the WiringPi pin numbers, which are different than the physical board pin numbers.  
