#include "Secf.hpp"
#include <fstream>
#include <iostream>
Secf::Secf(std::string file)
: secf_file_path(file)
{
    reload();
}

bool Secf::reload()
{
    bool result = false;
    std::fstream fs;
    fs.open(secf_file_path);
    if(fs.is_open())
    {
        std::string line;        
        while(!fs.eof())
        {
            line.clear();
            std::getline(fs, line);
            int sep = line.find(" ");
            Entry entry = {
                line.substr(0, sep), 
                line.substr(sep + 1, line.length())};
            secf_index.push_back(entry);
       }
       if(secf_file_path.length()) result = true;
    }
    return result;
}

std::string Secf::get(std::string value)
{
    std::string result = "";
    for(auto it : secf_index)
    {
        if(value == it.name)
        {
            result = it.value;
            break;
        }
    }
    return result;
}

EntryVector Secf::find(std::string expr)
{
    EntryVector ev;
    for(auto it : secf_index)
    {
        if(std::regex_match(it.name, std::regex(expr)))
        {
            ev.push_back(it);
        }
    }
    return ev;
}