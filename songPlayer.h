//
// @author Created by Amir Ijad on 2019-10-31.
//

#ifndef SOUND_SONGPLAYER_H
#define SOUND_SONGPLAYER_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
using namespace std;



class songPlayer {
private:
    string scriptFile;
    inline bool exist(const std::string &filename);

public:
    songPlayer();
    string* getSongs();
    int playSong(string filename);
    int playDefault();
};


#endif //SOUND_SONGPLAYER_H
