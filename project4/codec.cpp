//
// Created by bob on 11/5/19.
//
// Modification history:
// 22 july 2021
// - changed structure to include file stream
// - changed methods to directly read/write to stream
//

#include "codec.h"

static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "0123456789+/";

Codec64::Codec64() {

    isEncoding = isDecoding = false;
    inHead = inTail = inCount = outHead = outTail = outCount = 0;
}
/*
bool Codec64::getEncodedChar(uint8_t &ch) {

    if (outCount == 0)
        return false;

    ch = outBuffer[outHead];
    outHead = ++outHead % CODEC_BUF_SIZE;
    outCount--;

    return true;
}

bool Codec64::putEncodedChar(uint8_t ch) {
    uint8_t
        c[4];
    uint32_t
        tmp,
        i;

    if (!isDecoding)
        return false;

    inBuffer[inTail] = ch;
    inTail = ++inTail % CODEC_BUF_SIZE;
    inCount++;

    if (inCount == 4) {
        for (i=0;i<4;i++) {
            c[i] = inBuffer[inHead];
            inHead = ++inHead % CODEC_BUF_SIZE;
            inCount--;
        }
        for (i=0;c[0]!=charset[i];i++);
        tmp = i << 18u;
        for (i=0;c[1]!=charset[i];i++);
        tmp += i << 12u;

        outBuffer[outTail] = (tmp >> 16u) & 0xffu;
        outTail = ++outTail % CODEC_BUF_SIZE;
        outCount++;

        if (c[2] != '=') {
            for (i=0;c[2]!=charset[i];i++);
            tmp += i << 6u;

            outBuffer[outTail] = (tmp >> 8u) & 0xffu;
            outTail = ++outTail % CODEC_BUF_SIZE;
            outCount++;

            if (c[3] != '=') {
                for (i=0;c[3]!=charset[i];i++);
                tmp += i;

                outBuffer[outTail] = tmp & 0xffu;
                outTail = ++outTail % CODEC_BUF_SIZE;
                outCount++;

            }
        }
    }

    return true;
}
*/
void Codec64::put8(uint8_t n) {
    uint32_t
        i,
        tmp;
    uint8_t
        ch;

    if (isEncoding) {
        inBuffer[inTail] = n;
        inTail = ++inTail % CODEC_BUF_SIZE;
        inCount++;

        if (inCount == 3) {
            tmp = 0;
            for (i=0;i<3;i++) {
                ch = inBuffer[inHead];
                inHead = ++inHead % CODEC_BUF_SIZE;
                inCount--;
                tmp = (tmp << 8u) + ch;
            }
            for (i=0;i<4;i++) {
                ch = charset[(tmp >> (18u-6u*i)) & 0x3fu];
                outBuffer[outTail] = ch;
                outTail = ++outTail % CODEC_BUF_SIZE;
                outCount++;
            }
        }
    }
}

void Codec64::put16(uint16_t n) {

    put8((unsigned char)(n & 0xffu));
    put8((unsigned char)(n >> 8u));
}

void Codec64::put32(uint32_t n) {

    put16((uint16_t)(n & 0xffffu));
    put16((uint16_t)(n >> 16u));
}

void Codec64::put64(uint64_t n) {

    put32((uint32_t)(n & 0xffffffffu));
    put32((uint32_t)(n >> 32u));
}

bool Codec64::get8(uint8_t &n) {

    if (outCount == 0)
        return false;

    n = outBuffer[outHead];
    outHead = ++outHead % CODEC_BUF_SIZE;
    outCount--;

    return true;
}

bool Codec64::get16(uint16_t &n) {
    uint8_t
        high,low;

    if (outCount < 2)
        return false;

    get8(low);
    get8(high);

    n = low + ((uint16_t)high << 8u);

    return true;
}

bool Codec64::get32(uint32_t &n) {
    uint16_t
        high,low;

    if (outCount < 4)
        return false;

    get16(low);
    get16(high);

    n = low + ((uint32_t)high << 16u);

    return true;
}

bool Codec64::get64(uint64_t &n) {
    uint32_t
        high,low;

    if (outCount < 8)
        return false;

    get32(low);
    get32(high);

    n = low + ((uint64_t)high << 32u);

    return true;
}

void Codec64::beginEncode() {
    inCount = inHead = inTail = outCount = outHead = outTail = 0;
    isEncoding = true;
    isDecoding = false;
}

void Codec64::beginDecode() {
    inCount = inHead = inTail = outCount = outHead = outTail = 0;
    isEncoding = false;
    isDecoding = true;
}

void Codec64::endEncode() {

    if (inCount == 2) {
        put8(0);
        outTail = (outTail + CODEC_BUF_SIZE - 1) % CODEC_BUF_SIZE;
        outBuffer[outTail] = '=';
    }

    if (inCount == 1) {
        put16(0);
        outTail = (outTail + CODEC_BUF_SIZE - 2) % CODEC_BUF_SIZE;
        outBuffer[outTail] = '=';
        outBuffer[(outTail+1)%CODEC_BUF_SIZE] = '=';
    }

    isEncoding = false;
}

void Codec64::endDecode() {

    isDecoding = false;
}
