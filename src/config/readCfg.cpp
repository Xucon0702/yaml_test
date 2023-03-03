#include<iostream>
#include <string>
#include "readCfg.h"

using namespace std;

using namespace motovis;
using namespace yamlVehicle;

vector<vector<int16_t> > gSAMinDis;
vector<vector<float> > gSARatio;
VehicleConfig gObj;
CCfgVehicleCode  gVehicleYaml;

//一个文件中的变量到处被调用的写法:(cpp中定义,.h中引用)
#ifdef  GAC_A58
uint32_t AHEAD_CTRL_POINT_NUM = 1;                      //暂不用
// float   VisionSlotDelay                               (1)

float WIDTH_HALF             = 0.9435;
float MIDDLE_TO_REAR         = 0;

float MIDDLE_TO_REAR_FREESPACE      = 1.349;//车辆中心到后轴距离
float AXIS_DISTANCE                 = 2.730;//轴距
float FRONT_USS_TO_FRONT_AXLE_DIST  = 0.956;//前超声到前轴距离
float SENSORS_LONGITUDINAL_DIST     = 3.28;//超声安装相关
float HALF_VEHICLE_WIDTH            = WIDTH_HALF;

float WHEEL_SPEED_PULSE_METERS_PER_PULSE      = 0.0269;//轮脉冲分辨率
float FL_WHEEL_SPEED_PULSE_METERS_PER_PULSE   = 0.0269;
float FR_WHEEL_SPEED_PULSE_METERS_PER_PULSE   = 0.0269;
float RL_WHEEL_SPEED_PULSE_METERS_PER_PULSE   = 0.0269;
float RR_WHEEL_SPEED_PULSE_METERS_PER_PULSE   = 0.0269;

float FRONT_WHEEL_SPAN = 1.617;                  //前轮距
float REAR_WHEEL_SPAN  = 1.610;                  //后轮距

//1.GAC_A58车车身参数,单位/m
float VEHICLE_LEN			= 4.650;            //车长
float VEHICLE_WID			= 1.887;            //车宽
float FRONT_EDGE2CENTER		= 3.674;            //前沿到后轴距离
float REAR_EDGE2CENTER		= 0.976;            //后沿到后轴距离
float SIDE_EDGE2CENTER		= VEHICLE_WID / 2;   //侧边沿到中心距离
float WHEEL_BASE             = AXIS_DISTANCE;       //轴距
//jiao dian zxy....目前用的L1/L2
float CHAMFER_LENGTH         = 0.4;                       
float FRONT_CHAMFER_L1       = 0.;                       //前保到倒角距离
float FRONT_CHAMFER_L2       = 0.;
float REAR_CHAMFER_L1        = 0.2;
float REAR_CHAMFER_L2        = 0.2;
float CHAMFER_ANGLE          = 45*PI/180;
/*后视镜长度*/
float REAR_VIEW_LENGTH       = 0.2;
float REAR_VIEW_WIDTH        = 0.25;
float REAR_VIEW_2_FRONT_AXLE = 2.16;             //后视镜到后轴距离
//2.超声安装参数
float SIDE_LURF_CENTER_X		= 3.259;			//前侧边超声到车辆后轴中心点的X距离
float SIDE_LUR_CENTERY		= 0.943;			//两侧边超声到车辆后轴中心点的Y距离
float SIDE_LURR_CENTERX	    = 0.569;            //后侧边超声到车辆后轴中心点的X距离
// float SENSORS_LONGITUDINAL_DIST		(3.28)			//????????????????????????????
float FURTHEST_SIDE_DISTANCE	= 999;			//如果探测的距离是0，就赋此值


float LeftCameraX            = REAR_VIEW_2_FRONT_AXLE - 0.16;
float LeftCameraY            = VEHICLE_WID * 0.5 + 0.05;
float RightCameraX           = LeftCameraX;
float RightCameraY           = -LeftCameraY;
float FrontCameraX           = FRONT_EDGE2CENTER;
float FrontCameraY           = 0.;
float RearCameraX            = -REAR_EDGE2CENTER;
float RearCameraY            = 0.;

/*yrm3,实际车辆的超声安装位置*/
float SENSOR1_X              = 3.564;
float SENSOR1_Y              = 0.667;
float SENSOR1_ANGLE          = 42 * PI / 180;//132

