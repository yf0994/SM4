//
//  crypto_apis.cpp
//  smc++
//
//  Created by yinfeng on 14-10-13.
//  Copyright (c) 2014年 singuloid. All rights reserved.
//
#include "crypto_apis.h"

#include "sm4_api.h"
#include <stdio.h>
#include <string.h>

using namespace SM4;
namespace crypto
{
    bool Apis::encryptBlock(Block &block)
    {
        unsigned char buf[CRYPTO_BLOCK_SIZE];
        memcpy(buf, block.constData(), CRYPTO_BLOCK_SIZE);
        SM4::Apis::encrypt(buf,CRYPTO_BLOCK_SIZE,buf);
        printf("++++++++[%s]\n",buf);
        memcpy(block.data(), buf, CRYPTO_BLOCK_SIZE);
        return true;
    }
    
    bool Apis::decryptBlock(Block &block)
    {
        unsigned char buf[CRYPTO_BLOCK_SIZE];
        memcpy(buf, block.constData(), CRYPTO_BLOCK_SIZE);
        printf("--------[%s]\n",buf);
        SM4::Apis::decrypt(buf,CRYPTO_BLOCK_SIZE,buf);
        memcpy(block.data(), buf, CRYPTO_BLOCK_SIZE);
        
        return true;
    }
    
    
    
    
    bool Apis::encryptBlocks(BlockList &blocks)
    {
        BlockListIterator iter;
        for(iter = blocks.begin(); iter != blocks.end(); ++iter)
        {
            encryptBlock(*iter);
        }
        return true;
    }
    
    bool Apis::decrpytBlocks(BlockList &blocks)
    {
        BlockListIterator iter;
        for(iter = blocks.begin(); iter != blocks.end(); ++iter)
        {
            decryptBlock(*iter);
        }
        return true;
    }

    bool Apis::encryptBlocksTo(BlockList &blocks,char * buf)
    {
        BlockListConstIterator iter;
        string str;
        for(iter = blocks.cbegin(); iter != blocks.cend(); ++iter)
        {
            unsigned char tmpBuf[CRYPTO_BLOCK_SIZE];
            memcpy(tmpBuf, iter -> constData(), CRYPTO_BLOCK_SIZE);
            SM4::Apis::encrypt(tmpBuf,CRYPTO_BLOCK_SIZE,tmpBuf);
            printf("++++++++++[%s]\n",tmpBuf);
            memcpy(buf, tmpBuf, CRYPTO_BLOCK_SIZE);
            buf += CRYPTO_BLOCK_SIZE;
        }
        return true;
    }
    
    bool Apis::decryptBlocksTo(BlockList &blocks,char *buf)
    {
        BlockListConstIterator iter;
        for(iter = blocks.cbegin();iter != blocks.cend(); ++iter)
        {
            printf("-----------[%s]\n",iter -> constData());
            unsigned char tmpBuf[CRYPTO_BLOCK_SIZE];
            memcpy(tmpBuf, iter -> constData(), CRYPTO_BLOCK_SIZE);
            SM4::Apis::decrypt(tmpBuf,CRYPTO_BLOCK_SIZE,tmpBuf);
//            printf("!!!!!!!!!!!![%s]\n",tmpBuf);
            memcpy(buf, tmpBuf, CRYPTO_BLOCK_SIZE);
            buf += CRYPTO_BLOCK_SIZE;
        }
        return true;
    }
}
