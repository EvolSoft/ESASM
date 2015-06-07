/*
 * ESASM (v1.0.0) by EvolSoft
 * Developer: EvolSoft
 * Website: http://www.evolsoft.tk
 * Date: 07/06/2015 11:15 AM (UTC)
 * Copyright & License: (C) 2015 EvolSoft
 * Licensed under MIT (https://github.com/EvolSoft/ESASM/blob/master/LICENSE)
 */

#include <string>
#include "compiler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;

int Compiler::compile(string outfile, int type){
    ofstream out(outfile.c_str(), ios::binary);
    if(out.fail()){
        return 1;
    }else{
        ostream_iterator<unsigned char> output_iterator(out, "");
        copy(bs.begin(), bs.end(), output_iterator);
        return 0;
    }
}

void Compiler::addByte(char byte){
    bs.push_back(byte);
}

