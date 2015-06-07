/*
 * ESASM (v1.0.0) by EvolSoft
 * Developer: EvolSoft
 * Website: http://www.evolsoft.tk
 * Date: 06/06/2015 04:03 PM (UTC)
 * Copyright & License: (C) 2015 EvolSoft
 * Licensed under MIT (https://github.com/EvolSoft/ESASM/blob/master/LICENSE)
 */

#include <iostream>
#include <string>

using namespace std;

class aad {
public:
    aad(Parser* parser, vector<string> line, string filename, int fileline);
};

aad::aad(Parser* parser, vector<string> line, string filename, int fileline){
    if(line.size() > 1){
        cout << "\n" << filename << ":" << fileline << ", Error: Invalid usage";
        parser->status = 1;
    }else{
        Compiler::addByte(0xD5);
        Compiler::addByte(0x0A);
    }
}

