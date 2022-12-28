#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string txt;
    std::ifstream fl("input");

    int hold = 0;
    int bigger[3] = {0,0,0};
    while(getline(fl, txt)) {
            if(txt == ""){
                if(hold > bigger[0]){
                    bigger[0] = hold;
                }else if(hold > bigger[1]){
                    bigger[1] = hold;
                }else if(hold > bigger[2]){
                    bigger[2] = hold;
                }
                hold = 0;
                continue;
            }
            int i = std::stoi(txt);
            hold += i;
    }

    std::cout << bigger[0] + bigger[1] +  bigger[2] << std::endl;

    fl.close();
    return 0;
}
