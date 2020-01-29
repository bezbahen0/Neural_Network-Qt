#ifndef FILE_H
#define FILE_H

#include <vector>
#include <string>
#include <fstream>

class File
{
private:
    int Max_Iterations;
    int Data_Size;
    std::vector<unsigned> layout;
    std::vector<std::vector<double>> inputs;
    std::vector<std::vector<double>> targets;
public:
    File(const char* filePath);
    std::vector<double> getInputs(const int index){return inputs[index]; }
    std::vector<double> getTargets(const int index){return targets[index]; }
    std::vector<unsigned> getLayout(){return layout; }
    int getMaxIterations(){return Max_Iterations; }
    int getDataSize(){return Data_Size; }
};

#endif // FILE_H
