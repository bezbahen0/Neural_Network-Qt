#include "include/file.h"


std::vector<std::string> split(std::string str, char c)
{
    std::vector<std::string> array;
    std::string element = "";
    for(unsigned i = 0; i != str.length(); ++i)
    {
        if(str[i] != c)
        {
            element += str[i];
        }
        if(str[i] == c && element != "")
        {
            array.push_back(element);
            element = "";
        }
    }
    if(element != "")
    {
        array.push_back(element);
    }
    return array;
}

File::File(const char* filePath)
{
    std::string line;
    std::vector<std::string> part;
    std::ifstream file(filePath);

    if(file.is_open())
    {
        int index = 0;
        while(std::getline(file, line))
        {
            if(index == 0)
            {
                Max_Iterations = atoi(line.c_str());
            }
            else if(index == 1)
            {
                part = split(line, ' ');
                for(auto p = part.begin(); p != part.end(); p++)
                {
                    layout.push_back(atoi(p -> c_str()));
                }
            }
            else if(index % 2 == 0)
            {
                std::vector<double> i;
                part = split(line, ' ');
                for(auto p = part.begin(); p != part.end(); p++)
                {
                    i.push_back(atof(p -> c_str()));
                }
                inputs.push_back(i);
            }
            else
            {
                std::vector<double> t;
                part = split(line, ' ');
                for(auto p = part.begin(); p != part.end(); p++)
                {
                    t.push_back(atoi(p -> c_str()));
                }
                targets.push_back(t);
            }
            ++index;
        }
    }
    Data_Size = inputs.size();
    file.close();
}
