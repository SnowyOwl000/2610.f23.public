//
// Created by bob on 7/30/21.
//

#ifndef CODEC64_CODEC64_H
#define CODEC64_CODEC64_H

#include <fstream>

class Codec64 {
public:
    Codec64();
    ~Codec64();

    void put8(uint8_t n,uint32_t nEquals=0);

    void put16(uint16_t n,uint32_t nEquals=0);

    void put32(uint32_t n);

    void put64(uint64_t n);

    uint8_t get8();

    uint16_t get16();

    uint32_t get32();

    uint64_t get64();

    void beginEncode(const char *);
    void beginDecode(const char *);
    void endEncode();
    void endDecode();

private:
    uint32_t
        bufCount,
        buffer,
        nColumns;
    bool
        isEncoding,
        isDecoding;
    std::fstream
        file;
};

#endif //CODEC64_CODEC64_H
