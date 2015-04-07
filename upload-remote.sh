#!/bin/sh

# Configure the following two for your system
HOST=raspberrypi.local
LOADER=/home/pi/teensy_loader_cli/teensy_loader_cli

# Shouldn't need to change these
FIRMWARE_FILE=MSPF-firmware-teensy.hex
TEMP_DIR=$(ssh pi@$HOST 'mktemp -d')
MMCU=mk20dx256
scp $FIRMWARE_FILE pi@$HOST:$TEMP_DIR
ssh pi@$HOST "sudo service mspf stop; udo $LOADER -s -mmcu=$MMCU -v -w $TEMP_DIR/$FIRMWARE_FILE; rm -rf $TEMP_DIR; sudo service mspf start"
