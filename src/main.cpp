#include <iostream>
#include <Secf.hpp>

int main()
{
    Secf secf;

    std::cout << "parent 1: " << secf.get("PARENT_1") << "\n";
    std::cout << "parent 2: " << secf.get("PARENT_2") << "\n";
    std::cout << "child 1: " << secf.get("CHILD_1") << "\n\n";
    std::cout << "stranger: " << secf.get("STRANGER") << "\n\n";

    auto vec1 = secf.find("^.*$");
    auto vec2 = secf.find("^PARENT.*$");
    auto vec3 = secf.find("^.*1$");



    std::cout << "All values:\n";
    for(auto it : vec1) std::cout << it.name << "\t" << it.value << "\n";
    std::cout << "Parents Only:\n";
    for(auto it : vec2) std::cout << it.name << "\t" << it.value << "\n";
    std::cout << "First of each:\n";
    for(auto it : vec3) std::cout << it.name << "\t" << it.value << "\n";
}