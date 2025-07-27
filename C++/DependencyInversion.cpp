class LightBulb
{
public:
	void turnOn()
	{
		cout << "Bulb" <<endl;
	}

	void turnOff()
	{
		cout << "Turn Bulb off" << endl;
	}
};


class Switch
{
	LightBulb* bulb;
public:
	Switch(LightBulb* b): bulb(b)
	{}

	void operate(bool on)
	{
		if(on)
		{
			bulb->turnOn();
		}
		else
		{
			bulb->turnOff();
		}
	}
}

//Its more better to create a interface
class ISwitchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~ISwitchable() = default;
};

class LightBulb : public ISwitchable {
public:
    void turnOn() override { std::cout << "Bulb ON\n"; }
    void turnOff() override { std::cout << "Bulb OFF\n"; }
};


class Switch {
    ISwitchable* device;
public:
    Switch(ISwitchable* d) : device(d) {}

    void operate(bool on) {
        if (on) device->turnOn();
        else    device->turnOff();
    }
};
