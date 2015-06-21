//
// Created by megaxela on 18.03.15.
//

#include "Compression.h"

char* Compression::zlibDeflate(char const *data, int len, int *resultLen, bool deleteInput)
{
    char* deflated = new char[ len ];
    // Настраиваем поток.
    z_stream deflateStream;
    deflateStream.zalloc = Z_NULL;
    deflateStream.zfree  = Z_NULL;
    deflateStream.opaque = Z_NULL;

    // Настраиваем входные и выходные данные
    deflateStream.avail_in = ( unsigned int ) len;
    deflateStream.next_in = (Bytef *) data;
    deflateStream.avail_out = ( unsigned int ) len;
    deflateStream.next_out = (Bytef *) deflated;

    // Производим сжатие
    deflateInit( &deflateStream, Z_BEST_COMPRESSION );
    deflate( &deflateStream, Z_FINISH );
    deflateEnd( &deflateStream );

    if ( deleteInput )
        delete []data;

    if ( resultLen )
        ( *resultLen ) = (int) deflateStream.total_out;

    return deflated;
}

char* Compression::zlibInflate(char const *data, int len, int *resultLen, bool deleteInput)
{
    char* inflated = new char [ MAXIMUM_SIZE ];
    // Настраиваем поток
    z_stream inflateStream;
    inflateStream.zalloc = Z_NULL;
    inflateStream.zfree  = Z_NULL;
    inflateStream.opaque = Z_NULL;

    // Настраиваем входные и выходные данные
    inflateStream.avail_in = ( unsigned int ) len;
    inflateStream.next_in  = ( Bytef * ) data;
    inflateStream.avail_out = ( unsigned int ) MAXIMUM_SIZE;
    inflateStream.next_out = ( Bytef * ) inflated;

    // Производим разжатие
    inflateInit( &inflateStream );
    inflate( &inflateStream, Z_NO_FLUSH );
    inflateEnd( &inflateStream );

    if ( deleteInput )
        delete []data;

    if ( resultLen )
        ( *resultLen ) = (int) inflateStream.total_out;

    return inflated;
}

static const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

static inline bool is_base64(unsigned char c)
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}
char* Compression::base64Encode(char const *data, int len, int *resultLen, bool deleteInput)
{
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (len--)
    {
        char_array_3[i++] = (unsigned char) *(data++);
        if (i == 3)
        {
            char_array_4[0] = (unsigned char) ((char_array_3[0] & 0xfc) >> 2);
            char_array_4[1] = (unsigned char) (((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4));
            char_array_4[2] = (unsigned char) (((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6));
            char_array_4[3] = (unsigned char) (char_array_3[2] & 0x3f);

            for(i = 0; (i <4) ; i++)
                ret += data[char_array_4[i]];
            i = 0;
        }
    }

    if (i)
    {
        for(j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (unsigned char) ((char_array_3[0] & 0xfc) >> 2);
        char_array_4[1] = (unsigned char) (((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4));
        char_array_4[2] = (unsigned char) (((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6));
        char_array_4[3] = (unsigned char) (char_array_3[2] & 0x3f);

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while((i++ < 3))
            ret += '=';

    }

    if ( resultLen )
        (*resultLen) = (int) ret.length();

    if ( deleteInput )
        delete[] data;

    char* results = new char[ ret.length() ];
    memcpy(results, ret.c_str(), ret.length());

    return results;
}

char* Compression::base64Decode(char const *data, int len, int *resultLen, bool deleteInput)
{

    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (len-- && ( data[in_] != '=') && is_base64((unsigned char) data[in_]))
    {
        char_array_4[i++] = (unsigned char) data[in_]; in_++;
        if (i ==4)
        {
            for (i = 0; i <4; i++)
                char_array_4[i] = (unsigned char) base64_chars.find(char_array_4[i]);

            char_array_3[0] = (unsigned char) ((char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4));
            char_array_3[1] = (unsigned char) (((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2));
            char_array_3[2] = (unsigned char) (((char_array_4[2] & 0x3) << 6) + char_array_4[3]);

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j <4; j++)
            char_array_4[j] = 0;

        for (j = 0; j <4; j++)
            char_array_4[j] = (unsigned char) base64_chars.find(char_array_4[j]);

        char_array_3[0] = (unsigned char) ((char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4));
        char_array_3[1] = (unsigned char) (((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2));
        char_array_3[2] = (unsigned char) (((char_array_4[2] & 0x3) << 6) + char_array_4[3]);

        for (j = 0; (j < i - 1); j++)
            ret += char_array_3[j];
    }

    if ( resultLen )
        (*resultLen) = (int) ret.length();

    if ( deleteInput )
        delete[] data;

    char* results = new char[ ret.length() ];
    memcpy(results, ret.c_str(), ret.length());

    return results;
}