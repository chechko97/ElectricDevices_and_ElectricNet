#pragma once

class ElectricDevice
{
private:
	char* name;
	int power;
	void copyName(const char* name);

public:
	ElectricDevice();
	ElectricDevice(const char* name, int power);
	ElectricDevice(const ElectricDevice& other);
	ElectricDevice& operator=(const ElectricDevice& other);
	~ElectricDevice();
	void setName(const char* name);
	void setPower(int power);
	char* getName() const;
	int getPower() const;
};