#include <iostream>
#include "electricDevice.h"
#include "ålectricNet.h"

using namespace std;

void ElectricNet::erase()
{
	delete[] devices;
}

void ElectricNet::resize()
{
	ElectricDevice* newDevices = new ElectricDevice[2 * capacity];
	for (int i = 0; i < size; i++)
	{
		newDevices[i] = devices[i];
	}
	erase();
	devices = newDevices;
	capacity *= 2;
}

void ElectricNet::copy(const ElectricNet & other)
{
	size = other.size;
	capacity = other.capacity;
	nowConsumingEnergy = other.nowConsumingEnergy;
	maxConsumingEnergy = other.maxConsumingEnergy;
	devices = new ElectricDevice[capacity];
	for (int i = 0; i < size; i++)
	{
		devices[i] = other.devices[i];
	}
}

ElectricNet::ElectricNet()
{
	maxConsumingEnergy = 0;
	nowConsumingEnergy = 0;
	size = 0;
	capacity = 4;
	devices = new ElectricDevice[capacity];
}

ElectricNet::ElectricNet(const ElectricNet & other)
{
	copy(other);
}

ElectricNet & ElectricNet::operator=(const ElectricNet & other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

ElectricNet::ElectricNet(int maxConsumingEnergy)
{
	*this = ElectricNet();
	this->maxConsumingEnergy = maxConsumingEnergy;
}

ElectricNet::~ElectricNet()
{
	erase();
}

ElectricNet & ElectricNet::operator+=(const ElectricDevice & other)
{
	if (nowConsumingEnergy + other.getPower() <= maxConsumingEnergy)
	{
		if (capacity == size)
		{
			resize();
		}
		devices[size++] = other;
		nowConsumingEnergy += other.getPower();
	}
	return *this;
}

const ElectricNet ElectricNet::operator+(const ElectricDevice & other)
{
	*this += other;
	return *this;
}

ElectricNet & ElectricNet::operator-=(const ElectricDevice & other)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(devices[i].getName(), other.getName()) == 0)
		{
			for (int j = i; j<size - 1; j++)
			{
				devices[j] = devices[j + 1];
			}
			size--;
			nowConsumingEnergy -= other.getPower();
			return *this;
		}
	}
	cout << "device not found" << endl;
	return *this;
}

const ElectricNet ElectricNet::operator-(const ElectricDevice & other)
{
	*this -= other;
	return *this;
}

ElectricDevice  ElectricNet::operator[](int num)
{
	if (num < 0 || size == 0)
	{
		return ElectricDevice();
	}
	return devices[num];
}

bool ElectricNet::operator!()
{
	return size > 0;
}

ElectricNet ElectricNet::operator++(int)
{
	ElectricNet old = *this;
	this->maxConsumingEnergy *= 2;
	return old;
}

ElectricNet & ElectricNet::operator--()
{
	if (nowConsumingEnergy <= (maxConsumingEnergy / 2))
	{
		maxConsumingEnergy /= 2;
	}
	return *this;
}

void ElectricNet::setMaxConsumingEnergy(int maxConsumingEnergy)
{
	if (nowConsumingEnergy < maxConsumingEnergy)
	{
		this->maxConsumingEnergy = maxConsumingEnergy;
	}
}

int ElectricNet::getNowConsumingEnergy() const
{
	return nowConsumingEnergy;
}

int ElectricNet::getMaxConsumingEnergy() const
{
	return maxConsumingEnergy;
}
