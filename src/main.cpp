#include <cstdio>
#include<iostream>
#include<cstring>
#include <cstdlib>
#include "yaml.h"
#include "cfg_function_code.h"

using namespace std;
using namespace YAML;
using namespace yamlFunc;
using namespace yamlTest;

char * config_yaml_path = NULL;
std::string s_config_yaml_path;

static CCfgManagerFunCode gYamlTest;

int getConfigPathFromArgv(int argc, char* argv[])
{
    if(argc<2)
    {    
        cout<<"No command line arguments were passed in,config path need set in MV_STATE_YAML"<<endl;
        return 0;
    }
    else
    {
        config_yaml_path = argv[1];
        cout<<"config_yaml_path:"<<config_yaml_path<<endl;
        s_config_yaml_path = argv[1];
        cout<<"strings:"<<s_config_yaml_path<<endl;

        gYamlTest.configPath = s_config_yaml_path;
        cout<<"gYamlTest.configPath:"<<gYamlTest.configPath<<endl;
    }

    // //just show test
    // YAML::Emitter out;
    // out << "Hello, World!";

    // std::cout << "Here's the output YAML:\n" << out.c_str(); // prints "Hello, World!"

    // out << YAML::BeginSeq;
    // out << "eggs";
    // out << "bread";
    // out << "milk";
    // out << YAML::EndSeq;

    // out.SetOutputCharset(YAML::EscapeNonAscii);
    // out.SetIndent(4);

    return 0;
}

int main(int argc, char* argv[])
{
    //命令行传参
    getConfigPathFromArgv(argc,argv);
    //yamlFunc内从环境变量获取配置路径
    
    gYamlTest.showFunctionConfig();
    gYamlTest.Init();
    gYamlTest.showFunctionConfig();



    return 0;
}