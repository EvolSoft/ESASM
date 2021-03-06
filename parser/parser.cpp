/*
 * ESASM (v1.0.0) by EvolSoft
 * Developer: EvolSoft
 * Website: http://www.evolsoft.tk
 * Date: 07/06/2015 02:01 PM (UTC)
 * Copyright & License: (C) 2015 EvolSoft
 * Licensed under MIT (https://github.com/EvolSoft/ESASM/blob/master/LICENSE)
 */

#include <iostream>
#include <io.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include "parser.h"
//Opcodes
#include "opcodes\aaa.h"
#include "opcodes\aad.h"

using namespace std;

bool hasOnlySpaces(string line){
    return line.find_first_not_of(' ') == line.npos;
}

string trim(string line){
    if(!line.empty() && !hasOnlySpaces(line)){
        size_t f = line.find_first_not_of(' ');
        size_t l = line.find_last_not_of(' ');
        return line.substr(f, l-f+1);
    }else{
        return "";
    }
}

string fixSpaces(string line){
    string out;
    bool first = true;
    bool space = false;
    if(!line.empty() && !hasOnlySpaces(line)){
        for(string::const_iterator it = line.begin(); it != line.end(); it++){
            if(*it == ' '){
                if(first == false){
                    space = true;
                }
            }else if(*it != ' '){
                if(space){
                    out.push_back(' ');
                }
                out.push_back(*it);
                space = false;
                first = false;
            }else{
                space = false;
            }
        }
        return out;
    }else{
        return "";
    }
}

vector<string> split(string line) {
    vector<string> elements;
    stringstream ss(line);
    string token;
    while(getline(ss, token, ' ')) {
        elements.push_back(token);
    }
    return elements;
}

string removeComments(string line){
    bool is_string = false;
    int pos = line.length();
    for(int i = 0; i <= line.length(); i++){
        if((line[i] == '\"' && line[i] == '\'') && line[i-1] != '\\'){
            is_string = !is_string;
        }
        if(line[i] == ';' && !is_string){
            pos = i;
            break;
        }
    }
    return line.substr(0, pos);
}

void Parser::parse(string filename, int type){
    ifstream file(filename.c_str());
    string line;
    if(file.is_open()){
        status = 0;
        int fileline = 0;
        while(getline(file, line)){
            fileline += 1;
            line = trim(line);
            line = fixSpaces(line);
            line = removeComments(line);
            if(!line.empty() && !hasOnlySpaces(line)){
                vector<string> el = split(line);
                transform(el[0].begin(), el[0].end(), el[0].begin(), ::tolower);
                if(el[0].compare("aaa") == 0){
                    aaa aaa_ = aaa(this, el, filename, fileline);
                }else if(el[0].compare("aad") == 0){
                    aad aad_ = aad(this, el, filename, fileline);
                }
            }
        }
    }else{
        cout << "\nError: Can't read source file. Permission denied.";
        status = 1;
    }
}
int Parser::getStatus(){
    return status;
}
