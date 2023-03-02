#include "cfg_vehicle_code.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include<iostream>
#include<assert.h>

#include "base.h"

namespace motovis
{
    namespace yamlVehicle
    {

        bool CCfgVehicleCode::Init()
        {
            std::cout << "CCfgVehicleCode  Init start 2211301445"<<"\n";
            md5Result.empty();
            version.empty();
            EPSSteeringAngleRatio.clear();
            EPSSteeringAngleRatio.resize(0);
            SteeringAngleMinDis.clear();
            SteeringAngleMinDis.resize(0);

            m_VehicleConfig.ahead_ctrl_point_num = 0;
            m_VehicleConfig.width_half = 0;
            m_VehicleConfig.middle_to_rear = 0;

            EPSSteeringAngleRatiosRows = 0;
            EPSSteeringAngleRatiosClos = 0;

            return YamlInit();
        }

        bool CCfgVehicleCode::YamlInit()
        {
            bool res = false;
            std::cout << "CCfgVehicleCode YamlInit start !!!!!"<<"\n";

            try
            {
                const char *p = getenv(CFG_VEHICLE_CODE_FILE);
                std::string mvYamlPath = "";
                std::cout << "getenv MV_VEHICLE_YAML start !"<<"\n";
                if (p == NULL)
                {
                    std::cout << "getenv MV_VEHICLE_YAML is NULL!"<<"\n";
                }
                else
                {
                    mvYamlPath = p;
                    std::cout << "getenv MV_VEHICLE_YAML successful !! mvYamlPath = " << mvYamlPath<<"\n";
                }

                if (IsFileExistsAccess(mvYamlPath))
                {
                    YAML::Node config;
                    // 当文件不存在或yaml格式出错时，抛异常
                    try
                    {
                        config = YAML::LoadFile(mvYamlPath);
                        res = PasingYamlNode(config);


                        PasingYamlArray(config);
                    }
                    catch (const YAML::Exception &e)
                    {
                        std::cout << "YAML::Exception :" << e.what()<<"\n";
                    }
                }
                else
                {
                    std::cout << "mvYamlPath = " << mvYamlPath << " is not exit !!"<<"\n";
                    //当环境变量没有设置时也可以通过设置readConfigPath来配置
                    mvYamlPath = readConfigPath;
                    if (IsFileExistsAccess(mvYamlPath))
                    {
                        YAML::Node config;
                        // 当文件不存在或yaml格式出错时，抛异常
                        try
                        {
                            config = YAML::LoadFile(mvYamlPath);
                            res = PasingYamlNode(config);
                            PasingYamlArray(config);

                        }
                        catch (const YAML::Exception &e)
                        {
                            std::cout << "YAML::Exception :" << e.what()<<"\n";
                        }
                    }
                    else
                    {
                        std::cout << "mvYamlPath = readConfigPath =  " << mvYamlPath << " is not exit !!"<<"\n";
                    }
                }
            }
            catch (...)
            {
                std::cout << "please export MV_VEHICLE_YAML path !!"<<"\n";
            }
            return res;
        }

        bool CCfgVehicleCode::PasingYamlNode(const YAML::Node &tNode)
        {
            std::string str;            

            try
            {
                for (YAML::const_iterator it = tNode.begin(); it != tNode.end(); ++it)
                {
                    std::string key = it->first.as<std::string>();
                    YAML::Node value = it->second;

					//不是常量的话递归子数据集
                    if (YAML::NodeType::Scalar != value.Type())
                    {
                        std::cout << "Yaml--111:" << key << " : "<<"\n";
                        PasingYamlNode(value);
                    }
                    else
                    {
                        std::cout << "Yaml--222:" << key << " : " << tNode[key].as<std::string>()<<"\n";
                        PasNode(key,tNode[key].as<std::string>());                        
                    }
                   
                }
            }
            catch (const YAML::Exception &e)
            {
                std::cout<< "YAML::Exception" << e.what()<<"\n";
                return false;
            }

            return true;
        }

