#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    int sum {0};
    std::string t {};
    std::ifstream fl("input");
    std::vector<std::vector<char>> m;
    bool init {true};
    
    while(getline(fl, t)){
        // init vector
        if(m.size()==0){
            for(int i = 0; i < t.size()/4+1; i++){
                std::vector<char> t{};
                m.push_back(t);
            }
        }

        if(init){
            for(int i = 0; true; i+=4){
                if(t[i+1] != ' ' && t[i+1] >= 65)
                    m[i/4].push_back(t[i+1]);
                if(i+4 >= t.size())
                    break;
            }
        }

        // execute command
        if(!init){
            int mv = std::stoi(t.substr(5, t.find(" from ") - 5));
            int frm = std::stoi(t.substr(t.find("from ") + 5, t.find("to") - t.find(" to ") - 5));
            int to = std::stoi(t.substr(t.find("to ") + 3));
            for(int i=0;i<mv;i++){
                char tmp = m[frm-1][0];
                m[to-1].insert(m[to-1].begin(), tmp);
                m[frm-1].erase(m[frm-1].begin());
            }
        }

        if(t.size()==0)
            init = false;
    }

    for(auto & element : m){
        std::cout << element[0];
    }
    std::cout << "\n";

    return 0;
}
