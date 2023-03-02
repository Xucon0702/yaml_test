#ifndef CFG_VEHICLE_CODE_H
#define CFG_VEHICLE_CODE_H

//注意：此文件中回车换行必须是LF!!!

#include<cstring>
#include <stddef.h>
#include<stdint.h>
#include<vector>

#include "yaml.h"

using namespace std;

#define MD5RESULT "S58_ss_656546531"
#define VERSION   "A58_2023_02_27_0_0_1"

namespace motovis
{
    namespace yamlVehicle
    {

#define CFG_VEHICLE_CODE_FILE "MV_VEHICLE_YAML" //从环境变量获取配置文件路径

        typedef struct _VehicleConfig
        {
            //车身参数
            uint32_t    ahead_ctrl_point_num;//AHEAD_CTRL_POINT_NUM
            float       width_half;         //WIDTH_HALF        一半车宽
            float       middle_to_rear;     //MIDDLE_TO_REAR    车辆中心到后轴距离

            float       middle_to_rear_freespace;//MIDDLE_TO_REAR_FREESPACE 车辆中心到后轴距离
            float       axis_distance;//AXIS_DISTANCE
            float       front_uss_to_front_axle_dist;//FRONT_USS_TO_FRONT_AXLE_DIST
            float       sensors_longitudinal_dist;//SENSORS_LONGITUDINAL_DIST
            float       half_vehicle_width;//HALF_VEHICLE_WIDTH=width_half

            //轮脉冲
            float       wheel_speed_pulse_meters_per_pulse;//WHEEL_SPEED_PULSE_METERS_PER_PULSE
            float       fl_wheel_speed_pulse_meters_per_pulse;//FL_WHEEL_SPEED_PULSE_METERS_PER_PULSE
            float       fr_wheel_speed_pulse_meters_per_pulse;//FR_WHEEL_SPEED_PULSE_METERS_PER_PULSE
            float       rl_wheel_speed_pulse_meters_per_pulse;//RL_WHEEL_SPEED_PULSE_METERS_PER_PULSE
            float       rr_wheel_speed_pulse_meters_per_pulse;//RR_WHEEL_SPEED_PULSE_METERS_PER_PULSE

            float       front_wheel_span;//FRONT_WHEEL_SPAN
            float       rear_wheel_span;//REAR_WHEEL_SPAN

            float       vehicle_len;//VEHICLE_LEN   
            float       vehicle_wid;//VEHICLE_WID
            float       front_edge2center;//FRONT_EDGE2CENTER
            float       rear_edge2center;//REAR_EDGE2CENTER
            float       side_edge2center;//SIDE_EDGE2CENTER=VEHICLE_WID/2 
            float       wheel_base;//WHEEL_BASE=AXIS_DISTANCE

            float       chamfer_length;//CHAMFER_LENGTH
            float       front_chamfer_l1;//FRONT_CHAMFER_L1
            float       front_chamfer_l2;//FRONT_CHAMFER_L2
            float       rear_chamfer_l1;//rear_CHAMFER_L1
            float       rear_chamfer_l2;//rear_CHAMFER_L2
            float       chamfer_angle;//CHAMFER_ANGLE = 45*PI/180

            /*后视镜长度*/
            float       rear_view_length;//REAR_VIEW_LENGTH
            float       read_view_width;//REAR_VIEW_WIDTH
            float       rear_view_2_front_axle;//REAR_VIEW_2_FRONT_AXLE

            //2.超声安装参数
            float       side_lurf_center_x;//SIDE_LURF_CENTER_X 前侧边超声到车辆后轴中心点的X距离
            float       side_lur_centery;//SIDE_LUR_CENTERY     两侧边超声到车辆后轴中心点的Y距离
            float       side_lurr_centerx;//SIDE_LURR_CENTERX   后侧边超声到车辆后轴中心点的X距离
            float       furthest_side_distance;//FURTHEST_SIDE_DISTANCE    如果探测的距离是0，就赋此值,暂不使用

            float       leftCamerax;//LeftCameraX = REAR_VIEW_2_FRONT_AXLE-0.16f        
            float       leftCameraY;//LeftCameraY = VEHICLE_WID*0.5+0.05
            float       rightCameraX;//RightCameraX = LeftCameraX
            float       rightCameraY;//RightCameraY = -LeftCameraX
            float       frontCameraX;//FrontCameraX = FRONT_EDGE2CENTER
            float       frontCameraY;//FrontCameraY = 0;
            float       rearCameraX;//RearCameraX  = -REAR_EDGE2CENTER
            float       rearCameraY;//RearCameraY = 0;

            //实际车辆的超声安装位置
            float       sensor1_x;//SENSOR1_X
            float       sensor1_y;//SENSOR1_Y
            float       sensor1_angle;//SENSOR1_ANGLE
            float       sensor2_x;//SENSOR2_X
            float       sensor2_y;//SENSOR2_Y
            float       sensor2_angle;//SENSOR2_ANGLE
            float       sensor3_x;//SENSOR3_X
            float       sensor3_y;//SENSOR3_Y
            float       sensor3_angle;//SENSOR3_ANGLE
            float       sensor4_x;//SENSOR4_X
            float       sensor4_y;//SENSOR4_Y
            float       sensor4_angle;//SENSOR4_ANGLE
            float       sensor5_x;//SENSOR5_X
            float       sensor5_y;//SENSOR5_Y
            float       sensor5_angle;//SENSOR5_ANGLE
            float       sensor6_x;//SENSOR6_X
            float       sensor6_y;//SENSOR6_Y
            float       sensor6_angle;//SENSOR6_ANGLE
            float       sensor7_x;//SENSOR7_X
            float       sensor7_y;//SENSOR7_Y
            float       sensor7_angle;//SENSOR7_ANGLE
            float       sensor8_x;//SENSOR8_X
            float       sensor8_y;//SENSOR8_Y
            float       sensor8_angle;//SENSOR8_ANGLE
            float       sensor9_x;//SENSOR9_X  = SIDE_LURF_CENTER_X
            float       sensor9_y;//SENSOR9_Y  = SIDE_EDGE2CENTER
            float       sensor9_angle;//SENSOR9_ANGLE
            float       sensor10_x;//SENSOR10_X
            float       sensor10_y;//SENSOR10_Y
            float       sensor10_angle;//SENSOR10_ANGLE
            float       sensor11_x;//SENSOR11_X = -SIDE_LURR_CENTERX
            float       sensor11_y;//SENSOR11_Y = SIDE_EDGE2CENTER
            float       sensor11_angle;//SENSOR11_ANGLE
            float       cos_sensor11_dis_angel;//COS_SENSOR11_DIS_ANGEL 
            float       sensor12_x;//SENSOR12_X
            float       sensor12_y;//SENSOR12_Y
            float       sensor12_angle;//SENSOR12_ANGLE
            float       cos_sensor12_dis_angel;//COS_SENSOR12_DIS_ANGEL 

            uint32_t    uss_k;//USS_K
            float       uss_k2;//USS_K2
            uint32_t    speed_k;//SPEED_K
            uint32_t    plus_count;//PLUS_COUNT

        //规划参数
            // 最大规划转向角
            uint32_t    max_steering_angle;//MAX_STEERING_ANGLE
            uint32_t    max_steering_angle_speed;//MAX_STEERING_ANGLE_SPEED //最大方向盘角速度
            float       max_front_axle_angle;//MAX_FRONT_AXLE_ANGLE
            float       camera_2_mid;//CAMERA_2_MID 环视参数
            //速度默认
            float       very_dangrous_velocity;//VERY_DANGOUS_VELOCITY
            float       dangrous_velocity;//DANGOUS_VELOCITY
            //转向角误差
            uint32_t    steering_wheel_angle_error;//STEERING_WHEEL_ANGLE_ERROR 目标方向盘转角和实际方向盘转角最大允许差值
            uint32_t    addIdegree;//ADDIDEGREE

            //USS state
            uint32_t   proximity;//PROXIMITY (16)
            uint32_t   normal;//NORMAL    (0)
            
            //GEAR
            uint32_t    gear_p;//GEAR_P
            uint32_t    gear_r;//GEAR_R
            uint32_t    gear_n;//GEAR_N
            uint32_t    gear_d;//GEAR_D

        }VehicleConfig;    


