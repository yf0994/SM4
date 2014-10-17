/*
 * SM4/SMS4 algorithm test programme
 * 2012-4-21
 */

#include <string.h>
#include <stdio.h>
#include "sm4.h"
#include "sm4_api.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "block.h"
#include <stdlib.h>
#include "data_helper.h"
#include "crypto_apis.h"
#define LENGHT 1024;
int main()
{
//    unsigned char key[16] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10};
//    unsigned char input[16] = "关关雎";
//    unsigned char output[16];
//    SM4::Apis::encrypt(input, 16, output);
//    SM4::Apis::decrypt(output, 16, output);
//    printf("%s\n",output);
//    sm4_context ctx;
////    unsigned long i;
//    
//    //encrypt standard testing vector
//    sm4_setkey_enc(&ctx,key);
//    sm4_crypt_ecb(&ctx,1,16,input,output);
////    for(i=0;i<16;i++)
////        printf("%02x ", output[i]);
//    printf("[%s]",output);
//    printf("\n");
//    
//    //decrypt testing
//    sm4_setkey_dec(&ctx,key);
//    sm4_crypt_ecb(&ctx,0,16,output,output);
//    printf("%s\n",output);
////    for(i=0;i<16;i++)
////        printf("%02x ", output[i]);
//    printf("\n");
//
    const  char * str = "关关雎鸠，在河之洲。窈窕淑女，君子好逑。参差荇菜，左右流之。窈窕淑女，寤寐求之。求之不得，寤寐思服。悠哉悠哉，辗转反侧。参差荇菜，左右采之。窈窕淑女，琴瑟友之。参差荇菜，左右芼之。窈窕淑女，钟鼓乐之。";
    int len = (int)strlen(str);
    printf("%d\n",len);
    crypto::BlockList blockList = crypto::Utils::toBlocks(str, len);
    crypto::BlockList blockList1 = crypto::Utils::toBlocks(str, len);
    crypto::BlockListIterator iter;
    char encryptData[len];
    char decryptData[len];
    memset(encryptData, 0, len);
    memset(decryptData, 0, len);
    string ret;
    crypto::Apis::encryptBlocks(blockList);
    
    crypto::Apis::encryptBlocksTo(blockList1,encryptData);
    printf("++++++[%s]\n",encryptData);
    printf("========================\n");
    
    crypto::BlockList blockList2 = crypto::Utils::toBlocks(encryptData, len);
    for(iter = blockList2.begin();iter != blockList2.end();++iter)
    {
        ret += string(iter -> constData());
    }
    int flag = strcmp(ret.c_str(), encryptData);
    printf("%d\n",flag);
    crypto::Apis::decryptBlocksTo(blockList2, decryptData);
    printf("222222222222[%s]\n",decryptData);
    crypto::Apis::decrpytBlocks(blockList);
    for(iter = blockList.begin();iter != blockList.end(); ++iter)
    {
        printf("%s",iter ->constData());
    }
    printf("\n");
    return 0;
}
