FILENAME = blinkLED
#PORT = /dev/cu.usbserial-00000000
DEVICE = atmega168p
PROGAMMER = atmelice_isp
BAUD = 9600UL
CC = avr-gcc 
CFLAGS = -Wall  -std=gnu99 -Os -mmcu=$(DEVICE)

default: 
	build flash clean

build:
	$(CC) $(CFLAGS) -c $(FILENAME).c -o $(FILENAME).o
	$(CC) $(CFLAGS) -o $(FILENAME).elf $(FILENAME).o
	avr-objcopy -j .text -j .data -O ihex $(FILENAME).elf $(FILENAME).hex
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).elf

flash:
	avrdude -v -p $(DEVICE) -c $(PROGAMMER) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm $(FILENAME).o
	rm $(FILENAME).elf
	rm $(FILENAME).hex