float SENSOR2_X              = 3.631;
float SENSOR2_Y              = 0.345;
float SENSOR2_ANGLE          = 7 * PI / 180;//96

float SENSOR3_X              = SENSOR2_X ;
float SENSOR3_Y              = -SENSOR2_Y ;
float SENSOR3_ANGLE          = -SENSOR2_ANGLE ;

float SENSOR4_X              = SENSOR1_X ;
float SENSOR4_Y              = -SENSOR1_Y ;
float SENSOR4_ANGLE          = -SENSOR1_ANGLE ;

float SENSOR5_X              = -0.902;
float SENSOR5_Y              = 0.603;
float SENSOR5_ANGLE          = 149 * PI / 180;//301

float SENSOR6_X              = -0.965;
float SENSOR6_Y              = 0.249;
float SENSOR6_ANGLE          = 173 * PI / 180;

float SENSOR7_X              = SENSOR6_X ;
float SENSOR7_Y              = -SENSOR6_Y ;
float SENSOR7_ANGLE          = -SENSOR6_ANGLE ;

float SENSOR8_X              = SENSOR5_X ;
float SENSOR8_Y              = -SENSOR5_Y ;
float SENSOR8_ANGLE          = -SENSOR5_ANGLE ;

float SENSOR9_X              = SIDE_LURF_CENTER_X ;
float SENSOR9_Y              = SIDE_EDGE2CENTER ;
float SENSOR9_ANGLE          = 82 * PI / 180;

float SENSOR10_X             = SENSOR9_X ;
float SENSOR10_Y             = -SENSOR9_Y ;
float SENSOR10_ANGLE         = -SENSOR9_ANGLE ;

float SENSOR11_X             = -SIDE_LURR_CENTERX;
float SENSOR11_Y             = SIDE_EDGE2CENTER;
float SENSOR11_ANGLE         = 92 * PI / 180;// *pi/3 rad, 120 degree
float COS_SENSOR11_DIS_ANGEL = 1.0;

float SENSOR12_X             = SENSOR11_X;
float SENSOR12_Y             = -SENSOR11_Y;
float SENSOR12_ANGLE         = -SENSOR11_ANGLE;
float COS_SENSOR12_DIS_ANGEL = 1.0;

uint32_t USS_K               = 58;
float USS_K2                 = 7.752;
uint32_t SPEED_K             = 1;
uint32_t PLUS_COUNT          = 4096;


//3.规划参数
// 最大规划转向角(°)
uint32_t MAX_STEERING_ANGLE        = 456;                    //最大方向盘转角
uint32_t MAX_STEERING_ANGLE_SPEED  = 400;                   //最大方向盘角速
float MAX_FRONT_AXLE_ANGLE         = 0.6;                           //最大前轴转角
//4.环视参数
float CAMERA_2_MID                 = 0.58;                   //暂未用

//5.速度默认-避障相关
float VERY_DANGOUS_VELOCITY        = 0.2;
float DANGOUS_VELOCITY             = 0.3;

//6.转向角误差
float STEERING_WHEEL_ANGLE_ERROR   = 10;          //目标方向盘转角和实际方向盘转角最大允许差值

uint32_t ADDIDEGREE                = 0;              //暂未用

//7.USS state
uint32_t PROXIMITY = 16;
uint32_t NORMAL    = 0;


//rows(11);cols(5);vector<float>
int EPS_STEERING_ANGLE_RATIO_SEGMENT=11;
float EPSSteeringAngleRatio[11][EPSSARatioClos]=
{
//SteeringAngle LeftForward  LeftBack RightForward RightRear
{170*PI/180, 0.182713, 0.186183, 0.193731, 0.195271},
{200*PI/180, 0.213624, 0.210972, 0.225991, 0.225291},
{230*PI/180, 0.253340, 0.246417, 0.264447, 0.257712},
{260*PI/180, 0.281727, 0.283221, 0.295076, 0.292958},
{290*PI/180, 0.316585, 0.312152, 0.329033, 0.325144},
{320*PI/180, 0.353413, 0.348024, 0.334337, 0.362713},
{350*PI/180, 0.368205, 0.380656, 0.402151, 0.392548},
{380*PI/180, 0.423274, 0.415827, 0.438791, 0.427377},
{410*PI/180, 0.466571, 0.456298, 0.476865, 0.467039},
{440*PI/180, 0.504171, 0.483403, 0.517839, 0.498223},
{470*PI/180, 0.527227, 0.513124, 0.541730, 0.524689}
};


