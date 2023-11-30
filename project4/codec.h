//
// Created by bob on 11/5/19.
//
// Modification history:
// 22 july 2021
// - changed structure to include file stream
// - changed methods to directly read/write to stream
//

#ifndef _CODEC_H
#define _CODEC_H

#include <cstdint>

const unsigned int CODEC_BUF_SIZE = 16;

class Codec64 {
public:
    Codec64();
    ~Codec64() = default;

//    bool getEncodedChar(uint8_t &ch);
//    bool putEncodedChar(uint8_t ch);

    void put8(uint8_t n);

    void put16(uint16_t n);

    void put32(uint32_t n);

    void put64(uint64_t n);

    bool get8(uint8_t &n);

    bool get16(uint16_t &n);

    bool get32(uint32_t &n);

    bool get64(uint64_t &n);

    void beginEncode(char *);
    void beginDecode(char *);
    void endEncode();
    void endDecode();

private:
    uint8_t
        inBuffer[CODEC_BUF_SIZE]{},
        outBuffer[CODEC_BUF_SIZE]{};
    uint32_t
        inHead,inTail,inCount,
        outHead,outTail,outCount;
    bool
        isEncoding,
        isDecoding;
    fstream
        file;
};

#endif //_CODEC_H
