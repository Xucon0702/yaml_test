#include <cstdio>
#include<iostream>
#include "yaml.h"

using namespace std;
using namespace YAML;

int main()
{
    printf("yaml_test_xc\n");
    YAML::Emitter out;
   out << "Hello, World!";
   
   std::cout << "Here's the output YAML:\n" << out.c_str(); // prints "Hello, World!"

// YAML::Emitter out;
out << YAML::BeginSeq;
out << "eggs";
out << "bread";
out << "milk";
out << YAML::EndSeq;
    
    return 0;
}