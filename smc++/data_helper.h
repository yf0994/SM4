//
//  data_helper.h
//  smc++
//
//  Created by yinfeng on 14/10/17.
//  Copyright (c) 2014年 singuloid. All rights reserved.
//

#ifndef __smc____data_helper__
#define __smc____data_helper__

#include <string>

using std::string;
namespace io
{
    class DataHelper
    {
    public:
        static string encryptData(const char *buf,unsigned len);
        static string decryptData(const char *buf,unsigned len);
        
        static string encryptDataNative(const char *buf,int len);
        static string decrpytDataNative(const char *buf,int len);
    };
}

#endif /* defined(__smc____data_helper__) */
