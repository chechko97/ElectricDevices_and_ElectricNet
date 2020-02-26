#pragma once

class ElectricNet
{
private:
	ElectricDevice * devices;
	int maxConsumingEnergy;
	int nowConsumingEnergy;
	int size;
	int capacity;
	void erase();
	void resize();
	void copy(const ElectricNet& other);

public:
	ElectricNet();
	ElectricNet(const ElectricNet& other);
	ElectricNet& operator=(const ElectricNet& other);
	ElectricNet(int maxConsumingEnergy);
	~ElectricNet();
	ElectricNet& operator+=(const ElectricDevice& other);
	const ElectricNet operator+(const ElectricDevice& other);
	ElectricNet& operator-=(const ElectricDevice& other);
	const ElectricNet operator-(const ElectricDevice& other);
	ElectricDevice operator[](int num);
	bool operator!();
	ElectricNet operator++(int);
	ElectricNet& operator--();
	void setMaxConsumingEnergy(int maxConsumingEnergy);
	int getNowConsumingEnergy() const;
	int getMaxConsumingEnergy() const;

};