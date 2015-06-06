/*
 * ESASM (v1.0.0) by EvolSoft
 * Developer: EvolSoft
 * Website: http://www.evolsoft.tk
 * Date: 06/06/2015 03:57 PM (UTC)
 * Copyright & License: (C) 2015 EvolSoft
 * Licensed under MIT (https://github.com/EvolSoft/ESASM/blob/master/LICENSE)
 */

#include <iostream>
#include <string>
#include <io.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "parser\parser.h"

using namespace std;

int main(int argc, char* argv[]){
    Parser parser;
    Compiler compiler;
    string rawname;
    cout << "EvolSoft ESASM v1.0.0\n";
    cout << "(C) 2015 EvolSoft. Licensed under MIT\n";
    cout << "http://www.evolsoft.tk\n\n";
    bool has_c = false; //Doesn't repeat commands
    bool has_o = false; //Doesn't repeat commands
    for(int i = 0; i < argc; i++){
        if(strstr(argv[i], "-c") || strstr(argv[i], "-C")){
            if(!has_c){
                has_c = true;
                struct stat st;
                if(stat(argv[i+1], &st) == 0 && S_ISREG(st.st_mode)){
                    parser.parse(argv[i+1], 0);
                    int lastindex = string(argv[i+1]).find_last_of(".");
                    rawname = string(argv[i+1]).substr(0, lastindex);
                }else{
                    cout << "Error: Source file not found";
                    return 1; //Return I/O related error
                }
            }
        }
        if(strstr(argv[i], "-o") || strstr(argv[i], "-O")){
            if(!has_o){
                has_o = true;
                rawname = argv[i+1];
            }
        }
    }
    if(parser.getStatus() == 0 && has_c){
        int ret = compiler.compile(rawname, 1);
        if(ret == 0){
            cout << "Success: Compilation complete!";
        }
    }
}