//9.避障参数
// #define LIST_NUM    (3)
//vetor<vector<short>>
short SteeringAngleMinDis[LIST_NUM][25]=
{
//SteeringAngle sUss1 sUss2 sUss3 sUss4 sUss5 sUss6 sUss7 lUss8 lUss9 lUss10 lUss11

// Use angle should mulitple 10
// -1 means disable
{0,
    35, 45, 45, 35,     -1, -1, -1, -1,     -1, -1, -1, -1,//forward
    -1, -1, -1, -1,     30, 30, 30, 30,     -1, -1, -1, -1,//backward
}, //0
{250,
    45, 45, 45, 45,     -1, -1, -1, -1,     35, -1, -1, -1,//forward  默认左转
    -1, -1, -1, -1,     35, 30, 30, 35,    -1, 25, 30, 30,//backward
}, //250
{400,
    45, 45, 45, 45,     -1, -1, -1, -1,     35, -1, -1, -1,//forward x,x,x,x,  x,x,x,x,  25, -1, -1, -1,超声安装位置调整之前
    -1, -1, -1, -1,    35, 35, 35, 35,     -1, 25, 30, 30,//backward
}, //400
};


//10.GEAR
uint32_t GEAR_P = 1;
uint32_t GEAR_R = 2;
uint32_t GEAR_N = 3;
uint32_t GEAR_D = 4;
#endif



uint32_t getGEAR_P()
{   
    // GEAR_P = 989898;
    printf("getGEAR_P = %d;0x:%x\n",GEAR_P,&GEAR_P);
    return GEAR_P;
}

