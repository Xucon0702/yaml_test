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

void showAllCfg()
{
    DBGprint("showAllCfg start\n");
    DBGprint("AHEAD_CTRL_POINT_NUM:%d\n",AHEAD_CTRL_POINT_NUM);
    DBGprint("WIDTH_HALF:%f\n",WIDTH_HALF);
    DBGprint("MIDDLE_TO_REAR:%f\n",MIDDLE_TO_REAR);
    DBGprint("AXIS_DISTANCE:%f\n",AXIS_DISTANCE);
    DBGprint("FRONT_USS_TO_FRONT_AXLE_DIST:%f\n",FRONT_USS_TO_FRONT_AXLE_DIST);
    DBGprint("SENSORS_LONGITUDINAL_DIST:%f\n",SENSORS_LONGITUDINAL_DIST);
    DBGprint("HALF_VEHICLE_WIDTH:%f\n",HALF_VEHICLE_WIDTH);

    DBGprint("WHEEL_SPEED_PULSE_METERS_PER_PULSE:%f\n",WHEEL_SPEED_PULSE_METERS_PER_PULSE);
    DBGprint("FL_WHEEL_SPEED_PULSE_METERS_PER_PULSE:%f\n",FL_WHEEL_SPEED_PULSE_METERS_PER_PULSE);
    DBGprint("FR_WHEEL_SPEED_PULSE_METERS_PER_PULSE:%f\n",FR_WHEEL_SPEED_PULSE_METERS_PER_PULSE);
    DBGprint("RL_WHEEL_SPEED_PULSE_METERS_PER_PULSE:%f\n",RL_WHEEL_SPEED_PULSE_METERS_PER_PULSE);
    DBGprint("RR_WHEEL_SPEED_PULSE_METERS_PER_PULSE:%f\n",RR_WHEEL_SPEED_PULSE_METERS_PER_PULSE);
    
    DBGprint("FRONT_WHEEL_SPAN:%f\n",FRONT_WHEEL_SPAN);
    DBGprint("REAR_WHEEL_SPAN:%f\n",REAR_WHEEL_SPAN);

    DBGprint("VEHICLE_LEN:%f\n",VEHICLE_LEN);
    DBGprint("VEHICLE_WID:%f\n",VEHICLE_WID);
    DBGprint("FRONT_EDGE2CENTER:%f\n",FRONT_EDGE2CENTER);
    DBGprint("REAR_EDGE2CENTER:%f\n",REAR_EDGE2CENTER);
    DBGprint("SIDE_EDGE2CENTER:%f\n",SIDE_EDGE2CENTER);
    DBGprint("WHEEL_BASE:%f\n",WHEEL_BASE);

    DBGprint("CHAMFER_LENGTH:%f\n",CHAMFER_LENGTH);
    DBGprint("FRONT_CHAMFER_L1:%f\n",FRONT_CHAMFER_L1);
    DBGprint("FRONT_CHAMFER_L2:%f\n",FRONT_CHAMFER_L2);
    DBGprint("REAR_CHAMFER_L1:%f\n",REAR_CHAMFER_L1);
    DBGprint("REAR_CHAMFER_L2:%f\n",REAR_CHAMFER_L2);
    DBGprint("CHAMFER_ANGLE:%f\n",CHAMFER_ANGLE);
    DBGprint("REAR_VIEW_LENGTH:%f\n",REAR_VIEW_LENGTH);
    DBGprint("REAR_VIEW_WIDTH:%f\n",REAR_VIEW_WIDTH);
    DBGprint("REAR_VIEW_2_FRONT_AXLE:%f\n",REAR_VIEW_2_FRONT_AXLE);

    DBGprint("SIDE_LURF_CENTER_X:%f\n",SIDE_LURF_CENTER_X);
    DBGprint("SIDE_LUR_CENTERY:%f\n",SIDE_LUR_CENTERY);
    DBGprint("SIDE_LURR_CENTERX:%f\n",SIDE_LURR_CENTERX);
    DBGprint("FURTHEST_SIDE_DISTANCE:%f\n",FURTHEST_SIDE_DISTANCE);
    DBGprint("LeftCameraX:%f\n",LeftCameraX);
    DBGprint("LeftCameraY:%f\n",LeftCameraY);
    DBGprint("RightCameraX:%f\n",RightCameraX);
    DBGprint("RightCameraY:%f\n",RightCameraY);
    DBGprint("FrontCameraX:%f\n",FrontCameraX);
    DBGprint("FrontCameraY:%f\n",FrontCameraY);
    DBGprint("RearCameraX:%f\n",RearCameraX);
    DBGprint("RearCameraY:%f\n",RearCameraY);

    DBGprint("SENSOR1_X:%f\n",SENSOR1_X);
    DBGprint("SENSOR1_Y:%f\n",SENSOR1_Y);
    DBGprint("SENSOR1_ANGLE:%f\n",SENSOR1_ANGLE);
    DBGprint("SENSOR2_X:%f\n",SENSOR2_X);
    DBGprint("SENSOR2_Y:%f\n",SENSOR2_Y);
    DBGprint("SENSOR2_ANGLE:%f\n",SENSOR2_ANGLE);
    DBGprint("SENSOR3_X:%f\n",SENSOR3_X);
    DBGprint("SENSOR3_Y:%f\n",SENSOR3_Y);
    DBGprint("SENSOR3_ANGLE:%f\n",SENSOR3_ANGLE);
    DBGprint("SENSOR4_X:%f\n",SENSOR4_X);
    DBGprint("SENSOR4_Y:%f\n",SENSOR4_Y);
    DBGprint("SENSOR4_ANGLE:%f\n",SENSOR4_ANGLE);
    DBGprint("SENSOR5_X:%f\n",SENSOR5_X);
    DBGprint("SENSOR5_Y:%f\n",SENSOR5_Y);
    DBGprint("SENSOR5_ANGLE:%f\n",SENSOR5_ANGLE);
    DBGprint("SENSOR6_X:%f\n",SENSOR6_X);
    DBGprint("SENSOR6_Y:%f\n",SENSOR6_Y);
    DBGprint("SENSOR6_ANGLE:%f\n",SENSOR6_ANGLE);
    DBGprint("SENSOR7_X:%f\n",SENSOR7_X);
    DBGprint("SENSOR7_Y:%f\n",SENSOR7_Y);
    DBGprint("SENSOR7_ANGLE:%f\n",SENSOR7_ANGLE);
    DBGprint("SENSOR8_X:%f\n",SENSOR8_X);
    DBGprint("SENSOR8_Y:%f\n",SENSOR8_Y);
    DBGprint("SENSOR8_ANGLE:%f\n",SENSOR8_ANGLE);
    DBGprint("SENSOR9_X:%f\n",SENSOR9_X);
    DBGprint("SENSOR9_Y:%f\n",SENSOR9_Y);
    DBGprint("SENSOR9_ANGLE:%f\n",SENSOR9_ANGLE);
    DBGprint("SENSOR10_X:%f\n",SENSOR10_X);
    DBGprint("SENSOR10_Y:%f\n",SENSOR10_Y);
    DBGprint("SENSOR10_ANGLE:%f\n",SENSOR10_ANGLE);
    DBGprint("SENSOR11_X:%f\n",SENSOR11_X);
    DBGprint("SENSOR11_Y:%f\n",SENSOR11_Y);
    DBGprint("SENSOR11_ANGLE:%f\n",SENSOR11_ANGLE);
    DBGprint("COS_SENSOR11_DIS_ANGEL:%f\n",COS_SENSOR11_DIS_ANGEL);
    DBGprint("SENSOR12_X:%f\n",SENSOR12_X);
    DBGprint("SENSOR12_Y:%f\n",SENSOR12_Y);
    DBGprint("SENSOR12_ANGLE:%f\n",SENSOR12_ANGLE);
    DBGprint("COS_SENSOR12_DIS_ANGEL:%f\n",COS_SENSOR12_DIS_ANGEL);
    DBGprint("USS_K:%d\n",USS_K);
    DBGprint("USS_K2:%f\n",USS_K2);
    DBGprint("SPEED_K:%d\n",SPEED_K);
    DBGprint("PLUS_COUNT:%d\n",PLUS_COUNT);

    DBGprint("MAX_STEERING_ANGLE:%d\n",MAX_STEERING_ANGLE);
    DBGprint("MAX_STEERING_ANGLE_SPEED:%d\n",MAX_STEERING_ANGLE_SPEED);
    DBGprint("MAX_FRONT_AXLE_ANGLE:%f\n",MAX_FRONT_AXLE_ANGLE);
    DBGprint("CAMERA_2_MID:%f\n",CAMERA_2_MID);

    DBGprint("VERY_DANGOUS_VELOCITY:%f\n",VERY_DANGOUS_VELOCITY);
    DBGprint("DANGOUS_VELOCITY:%f\n",DANGOUS_VELOCITY);
    DBGprint("STEERING_WHEEL_ANGLE_ERROR:%f\n",STEERING_WHEEL_ANGLE_ERROR);
    DBGprint("ADDIDEGREE:%d\n",ADDIDEGREE);
    DBGprint("PROXIMITY:%d\n",PROXIMITY);
    DBGprint("NORMAL:%d\n",NORMAL);
    DBGprint("EPS_STEERING_ANGLE_RATIO_SEGMENT:%d\n",EPS_STEERING_ANGLE_RATIO_SEGMENT);
    
    DBGprint("GEAR_P:%d\n",GEAR_P);
    DBGprint("GEAR_R:%d\n",GEAR_R);
    DBGprint("GEAR_N:%d\n",GEAR_N);
    DBGprint("GEAR_D:%d\n",GEAR_D);
   
    DBGprint("EPSSteeringAngleRatio:\n");
    for(int i =0;i<EPS_STEERING_ANGLE_RATIO_SEGMENT;i++)
    {
        for(int j=0;j<EPSSARatioClos;j++)
        {
            DBGprint("%f ",EPSSteeringAngleRatio[i][j]);
        }
        DBGprint("\n");
    }
    
    DBGprint("SteeringAngleMinDis:\n");
    for(int i =0;i<LIST_NUM;i++)
    {
        for(int j=0;j<SAMinDisClos;j++)
        {
            DBGprint("%d ",SteeringAngleMinDis[i][j]);
        }
        DBGprint("\n");
    }

    DBGprint("showAllCfg end\n");

    return ;
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

    getCfgInfo(gSAMinDis,gSARatio,gObj);
    // showVehCfg(gObj);

    showAllCfg();

    return 0;
}