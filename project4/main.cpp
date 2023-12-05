#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/stat.h>
#include <random>
#include "codec.h"

using namespace std;

bool isPrime(uint64_t n) {

    // if n < 2, n is not prime

    // otherwise, if n is 2, it is prime

    // otherwise, if n is even, it is not prime

    // otherwise, check all odd integers from 3 to sqrt(n)

        // if that odd integer evenly divides n, then n is not prime

    // otherwise, n is prime
}

//============================================================================
// int64_t modInverse(int64_t a,int64_t n)
//  compute and return b such that (a * b) % n == 1
//
// Parms
//   a - value to find inverse of
//   n - modulus
//
// Returns
//   b such that (a * b) % n == 1, if such a number exists
//   -1 if no such number exists
//

int64_t modInverse(int64_t a,int64_t n) {
    // t = 0, tNew = 1
    // r = n, rNew = a
    int64_t
        t=0,tNew=1,
        r=n,rNew=a,
        q,tmp;

    // while rNew != 0 {
    while (rNew != 0) {

        // q = r / rNew
        q = r / rNew;

        // (t,tNew) = (tNew,t - q*tNew)
        tmp = tNew;
        tNew = t - q * tNew;
        t = tmp;

        // (r,rNew) = (rNew,r - q*rNew)
        tmp = rNew;
        rNew = r - q * rNew;
        r = tmp;
        // }
    }

    // if r > 1, error
    if (r > 1)
        return -1;

    // if t < 0, then t = t + n
    if (t < 0)
        t += n;

    // return t
    return t;
}

uint64_t modExp(uint64_t base,uint64_t exp,uint64_t m) {

    // ans = 1

    // while exp != 0 {

        // if exp is odd, then ans = (ans * base) % m

        // base = (base * base) % m

        // exp = exp / 2

    // }

    // return ans
}

int64_t getFileSize(char *fn) {
    struct stat
        fs{};

    stat(fn,&fs);

    return fs.st_size;
}

void keyGen() {
    random_device
        rd;
    mt19937
        mt(rd());
    uniform_int_distribution<>
        dis(4096,65535);
    ofstream
        outFile;
    uint32_t
        p,q,
        n,f,
        d,e;

    // choose prime number p such that 4096 <= p < 65536
    do {
        p = dis(mt);
    } while (!isPrime(p));

    // choose prime number q, same range and p != q
    do {
        q = dis(mt);
    } while (!isPrime(q) || p == q);

    // calculate n = p * q
    n = p * q;

    // calculate totient function f = (p-1) * (q-1)
    f = (p-1) * (q-1);

    // choose e such that e & f are relatively prime
    do {
        e = dis(mt);
    } while (gcd(e,f) != 1);

    // calculate d such that (d * e) % f == 1
    d = modInverse(e,f);

    // write n and e to public.key
    outFile.open("public.key");
    if (!outFile) {
        cout << "Could not open public.key" << endl;
        exit(EXIT_FAILURE);
    }

    outFile << n << ' ' << e << endl;

    outFile.close();

    // write n and d to private.key
}

void encrypt(char *inName,char *outName,int64_t n,int64_t e) {
    ifstream
        inFile;
    Codec64
        codec;
    uint32_t
        fileSize,
        plain,cipher;
    uint8_t
        c1,c2,c3;

    // open input file and check to make sure it worked

    // get the file size for input file and remember it
    fileSize = getFileSize(inName);

    // create Codec64 object and prepare it for writing
    codec.beginEncode(outName);

    // write file size to codec
    codec.put32(fileSize);

    // while bytes read < file size, do {

        // read c1, c2 and c3 from input file
        c1 = inFile.get();

        // combine them into one number
        plain = c1 + 256 * c2 + 65536 * c3;

        // encrypt number with modExp
        cipher = modExp(plain,e,n);

        // send encrypted value to codec
        codec.put32(cipher);

    // }

    // tell codec to stop
    codec.endEncode();

    // close input file
}

void decrypt(char *inName,char *outName,int64_t n,int64_t d) {
    ofstream
        outFile;
    Codec64
        codec;
    uint32_t
        fileSize,
        plain,cipher;
    uint8_t
        c1,c2,c3;

    // open output file and make sure it worked

    // create Codec64 object and prepare it for reading

    // get file size from codec
    codec.get32(fileSize);

    // while bytes written < file size, do {

        // get value from codec

        // decrypt value using modExp
        plain = modExp(cipher,d,n);

        // extract c1, c2, c3 from decrypted number
        c1 = plain % 256;
        plain = plain / 256;

        c2 = plain % 256;
        plain /= 256;

        c3 = plain % 256;

        // output c1, c2 and c3... but only if bytes written < file size
        outFile << c1;

        // if bytes written < file size, write c2 same way

        // if bytes written < file size, write c3 same way

    // }

    // tell codec to stop

    // close output file
}

void usage(char *progName) {
    cout << "Usage: " << progName << " -k" << endl;
    cout << "       " << progName << " -e infile outfile" << endl;
    cout << "       " << progName << " -d infile outfile" << endl;

    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]) {
    int64_t
        n,e,d;

    // make sure there are at least two command-line items
    if (argc < 2)
        usage(argv[0]);

    // make sure second item starts with -
    if (argv[1][0] != '-')
        usage(argv[0]);

    // make sure second item is only - + single letter
    if (strlen(argv[1]) != 2)
        usage(argv[0]);

    // determine which option... that's the second character
    if (argv[1][1] == 'k') {
        // generate a key... just call keyGen
        keyGen();
    } else if (argv[1][1] == 'e') {
        // encrypt a file...
        // make sure argc is 4

        // read n and e from public.key file

        // call encrypt
        encrypt(argv[2],argv[3],n,e);
    } else if (argv[1][1] == 'd') {
        // decrypt a file...
        // make sure argc is 4

        // read n and d from private.key file

        // call decrypt
        decrypt(argv[2],argv[3],n,d);
    } else
        usage(argv[0]);

    return 0;
}
