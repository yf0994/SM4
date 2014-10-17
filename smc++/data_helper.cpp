//
//  data_helper.cpp
//  smc++
//
//  Created by yinfeng on 14/10/17.
//  Copyright (c) 2014年 singuloid. All rights reserved.
//

#include "data_helper.h"
#define HEAD_MAGIC_V1 0x0ea8b311
#include <string.h>
#include "crypto_apis.h"
namespace io
{
    typedef struct  DataHead
    {
        uint32_t magic;
        uint32_t psize;
        uint32_t esize;
    }DataHead;
    
    static void initDataHead(DataHead *head)
    {
        head -> magic = HEAD_MAGIC_V1;
        head -> psize = 0;
        head -> esize = 0;
    }
    
    static DataHead readDataHead(const char *buf,int len)
    {
        DataHead head;
        int s = sizeof(DataHead);
        memset((void *)&head,0, s);
        if(len < s)
        {
            return head;
        }
        
        memcpy((void *)&head, buf, s);
        return head;
    }
    
    static bool isEncrypted(DataHead *head)
    {
        return head == NULL ? false : head -> magic == HEAD_MAGIC_V1;
    }
    
    string DataHelper::encryptData(const char *buf, unsigned int len)
    {
        crypto::BlockList blockList = crypto::Utils::toBlocks(buf, len);
//        int total = (int)blockList.size() * CRYPTO_BLOCK_SIZE;
//        printf("!!!!!%d\n",total);
        char *tmpBuf = (char *)calloc(1, len + 1);
        crypto::Apis::encryptBlocksTo(blockList, tmpBuf);
        string ret = string(tmpBuf);
        free(tmpBuf);
        return ret;
    }
    
    string DataHelper::decryptData(const char *buf, unsigned int len)
    {
        
        crypto::BlockList blockList = crypto::Utils::toBlocks(buf, len);
//        printf("%d %d\n",blockList.size(),len);
//        int total = (int)blockList.size() * CRYPTO_BLOCK_SIZE;
//        printf("~~~~%d\n",total);
        char *tmpBuf = (char *) calloc(1, len + 1);
        crypto::Apis::decryptBlocksTo(blockList, tmpBuf);
        printf("%s\n",tmpBuf);
        string ret = string(tmpBuf);
        free(tmpBuf);
        return ret;
    }
    
    
    
    
    
    
    
    
    
    
    
    
}