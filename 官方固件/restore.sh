#! /bin/bash
flashrom -p serprog:dev=/dev/ttyACM0:4000000 -w backup.bin  
