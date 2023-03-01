#ifndef BASE_H
#define BASE_H


//公用但不用配置的
#if 1
#define PI 								 (3.1415926535897932384626433832795)
#endif

#define     GAC_A58

#ifdef  GAC_A58

static uint32_t AHEAD_CTRL_POINT_NUM = 1;                      //暂不用
//static float   VisionSlotDelay                               (1)

static float WIDTH_HALF             = 0.9435;
static float MIDDLE_TO_REAR         = 0;

static float MIDDLE_TO_REAR_FREESPACE      = 1.349;//车辆中心到后轴距离
static float AXIS_DISTANCE                 = 2.730;//轴距
static float FRONT_USS_TO_FRONT_AXLE_DIST  = 0.956;//前超声到前轴距离
static float SENSORS_LONGITUDINAL_DIST     = 3.28;//超声安装相关
static float HALF_VEHICLE_WIDTH            = WIDTH_HALF;

static float WHEEL_SPEED_PULSE_METERS_PER_PULSE      = 0.0269;//轮脉冲分辨率
static float FL_WHEEL_SPEED_PULSE_METERS_PER_PULSE   = 0.0269;
static float FR_WHEEL_SPEED_PULSE_METERS_PER_PULSE   = 0.0269;
static float RL_WHEEL_SPEED_PULSE_METERS_PER_PULSE   = 0.0269;
static float RR_WHEEL_SPEED_PULSE_METERS_PER_PULSE   = 0.0269;

static float FRONT_WHEEL_SPAN = 1.617;                  //前轮距
static float REAR_WHEEL_SPAN  = 1.610;                  //后轮距

//1.GAC_A58车车身参数,单位/m
static float VEHICLE_LEN			= 4.650;            //车长
static float VEHICLE_WID			= 1.887;            //车宽
static float FRONT_EDGE2CENTER		= 3.674;            //前沿到后轴距离
static float REAR_EDGE2CENTER		= 0.976;            //后沿到后轴距离
static float SIDE_EDGE2CENTER		= VEHICLE_WID / 2;   //侧边沿到中心距离
static float WHEEL_BASE             = AXIS_DISTANCE;       //轴距
//jiao dian zxy....目前用的L1/L2
static float CHAMFER_LENGTH         = 0.4;                       
static float FRONT_CHAMFER_L1       = 0.;                       //前保到倒角距离
static float FRONT_CHAMFER_L2       = 0.;
static float REAR_CHAMFER_L1        = 0.2;
static float REAR_CHAMFER_L2        = 0.2;
static float CHAMFER_ANGLE          = 45*PI/180;
/*后视镜长度*/
static float REAR_VIEW_LENGTH       = 0.2;
static float REAR_VIEW_WIDTH        = 0.25;
static float REAR_VIEW_2_FRONT_AXLE = 2.16;             //后视镜到后轴距离
//2.超声安装参数
static float SIDE_LURF_CENTER_X		= 3.259;			//前侧边超声到车辆后轴中心点的X距离
static float SIDE_LUR_CENTERY		= 0.943;			//两侧边超声到车辆后轴中心点的Y距离
static float SIDE_LURR_CENTERX	    = 0.569;            //后侧边超声到车辆后轴中心点的X距离
//static float SENSORS_LONGITUDINAL_DIST		(3.28)			//????????????????????????????
static float FURTHEST_SIDE_DISTANCE	= 999;			//如果探测的距离是0，就赋此值


static float LeftCameraX            = REAR_VIEW_2_FRONT_AXLE - 0.16;
static float LeftCameraY            = VEHICLE_WID * 0.5 + 0.05;
static float RightCameraX           = LeftCameraX;
static float RightCameraY           = -LeftCameraY;
static float FrontCameraX           = FRONT_EDGE2CENTER;
static float FrontCameraY           = 0.;
static float RearCameraX            = -REAR_EDGE2CENTER;
static float RearCameraY            = 0.;

/*yrm3,实际车辆的超声安装位置*/
static float SENSOR1_X              = 3.564;
static float SENSOR1_Y              = 0.667;
static float SENSOR1_ANGLE          = 42 * PI / 180;//132

