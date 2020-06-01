//songPlayer class
//
//@author: Amir Ijad
//
//@brief this class is responsible for returning a list of songs to the user to select from and playing
// the song that they choose when an entrance is detected

#include "songPlayer.h"
using namespace std;


songPlayer::songPlayer()
{
    scriptFile = "songPlayer";
}

/*
 * @brief This method checks if the filename that is passed as a parameter exists / is visible
 */
inline bool songPlayer::exist(const std::string &filename) {
    ifstream file(filename);

    if (!file)
        return false;
    else
        return true;
}

/*
 * @brief Returns a string pointer to an array of all the available songs by going through the
 * folder, scraping all the files that end with ".mp3" using the grep function in terminal,
 * then saving it to a temp file called songNames and reading them from there.
 * @returns The array with all of song file names is returned
 */
string* songPlayer::getSongs(){

    system("rm songNames.txt");
    system("ls | grep .mp3 >> songNames.txt");

    ifstream file("songNames.txt");
    if(file.is_open())
    {
        string* myArray = new string[5];

        for(int i = 0; i < 5; ++i)
        {
            file >> myArray[i];

        }

        return myArray;
    }
    else{
        cout<<"error: file could not be opened"<<endl;
        return 0;
    }
}

/*
 * @brief This method takes the filename of a mp3 file and runs a bash script that plays the mp3 file
 * using the raspberry native omxplayer.
 * 
 * @parameter song filename
 */
int songPlayer::playSong(string filename) {
    string command;

    bool ex1 = exist(scriptFile);
    bool ex2 = exist(filename);

    // Checking if both the script file and the song file exist, if they dont then print out an error and return 1
    if (ex1 == false) {
        printf("Script file entered does not exist\n");
        return 1;
    } else if (ex2 == false) {
        std::cout << "Song file entered does not exist\n";
        return 1;
    } else
        command = "./" + scriptFile + " " + filename;  // This is the command that is run through the commandline
    //cout << command;
    system(command.c_str()); // running the command in the terminal
    return 0;
}


/*
 * @brief Default option playes you got me
 */
int songPlayer::playDefault() {
    playSong("You-got-me.mp3");
    return 0;
}
