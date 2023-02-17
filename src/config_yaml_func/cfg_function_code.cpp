#include "cfg_function_code.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include<iostream>

//注意：此文件中回车换行必须是LF!!!

namespace yamlFunc
{
    namespace yamlTest
    {

        bool CCfgManagerFunCode::Init()
        {
            std::cout << "CCfgManagerFunCode  Init start 2211301445"<<"\n";
            // memset(&m_FunctionConfig, 0, sizeof(FunctionConfig));

            m_FunctionConfig.name.empty();
            m_FunctionConfig.sex.empty();
            m_FunctionConfig.age = 0;
            m_FunctionConfig.mySkills.cPlsuPlus = false;
            m_FunctionConfig.mySkills.java = false;
            m_FunctionConfig.mySkills.android = 0;
            m_FunctionConfig.mySkills.python = 0;

            return YamlInit();
        }

        bool CCfgManagerFunCode::YamlInit()
        {
            bool res = false;
            std::cout << "CCfgManagerFunCode YamlInit start !!!!!"<<"\n";

            try
            {
                const char *p = getenv(CFG_FUNCTION_CODE_FILE);
                std::string mvYamlPath = "";
                std::cout << "getenv MV_STATE_YAML start !"<<"\n";
                if (p == NULL)
                {
                    std::cout << "getenv MV_STATE_YAML is NULL!"<<"\n";
                }
                else
                {
                    mvYamlPath = p;
                    std::cout << "getenv MV_STATE_YAML successful !! mvYamlPath = " << mvYamlPath<<"\n";
                }

                if (IsFileExistsAccess(mvYamlPath))
                {
                    YAML::Node config;
                    // 当文件不存在或yaml格式出错时，抛异常
                    try
                    {
                        config = YAML::LoadFile(mvYamlPath);
                        res = PasingYamlNode(config);
                    }
                    catch (const YAML::Exception &e)
                    {
                        std::cout << "YAML::Exception :" << e.what()<<"\n";
                    }
                }
                else
                {
                    std::cout << "mvYamlPath = " << mvYamlPath << " is not exit !!"<<"\n";
                    //当环境变量没有设置时也可以通过设置configPath来配置
                    mvYamlPath = configPath;
                    if (IsFileExistsAccess(mvYamlPath))
                    {
                        YAML::Node config;
                        // 当文件不存在或yaml格式出错时，抛异常
                        try
                        {
                            config = YAML::LoadFile(mvYamlPath);
                            res = PasingYamlNode(config);
                        }
                        catch (const YAML::Exception &e)
                        {
                            std::cout << "YAML::Exception :" << e.what()<<"\n";
                        }
                    }
                    else
                    {
                        std::cout << "mvYamlPath = configPath =  " << mvYamlPath << " is not exit !!"<<"\n";
                    }
                }
            }
            catch (...)
            {
                std::cout << "please export MV_STATE_YAML path !!"<<"\n";
            }
            return res;
        }

        bool CCfgManagerFunCode::PasingYamlNode(const YAML::Node &tNode)
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
                    //            switch (value.Type())
                    //            {
                    //            case YAML::NodeType::Scalar:
                    //                MV_LOGINFO << "key: scalar //"<< key.c_str();
                    //                break;
                    //            case YAML::NodeType::Sequence:
                    //                MV_LOGINFO << "key: Sequence //"<< key.c_str();
                    //                break;
                    //            case YAML::NodeType::Map:
                    //                MV_LOGINFO << "key: Map //"<< key.c_str();
                    //                break;
                    //            case YAML::NodeType::Null:
                    //                MV_LOGINFO << "key: Null //"<< key.c_str();
                    //                break;
                    //            case YAML::NodeType::Undefined:
                    //                MV_LOGINFO << "key: Undefined //"<< key.c_str();
                    //                break;
                    //            }
                }
            }
            catch (const YAML::Exception &e)
            {
                std::cout<< "YAML::Exception" << e.what()<<"\n";
                return false;
            }

            return true;
        }

        void CCfgManagerFunCode::GetFunctionCode(FunctionConfig &obj)
        {
            obj = m_FunctionConfig;
            return;
        }

        void CCfgManagerFunCode::showFunctionConfig()
        {
            std::cout<<"\n"<<"showFunctionConfig"<<std::endl;
            std::cout<<"name:"<<m_FunctionConfig.name<<std::endl;
            std::cout<<"sex:"<<m_FunctionConfig.sex<<std::endl;
            std::cout<<"age:"<<m_FunctionConfig.age<<std::endl;
            std::cout<<"mySkills.cPlsuPlus:"<<m_FunctionConfig.mySkills.cPlsuPlus<<std::endl;
            std::cout<<"mySkills.java:"<<m_FunctionConfig.mySkills.java<<std::endl;
            std::cout<<"mySkills.android:"<<m_FunctionConfig.mySkills.android<<std::endl;
            std::cout<<"mySkills.python:"<<m_FunctionConfig.mySkills.python<<std::endl;
            std::cout<<"configPath:"<<configPath<<std::endl;
            std::cout<<"\n";

            return;
        }


        bool CCfgManagerFunCode::IsFileExistsAccess(std::string path)
        {
            return ((access(path.c_str(), F_OK ) != -1 ));
        }

        void CCfgManagerFunCode::PasNode(std::string key, std::string val)
        {
            if(key == "name")
            {
                m_FunctionConfig.name = val;
            }
            else if(key == "sex")
            {
                m_FunctionConfig.sex = val;
            }
            else if(key == "age")
            {
                m_FunctionConfig.age = StringToNum<int>(val);
            }
            else if(key == "cPlusPlus")
            {
                m_FunctionConfig.mySkills.cPlsuPlus = StringToNum<int>(val)==1 ? true : false;
            }
            else if(key == "java")
            {
                m_FunctionConfig.mySkills.java = StringToNum<int>(val)==1 ? true : false;
            }
            else if(key == "android")
            {
                m_FunctionConfig.mySkills.android = StringToNum<int>(val);
            }
            else if(key == "python")
            {
                m_FunctionConfig.mySkills.python = StringToNum<int>(val);
            }           
        }

        template <class Type>
        Type CCfgManagerFunCode::StringToNum(const std::string &str)
        {
            std::istringstream iss(str);
            Type num;
            iss >> num;
            return num;
        }

    } // namespace state
} // namespace motovis
