#include "mbed.h"
#include "SDFileSystem.h"
 
// SDFileSystem(PinName mosi, PinName miso, PinName sclk, PinName cs, const char* name); 
SDFileSystem sd(SPI_MOSI, SPI_MISO, SPI_SCK, SPI_CS, "sd"); // 
 
int main() {
    printf("Hello World!\n");   
 
    mkdir("/sd/mydir", 0777);
    
    FILE *fp = fopen("/sd/mydir/sdtest.txt", "w");
    if(fp == NULL) {
        error("Could not open file for write\n");
    }
    fprintf(fp, "I cannot believe this is working");
    fclose(fp); 
 
    printf("Goodbye World!\n");
}