void updataVehParam(vector<vector<int16_t> > & vSAMinDis,vector<vector<float> > & vSARatio,uint32_t & RatiosRows,VehicleConfig &mVehicleCfg)
{   
    AHEAD_CTRL_POINT_NUM = mVehicleCfg.ahead_ctrl_point_num;
    WIDTH_HALF = mVehicleCfg.width_half;
    MIDDLE_TO_REAR = mVehicleCfg.middle_to_rear;

    MIDDLE_TO_REAR_FREESPACE = mVehicleCfg.middle_to_rear_freespace;
    AXIS_DISTANCE = mVehicleCfg.axis_distance;
    FRONT_USS_TO_FRONT_AXLE_DIST = mVehicleCfg.front_uss_to_front_axle_dist;
    SENSORS_LONGITUDINAL_DIST = mVehicleCfg.sensors_longitudinal_dist;
    HALF_VEHICLE_WIDTH = mVehicleCfg.half_vehicle_width;

    WHEEL_SPEED_PULSE_METERS_PER_PULSE = mVehicleCfg.wheel_speed_pulse_meters_per_pulse;
    FL_WHEEL_SPEED_PULSE_METERS_PER_PULSE = mVehicleCfg.fl_wheel_speed_pulse_meters_per_pulse;
    FR_WHEEL_SPEED_PULSE_METERS_PER_PULSE = mVehicleCfg.fr_wheel_speed_pulse_meters_per_pulse;
    RL_WHEEL_SPEED_PULSE_METERS_PER_PULSE = mVehicleCfg.rl_wheel_speed_pulse_meters_per_pulse;
    RR_WHEEL_SPEED_PULSE_METERS_PER_PULSE = mVehicleCfg.rr_wheel_speed_pulse_meters_per_pulse;

    FRONT_WHEEL_SPAN = mVehicleCfg.front_wheel_span;
    REAR_WHEEL_SPAN = mVehicleCfg.rear_wheel_span;
    
    VEHICLE_LEN = mVehicleCfg.vehicle_len;
    VEHICLE_WID = mVehicleCfg.vehicle_wid;
    FRONT_EDGE2CENTER = mVehicleCfg.front_edge2center;
    REAR_EDGE2CENTER = mVehicleCfg.rear_edge2center;
    SIDE_EDGE2CENTER = mVehicleCfg.side_edge2center;
    WHEEL_BASE = mVehicleCfg.wheel_base;

    CHAMFER_LENGTH = mVehicleCfg.chamfer_length;
    FRONT_CHAMFER_L1 = mVehicleCfg.front_chamfer_l1;
    FRONT_CHAMFER_L2 = mVehicleCfg.front_chamfer_l2;
    REAR_CHAMFER_L1 = mVehicleCfg.rear_chamfer_l1;
    REAR_CHAMFER_L2 = mVehicleCfg.rear_chamfer_l2;
    CHAMFER_ANGLE = mVehicleCfg.chamfer_angle;

    REAR_VIEW_LENGTH = mVehicleCfg.rear_view_length;
    REAR_VIEW_WIDTH = mVehicleCfg.read_view_width;
    REAR_VIEW_2_FRONT_AXLE = mVehicleCfg.rear_view_2_front_axle;

    SIDE_LURF_CENTER_X = mVehicleCfg.side_lurf_center_x;
    SIDE_LUR_CENTERY = mVehicleCfg.side_lur_centery;
    SIDE_LURR_CENTERX = mVehicleCfg.side_lurr_centerx;
    FURTHEST_SIDE_DISTANCE = mVehicleCfg.furthest_side_distance;

    LeftCameraX = mVehicleCfg.leftCamerax;
    LeftCameraY = mVehicleCfg.leftCameraY;
    RightCameraX = mVehicleCfg.rightCameraX;
    RightCameraY = mVehicleCfg.rightCameraY;
    FrontCameraX = mVehicleCfg.frontCameraX;
    FrontCameraY = mVehicleCfg.frontCameraY;
    RearCameraX = mVehicleCfg.rearCameraX;
    RearCameraY = mVehicleCfg.rearCameraY;

    SENSOR1_X = mVehicleCfg.sensor1_x;
    SENSOR1_Y = mVehicleCfg.sensor1_y;
    SENSOR1_ANGLE = mVehicleCfg.sensor1_angle;
    SENSOR2_X = mVehicleCfg.sensor2_x;
    SENSOR2_Y = mVehicleCfg.sensor2_y;
    SENSOR2_ANGLE = mVehicleCfg.sensor2_angle;
    SENSOR3_X = mVehicleCfg.sensor3_x;
    SENSOR3_Y = mVehicleCfg.sensor3_y;
    SENSOR3_ANGLE = mVehicleCfg.sensor3_angle;
    SENSOR4_X = mVehicleCfg.sensor4_x;
    SENSOR4_Y = mVehicleCfg.sensor4_y;
    SENSOR4_ANGLE = mVehicleCfg.sensor4_angle;
    SENSOR5_X = mVehicleCfg.sensor5_x;
    SENSOR5_Y = mVehicleCfg.sensor5_y;
    SENSOR5_ANGLE = mVehicleCfg.sensor5_angle;
    SENSOR6_X = mVehicleCfg.sensor6_x;
    SENSOR6_Y = mVehicleCfg.sensor6_y;
    SENSOR6_ANGLE = mVehicleCfg.sensor6_angle;
    SENSOR7_X = mVehicleCfg.sensor7_x;
    SENSOR7_Y = mVehicleCfg.sensor7_y;
    SENSOR7_ANGLE = mVehicleCfg.sensor7_angle;
    SENSOR8_X = mVehicleCfg.sensor8_x;
    SENSOR8_Y = mVehicleCfg.sensor8_y;
    SENSOR8_ANGLE = mVehicleCfg.sensor8_angle;
    SENSOR9_X = mVehicleCfg.sensor9_x;
    SENSOR9_Y = mVehicleCfg.sensor9_y;
    SENSOR9_ANGLE = mVehicleCfg.sensor9_angle;
    SENSOR10_X = mVehicleCfg.sensor10_x;
    SENSOR10_Y = mVehicleCfg.sensor10_y;
    SENSOR10_ANGLE = mVehicleCfg.sensor10_angle;
    SENSOR11_X = mVehicleCfg.sensor11_x;
    SENSOR11_Y = mVehicleCfg.sensor11_y;
    SENSOR11_ANGLE = mVehicleCfg.sensor11_angle;
    COS_SENSOR11_DIS_ANGEL = mVehicleCfg.cos_sensor11_dis_angel;
    SENSOR12_X = mVehicleCfg.sensor12_x;
    SENSOR12_Y = mVehicleCfg.sensor12_y;
    SENSOR12_ANGLE = mVehicleCfg.sensor12_angle;
    COS_SENSOR12_DIS_ANGEL = mVehicleCfg.cos_sensor12_dis_angel;

    USS_K = mVehicleCfg.uss_k;
    USS_K2 = mVehicleCfg.uss_k2;
    SPEED_K = mVehicleCfg.speed_k;
    PLUS_COUNT = mVehicleCfg.plus_count;

    MAX_STEERING_ANGLE = mVehicleCfg.max_steering_angle;
    MAX_STEERING_ANGLE_SPEED = mVehicleCfg.max_steering_angle_speed;
    MAX_FRONT_AXLE_ANGLE = mVehicleCfg.max_front_axle_angle;
    CAMERA_2_MID = mVehicleCfg.camera_2_mid;

    VERY_DANGOUS_VELOCITY = mVehicleCfg.very_dangrous_velocity;
    DANGOUS_VELOCITY = mVehicleCfg.dangrous_velocity;
    STEERING_WHEEL_ANGLE_ERROR = mVehicleCfg.steering_wheel_angle_error;
    ADDIDEGREE = mVehicleCfg.addIdegree;
    PROXIMITY = mVehicleCfg.proximity;
    NORMAL = mVehicleCfg.normal;

    GEAR_P = mVehicleCfg.gear_p;
    GEAR_R = mVehicleCfg.gear_r;
    GEAR_N = mVehicleCfg.gear_n;
    GEAR_D = mVehicleCfg.gear_d;

    EPS_STEERING_ANGLE_RATIO_SEGMENT = RatiosRows;

    //数组
    if((vSAMinDis.size() ==  LIST_NUM)&&(vSAMinDis[0].size() == SAMinDisClos))
    {
        DBGprint("vSAMinDis raws and clos right\n");
        for (int i = 0; i < vSAMinDis.size(); i++) {       // 行数
                for (int j = 0; j < vSAMinDis[i].size(); j++) {  // A[i].size() 第i行的列数
                    SteeringAngleMinDis[i][j] =  vSAMinDis[i][j];
                    // std::cout << vSAMinDis[i][j] << "<-vSAMinDis ";
                    std::cout << SteeringAngleMinDis[i][j] << " ";
                }
                std::cout << std::endl;
        }
    }

    if((vSARatio.size() ==  EPS_STEERING_ANGLE_RATIO_SEGMENT)&&(vSARatio[0].size() == EPSSARatioClos))
    {
        DBGprint("vSARatio raws and clos right\n");
        for (int i = 0; i < vSARatio.size(); i++) {       // 行数
                for (int j = 0; j < vSARatio[i].size(); j++) {  // A[i].size() 第i行的列数
                    EPSSteeringAngleRatio[i][j] =  vSARatio[i][j];
                    // std::cout << vSARatio[i][j] << "<-vSARatio ";
                    std::cout << EPSSteeringAngleRatio[i][j] << " ";
                }
                std::cout << std::endl;
        }
    }

    return ;
}


