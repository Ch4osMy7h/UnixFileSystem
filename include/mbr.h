//
// Created by 林智超 on 2019-06-17.
//

#ifndef UNIXFILESYSTEM_MBR_H
#define UNIXFILESYSTEM_MBR_H

#include <iostream>
#include <cstring>
#include "const.h"
using namespace std;


// size = blocksize
struct MBR {

    char bootMessage[BLOCKSIZE-1];
    MBR() {
        memset(this->bootMessage, 0, sizeof(bootMessage));
    }
};



#endif //UNIXFILESYSTEM_MBR_H
