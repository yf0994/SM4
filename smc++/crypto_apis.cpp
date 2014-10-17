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
        Block out;
        SM4::Apis::encrypt((unsigned char *)block.constData(),CRYPTO_BLOCK_SIZE,(unsigned char *)out.data());
        memcpy(block.data(), out.data(), CRYPTO_BLOCK_SIZE);
        return true;
    }
    
    bool Apis::decryptBlock(Block &block)
    {
        Block out;
        SM4::Apis::decrypt((unsigned char *)block.constData(),CRYPTO_BLOCK_SIZE,(unsigned char *)out.data());
        memcpy(block.data(), out.data(), CRYPTO_BLOCK_SIZE);
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

    string Apis::encryptBlocksTo(BlockList &blocks,char * buf)
    {
        BlockListConstIterator iter;
        string str;
        for(iter = blocks.cbegin(); iter != blocks.cend(); ++iter)
        {
            
            SM4::Apis::encrypt((unsigned char *)iter -> constData(),CRYPTO_BLOCK_SIZE,(unsigned char *)buf);
//            strcat(buf, out.data());
            printf("%s",buf);
            str += string(buf);
            buf += CRYPTO_BLOCK_SIZE;
        }
//        printf("%d\n",i);
        return str;
    }
    
    bool Apis::decryptBlocksTo(BlockList &blocks,char *buf)
    {
        BlockListConstIterator iter;
        for(iter = blocks.cbegin();iter != blocks.cend(); ++iter)
        {
            
            SM4::Apis::decrypt((unsigned char *)iter -> constData(),CRYPTO_BLOCK_SIZE,(unsigned char *)buf);
//            printf("%s",out.data());
            buf += CRYPTO_BLOCK_SIZE;
//            strcat(buf, out.data());
        }
        
        
        return true;
    }
}
