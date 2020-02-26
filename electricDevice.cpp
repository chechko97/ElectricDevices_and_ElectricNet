#include <iostream>
#include "electricDevice.h"

using namespace std;

void ElectricDevice::copyName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

ElectricDevice::ElectricDevice()
{
	name = nullptr;
	power = 0;
}

ElectricDevice::ElectricDevice(const char * name, int power) : name(nullptr)
{
	setName(name);
	setPower(power);
}
 
ElectricDevice::ElectricDevice(const ElectricDevice & other)
{
	setName(other.name);
	setPower(other.power);
}

ElectricDevice & ElectricDevice::operator=(const ElectricDevice & other)
{
	if (this != &other)
	{
		delete[] name;
		setName(other.name);
		setPower(other.power);
	}
	return *this;
}

ElectricDevice::~ElectricDevice()
{
	delete[] name;
}

void ElectricDevice::setName(const char * name)
{
	delete[] this->name;
	this->name = nullptr;

	if (name)
	{
		copyName(name);
	}
}

void ElectricDevice::setPower(int power)
{
	this->power = power;
}

char * ElectricDevice::getName() const
{
	return name;
}

int ElectricDevice::getPower() const
{
	return power;
}
