# Terrain Mapping Using Swarm Robotics

Terrain mapping was done using FIREBIRD V(ATMEGA2560) bots, a SLAM(Simultaneous Localization And Mapping) program in python2.x and XCTU for communication using Xbee

## Getting Started

These instructions will get you a copy of the project up and running on your machine for development and testing purposes

### Prerequisites

Softwares to install

1. Arduino
2. Python2.x
3. Pylab
4. XCTU
5. AVR Bootloader

### Deployment

1. After you are done installing Arduino, you will have to make a change in preferences to generate the .hex file in an accessible directory.
	1. Open preferences.txt in 'C:\Program Files (x86)\Arduino\lib' directory in administrator mode
	2. Uncomment and change build.path to any accesible directory
	3. Save the changes

2. Open the Arduino program(.ino file) in Arduino IDE, tweak the values if required and compile the program by pressing the 'verify' button or 'Ctrl+R'. After compiling the .hex will be generated in the directory mentioned in step 1.

3. Connect the robot to your computer.

4. Open AVR Bootloader. Specify the .hex file location. Select the port that the robot is connected to. Switch on the robot. Press and hold the boot switch(switch on the right), while holding the boot switch press and release the reset switch(switch on the left), just after releasing the reset switch release the boot switch as well and click on the program button. After the program is successfully uploaded it will display a message:

	```Serial port timeout set to 5 sec.
	Found AVRBOOT on COM7!
	Entering programming mode...
	Parsing XML file for device parameters...
	Parsing '.\ATmega2560.xml'...
	#######
	Saving cached XML parameters...
	Signature matches device!
	Erasing chip contents...
	Reading HEX input file for flash operations...
	##############################################################################
	##############################################################################
	##############################################################################
	#####
	Programming Flash contents...
	Using block mode...
	###############
	Reading Flash contents...
	Using block mode...
	###############
	Comparing Flash data...
	Equal!
	Leaving programming mode...```

5. Before mounting the Xbee module on Firebird it has to configured with the master Xbee. Mount the Xbee on the Xbee adaptor and connect the adaptor to your computer. Open XCTU and add the Xbee connected. After the Xbee is added, open the configuration window and change MY(Xbee's address) and DL(Destination Xbee's address). Destination address is set to receiver Xbee's MY address. You can also change the baud rate, but the change should also reflect in the Arduino program.

6. After the Xbees are configured, mount the Xbee and sharp sensors on Firebird and connect the master Xbee to your computer using the adaptor. After the master Xbee is added in XCTU, search for other Xbees on the network and add them. Open the console window to start receiving data and logging it simultaneously. XCTU gives you an option to log data in hex format.

7. Switch on the robots from one point(common reference point), one after the other. The robots send the encoder readings to Master Xbee that are logged on the computer. Once you are done receiving the readings, switch off the robots and disconnect the Xbee.

8. Run the 'convert.py' and 'seperate.py' scripts to generate required text files for mapping. 

9. Run 'slam_02_a_filter_motor_question.py' to generate the map