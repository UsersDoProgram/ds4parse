DS4Parse ReadMe.md
===================


Just some simple code for parsing output from a DS4 Controller.<br>
GUI support is coming!<br>
Building is simple and easy, simple point to the header of the hidapi share lib or archive.<br>
My particular build script can be seen within the Makefile.<br>
Installing the archive and binary for hidapi is dirt simple.<br>

<pre>

For Linux:
	I'm running Manjaro's I3 -  an Arch based system so I just ran:
		pacman -S hidapi;to install pacman
		pacman -Ql hidapi; to find where the shared library files are
	For Mac OSX:
		brew install hidapi
	-Note that with Mac the location of hidapi should be inside:
		 /usr/local/Cellar
	For Windows:
		I have no stinking idea. You're on your own XD.
		No but seriously, just use the Ubuntu subsystem
		Run:  sudo apt-get install hidapi
		Then find those shared lib files and point it to g++ and link.
</pre>
-***
Example of how to compile code that makes use of `#include "DS4.h"`:<br>

     g++ -std=c++14 -Wall -L/usr/lib/libhidapi-hidraw.so.0.0.0 -lhidapi-hidraw  ../lib/DS4.o main.cpp -o main
<br>Where "../lib/DS4.o" is the location of the DS4 object file.<br>
-TODO

***

 -  **DS4Display**
	 - Add GUI Button Display Example
 - **DS4RPI**
	 - Add Protobuf serialization
	 - Add a server capabilities for sending DS4 Data to RPI
 - **DS4-2-PC** 
	 - Keyboard and Mouse Being controlled via DS4 DPAD and Axis 
 - Make better documentation since nobody with brain cells will understand my code.
 - Tell everyone how awesome Manjaro I3 is :)
