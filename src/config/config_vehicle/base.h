#ifndef BASE_H
#define BASE_H

#include "readCfg.h"

//公用但不用配置的
#if 1
// #define PI 								 (3.1415926535897932384626433832795)
#endif

// #define     GAC_A58

#ifdef  GAC_A58

extern uint32_t AHEAD_CTRL_POINT_NUM ;                      //暂不用
//extern float   VisionSlotDelay                               (1)

extern float WIDTH_HALF             ;
extern float MIDDLE_TO_REAR         ;

extern float MIDDLE_TO_REAR_FREESPACE      ;//车辆中心到后轴距离
extern float AXIS_DISTANCE                 ;//轴距
extern float FRONT_USS_TO_FRONT_AXLE_DIST  ;//前超声到前轴距离
extern float SENSORS_LONGITUDINAL_DIST     ;//超声安装相关
extern float HALF_VEHICLE_WIDTH            ;

extern float WHEEL_SPEED_PULSE_METERS_PER_PULSE      ;//轮脉冲分辨率
extern float FL_WHEEL_SPEED_PULSE_METERS_PER_PULSE   ;
extern float FR_WHEEL_SPEED_PULSE_METERS_PER_PULSE   ;
extern float RL_WHEEL_SPEED_PULSE_METERS_PER_PULSE   ;
extern float RR_WHEEL_SPEED_PULSE_METERS_PER_PULSE   ;

extern float FRONT_WHEEL_SPAN ;                  //前轮距
extern float REAR_WHEEL_SPAN  ;                  //后轮距

//1.GAC_A58车车身参数,单位/m
extern float VEHICLE_LEN			;            //车长
extern float VEHICLE_WID			;            //车宽
extern float FRONT_EDGE2CENTER		;            //前沿到后轴距离
extern float REAR_EDGE2CENTER		;            //后沿到后轴距离
extern float SIDE_EDGE2CENTER		;   //侧边沿到中心距离
extern float WHEEL_BASE             ;       //轴距
//jiao dian zxy....目前用的L1/L2
extern float CHAMFER_LENGTH         ;                       
extern float FRONT_CHAMFER_L1       ;                       //前保到倒角距离
extern float FRONT_CHAMFER_L2       ;
extern float REAR_CHAMFER_L1        ;
extern float REAR_CHAMFER_L2        ;
extern float CHAMFER_ANGLE          ;
/*后视镜长度*/
extern float REAR_VIEW_LENGTH       ;
extern float REAR_VIEW_WIDTH        ;
extern float REAR_VIEW_2_FRONT_AXLE ;             //后视镜到后轴距离
//2.超声安装参数
extern float SIDE_LURF_CENTER_X		;			//前侧边超声到车辆后轴中心点的X距离
extern float SIDE_LUR_CENTERY		;			//两侧边超声到车辆后轴中心点的Y距离
extern float SIDE_LURR_CENTERX	    ;            //后侧边超声到车辆后轴中心点的X距离
//extern float SENSORS_LONGITUDINAL_DIST		(3.28)			//????????????????????????????
extern float FURTHEST_SIDE_DISTANCE	;			//如果探测的距离是0，就赋此值


extern float LeftCameraX            ;
extern float LeftCameraY            ;
extern float RightCameraX           ;
extern float RightCameraY           ;
extern float FrontCameraX           ;
extern float FrontCameraY           ;
extern float RearCameraX            ;
extern float RearCameraY            ;

/*yrm3,实际车辆的超声安装位置*/
extern float SENSOR1_X              ;
extern float SENSOR1_Y              ;
extern float SENSOR1_ANGLE          ;//132

extern float SENSOR2_X              ;
extern float SENSOR2_Y              ;
extern float SENSOR2_ANGLE          ;//96

extern float SENSOR3_X              ;
extern float SENSOR3_Y              ;
extern float SENSOR3_ANGLE          ;

extern float SENSOR4_X              ;
extern float SENSOR4_Y              ;
extern float SENSOR4_ANGLE          ;

extern float SENSOR5_X              ;
extern float SENSOR5_Y              ;
extern float SENSOR5_ANGLE          ;//301

extern float SENSOR6_X              ;
extern float SENSOR6_Y              ;
extern float SENSOR6_ANGLE          ;

extern float SENSOR7_X              ;
extern float SENSOR7_Y              ;
extern float SENSOR7_ANGLE          ;

extern float SENSOR8_X              ;
extern float SENSOR8_Y              ;
extern float SENSOR8_ANGLE          ;

extern float SENSOR9_X              ;
extern float SENSOR9_Y              ;
extern float SENSOR9_ANGLE          ;

extern float SENSOR10_X             ;
extern float SENSOR10_Y             ;
extern float SENSOR10_ANGLE         ;

extern float SENSOR11_X             ;
extern float SENSOR11_Y             ;
extern float SENSOR11_ANGLE         ;// *pi/3 rad, 120 degree
extern float COS_SENSOR11_DIS_ANGEL ;

extern float SENSOR12_X             ;
extern float SENSOR12_Y             ;
extern float SENSOR12_ANGLE         ;
extern float COS_SENSOR12_DIS_ANGEL ;

extern uint32_t USS_K               ;
extern float USS_K2                 ;
extern uint32_t SPEED_K             ;
extern uint32_t PLUS_COUNT          ;


//3.规划参数
// 最大规划转向角(°)
extern uint32_t MAX_STEERING_ANGLE        ;                    //最大方向盘转角
extern uint32_t MAX_STEERING_ANGLE_SPEED  ;                   //最大方向盘角速
extern float MAX_FRONT_AXLE_ANGLE         ;                   //最大前轴转角
//4.环视参数
extern float CAMERA_2_MID                 ;                   //暂未用

//5.速度默认-避障相关
extern float VERY_DANGOUS_VELOCITY        ;
extern float DANGOUS_VELOCITY             ;

//6.转向角误差
extern float STEERING_WHEEL_ANGLE_ERROR   ;          //目标方向盘转角和实际方向盘转角最大允许差值

extern uint32_t ADDIDEGREE                ;              //暂未用

//7.USS state
extern uint32_t PROXIMITY ;
extern uint32_t NORMAL    ;


//rows(11);cols(5);vector<float>
extern float EPSSteeringAngleRatio[11][5];

extern int EPS_STEERING_ANGLE_RATIO_SEGMENT;


//9.避障参数

//vetor<vector<short>>
extern const short SteeringAngleMinDis[LIST_NUM][25];


//10.GEAR

// extern uint32_t GEAR_P = 1;
extern uint32_t GEAR_P ;
extern uint32_t GEAR_R ;
extern uint32_t GEAR_N ;
extern uint32_t GEAR_D ;
#endif

#endif