void getCfgInfo(vector<vector<int16_t> > & vSAMinDis,vector<vector<float> > & vSARatio,VehicleConfig &mVehicleCfg)
{
    uint32_t RatiosRows = 0;

     //车身参数配置获取:
    gVehicleYaml.showVehicleConfig();
    gVehicleYaml.Init();
    gVehicleYaml.showVehicleConfig();
    gVehicleYaml.checkCfg();
    gVehicleYaml.getVehicleConfig(mVehicleCfg);
    gVehicleYaml.getEPSSteeringAngleRatio(vSARatio);
    gVehicleYaml.getSteeringAngleMinDis(vSAMinDis);
    RatiosRows = gVehicleYaml.getEPSSteeringAngleRatiosRows();

    //设置变量:
    updataVehParam(vSAMinDis,vSARatio,RatiosRows,mVehicleCfg);
    
    return;
}

//结构体打印
void showVehCfg(VehicleConfig tS)
{
    // DEBUG_INFO("%s","here");
    DEBUG_INFO();

    Out(tS.ahead_ctrl_point_num);
    Out(tS.width_half);
    Out(tS.middle_to_rear);
    Out(tS.middle_to_rear_freespace);
    Out(tS.axis_distance);
    Out(tS.front_uss_to_front_axle_dist);
    Out(tS.sensors_longitudinal_dist);
    Out(tS.half_vehicle_width);
    Out(tS.wheel_speed_pulse_meters_per_pulse);
    Out(tS.fl_wheel_speed_pulse_meters_per_pulse);
    Out(tS.fr_wheel_speed_pulse_meters_per_pulse);
    Out(tS.rl_wheel_speed_pulse_meters_per_pulse);
    Out(tS.rr_wheel_speed_pulse_meters_per_pulse);
    Out(tS.front_wheel_span);
    Out(tS.rear_wheel_span);
    Out(tS.vehicle_len);
    Out(tS.vehicle_wid);
    Out(tS.front_edge2center);
    Out(tS.rear_edge2center);
    Out(tS.side_edge2center);
    Out(tS.wheel_base);
    Out(tS.chamfer_length);
    Out(tS.front_chamfer_l1);
    Out(tS.front_chamfer_l2);
    Out(tS.rear_chamfer_l1);
    Out(tS.rear_chamfer_l2);
    Out(tS.chamfer_angle);
    Out(tS.rear_view_length);
    Out(tS.read_view_width);
    Out(tS.rear_view_2_front_axle);
    Out(tS.side_lurf_center_x);
    Out(tS.side_lur_centery);
    Out(tS.side_lurr_centerx);
    Out(tS.furthest_side_distance);
    Out(tS.leftCamerax);
    Out(tS.leftCameraY);
    Out(tS.rightCameraX);
    Out(tS.rightCameraY);
    Out(tS.frontCameraX);
    Out(tS.frontCameraY);
    Out(tS.rearCameraX);
    Out(tS.rearCameraY);
    Out(tS.sensor1_x);
    Out(tS.sensor1_y);
    Out(tS.sensor1_angle);
    Out(tS.sensor2_x);
    Out(tS.sensor2_y);
    Out(tS.sensor2_angle);
    Out(tS.sensor3_x);
    Out(tS.sensor3_y);
    Out(tS.sensor3_angle);
    Out(tS.sensor4_x);
    Out(tS.sensor4_y);
    Out(tS.sensor4_angle);
    Out(tS.sensor5_x);
    Out(tS.sensor5_y);
    Out(tS.sensor5_angle);
    Out(tS.sensor6_x);
    Out(tS.sensor6_y);
    Out(tS.sensor6_angle);
    Out(tS.sensor7_x);
    Out(tS.sensor7_y);
    Out(tS.sensor7_angle);
    Out(tS.sensor8_x);
    Out(tS.sensor8_y);
    Out(tS.sensor8_angle);
    Out(tS.sensor9_x);
    Out(tS.sensor9_y);
    Out(tS.sensor9_angle);
    Out(tS.sensor10_x);
    Out(tS.sensor10_y);
    Out(tS.sensor10_angle);
    Out(tS.sensor11_x);
    Out(tS.sensor11_y);
    Out(tS.sensor11_angle);
    Out(tS.cos_sensor11_dis_angel);
    Out(tS.sensor12_x);
    Out(tS.sensor12_y);
    Out(tS.sensor12_angle);
    Out(tS.cos_sensor12_dis_angel);
    Out(tS.uss_k);
    Out(tS.uss_k2);
    Out(tS.speed_k);
    Out(tS.plus_count);
    Out(tS.max_steering_angle);
    Out(tS.max_steering_angle_speed);
    Out(tS.max_front_axle_angle);
    Out(tS.camera_2_mid);
    Out(tS.very_dangrous_velocity);
    Out(tS.dangrous_velocity);
    Out(tS.steering_wheel_angle_error);
    Out(tS.addIdegree);
    Out(tS.proximity);
    Out(tS.normal);
    Out(tS.gear_p);
    Out(tS.gear_r);
    Out(tS.gear_n);
    Out(tS.gear_d);

    DBGprint("showVehCfg over\n");

    return;
}