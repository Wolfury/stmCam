#include "mbed.h"

I2C i2c(D14, D15);

// DigitalOut myled(LED1);
// DigitalOut PWDN(D9);
// DigitalOut RST(D10);

Serial pc(SERIAL_TX, SERIAL_RX);

//mbed adds the 7th bit inside the read (adds 0), or write (adds 1) functions.
// data sheet has read addre = 0x42; write addr 0x43; normally situations this is correct as it takes into account
//the LSB normally added to define if you are reading/writing to a particular addres.
//0x43>>1 = 0x21; 0x43 >>1 = 0x21

char deviceAddress = 0x21;  
char registerToRead = 0x1D;

void initMco(void)
{
    //This clock setting works to get camera noticed on rpi i2c bus
    GPIO_InitTypeDef InitStruct;
    HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_PLLCLK, RCC_MCODIV_3);   // select PLLCLK as source - 14mhz

    /*Configure GPIO pin to output clock signal at  PA8 */
    InitStruct.Pin = GPIO_PIN_8;
    InitStruct.Mode = GPIO_MODE_AF_PP;
    InitStruct.Pull = GPIO_NOPULL;
    InitStruct.Speed = GPIO_SPEED_HIGH;
    InitStruct.Alternate = GPIO_AF0_MCO;
    HAL_GPIO_Init(GPIOA, &InitStruct);
}


int main()
{
    
    initMco();
    pc.printf("running");
    wait(1);

    while(1)
    {

      
    }
    

}