static float SENSOR2_X              = 3.631;
static float SENSOR2_Y              = 0.345;
static float SENSOR2_ANGLE          = 7 * PI / 180;//96

static float SENSOR3_X              = SENSOR2_X ;
static float SENSOR3_Y              = -SENSOR2_Y ;
static float SENSOR3_ANGLE          = -SENSOR2_ANGLE ;

static float SENSOR4_X              = SENSOR1_X ;
static float SENSOR4_Y              = -SENSOR1_Y ;
static float SENSOR4_ANGLE          = -SENSOR1_ANGLE ;

static float SENSOR5_X              = -0.902;
static float SENSOR5_Y              = 0.603;
static float SENSOR5_ANGLE          = 149 * PI / 180;//301

static float SENSOR6_X              = -0.965;
static float SENSOR6_Y              = 0.249;
static float SENSOR6_ANGLE          = 173 * PI / 180;

static float SENSOR7_X              = SENSOR6_X ;
static float SENSOR7_Y              = -SENSOR6_Y ;
static float SENSOR7_ANGLE          = -SENSOR6_ANGLE ;

static float SENSOR8_X              = SENSOR5_X ;
static float SENSOR8_Y              = -SENSOR5_Y ;
static float SENSOR8_ANGLE          = -SENSOR5_ANGLE ;

static float SENSOR9_X              = SIDE_LURF_CENTER_X ;
static float SENSOR9_Y              = SIDE_EDGE2CENTER ;
static float SENSOR9_ANGLE          = 82 * PI / 180;

static float SENSOR10_X             = SENSOR9_X ;
static float SENSOR10_Y             = -SENSOR9_Y ;
static float SENSOR10_ANGLE         = -SENSOR9_ANGLE ;

static float SENSOR11_X             = -SIDE_LURR_CENTERX;
static float SENSOR11_Y             = SIDE_EDGE2CENTER;
static float SENSOR11_ANGLE         = 92 * PI / 180;// *pi/3 rad, 120 degree
static float COS_SENSOR11_DIS_ANGEL = 1.0;

static float SENSOR12_X             = SENSOR11_X;
static float SENSOR12_Y             = -SENSOR11_Y;
static float SENSOR12_ANGLE         = -SENSOR11_ANGLE;
static float COS_SENSOR12_DIS_ANGEL = 1.0;

static uint32_t USS_K               = 58;
static float USS_K2                 = 7.752;
static uint32_t SPEED_K             = 1;
static uint32_t PLUS_COUNT          = 4096;


//3.规划参数
// 最大规划转向角(°)
static uint32_t MAX_STEERING_ANGLE        = 456;                    //最大方向盘转角
static uint32_t MAX_STEERING_ANGLE_SPEED  = 400;                   //最大方向盘角速
static float MAX_FRONT_AXLE_ANGLE         = 0.6;                           //最大前轴转角
//4.环视参数
static float CAMERA_2_MID                 = 0.58;                   //暂未用

//5.速度默认-避障相关
static float VERY_DANGOUS_VELOCITY        = 0.2;
static float DANGOUS_VELOCITY             = 0.3;

//6.转向角误差
static float STEERING_WHEEL_ANGLE_ERROR   = 10;          //目标方向盘转角和实际方向盘转角最大允许差值

static uint32_t ADDIDEGREE                = 0;              //暂未用

//7.USS state
static uint32_t PROXIMITY = 16;
static uint32_t NORMAL    = 0;


//rows(11);cols(5);vector<float>
static float EPSSteeringAngleRatio[11][5]=
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

static int EPS_STEERING_ANGLE_RATIO_SEGMENT=11;


//9.避障参数
#define LIST_NUM    (3)
//vetor<vector<short>>
static const short SteeringAngleMinDis[LIST_NUM][25]=
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

static uint32_t GEAR_P = 1;
static uint32_t GEAR_R = 2;
static uint32_t GEAR_N = 3;
static uint32_t GEAR_D = 4;
#endif

#endif