        class CCfgVehicleCode
        {
        public:
            bool Init();
            void showVehicleConfig();  
            void writeConfigYaml(); 
            bool checkCfg();      
            // void setCfgVariable(vector<vector<int16_t> > & vSAMinDis,vector<vector<int16_t> > & vSAMinDis,uint32_t disLsitNum,VehicleConfig mVehicleCfg);
            void getVehicleConfig(VehicleConfig & obj);
            uint32_t getSteeringAngleMinDisLsitNum();
            uint32_t getEPSSteeringAngleRatiosRows();

            void getSteeringAngleMinDis(vector<vector<int16_t> > & vSAMinDis);
            void getEPSSteeringAngleRatio( vector<vector<float> > & vSARatio);

        public:
            std::string readConfigPath = "../config/vehicle.yaml";
            std::string writeConfigPath;
        private:
            bool YamlInit();
            bool IsFileExistsAccess(std::string path = "");
            bool PasingYamlNode(const YAML::Node &tNode);
            void PasNode(std::string key, std::string val);
            bool PasingYamlArray(const YAML::Node &tNode);


            template <class Type>
            Type StringToNum(const std::string &str);
            
            VehicleConfig m_VehicleConfig;
            std::string md5Result = "";
            std::string version = "";

            uint32_t EPSSteeringAngleRatiosRows ;
            uint32_t EPSSteeringAngleRatiosClos ;
            vector<vector<float> > EPSSteeringAngleRatio;//方向盘转角标定值
            //避障参数
            uint32_t SteeringAngleMinDisLsitNum;
            uint32_t SteeringAngleMinDisLsitClos;
            vector<vector<int16_t> > SteeringAngleMinDis;
        };
        


    } // namespace yamlTest
} // namespace yamlFunc
#endif // CFG_MANAGER_H
