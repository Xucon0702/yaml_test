#ifndef CFG_MANAGER_FUN_H
#define CFG_MANAGER_FUN_H

//注意：此文件中回车换行必须是LF!!!

#include<cstring>
#include <stddef.h>

#include "yaml.h"

namespace yamlFunc
{
    namespace yamlTest
    {

#define CFG_FUNCTION_CODE_FILE "MV_STATE_YAML" //从环境变量获取配置文件路径

        typedef struct _Skills
        {
           bool     cPlsuPlus;//是否会
           bool     java;
           uint32_t android;  //score
           uint32_t python;
        }skills;        

        typedef struct _FunctionConfig
        {
            std::string  name;
            std::string  sex;
            uint32_t age;
            skills   mySkills;         
        }FunctionConfig;

        class CCfgManagerFunCode
        {
        public:
            bool Init();
            void GetFunctionCode(FunctionConfig &obj);
            void showFunctionConfig();            
        
        public:
            std::string configPath;

        private:
            bool YamlInit();
            bool IsFileExistsAccess(std::string path = "");
            bool PasingYamlNode(const YAML::Node &tNode);
            void PasNode(std::string key, std::string val);
            template <class Type>
            Type StringToNum(const std::string &str);
            FunctionConfig m_FunctionConfig;
        };

    } // namespace yamlTest
} // namespace yamlFunc
#endif // CFG_MANAGER_H