        bool CCfgVehicleCode::PasingYamlArray(const YAML::Node &tNode)
        {
            //ratios
            string rariosMemberName = "EPSSteeringAngleRatio_";
            vector<float> ratiosExt;
            ratiosExt.clear();
            ratiosExt.resize(0);
            //disList
            string disListMemberName = "SteeringAngleMinDis_";
            vector<int16_t> disListExt;
            disListExt.clear();
            disListExt.resize(0);

            //解析EPSSteeringAngleRatio
            std::cout<<"Pasing EPSSteeringAngleRatio start:"<<"EPSSteeringAngleRatiosRows="<<EPSSteeringAngleRatiosRows<<std::endl;
            for(int i= 0;i<EPSSteeringAngleRatiosRows;i++)
            {
                rariosMemberName = "EPSSteeringAngleRatio_";
                rariosMemberName += std::to_string(i);
                std::cout<<"rariosMemberName:"<<rariosMemberName<<std::endl;   
                ratiosExt= tNode["EPSSteeringAngleRatios"][rariosMemberName].as<vector<float>>();
                if(EPSSteeringAngleRatiosRows != 0)
                {
                    assert((int)ratiosExt.size() == EPSSteeringAngleRatiosClos);
                } 
                EPSSteeringAngleRatio.push_back(ratiosExt);   

                std::cout <<"ratiosExt:start:ratiosExt.size()="<<ratiosExt.size()<<std::endl;
            
                for (int i = 0; i < ratiosExt.size(); i++) { 
                    std::cout << ratiosExt[i] << " ";
                }            
                std::cout <<"\nratiosExt:end"<< std::endl;
            }

            for (int i = 0; i < EPSSteeringAngleRatio.size(); i++) {       // 行数
            std::cout<<"EPSSteeringAngleRatio:i="<<i<<";EPSSteeringAngleRatio[i].size()="<<EPSSteeringAngleRatio[i].size()<<std::endl;
            for (int j = 0; j < EPSSteeringAngleRatio[i].size(); j++) {  // A[i].size() 第i行的列数
                std::cout << EPSSteeringAngleRatio[i][j] << " ";
            }
            std::cout << std::endl;
            }

            //解析SteeringAngleMinDiss
              std::cout<<"Pasing SteeringAngleMinDiss start:"<<"SteeringAngleMinDisLsitNum="<<SteeringAngleMinDisLsitNum<<";SteeringAngleMinDisLsitClos = "<<SteeringAngleMinDisLsitClos<<std::endl;
            for(int i= 0;i<SteeringAngleMinDisLsitNum;i++)
            {
                disListMemberName = "SteeringAngleMinDis_";
                disListMemberName += std::to_string(i);
                std::cout<<"disListMemberName:"<<disListMemberName<<std::endl;   
                disListExt= tNode["SteeringAngleMinDiss"][disListMemberName].as<vector<int16_t>>();
                if(SteeringAngleMinDisLsitClos != 0)
                {
                    assert((int)disListExt.size() == SteeringAngleMinDisLsitClos);
                } 
                SteeringAngleMinDis.push_back(disListExt);   

                std::cout <<"disListExt:start:disListExt.size()="<<disListExt.size()<<std::endl;
            
                for (int i = 0; i < disListExt.size(); i++) { 
                    std::cout << disListExt[i] << " ";
                }            
                std::cout <<"\disListExt:end"<< std::endl;
            }

            for (int i = 0; i < SteeringAngleMinDis.size(); i++) {       // 行数
            std::cout<<"SteeringAngleMinDis:i="<<i<<";SteeringAngleMinDis[i].size()="<<SteeringAngleMinDis[i].size()<<std::endl;
            for (int j = 0; j < SteeringAngleMinDis[i].size(); j++) {  // A[i].size() 第i行的列数
                std::cout << SteeringAngleMinDis[i][j] << " ";
            }
            std::cout << std::endl;
            }

        }

