class Animal
{
	//we are declaring const over here 
	virtual void animalSpeak() const =0;
	virtual ~Animal()= default;
};

class Bird: public Animal{
	void animalSpeak() const overide
	{
		std::cout <<"bird is speaking" <<std::endl;
	}

};


class Iflyable
{
	public void fly() const =0;
	virtual ~Iflyable() = default;
}


class Sparrow : public Bird, public IFlyable {
public:
    void fly() const override {
        std::cout << "Sparrow flying!" << std::endl;
    }
};

class Penguin : public Bird {
    // No fly() at all – it's not part of the IFlyable interface
};
