
# SmileOS Makefile
# Created @ 07.10.2009 by TheFox@fox21.at


CC = gcc
NASM = nasm
LD = ld
RM = rm
MKFS = mke2fs
GRUB = grub

# -Werror -fwritable-strings -fno-builtin -fno-exceptions
CFLAGS = -Wall -m32 -ffreestanding -nostdinc -c -I. -I./src
AFLAGS = -f elf
LFLAGS = --warn-common -T link.ld

filesC = $(wildcard *.c ./src/*.c)
filesH = $(wildcard *.h ./src/*.h)
filesS = $(wildcard *.s ./asm/*.s)
filesB = $(wildcard *.bin)
filesO = boot.o main.o system.o stdlib.o screen.o gdt.o idt.o isr.o isr-asm.o process.o memory.o cpu.o test.o


smileos: clear asm1 c link img

asm1: $(filesS)
	$(foreach file, $(filesS), $(NASM) $(AFLAGS) $(file);)
	mv ./asm/*.o .

c: $(filesC) $(filesH)
	$(CC) $(CFLAGS) $(filesC)

link: asm1 c
	$(LD) $(LFLAGS) -o kernel.bin $(filesO)
	strip kernel.bin

cimg floppy.img:
	mkdir floppy || echo "floppy exists"
	
	dd if=/dev/zero of=./floppy.img bs=1024 count=1440
	$(MKFS) -F floppy.img
	chmod 644 floppy.img

	sudo mount -o loop floppy.img floppy/
	cp -r grub floppy
	$(GRUB) < grub.install
	sudo umount floppy/
	./mount.sh
	rm -rv floppy

img: floppy.img asm1 c link
	mkdir floppy || echo "floppy exists"
	sudo mount -o loop floppy.img floppy
	rm -f floppy/kernel.bin
	cp kernel.bin floppy
	sudo umount floppy/
	./mount.sh
	rm -r floppy
	date

clear:
	$(RM) -f $(filesO) $(filesB)

cleara: clear
	$(RM) -f floppy.img

bak: clear
	$(RM) -f backup.tar backup.tar.gz
	tar --exclude=floppy.img --exclude=backup* -cvf backup.tar *
	gzip backup.tar
	./bak.sh backup.tar.gz

# EOF
