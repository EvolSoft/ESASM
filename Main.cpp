#include <iostream>
#include <io.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "parser\parser.h"

using namespace std;

int main(int argc, char* argv[]){
    cout << "EvolSoft ESASM v1.0\n";
    cout << "(c) 2015 EvolSoft. Licensed under MIT\n";
    cout << "http://www.evolsoft.tk\n\n";
    /*FILE * file = fopen("test.txt", "w");
    fputc(0x01, file);
    fclose(file);*/
    bool has_c = false; //Doesn't repeat commands
    bool has_o = false; //Doesn't repeat commands
    for(int i = 0; i < argc; i++){
        if(strstr(argv[i], "-c") || strstr(argv[i], "-C")){
            if(!has_c){
                has_c = true;
                struct stat st;
                if(stat(argv[i+1], &st) == 0 && S_ISREG(st.st_mode)){
                    Parser* parser = new Parser(argv[i+1], 0);
                }else{
                    cout << "Source file not found";
                    return 1; //Return I/O related error
                }
            }
        }
        if(strstr(argv[i], "-o") || strstr(argv[i], "-O")){
            if(!has_o){
                has_o = true;
                //Do
            }
        }
    }
}