        void CCfgVehicleCode::showVehicleConfig()
        {
            std::cout<<"\n"<<"showVehicleConfig"<<std::endl;

            std::cout<<"version:"<<version<<std::endl;
            std::cout<<"md5Result:"<<md5Result<<std::endl;

            std::cout<<"ahead_ctrl_point_num:"<<m_VehicleConfig.ahead_ctrl_point_num<<std::endl;
            std::cout<<"width_half:"<<m_VehicleConfig.width_half<<std::endl;
            std::cout<<"middle_to_rear:"<<m_VehicleConfig.middle_to_rear<<std::endl;
  
            std::cout<<"EPSSteeringAngleRatiosRows:"<<EPSSteeringAngleRatiosRows<<std::endl;
            std::cout<<"EPSSteeringAngleRatiosClos:"<<EPSSteeringAngleRatiosClos<<std::endl;

            //EPSSteeringAngleRatio
            std::cout <<"EPSSteeringAngleRatio:start:EPSSteeringAngleRatio.size()="<<EPSSteeringAngleRatio.size()<<std::endl;
            for (int i = 0; i < EPSSteeringAngleRatio.size(); i++) {       // 行数
            std::cout<<"EPSSteeringAngleRatio:i="<<i<<";EPSSteeringAngleRatio[i].size()="<<EPSSteeringAngleRatio[i].size()<<std::endl;
            for (int j = 0; j < EPSSteeringAngleRatio[i].size(); j++) {  // A[i].size() 第i行的列数                
                std::cout << EPSSteeringAngleRatio[i][j] << " ";
            }
            std::cout << std::endl;
            }
            std::cout <<"EPSSteeringAngleRatio:end"<< std::endl;


            std::cout<<"\n";

            return;
        }


        bool CCfgVehicleCode::IsFileExistsAccess(std::string path)
        {
            return ((access(path.c_str(), F_OK ) != -1 ));
        }

