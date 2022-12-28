#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string txt;
    std::ifstream fl("input");
    
    int hold = 0;
    int bigger = 0;
    while(getline(fl, txt)) {
            if(txt == ""){
                if(hold > bigger)
                    bigger = hold;
                hold = 0;
                continue;
            }
            int i = std::stoi(txt);
            hold += i;
    }

    std::cout << bigger << std::endl;

    fl.close();
    return 0;
}
