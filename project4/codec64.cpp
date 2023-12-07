//
// Created by bob on 7/30/21.
//

#include "codec64.h"

static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "0123456789+/";

Codec64::Codec64() {

    isEncoding = isDecoding = false;
    nColumns = 0;
    buffer = 0;
    bufCount = 0;
}

Codec64::~Codec64() {

    if (file.is_open())
        file.close();
}

void Codec64::put8(uint8_t n,uint32_t nEquals) {
    uint8_t
        ch;

    // only process if we are encoding
    if (isEncoding) {
        // shift buffer contents and add in next char
        buffer = (buffer << 8) + n;

        // increment count of chars in buffer
        bufCount++;

        // if we have 3 chars == 24 bits, slice into 6-bit chunks and output
        if (bufCount == 3) {
            for (uint32_t i=0;i<4;i++) {
                // convert 6-bit slice to character
                ch = charset[(buffer >> (18-6*i)) & 0x3f];

                // if we are at the end of data stream, we might need to output 1 or 2 = instead of
                // characters
                if (i > 3 - nEquals)
                    file << '=';
                else
                    file << ch;

                // add line breaks to output file
                if (nColumns == 63)
                    file << '\n';
                nColumns = (nColumns + 1) & 0x3f;
            }

            // reset buffer and counter for next cycle
            buffer = 0;

            bufCount = 0;
        }
    }
}

void Codec64::put16(uint16_t n,uint32_t nEquals) {

    put8((unsigned char)(n & 0xffu));
    put8((unsigned char)(n >> 8u),nEquals);
}

void Codec64::put32(uint32_t n) {

    put16((uint16_t)(n & 0xffffu));
    put16((uint16_t)(n >> 16u));
}

void Codec64::put64(uint64_t n) {

    put32((uint32_t)(n & 0xffffffffu));
    put32((uint32_t)(n >> 32u));
}

uint8_t Codec64::get8() {
    char
        ch;

    // if we are not decoding, don't do anything
    if (!isDecoding)
        throw std::runtime_error("Codec64: Not decoding");

    // if we have nothing in the buffer, fetch next 3 bytes
    if (bufCount == 0) {
        // read 4 bytes from file
        for (uint32_t i=0;i<4;i++) {
            file >> ch;

            // if read fails, bail
            if (!file)
                throw std::length_error("Codec64: Unexpected EOF");

            // shift buffer left 6 bits
            buffer <<= 6;

            // if input is =, it's a placeholder. otherwise, decode the char
            if (ch != '=') {
                uint32_t
                j;
                for (j=0;ch!=charset[j];j++);
                buffer += j;
            }
        }

        // we now have 3 bytes in the buffer
        bufCount = 3;
    }

    // one less byte in the buffer
    bufCount--;

    // extract the byte from the buffer
    return (buffer >> (8*bufCount)) & 0xff;
}

uint16_t Codec64::get16() {
    uint8_t
        high,low;

    // try to get a byte... twice
    low = get8();
    high = get8();

    // combine bytes to get a word
    return low + ((uint16_t)high << 8u);
}

uint32_t Codec64::get32() {
    uint16_t
        high,low;

    low = get16();
    high = get16();

    return low + ((uint32_t)high << 16u);
}

uint64_t Codec64::get64() {
    uint32_t
        high,low;

    low = get32();
    high = get32();

    return low + ((uint64_t)high << 32u);
}

void Codec64::beginEncode(const char *fileName) {

    // close the file if it is open
    if (file.is_open())
        file.close();

    // we are not decoding
    isDecoding = false;

    // attempt to open the file for output.
    // encoding is activated iff the open succeeds
    file.open(fileName,std::ios::out);
    isEncoding = file.is_open();

    // clear the buffer
    buffer = 0;
    bufCount = 0;
    nColumns = 0;
}

void Codec64::beginDecode(const char *fileName) {

    // close the file if it is open
    if (file.is_open())
        file.close();

    // we are not encoding
    isEncoding = false;

    // attempt to open the file for input.
    // decoding is activated iff the open succeeds
    file.open(fileName,std::ios::in);
    isDecoding = file.is_open();

    // clear the buffer
    buffer = 0;
    bufCount = 0;
    nColumns = 0;
}

void Codec64::endEncode() {

    // if buffer is not empty, pad and signal to output 1 or 2 = at end
    if (bufCount == 2)
        put8(0,1);

    if (bufCount == 1)
        put16(0,2);

    // close the file
    file.close();

    // no longer encoding
    isEncoding = false;
}

void Codec64::endDecode() {

    // close the file
    file.close();

    // no longer decoding
    isDecoding = false;
}