        void CCfgVehicleCode::PasNode(std::string key, std::string val)
        {
            if(key == "version")
            {
                version = val;
                std::cout<<"version here:"<<version<<std::endl;
            }   
            else if(key == "md5")
            {
                md5Result = val;
            } 
            else if(key == "AHEAD_CTRL_POINT_NUM")
            {
                m_VehicleConfig.ahead_ctrl_point_num = StringToNum<uint32_t>(val);
            }
            else if(key == "WIDTH_HALF")
            {
                m_VehicleConfig.width_half = StringToNum<float>(val);
            }
            else if(key == "MIDDLE_TO_REAR")
            {
                m_VehicleConfig.middle_to_rear = StringToNum<float>(val);
            }
            else if(key == "MIDDLE_TO_REAR_FREESPACE")
            {
                m_VehicleConfig.middle_to_rear_freespace = StringToNum<float>(val);
            }
             else if(key == "AXIS_DISTANCE")
            {
                m_VehicleConfig.axis_distance = StringToNum<float>(val);
            }
             else if(key == "FRONT_USS_TO_FRONT_AXLE_DIST")
            {
                m_VehicleConfig.front_uss_to_front_axle_dist = StringToNum<float>(val);
            } else if(key == "SENSORS_LONGITUDINAL_DIST")
            {
                m_VehicleConfig.sensors_longitudinal_dist = StringToNum<float>(val);
            } else if(key == "HALF_VEHICLE_WIDTH")
            {
                m_VehicleConfig.half_vehicle_width = StringToNum<float>(val);
            } else if(key == "WHEEL_SPEED_PULSE_METERS_PER_PULSE")
            {
                m_VehicleConfig.wheel_speed_pulse_meters_per_pulse = StringToNum<float>(val);
            } else if(key == "FL_WHEEL_SPEED_PULSE_METERS_PER_PULSE")
            {
                m_VehicleConfig.fl_wheel_speed_pulse_meters_per_pulse = StringToNum<float>(val);
            } else if(key == "FR_WHEEL_SPEED_PULSE_METERS_PER_PULSE")
            {
                m_VehicleConfig.fr_wheel_speed_pulse_meters_per_pulse = StringToNum<float>(val);
            } else if(key == "RL_WHEEL_SPEED_PULSE_METERS_PER_PULSE")
            {
                m_VehicleConfig.rl_wheel_speed_pulse_meters_per_pulse = StringToNum<float>(val);
            } else if(key == "RR_WHEEL_SPEED_PULSE_METERS_PER_PULSE")
            {
                m_VehicleConfig.rr_wheel_speed_pulse_meters_per_pulse = StringToNum<float>(val);
            } else if(key == "FRONT_WHEEL_SPAN")
            {
                m_VehicleConfig.front_wheel_span = StringToNum<float>(val);
            } else if(key == "REAR_WHEEL_SPAN")
            {
                m_VehicleConfig.rear_wheel_span = StringToNum<float>(val);
            } else if(key == "VEHICLE_LEN")
            {
                m_VehicleConfig.vehicle_len = StringToNum<float>(val);
            } else if(key == "VEHICLE_WID")
            {
                m_VehicleConfig.vehicle_wid = StringToNum<float>(val);
            } else if(key == "FRONT_EDGE2CENTER")
            {
                m_VehicleConfig.front_edge2center = StringToNum<float>(val);
            } else if(key == "REAR_EDGE2CENTER")
            {
                m_VehicleConfig.rear_edge2center = StringToNum<float>(val);
            } else if(key == "SIDE_EDGE2CENTER")
            {
                m_VehicleConfig.side_edge2center = StringToNum<float>(val);
            } else if(key == "WHEEL_BASE")
            {
                m_VehicleConfig.wheel_base = StringToNum<float>(val);
            } else if(key == "CHAMFER_LENGTH")
            {
                m_VehicleConfig.chamfer_length = StringToNum<float>(val);
            } else if(key == "FRONT_CHAMFER_L1")
            {
                m_VehicleConfig.front_chamfer_l1 = StringToNum<float>(val);
            } else if(key == "FRONT_CHAMFER_L2")
            {
                m_VehicleConfig.front_chamfer_l2 = StringToNum<float>(val);
            } else if(key == "REAR_CHAMFER_L1")
            {
                m_VehicleConfig.rear_chamfer_l1 = StringToNum<float>(val);
            } else if(key == "REAR_CHAMFER_L2")
            {
                m_VehicleConfig.rear_chamfer_l2 = StringToNum<float>(val);
            } else if(key == "CHAMFER_ANGLE")
            {
                m_VehicleConfig.chamfer_angle = (StringToNum<float>(val))*PI/180;
            } else if(key == "REAR_VIEW_LENGTH")
            {
                m_VehicleConfig.rear_view_length = StringToNum<float>(val);
            } else if(key == "REAR_VIEW_WIDTH")
            {
                m_VehicleConfig.read_view_width = StringToNum<float>(val);
            } else if(key == "REAR_VIEW_2_FRONT_AXLE")
            {
                m_VehicleConfig.rear_view_2_front_axle = StringToNum<float>(val);
            } else if(key == "SIDE_LURF_CENTER_X")
            {
                m_VehicleConfig.side_lurf_center_x = StringToNum<float>(val);
            } else if(key == "SIDE_LUR_CENTERY")
            {
                m_VehicleConfig.side_lur_centery = StringToNum<float>(val);
            } else if(key == "SIDE_LURR_CENTERX")
            {
                m_VehicleConfig.side_lurr_centerx = StringToNum<float>(val);
            } else if(key == "FURTHEST_SIDE_DISTANCE")
            {
                m_VehicleConfig.furthest_side_distance = StringToNum<float>(val);
            } else if(key == "LeftCameraX")
            {
                m_VehicleConfig.leftCamerax = StringToNum<float>(val);
            } else if(key == "LeftCameraY")
            {
                m_VehicleConfig.leftCameraY = StringToNum<float>(val);
            } else if(key == "RightCameraX")
            {
                m_VehicleConfig.rightCameraX = StringToNum<float>(val);
            } else if(key == "RightCameraY")
            {
                m_VehicleConfig.rightCameraY = StringToNum<float>(val);
            } else if(key == "FrontCameraX")
            {
                m_VehicleConfig.frontCameraX = StringToNum<float>(val);
            } else if(key == "FrontCameraY")
            {
                m_VehicleConfig.frontCameraY = StringToNum<float>(val);
            } else if(key == "RearCameraX")
            {
                m_VehicleConfig.rearCameraX = StringToNum<float>(val);
            } else if(key == "RearCameraY")
            {
                m_VehicleConfig.rearCameraY = StringToNum<float>(val);
            } else if(key == "SENSOR1_X")
            {
                m_VehicleConfig.sensor1_x = StringToNum<float>(val);
            } else if(key == "SENSOR1_Y")
            {
                m_VehicleConfig.sensor1_y = StringToNum<float>(val);
            } else if(key == "SENSOR1_ANGLE")
            {
                m_VehicleConfig.sensor1_angle = (StringToNum<float>(val))* PI / 180;
            } else if(key == "SENSOR2_X")
            {
                m_VehicleConfig.sensor2_x = StringToNum<float>(val);
            } else if(key == "SENSOR2_Y")
            {
                m_VehicleConfig.sensor2_y = StringToNum<float>(val);
            } else if(key == "SENSOR2_ANGLE")
            {
                m_VehicleConfig.sensor2_angle = (StringToNum<float>(val))* PI / 180;
            } else if(key == "SENSOR3_X")
            {
                m_VehicleConfig.sensor3_x = StringToNum<float>(val);
            } else if(key == "SENSOR3_Y")
            {
                m_VehicleConfig.sensor3_y = StringToNum<float>(val);
            } else if(key == "SENSOR3_ANGLE")
            {
                m_VehicleConfig.sensor3_angle = (StringToNum<float>(val))* PI / 180;
            } else if(key == "SENSOR4_X")
            {
                m_VehicleConfig.sensor4_x = StringToNum<float>(val);
            } else if(key == "SENSOR4_Y")
            {
                m_VehicleConfig.sensor4_y = StringToNum<float>(val);
            } else if(key == "SENSOR4_ANGLE")
            {
                m_VehicleConfig.sensor4_angle = (StringToNum<float>(val))* PI / 180;
            } else if(key == "SENSOR5_X")
            {
                m_VehicleConfig.sensor5_x = StringToNum<float>(val);
            } else if(key == "SENSOR5_Y")
            {
                m_VehicleConfig.sensor5_y = StringToNum<float>(val);
            } else if(key == "SENSOR5_ANGLE")
            {
                m_VehicleConfig.sensor5_angle = (StringToNum<float>(val))* PI / 180;
            } else if(key == "SENSOR6_X")
            {
                m_VehicleConfig.sensor6_x = StringToNum<float>(val);
            } else if(key == "SENSOR6_Y")
            {
                m_VehicleConfig.sensor6_y = StringToNum<float>(val);
            } else if(key == "SENSOR6_ANGLE")
            {
                m_VehicleConfig.sensor6_angle = (StringToNum<float>(val))* PI / 180;
            } else if(key == "SENSOR7_X")
            {
                m_VehicleConfig.sensor7_x = StringToNum<float>(val);
            } else if(key == "SENSOR7_Y")
            {
                m_VehicleConfig.sensor7_y = StringToNum<float>(val);
            } else if(key == "SENSOR7_ANGLE")
            {
                m_VehicleConfig.sensor7_angle = (StringToNum<float>(val))* PI / 180;
            }else if(key == "SENSOR8_X")
            {
                m_VehicleConfig.sensor8_x = StringToNum<float>(val);
            }else if(key == "SENSOR8_Y")
            {
                m_VehicleConfig.sensor8_y = StringToNum<float>(val);
            }else if(key == "SENSOR8_ANGLE")
            {
                m_VehicleConfig.sensor8_angle = (StringToNum<float>(val))* PI / 180;
            }else if(key == "SENSOR9_X")
            {
                m_VehicleConfig.sensor9_x = StringToNum<float>(val);
            }else if(key == "SENSOR9_Y")
            {
                m_VehicleConfig.sensor9_y = StringToNum<float>(val);
            }else if(key == "SENSOR9_ANGLE")
            {
                m_VehicleConfig.sensor9_angle = (StringToNum<float>(val))* PI / 180;
            }else if(key == "SENSOR10_X")
            {
                m_VehicleConfig.sensor10_x = StringToNum<float>(val);
            }else if(key == "SENSOR10_Y")
            {
                m_VehicleConfig.sensor10_y = StringToNum<float>(val);
            }else if(key == "SENSOR10_ANGLE")
            {
                m_VehicleConfig.sensor10_angle = (StringToNum<float>(val))* PI / 180;
            }else if(key == "SENSOR11_X")
            {
                m_VehicleConfig.sensor11_x = StringToNum<float>(val);
            }else if(key == "SENSOR11_Y")
            {
                m_VehicleConfig.sensor11_y = StringToNum<float>(val);
            }else if(key == "SENSOR11_ANGLE")
            {
                m_VehicleConfig.sensor11_angle = (StringToNum<float>(val))* PI / 180;
            }else if(key == "COS_SENSOR11_DIS_ANGEL")
            {
                m_VehicleConfig.cos_sensor11_dis_angel = StringToNum<float>(val);
            }else if(key == "SENSOR12_X")
            {
                m_VehicleConfig.sensor12_x = StringToNum<float>(val);
            }else if(key == "SENSOR12_Y")
            {
                m_VehicleConfig.sensor12_y = StringToNum<float>(val);
            }else if(key == "SENSOR12_ANGLE")
            {
                m_VehicleConfig.sensor12_angle = (StringToNum<float>(val))* PI / 180;
            }else if(key == "COS_SENSOR12_DIS_ANGEL")
            {
                m_VehicleConfig.cos_sensor12_dis_angel = StringToNum<float>(val);
            }else if(key == "USS_K")
            {
                m_VehicleConfig.uss_k = StringToNum<uint32_t>(val);
            }else if(key == "USS_K2")
            {
                m_VehicleConfig.uss_k2 = StringToNum<float>(val);
            }else if(key == "SPEED_K")
            {
                m_VehicleConfig.speed_k = StringToNum<uint32_t>(val);
            }else if(key == "PLUS_COUNT")
            {
                m_VehicleConfig.plus_count = StringToNum<uint32_t>(val);
            }else if(key == "MAX_STEERING_ANGLE")
            {
                m_VehicleConfig.max_steering_angle = StringToNum<uint32_t>(val);
            }else if(key == "MAX_STEERING_ANGLE_SPEED")
            {
                m_VehicleConfig.max_steering_angle_speed = StringToNum<uint32_t>(val);
            }else if(key == "MAX_FRONT_AXLE_ANGLE")
            {
                m_VehicleConfig.max_front_axle_angle = StringToNum<float>(val);
            }else if(key == "CAMERA_2_MID")
            {
                m_VehicleConfig.camera_2_mid = StringToNum<float>(val);
            }else if(key == "VERY_DANGOUS_VELOCITY")
            {
                m_VehicleConfig.very_dangrous_velocity = StringToNum<float>(val);
            }else if(key == "DANGOUS_VELOCITY")
            {
                m_VehicleConfig.dangrous_velocity = StringToNum<float>(val);
            }else if(key == "STEERING_WHEEL_ANGLE_ERROR")
            {
                m_VehicleConfig.steering_wheel_angle_error = StringToNum<uint32_t>(val);
            }else if(key == "ADDIDEGREE")
            {
                m_VehicleConfig.addIdegree = StringToNum<uint32_t>(val);
            }else if(key == "PROXIMITY")
            {
                m_VehicleConfig.proximity = StringToNum<uint32_t>(val);
            }else if(key == "NORMAL")
            {
                m_VehicleConfig.normal = StringToNum<uint32_t>(val);
            }else if(key == "GEAR_P")
            {
                m_VehicleConfig.gear_p = StringToNum<uint32_t>(val);
            }else if(key == "GEAR_R")
            {
                m_VehicleConfig.gear_r = StringToNum<uint32_t>(val);
            }else if(key == "GEAR_N")
            {
                m_VehicleConfig.gear_n = StringToNum<uint32_t>(val);
            }else if(key == "GEAR_D")
            {
                m_VehicleConfig.gear_d = StringToNum<uint32_t>(val);
            }
            //数组行、列
            else if(key == "EPSSteeringAngleRatiosRows")
            {
                EPSSteeringAngleRatiosRows = StringToNum<uint32_t>(val);
            } 
            else if(key == "EPSSteeringAngleRatiosClos")
            {
                EPSSteeringAngleRatiosClos = StringToNum<uint32_t>(val);
            }
            else if(key == "SteeringAngleMinDisLsitNum")
            {
                SteeringAngleMinDisLsitNum = StringToNum<uint32_t>(val);
            }
            else if(key == "SteeringAngleMinDisLsitClos")
            {
                SteeringAngleMinDisLsitClos = StringToNum<uint32_t>(val);
            }                  
        }

