/*
 * ESASM (v1.0.0) by EvolSoft
 * Developer: EvolSoft
 * Website: http://www.evolsoft.tk
 * Date: 06/06/2015 04:33 PM (UTC)
 * Copyright & License: (C) 2015 EvolSoft
 * Licensed under MIT (https://github.com/EvolSoft/ESASM/blob/master/LICENSE)
 */

#include <string>
#include <vector>

using namespace std;

static vector<unsigned char> bs;

class Compiler {
public:
    static int compile(string outfile, int type);
    void setType(int type);
    void getType();
    static void addByte(char byte);
    void addByte(char byte, int position);
};
