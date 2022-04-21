#pragma once

#include <fstream>
#include <string>

std::string loadTxtIntoString(std::string _FileName)
{

    std::ifstream ifs(_FileName);
    std::string content((std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));

    return content;
}