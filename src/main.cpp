#include <cstdio>
#include<iostream>
#include<cstring>
#include <cstdlib>
#include "cfg_function_code.h"
#include "base.h"

using namespace std;
using namespace YAML;
using namespace yamlFunc;
using namespace yamlTest;
using namespace motovis;
using namespace yamlVehicle;

char * config_yaml_path = NULL;
std::string s_config_yaml_path;

extern vector<vector<int16_t> > gSAMinDis;
extern vector<vector<float> > gSARatio;
extern VehicleConfig gObj;
extern CCfgVehicleCode  gVehicleYaml;
extern uint32_t gEPSSteeringAngleRatiosRows;
uint32_t gDisLsitNum = 0;

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

        gYamlTest.readConfigPath = s_config_yaml_path;
        cout<<"gYamlTest.readConfigPath:"<<gYamlTest.readConfigPath<<endl;
    }

    return 0;
}

int main(int argc, char* argv[])
{
    //命令行传参
    getConfigPathFromArgv(argc,argv);
    //yamlFunc内从环境变量获取配置路径
    
    //默认config配置
    // gYamlTest.showFunctionConfig();
    // gYamlTest.Init();
    // gYamlTest.showFunctionConfig();
    // gYamlTest.writeConfigYaml();

    // //车身参数配置:
    // gVehicleYaml.showVehicleConfig();
    // gVehicleYaml.Init();
    // gVehicleYaml.showVehicleConfig();
    // gVehicleYaml.checkCfg();
    // gVehicleYaml.getVehicleConfig(gObj);
    // gVehicleYaml.getSteeringAngleMinDis(gSAMinDis);
    // gVehicleYaml.getEPSSteeringAngleRatio(gSARatio);

    getCfgInfo(gSAMinDis,gSARatio,gDisLsitNum,gObj);
    showVehCfg(gObj);

    DBGprint("main GEAR_P = %d;0x:%x\n",GEAR_P,&GEAR_P);

    return 0;
}