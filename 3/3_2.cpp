#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string txt;
    std::ifstream fl("input"); 

    int sum {0}, c {1};
    int hl[52] = {0};
    bool part_2 {false}, part_3 {false};

    while(getline(fl, txt)){
        int sz = txt.size();

        for(int i = 0; i < sz; i++){
            int dc = (txt[i] > 96) ? txt[i] - 97 : (txt[i] - 65) + 26;
            if((hl[dc] == 0 && c == 1) || hl[dc] == 1 && c == 2 || hl[dc] == 2 && c == 3)
                hl[dc] += 1;
        }

        if(c%3==0){
            for(int i = 0; i < 52; i++){
                sum += (hl[i] > 2) ? i+1 : 0;
                // reset
                hl[i] = 0;
            }

            c = 1;
            continue;
        }
        c++;
    }

    std::cout << sum << std::endl;
    fl.close();

    return 0;
}
