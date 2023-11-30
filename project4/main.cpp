#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/stat.h>
#include <random>

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

}

void decrypt(char *inName,char *outName,int64_t n,int64_t d) {

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
