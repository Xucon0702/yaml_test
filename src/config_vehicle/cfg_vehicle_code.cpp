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
            int subscript = 0;
            string memberName = "EPSSteeringAngleRatio_";
            vector<float> ext;
            ext.clear();
            ext.resize(0);

            std::cout<<"PasingYamlArray start:"<<"EPSSteeringAngleRatiosRows="<<EPSSteeringAngleRatiosRows<<std::endl;
            for(int i= 0;i<EPSSteeringAngleRatiosRows;i++)
            {
                memberName = "EPSSteeringAngleRatio_";
                memberName += std::to_string(i);
                std::cout<<"memberName:"<<memberName<<std::endl;   
                ext= tNode["EPSSteeringAngleRatios"][memberName].as<vector<float>>();
                if(EPSSteeringAngleRatiosRows != 0)
                {
                    // assert((int)ext.size() == EPSSteeringAngleRatiosClos);
                } 
                EPSSteeringAngleRatio.push_back(ext);   

                std::cout <<"ext:start:ext.size()="<<ext.size()<<std::endl;
            
                for (int i = 0; i < ext.size(); i++) { 
                    std::cout << ext[i] << " ";
                }            
                std::cout <<"\next:end"<< std::endl;
            }

            // //解析EPSSteeringAngleRatio
            // // vector<vector<float>> ext= tNode["EPSSteeringAngleRatios"].as<vector<vector<float>>>();
            // vector<float> ext= tNode["EPSSteeringAngleRatios"]["EPSSteeringAngleRatio[0]"].as<vector<float>>();
            // std::cout<<"here 111"<<std::endl;
            
            // if(EPSSteeringAngleRatiosRows != 0)
            // {
            //     assert((int)ext.size() == EPSSteeringAngleRatiosClos);
            // }
            // std::cout<<"here 222"<<std::endl;

            // // EPSSteeringAngleRatio = ext;
            // EPSSteeringAngleRatio.push_back(ext);
            // std::cout<<"here 333"<<std::endl;

            // std::cout <<"ext:start:ext.size()="<<ext.size()<<std::endl;
            
            // for (int i = 0; i < ext.size(); i++) { 
            //     std::cout << ext[i] << " ";
            // }            
            // std::cout <<"\next:end"<< std::endl;

            for (int i = 0; i < EPSSteeringAngleRatio.size(); i++) {       // 行数
            std::cout<<"EPSSteeringAngleRatio:i="<<i<<";EPSSteeringAngleRatio[i].size()="<<EPSSteeringAngleRatio[i].size()<<std::endl;
            for (int j = 0; j < EPSSteeringAngleRatio[i].size(); j++) {  // A[i].size() 第i行的列数
                std::cout << EPSSteeringAngleRatio[i][j] << " ";
            }
            std::cout << std::endl;
            }

            //解析EPSSteeringAngleRatio
        }


        void CCfgVehicleCode::GetVehicleCode(VehicleConfig &obj)
        {
            obj = m_VehicleConfig;
            return;
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
            else if(key == "EPSSteeringAngleRatiosRows")
            {
                EPSSteeringAngleRatiosRows = StringToNum<uint32_t>(val);
            } 
            else if(key == "EPSSteeringAngleRatiosClos")
            {
                EPSSteeringAngleRatiosClos = StringToNum<uint32_t>(val);
            }
            // else if(key == "EPSSteeringAngleRatio[0]")
            // {
            //     EPSSteeringAngleRatiosClos = StringToNum<uint32_t>(val);
            //     EPSSteeringAngleRatio.
            // }                 
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

        void CCfgVehicleCode::checkVehicleCfg()
        {

            return ;
        }



    } // namespace vehicle
} // namespace motovis