//
//  sm4_api.h
//  smc++
//
//  Created by yinfeng on 14-10-13.
//  Copyright (c) 2014年 singuloid. All rights reserved.
//

#ifndef __smc____sm4_api__
#define __smc____sm4_api__

//#include "block.h"
#define CRYPTO_BLOCK_SIZE 16

//using crypto::Block;


namespace SM4
{
    typedef struct UserKey
    {
        unsigned char data[CRYPTO_BLOCK_SIZE];
    }UserKey;
    
    
    class Apis
    {
    public:
        static bool initKey(UserKey *uk);
        static bool encrypt(unsigned char *in, int inSize,unsigned char *out);
        static bool decrypt(unsigned char *in, int inSize,unsigned char *out);
    };
    
}

#endif /* defined(__smc____sm4_api__) */
