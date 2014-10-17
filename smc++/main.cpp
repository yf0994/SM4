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
//
    const  char * str = "关关雎鸠，在河之洲。窈窕淑女，君子好逑。参差荇菜，左右流之。窈窕淑女，寤寐求之。求之不得，寤寐思服。悠哉悠哉，辗转反侧。参差荇菜，左右采之。窈窕淑女，琴瑟友之。参差荇菜，左右芼之。窈窕淑女，钟鼓乐之。";
    int len = (int)strlen(str);
    printf("%d\n",len);
//    unsigned char input[len];
//    memcpy(input, str, len);
//    unsigned char output[len];
//    SM4::Apis::encrypt(input, len, output);
//    printf("%s %d\n",output,sizeof(output));
//    SM4::Apis::decrypt(output, len, output);
//    printf("%s\n",output);
    crypto::BlockList blockList = crypto::Utils::toBlocks(str, len);
    char encryptData[len];
    char decryptData[len];
    memset(encryptData, 0, len);
    memset(decryptData, 0, len);
    crypto::Apis::encryptBlocks(blockList);
//    string ret = crypto::Apis::encryptBlocksTo(blockList, encryptData);
    crypto::BlockListIterator iter;
    string ret ;
            for(iter = blockList.begin(); iter != blockList.end(); ++iter)
            {
//                printf("%s",iter->data());
                ret += string(iter -> data());
            }
    printf("%s\n",ret.c_str());
    printf("\n---------------\n");
//    printf("%s\n",ret.c_str());
//     printf("\n---------------%lu\n",ret.size());
//    printf("----%s\n",encryptData);
//        crypto::BlockList blockList1 = crypto::Utils::toBlocks(ret.c_str(), len);
//        crypto::Apis::decryptBlocksTo(blockList1, decryptData);
//    printf("%s\n",decryptData);

    crypto::Apis::decrpytBlocks(blockList);
    for(iter = blockList.begin(); iter != blockList.end(); ++iter)
    {
        printf("%s",iter->data());
    }
//        crypto::BlockListIterator iter;
    
    printf("\n");
    printf("%d\n",strlen(encryptData));
    return 0;
}
