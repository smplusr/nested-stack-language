CC	:= gcc
CFLAGS	:= -Wall -v

TARGET	:= main.elf




all:	$(TARGET)


run:	$(TARGET)
	clear
	./$<


clean:
	$(RM) *.elf




%.elf:	*.c
	$(CC) $(CFLAGS) -o $@ $^
