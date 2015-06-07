/*
 * ESASM (v1.0.0) by EvolSoft
 * Developer: EvolSoft
 * Website: http://www.evolsoft.tk
 * Date: 07/06/2015 02:07 PM (UTC)
 * Copyright & License: (C) 2015 EvolSoft
 * Licensed under MIT (https://github.com/EvolSoft/ESASM/blob/master/LICENSE)
 */

#include <iostream>
#include <string>

using namespace std;

class aaa {
public:
    aaa(Parser* parser, vector<string> line, string filename, int fileline);
};

aaa::aaa(Parser* parser, vector<string> line, string filename, int fileline){
    if(line.size() > 1){
        cout << "\n[" << filename << ":" << fileline << "] Error: Invalid usage";
        parser->status = 1;
    }else{
        Compiler::addByte(0x37);
    }
}