        template <class Type>
        Type CCfgVehicleCode::StringToNum(const std::string &str)
        {
            std::istringstream iss(str);
            Type num;
            iss >> num;
            return num;
        }

        //写yaml文件:流文件-->loadfile-->填充数据-->流刷新文件
        void CCfgVehicleCode::writeConfigYaml()
        {
            std::ofstream fOut("cfg_vehicle.yaml");                    //如果文件不存在会被创建
            YAML::Node wConfig = YAML::LoadFile("./cfg_vehicle.yaml"); //以node形式加载文件,如果是前面load过的config直接用的话是以当前所在的node开始追加写的方式,否则整体覆盖写
            wConfig["lib"] = "js";                              //不同的展现形式有对应写法
            fOut << wConfig;                                    //数据填充流
            fOut.close(); 

            return;
        }       

        //校验失败就用原本的初始化值
        bool CCfgVehicleCode::checkCfg()
        {
            bool ret = true;
            if(version.compare(VERSION) != 0)
            {
                cout<<"parse version is not request:"<<version<<";request is :"<<VERSION<<endl;
                ret = false;
            }
            if(md5Result.compare(MD5RESULT) != 0)
            {
                cout<<"parse md5Result is not request:"<<md5Result<<";request is :"<<MD5RESULT<<endl;
                ret = false;
            }

            if(ret == true)
            cout<<"checkCfg success"<<endl;
            return ret;
        }

