#include <xinu.h>
#include <string.h>

/**
 * Prints out the number of bytes in the text, data, and bss segments.
 * This is done by subtracting the start address from the end address.
 * Then, those corresponding addresses are printed to the console in
 * hexadecimal format.
**/
void printsegaddress(void) {
	kprintf("%10d bytes of text segment", (uint32)&etext - (uint32)&text);
	kprintf("           [0x%08X to 0x%08X]\n", (uint32)&text, (uint32)&etext - 1);
	kprintf("%10d bytes of data segment", (uint32)&edata - (uint32)&data);
	kprintf("           [0x%08X to 0x%08X]\n", (uint32)&data, (uint32)&edata - 1);
	kprintf("%10d bytes of bss segment ", (uint32)&ebss - (uint32)&bss);
	kprintf("           [0x%08X to 0x%08X]\n", (uint32)&bss, (uint32)&ebss - 1);
}
