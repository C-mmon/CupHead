#include <iostream>

class Logger
{
public:
	static Logger& inst()
	{
		static Logger lg;
		return lg;
	}
	void inc() { ++value;}

	int get() const{
		return value;
	}

private: 
	Logger() = default; //hide the ctor
	~Logger() = default;

	Logger(const Logger&) = delete; //delete copy constructor
	Logger& operator=(const Logger&) = delete; //copy assignment
	int value =0;
};

int main()
{
	Logger::inst().inc();
	std::cout << "Logger Value "<<Logger::inst().get() <<std::endl;
}
