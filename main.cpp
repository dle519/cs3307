//main Class
//
//@authors Authors: Rachelle Cheung, Amir Ijad, Khadija Khairullah, Asad Khan, David Le
//
//
//@brief This is the main user interface class, it allows the user to select their song and light pattern
// and plays the selections when an entrance is detected 

#include <iostream>
#include "lights.h"
#include "motionDetector.h"
#include "songPlayer.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
string songName;
int pattern;
string* songList;

/*
 * @brief allows for user to select which song they want as their anthem 
 * from the list of songs, 'songList' and lets the user choose which 
 * light pattern they would like to select for their entrance
 * 
 * 
 */
void select(){
    int song;
    for(int i = 0; i < 5; i++){
	cout<< i+1 << " - " << songList[i]<<endl;
    }
    cout << "Which song would you like? ";
    cin >> song;
    //input validation for song choice
    if (song == 1 ||  song == 2 ||  song == 3 ||  song == 4 || song == 5)
    {
	songName = songList[song-1];
    }
    else{
	songName = "default";
    }
    //getting user input for light pattern selection
    cout << "Please select your LED pattern: " << endl;
    cout << "1 - Consecutive Lights" << endl;
    cout << "2 - David Hasselhoff Pattern" << endl;
    cout << "3 - Inside + Outside Pattern" << endl;
    cout << "Which LED pattern would you like? " << endl;
    cin >> pattern;
    //input validation for light pattern selection
    if (pattern != 1 && pattern != 2 && pattern != 3)
    {
	pattern = 0;
    }
}

/*
 * @brief provides an interface for the user to select their 
 * song and light pattern. 
 * 
 * 
 * 
 */
int main(int argc, char **argv){
    char ch;
    lights l;
    motionDetector md;
    songPlayer play = songPlayer();
    songList = play.getSongs();
    //getting user input for song choice
    cout << "Welcome to Entrance Music!" << endl;
    select();

    //checking if wiringPi is setup correctly
    if(wiringPiSetup() < 0){
	cout<<"wiring setup error"<<endl;
	return 1;
    }
    l.setup();
    md.setup();
    //continuously checking if the motion detector is triggered
    while(true){
	if(md.checkPin1()==1){
		delay(100);
		if (pattern == 0)
		{
		    l.defaultPattern();
		}
		else
		{
		    l.chosenPattern(pattern);
		}
		//music trigger Make sure song file and "songPlayer" script are in the working directory!
		if (songName == "default")
		{
			play.playDefault();
		}
		else
		{
			play.playSong(songName);
		}
		l.turnOff();
	}

    }
	return 0;
}
