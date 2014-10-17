//
//  block.h
//  smc++
//
//  Created by yinfeng on 14-10-13.
//  Copyright (c) 2014年 singuloid. All rights reserved.
//

#ifndef smc___block_h
#define smc___block_h
#include <string.h>
#include <list>
#include <unistd.h>
#include <stdlib.h>
using std::list;

#define CRYPTO_BLOCK_SIZE 16

namespace crypto
{
    
    class Block
    {
    public:
        Block()
        {
            _data = (char *)calloc(1, CRYPTO_BLOCK_SIZE + 1);
        }
        
        Block(const char *buf, int copySize)
        {
            _data = (char *)calloc(1, CRYPTO_BLOCK_SIZE + 1);
            memcpy(_data, buf, copySize);
        }
        
        Block(Block const &block)
        {
            _data = (char *)calloc(1, CRYPTO_BLOCK_SIZE + 1);
            memcpy(_data, block.constData(), CRYPTO_BLOCK_SIZE);
        }
        
        ~Block(){ clear(); }
        
        const char *constData() const{ return (const char *)_data; }
        char *data(){ return _data; }
        
        void clear()
        {
            if (_data != NULL)
                free(_data);
            _data = NULL;
        }
        
        Block & operator=(Block const &rh)
        {
            memset(_data, 0, CRYPTO_BLOCK_SIZE);
            memcpy(_data, rh.constData(), CRYPTO_BLOCK_SIZE);
            return *this;
        }
        
    private:
        char *_data;
    };
    
    typedef list<Block> BlockList;
    typedef list<Block>::iterator BlockListIterator;
    typedef list<Block>::const_iterator BlockListConstIterator;
    
    class Utils
    {
    public:
        static BlockList toBlocks(const char *buf, int size)
        {
            int count = size / CRYPTO_BLOCK_SIZE;
            int rest = size % CRYPTO_BLOCK_SIZE;
            BlockList blocks;
            
            for (int i = 0; i < count; ++i)
            {
                blocks.push_back(Block(buf, CRYPTO_BLOCK_SIZE));
                buf += CRYPTO_BLOCK_SIZE;
            }
            if (rest > 0)
                blocks.push_back(Block(buf, CRYPTO_BLOCK_SIZE));
            
            return blocks;
        }
        
        static BlockList toBlocks(const char *buf)
        {
            return toBlocks(buf, (int)strlen(buf));
        }
    };
    
}

#endif
