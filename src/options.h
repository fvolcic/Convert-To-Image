
#include <string>

class Options
{

public:
    /**
     * @brief Construct a new Options object
     * 
     * @param argc 
     * @param argv 
     */
    Options(int argc, char **argv);
    std::string filename;

    std::string outfile;
    bool hasOutFile = false;

    bool toImage = false;
    bool fromImage = false;

private:
    bool hasfilename = false;

    

    bool checkoptions();

    void printhelp();
};
