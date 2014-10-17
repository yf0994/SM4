//
//  crypto_apis.h
//  smc++
//
//  Created by yinfeng on 14-10-13.
//  Copyright (c) 2014年 singuloid. All rights reserved.
//

#ifndef __smc____crypto_apis__
#define __smc____crypto_apis__
#include "block.h"
using std::string;
#include <string>
namespace crypto
{
    class Apis
    {
    public:
        static bool encryptFile(const char *inpath,const char *outpath);
        static bool decryptFile(const char *inpath,const char * outpath);
        
        
        static bool encryptBlock(Block &block);
        static bool decryptBlock(Block &block);
        
        static bool encryptBlocks(BlockList &blocks);
        static bool decrpytBlocks(BlockList &blocks);
        
        static bool encryptBlocksTo(BlockList &blocks,char *buf);
        static bool decryptBlocksTo(BlockList &blocks,char *buf);
        
        
    };
}

#endif /* defined(__smc____crypto_apis__) */
