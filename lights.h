// lights header file	
//@brief Assigns the output pin number for each LED light and declares functions related to lights. 
//@authors Authors: Rachelle Cheung, Amir Ijad, Khadija Khairullah, Asad Khan, David Le

class lights{
    private:
        int pattern;
	int ledPin1 = 25;
	int ledPin2 = 23;
	int ledPin3 = 22;
	int ledPin4 = 21;
	int number;

    public:
        void setup();
        void defaultPattern();
	void chosenPattern(int number);
	void turnOff();
};
