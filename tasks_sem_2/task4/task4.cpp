#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Device
{
protected:
	std::string m_name;
public:
	Device(const std::string& name)
	{
		this->m_name = name;
	}
	virtual void poll() = 0;
	virtual ~Device() {}
};
class ElectricityMeter : public Device
{
public:
	explicit ElectricityMeter(const std::string& name) : Device(name) {}
	void poll() override
	{
		std::cout << this->m_name << std::endl;
	}
};
class DSIBlock : public Device
{
public:
	explicit DSIBlock(const std::string& name) : Device(name) {}
	void poll() override
	{
		std::cout << this->m_name << std::endl;
	}
};
class HeatControlBlock : public Device
{
public:
	explicit HeatControlBlock(const std::string& name) : Device(name) {}
	void poll() override
	{
		std::cout << this->m_name << std::endl;
	}
};


struct {
private:
	std::vector<Device*> m_devices;
public:
	void pollAll()
	{
		for (auto n : m_devices)
		{
			n->poll();
		}
	}
	void setDevice(Device* newDevices)
	{
		m_devices.push_back(newDevices);
	}
}Configuration;
namespace DeviceBase
{
	std::string EMs[] = {
		"Меркурий 230", "Нева МТ314", "Энергомера CE308"
	};
	std::string DSIs[] = {
			"Reallab NL-16HV", "Приборэлектро PRE-16", "Энергосервис ЭНМВ-1-24"
	};
	std::string HCs[] = {
			"Ouman S203", "Овен ТРМ232"
	};
}


int main() {
	setlocale(LC_ALL, "ru");
	std::fstream f("conf.txt");
	std::string currDevice;

	while (getline(f, currDevice))
	{
		int n = sizeof(DeviceBase::EMs) / sizeof(std::string);
		for (int i = 0; i < n; ++i)
		{
			if (DeviceBase::EMs[i] == currDevice)
			{
				ElectricityMeter* EM = new ElectricityMeter(currDevice);
				Configuration.setDevice(EM);
			}
		}
		n = sizeof(DeviceBase::DSIs) / sizeof(std::string);
		for (int i = 0; i < n; ++i)
		{
			if (DeviceBase::DSIs[i] == currDevice)
			{
				DSIBlock* DSI = new DSIBlock(currDevice);
				Configuration.setDevice(DSI);
			}
		}
		n = sizeof(DeviceBase::HCs) / sizeof(std::string);
		for (int i = 0; i < n; ++i)
		{
			if (DeviceBase::HCs[i] == currDevice)
			{
				HeatControlBlock* HC = new HeatControlBlock(currDevice);
				Configuration.setDevice(HC);
			}
		}
	}
	Configuration.pollAll();
	return 0;
}
