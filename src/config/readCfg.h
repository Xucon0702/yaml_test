#ifndef READCFG_H_
#define READCFG_H_

#include "base.h"
#include "cfg_vehicle_code.h"

/*添加class的头文件后,using 不写的话用时就得motovis::yamlVehicle::VehicleConfig*/
using namespace motovis;
using namespace yamlVehicle;

 void getCfgInfo(vector<vector<int16_t> > & vSAMinDis,vector<vector<float> > & vSARatio,uint32_t & disLsitNum,VehicleConfig &mVehicleCfg);














#endif