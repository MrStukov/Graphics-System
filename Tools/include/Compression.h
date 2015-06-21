//
// Created by megaxela on 18.03.15.
//

#ifndef _SERVER_COMPRESSION_H_
#define _SERVER_COMPRESSION_H_

#include "zlib.h"
#include <string>
#include <string.h>

#define MAXIMUM_SIZE 40960

/*
* 1. Версия от 18.03.05
*     Написал сжатие и разжатие по zlib
*     все работает багов не обнаружено.
*/

//TODO: Добавить сжатие в base64, ибо отправлять не ASCII байты не айс.
namespace Compression
{
    char* zlibDeflate (char const* data, int len, int *resultLen, bool deleteInput = false);
    char* zlibInflate (char const* data, int len, int *resultLen, bool deleteInput = false);
    char* base64Encode(char const* data, int len, int *resultLen, bool deleteInput = false);
    char* base64Decode(char const* data, int len, int *resultLen, bool deleteInput = false);
};


#endif //_SERVER_COMPRESSION_H_
