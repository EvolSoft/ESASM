/*
 * ESASM (v1.0.0) by EvolSoft
 * Developer: EvolSoft
 * Website: http://www.evolsoft.tk
 * Date: 07/06/2015 11:14 AM (UTC)
 * Copyright & License: (C) 2015 EvolSoft
 * Licensed under MIT (https://github.com/EvolSoft/ESASM/blob/master/LICENSE)
 */

#include <string>
#include "../compiler/compiler.h"

using namespace std;

class Parser {
public:
    void parse(string filename, int type);
    int status;
    int getStatus();
};
