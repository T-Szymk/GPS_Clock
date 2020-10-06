#FILE = blinkLED
#PORT = /dev/cu.usbserial-00000000
#DEVICE = atmega168p
PROGAMMER = atmelice_isp
BAUD = 9600
CC = avr-gcc 
CFLAGS = -Wall  -std=gnu99 -Os -mmcu=$(DEVICE)

build:
	$(CC) $(CFLAGS) -c $(FILE).c -o $(FILE).o
	$(CC) $(CFLAGS) -o $(FILE).elf $(FILE).o
	avr-objcopy -j .text -j .data -O ihex $(FILE).elf $(FILE).hex
	avr-size --format=avr --mcu=$(DEVICE) $(FILE).elf

flash:
	avrdude -v -p $(DEVICE) -c $(PROGAMMER) -b $(BAUD) -U flash:w:$(FILE).hex:i

clean:
	rm $(FILE).o
	rm $(FILE).elf
	rm $(FILE).hex

default: 
	build flash clean