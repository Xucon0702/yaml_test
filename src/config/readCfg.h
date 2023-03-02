#ifndef READCFG_H_
#define READCFG_H_

#include "cfg_vehicle_code.h"


#define GAC_A58

#ifdef  GAC_A58
#define PI 								 (3.1415926535897932384626433832795)

#define EPSSARatioClos (5)		//对应EPSSteeringAngleRatio的数组

#define LIST_NUM    (3)
#define SAMinDisClos	(25)	//对应SteeringAngleMinDis的数组

#endif


#define toStr(X) #X     //toStr(X) --> "X" ; substr:功能是复制子字符串，从指定位置开始,并具有指定的长度:如下、从第0个字符开始的实际字符长度
#define Out(X) {string xname=toStr(X);cout<<xname.substr(0,xname.size()-1)<<": "<<X<<endl;}

#define DEBUG   //是否开启打印的宏开关

#ifdef DEBUG
#define DBGprint(...) printf(__VA_ARGS__)
#else
#define DBGprint(...)
#endif

//宏前面加上##的作用在于：当可变参数的个数为0时，这里的## 起到把前面多余的","去掉的作用
#define DEBUG_INFO(format, ...) printf("File:%s, Line:%d, Function:%s, %s\n", \
	__FILE__, __LINE__ , __FUNCTION__, ##__VA_ARGS__);

/*添加class的头文件后,using 不写的话用时就得motovis::yamlVehicle::VehicleConfig*/


using namespace motovis;
using namespace yamlVehicle;

void getCfgInfo(vector<vector<int16_t> > & vSAMinDis,vector<vector<float> > & vSARatio,uint32_t & disLsitNum,VehicleConfig &mVehicleCfg);
void showVehCfg(VehicleConfig tS);
void updataVehParam();
// //test
uint32_t getGEAR_P();













#endif