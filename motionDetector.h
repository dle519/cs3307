// motion detector header file
//@brief sets up motion detector pin to detect motion with IR sensor
//@authors Authors: Rachelle Cheung, Amir Ijad, Khadija Khairullah, Asad Khan, David Le

class motionDetector{
    private:
        int mdPin1 = 7;
        
    public:
        void setup();
        int checkPin1();
};
