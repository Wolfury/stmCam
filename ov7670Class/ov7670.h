//preprocesser directive to keep compiler from including file mulitple times 
// replaces the standard macro : #ifndef #define ..; 
#pragma once	

//gives acces to mbed class - i2c etc?
#include "mbed.h" 

//define directives, tells compiler to replace to all following instances 
//of the identifier with the replacement
#define OV7670_ADDR (0x21<<1) 

class OV7670
{
public:
	OV7670(pinName sda, pinName scl);

	~OV7670();

	//add public function
	int writeAck(int deviceAddress);

private:
	I2C _i2c;
			
};

/*
main foulw look like

OV7670 camera(I2C_SDA,I2C_SCL);

int ack;

ack = camera.writeAck();

printf("the ack is: %d",ack);

*