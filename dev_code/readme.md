Readme for using the dev board and running the code. 

CPU: STM32 F446ZE
Dev Board: Nucleo 144 

Must install: 
stlinkv-2.1 >>> Drivers that allow your computer to detect the dev board once USB is connected 

Recommended to install: 
STM CubeMX >>> Program that generates starter code for the entire range of STM32 cpus and dev boards. It allows you to select CPU and dev board, select pins to configure to desired settings(GPIO In, GPIO Out, etc), as well as other configurations. It will generate code for your development environment. I use makefiles. These folders all contain makefiles that do all the compiling. 


1.1 Install stlink 
1.2 Test stlink: If using linux, cd /dev for connected devices. If you run ls when the board is connected, "stlinkv2-1_" and some others should show up. On windows and mac, I'm assuming some prompt will pop up and tell you the board is connected. 

2.1 Compile program: run these commands from the root project directory: 
make clean 
make 

2.2 Flash file: A ".bin" file should then be generated in the build folder. This file is what you flash to the dev board. Navigate to the build folder, and flash the file using this command:
st-flash write <filename> 0x8000000



 
