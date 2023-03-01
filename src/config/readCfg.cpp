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

void getCfgInfo(vector<vector<int16_t> > & vSAMinDis,vector<vector<float> > & vSARatio,uint32_t & disLsitNum,VehicleConfig &mVehicleCfg)
{
     //车身参数配置获取:
    gVehicleYaml.showVehicleConfig();
    gVehicleYaml.Init();
    gVehicleYaml.showVehicleConfig();
    gVehicleYaml.checkCfg();
    disLsitNum = gVehicleYaml.getSteeringAngleMinDisLsitNum();
    gVehicleYaml.getVehicleConfig(mVehicleCfg);
    gVehicleYaml.getSteeringAngleMinDis(vSAMinDis);
    gVehicleYaml.getEPSSteeringAngleRatio(vSARatio);

    //设置静态变量:
    


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