#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

typedef struct Node{
    Node* parent;
    int size;
    std::string name;
    bool folder;
}Node;

int main()
{
    int sum {};
    std::string ln {};
    std::ifstream fl("input");
    Node root = {NULL, 0, "/", true};
    Node* current = &root;
    std::map<std::string, Node> m;
    std::map<std::string, Node*> r;
    m.insert({root.name, root});

    while(getline(fl, ln)){
        if(ln.rfind("$ ") == 0){
            if(ln.rfind("$ cd ") != 0)
                continue;
            //std::cout << "change directory [" << ln.substr(5) << "]"<< std::endl;
            if(ln.substr(5) == "..")
                current = (*current).parent ? (*current).parent : current ;
            else
                current = &m[ln.substr(5)];
        }else{
            if(ln.rfind("dir ") == 0){
                Node n = {current, 0, ln.substr(4), true};
                m.insert({ln.substr(4), n});
                //std::cout << "create directory [" << ln.substr(4) << "] in [" << (*current).name << "]" << std::endl;
            }else{
                Node n = {current, std::stoi(ln.substr(0, ln.find(" ")+1)), ln.substr(ln.find(" ")+1), true};
                m.insert({ln.substr(ln.find(" ")+1), n});
                Node *t = current;
                while(true){
                    (*t).size += n.size;
                    if((*t).size <= 100000){
                        r.insert({(*t).name, t});
                    }else{
                        r.erase((*t).name);
                    }
                    if((*t).parent == NULL)
                        break;
                    t = (*t).parent;
                }
                //std::cout << "create file [" << ln.substr(0, ln.find(" ")) << ":" << ln.substr(ln.find(" ")+1) << "] in [" << (*current).name << "]" << std::endl;
            }
        }
    }

    for(auto const& x : r){
        Node *t = (*x.second).parent;
        sum += (*x.second).size;
        std::cout << "[" << (*x.second).size << "] " << x.first << " : ";
        while(true){
            std::cout << (*t).name << " ";
            if((*t).parent == NULL)
                break;
            t = (*t).parent;
        }
        std::cout << std::endl;
    }
    std::cout << sum << std::endl;

    return 0;
}
