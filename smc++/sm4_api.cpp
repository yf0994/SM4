//
//  sm4_api.cpp
//  smc++
//
//  Created by yinfeng on 14-10-13.
//  Copyright (c) 2014年 singuloid. All rights reserved.
//

#include "sm4.h"
#include "sm4_api.h"
#include <stdio.h>
namespace SM4
{
    bool Apis::initKey(UserKey *uk)
    {
        int i;
        for(i = 0; i < CRYPTO_BLOCK_SIZE; i++)
        {
            uk -> data[i] = i + 32;
        }
        return true;
    }
    
    bool Apis::encrypt(unsigned char *in,int inSize,unsigned char *out)
    {
        UserKey uk;
        initKey(&uk);
        sm4_context ctx;
        sm4_setkey_enc(&ctx, (unsigned char *)uk.data);
        sm4_crypt_ecb(&ctx, SM4_ENCRYPT, inSize, in, out);
        return true;
    }
    
    bool Apis::decrypt(unsigned char *in,int inSize,unsigned char *out)
    {
        UserKey uk;
        initKey(&uk);
        sm4_context ctx;
        sm4_setkey_dec(&ctx, (unsigned char *)uk.data);
        sm4_crypt_ecb(&ctx, SM4_DECRYPT, inSize, in, out);
        return true;
    }
}