        /*数据获取接口*/       
        void CCfgVehicleCode::getVehicleConfig(VehicleConfig & obj)
        {
            // obj = m_VehicleConfig;
            memcpy(&obj,&m_VehicleConfig,sizeof(VehicleConfig));
            return ;
        }

        uint32_t CCfgVehicleCode::getSteeringAngleMinDisLsitNum()
        {
            return SteeringAngleMinDisLsitNum;
        }
        
        uint32_t CCfgVehicleCode::getEPSSteeringAngleRatiosRows()
        {
            return EPSSteeringAngleRatiosRows;
        }

        void CCfgVehicleCode::getSteeringAngleMinDis(vector<vector<int16_t> > & vSAMinDis)
        {
            vSAMinDis.assign(SteeringAngleMinDis.begin(),SteeringAngleMinDis.end());
            
            std::cout <<"vSAMinDis:start:vSAMinDis.size()="<<vSAMinDis.size()<<std::endl;
            for (int i = 0; i < vSAMinDis.size(); i++) {       // 行数
            std::cout<<"vSAMinDis:i="<<i<<";vSAMinDis[i].size()="<<vSAMinDis[i].size()<<std::endl;
            for (int j = 0; j < vSAMinDis[i].size(); j++) {  // A[i].size() 第i行的列数                
                std::cout << vSAMinDis[i][j] << " ";
            }
            std::cout << std::endl;
            }

            return ;
        }

        void CCfgVehicleCode::getEPSSteeringAngleRatio( vector<vector<float> > & vSARatio)
        {
            vSARatio.assign(EPSSteeringAngleRatio.begin(),EPSSteeringAngleRatio.end());
            
            std::cout <<"vSARatio:start:vSARatio.size()="<<vSARatio.size()<<std::endl;
            for (int i = 0; i < vSARatio.size(); i++) {       // 行数
            std::cout<<"vSARatio:i="<<i<<";vSARatio[i].size()="<<vSARatio[i].size()<<std::endl;
            for (int j = 0; j < vSARatio[i].size(); j++) {  // A[i].size() 第i行的列数                
                std::cout << vSARatio[i][j] << " ";
            }
            std::cout << std::endl;
            }

            return ;            
        }






    } // namespace vehicle
} // namespace motovis
