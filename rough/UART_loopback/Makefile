FILE1 = uart_loopback
FILE2 = USART
#PORT = /dev/cu.usbserial-00000000
DEVICE = atmega168p
PROGAMMER = atmelice_isp
BAUD = 9600
CC = avr-gcc 
CFLAGS = -Wall  -std=gnu99 -Os -mmcu=$(DEVICE)

build:
	$(CC) $(CFLAGS) -c $(FILE1).c  -o $(FILE1).o
	$(CC) $(CFLAGS) -o $(FILE1).elf $(FILE1).o
	avr-objcopy -j .text -j .data -O ihex $(FILE1).elf $(FILE1).hex
	avr-size --format=avr --mcu=$(DEVICE) $(FILE1).elf

flash:
	avrdude -v -p $(DEVICE) -c $(PROGAMMER) -b $(BAUD) -U flash:w:$(FILE1).hex:i

clean:
	rm $(FILE1).o
	rm $(FILE1).elf
	rm $(FILE1).hex

default: 
	build flash clean