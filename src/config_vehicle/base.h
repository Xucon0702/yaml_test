#ifndef BASE_H
#define BASE_H


//公用但不用配置的
#if 1
#define PI 								 (3.1415926535897932384626433832795)

#endif

#define GAC_A58

#ifdef  GAC_A58

#define MD5RESULT "151666165"

#define AHEAD_CTRL_POINT_NUM (1)
//#define   VisionSlotDelay                               (1)

#define   WIDTH_HALF                                     (0.9435f)
#define   MIDDLE_TO_REAR                                 (0)//(1.3175)//车辆中心到后轴距离

#define   MIDDLE_TO_REAR_FREESPACE                       (1.349f)//车辆中心到后轴距离
#define   AXIS_DISTANCE                                  (2.730f)
#define   FRONT_USS_TO_FRONT_AXLE_DIST                   (0.956f)
#define   SENSORS_LONGITUDINAL_DIST                      (3.28f)
#define   HALF_VEHICLE_WIDTH                             (WIDTH_HALF)
#define   WHEEL_SPEED_PULSE_METERS_PER_PULSE             (0.0269f)
#define   FL_WHEEL_SPEED_PULSE_METERS_PER_PULSE             (0.0269f)
#define   FR_WHEEL_SPEED_PULSE_METERS_PER_PULSE             (0.0269f)
#define   RL_WHEEL_SPEED_PULSE_METERS_PER_PULSE             (0.0269f)
#define   RR_WHEEL_SPEED_PULSE_METERS_PER_PULSE             (0.0269f)

#define FRONT_WHEEL_SPAN  (1.617f)

#define REAR_WHEEL_SPAN         (1.610f)
//1.GAC_A58车车身参数,单位/m
#define VEHICLE_LEN				(4.650f)
#define VEHICLE_WID				(1.887f)
#define FRONT_EDGE2CENTER		(3.674f)
#define REAR_EDGE2CENTER		(0.976f)
#define SIDE_EDGE2CENTER		(VEHICLE_WID / 2)
#define WHEEL_BASE              AXIS_DISTANCE
//jiao dian zxy....
#define CHAMFER_LENGTH (0.4f)
#define FRONT_CHAMFER_L1 (0.)
#define FRONT_CHAMFER_L2 (0.)
#define REAR_CHAMFER_L1 (0.2f)
#define REAR_CHAMFER_L2 (0.2f)
#define CHAMFER_ANGLE (45*PI/180)
/*后视镜长度*/
#define REAR_VIEW_LENGTH   (0.2f)
#define REAR_VIEW_WIDTH  (0.25f)
#define REAR_VIEW_2_FRONT_AXLE  (2.16f)
//2.超声安装参数
#define SIDE_LURF_CENTER_X				(3.259f)			//前侧边超声到车辆后轴中心点的X距离
#define SIDE_LUR_CENTERY				(0.943f)			//两侧边超声到车辆后轴中心点的Y距离
#define SIDE_LURR_CENTERX				(0.569f)            //后侧边超声到车辆后轴中心点的X距离
//#define SENSORS_LONGITUDINAL_DIST		(3.28)			//????????????????????????????
#define FURTHEST_SIDE_DISTANCE			(999)			//如果探测的距离是0，就赋此值


#define LeftCameraX (REAR_VIEW_2_FRONT_AXLE - 0.16f)
#define LeftCameraY (VEHICLE_WID * 0.5 + 0.05)
#define RightCameraX (LeftCameraX)
#define RightCameraY (-LeftCameraY)
#define FrontCameraX (FRONT_EDGE2CENTER)
#define FrontCameraY (0.)
#define RearCameraX (-REAR_EDGE2CENTER)
#define RearCameraY (0.)

/*yrm3,实际车辆的超声安装位置*/
#define SENSOR1_X     (3.564f)
#define SENSOR1_Y     (0.667f)
#define SENSOR1_ANGLE (42 * PI / 180)//132

#define SENSOR2_X     (3.631f)
#define SENSOR2_Y     (0.345f)
#define SENSOR2_ANGLE (7 * PI / 180)//96

#define SENSOR3_X     ( SENSOR2_X )
#define SENSOR3_Y     (-SENSOR2_Y )
#define SENSOR3_ANGLE (-SENSOR2_ANGLE )

#define SENSOR4_X     ( SENSOR1_X )
#define SENSOR4_Y     (-SENSOR1_Y )
#define SENSOR4_ANGLE (-SENSOR1_ANGLE )

#define SENSOR5_X     (-0.902f)
#define SENSOR5_Y     ( 0.603f)
#define SENSOR5_ANGLE (149 * PI / 180)//301

#define SENSOR6_X     (-0.965f)
#define SENSOR6_Y     (0.249f)
#define SENSOR6_ANGLE (173 * PI / 180)

#define SENSOR7_X     (SENSOR6_X )
#define SENSOR7_Y     (-SENSOR6_Y )
#define SENSOR7_ANGLE (-SENSOR6_ANGLE )

#define SENSOR8_X     (SENSOR5_X )
#define SENSOR8_Y     (-SENSOR5_Y )
#define SENSOR8_ANGLE ( -SENSOR5_ANGLE )

#define SENSOR9_X     ( SIDE_LURF_CENTER_X )
#define SENSOR9_Y     ( SIDE_EDGE2CENTER )
#define SENSOR9_ANGLE (82 * PI / 180)

#define SENSOR10_X     ( SENSOR9_X )
#define SENSOR10_Y     (-SENSOR9_Y )
#define SENSOR10_ANGLE (-SENSOR9_ANGLE )

#define SENSOR11_X     (-SIDE_LURR_CENTERX)
#define SENSOR11_Y     ( SIDE_EDGE2CENTER)
#define SENSOR11_ANGLE (92 * PI / 180)// *pi/3 rad, 120 degree
#define COS_SENSOR11_DIS_ANGEL (1.0f)

#define SENSOR12_X     (SENSOR11_X)
#define SENSOR12_Y     (-SENSOR11_Y)
#define SENSOR12_ANGLE (-SENSOR11_ANGLE)
#define COS_SENSOR12_DIS_ANGEL (1.0f)

#define USS_K               (58)
#define USS_K2              (7.752)
#define SPEED_K             (1)
#define PLUS_COUNT          (4096)


//3.规划参数
// 最大规划转向角(°)
#define MAX_STEERING_ANGLE              (456)
#define MAX_STEERING_ANGLE_SPEED (400)                       //最大方向盘角速度
#define MAX_FRONT_AXLE_ANGLE (0.6)
//4.环视参数
#define CAMERA_2_MID                (0.58)

//5.速度默认
#define VERY_DANGOUS_VELOCITY (0.2)
#define DANGOUS_VELOCITY (0.3)

//6.转向角误差
#define STEERING_WHEEL_ANGLE_ERROR (10)          //目标方向盘转角和实际方向盘转角最大允许差值


#define ADDIDEGREE              (0)


//7.USS state
#define PROXIMITY (16)
#define NORMAL    (0)

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
#define LIST_NUM                     (3)
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

#define GEAR_P (1)
#define GEAR_R (2)
#define GEAR_N (3)
#define GEAR_D (4)
#endif

#endif