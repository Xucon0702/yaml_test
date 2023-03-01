#include<iostream>
#include "readCfg.h"

using namespace std;

using namespace motovis;
using namespace yamlVehicle;

vector<vector<int16_t> > gSAMinDis;
vector<vector<float> > gSARatio;
VehicleConfig gObj;
CCfgVehicleCode  gVehicleYaml;

 void getCfgInfo(vector<vector<int16_t> > & vSAMinDis,vector<vector<float> > & vSARatio,uint32_t & disLsitNum,VehicleConfig &mVehicleCfg)
{
     //车身参数配置:
    gVehicleYaml.showVehicleConfig();
    gVehicleYaml.Init();
    gVehicleYaml.showVehicleConfig();
    gVehicleYaml.checkCfg();
    disLsitNum = gVehicleYaml.getSteeringAngleMinDisLsitNum();
    gVehicleYaml.getVehicleConfig(mVehicleCfg);
    gVehicleYaml.getSteeringAngleMinDis(vSAMinDis);
    gVehicleYaml.getEPSSteeringAngleRatio(vSARatio);

    return;
}