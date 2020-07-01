Just some simple code for parsing output from a DS4 Controller.
GUI support is coming!
Building is simple and easy, simple point to the header of the hidapi share lib or archive.
My particular build script can be seen within the Makefile.
Installing the archive and binary for hidapi is dirt simple.
For Linux:
	Im running Manjaro's I3 -  an Arch based system so I just ran:
		pacman -S hidapi;to install pacman
		pacman -Ql hidapi; to find where the shared library files are
	For Mac OSX:
		brew install hidapi
	-Note that with Mac the location of hidapi should be placed inside /usr/local/Cellar
	For Windows:
		I have no stinking idea. You're on your own XD.
		No but seriously, just use the Ubuntu subsystem
		Run:  sudo apt-get install hidapi
		Then find those shared lib files and point it to g++ and link.
--TODO--
Finish adding support the full list of buttons for isPressed()
Make better documentation since nobody with brain cells will understand my code.
Tell everyone how awesome Manjaro I3 is :)

