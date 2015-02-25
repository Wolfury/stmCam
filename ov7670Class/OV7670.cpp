#include "mbed.h"
#include "OV7670.h"

OV7670::OV7670(pinName sda, pinName scl) : _i2c(sda,scl){
	_i2c(sda,scl);
}

	
int OV7670::writeAck(int deviceAddress)
{
	return _i2c.write(deviceAddress);
}