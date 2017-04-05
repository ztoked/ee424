#define _GNU_SOURCE
#include "cachelab.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/***************************************
* UserIds:
*          zh18779 Zach Halvorsen
*          jcleish Christian Leishman
****************************************/

enum i_type {LOAD, STORE, MODIFY, INSTRUCTION};
enum hit_type {HIT, MISS, EVICTION};

char verboseFlag = 0;
char trace[100];

unsigned numSets = 0;
unsigned numSetBits = 0;
unsigned numLinesPerSet = 0;
unsigned numBlocks = 0;
unsigned numBlockBits = 0;
unsigned hits = 0;
unsigned misses = 0;
unsigned evictions = 0;

typedef struct _lineType {
    long tag;
    char valid;
    long counter;
} lineType;

lineType *cache;
ssize_t read;
size_t  readLen;
char *line;

FILE *file;

unsigned getNumFromString(char * str);
void parseArg(int argc, char *argv[]);
char load(unsigned setIndex, unsigned tag);
char store(unsigned setIndex, unsigned tag);
void parseLine(char *line, ssize_t read, char *type, unsigned *size,
    unsigned long *address);
void parseAddr(unsigned long address, unsigned *set, unsigned *tag,
    unsigned *block);
void recordHit(char isHit);

int main(int argc, char *argv[])
{
    parseArg(argc, argv);
    if(numSets > 0 && numLinesPerSet > 0 && numBlocks > 0) {
        cache = (lineType *) malloc(numSets * numLinesPerSet
            * sizeof(lineType));
        file = fopen(trace, "r");
        if(file == NULL) {
            exit(EXIT_FAILURE);
        }
        while((read = getline(&line, &readLen, file)) != -1) {
            char type = 0;
            unsigned size = 0;
            unsigned long address = 0;
            parseLine(line, read, &type, &size, &address);
            if(type == INSTRUCTION) {
                continue;
            }
            if(verboseFlag) {
                printf("%s, ", line);
            }
            unsigned set;
            unsigned tag;
            unsigned block;
            parseAddr(address, &set, &tag, &block);
            switch (type) {
            case LOAD:
                recordHit(load(set, tag));
                if(verboseFlag) {
                    printf("\n");
                }
                break;
            case STORE:
                recordHit(store(set, tag));
                if(verboseFlag) {
                    printf("\n");
                }
                break;
            case MODIFY:
                recordHit(load(set, tag));
                recordHit(store(set, tag));
                if(verboseFlag) {
                    printf("\n");
                }
                break;
            default:
                continue;
            }
        }
        printSummary(hits, misses, evictions);
    } else {
        printf("Did not put one of the values needed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

unsigned strLen(char *str)
{
    unsigned ret = 0;
    unsigned i = 0;
    while(str[i] >= '0' && str[i] <= '9') {
        i++;
        ret++;
    }
    return ret;
}

unsigned getNumFromString(char * str) {
    unsigned len = strLen(str);
    unsigned ret = 0;
    unsigned i = 0;
    for(i = 0; i < len; ++i) {
        double power = pow(10,len - i - 1);
        ret += (unsigned)power * (str[i] - '0');
    }
    return ret;
}

void incOthers(lineType *set, unsigned index)
{
    for(unsigned i = 0; i < numLinesPerSet; ++i) {
        if(i == index) {
            set[i].counter = 0;
            continue;
        }
        set[i].counter++;
    }
}

char load(unsigned setIndex, unsigned tag)
{
    lineType *set = &cache[setIndex * numLinesPerSet];
    for (unsigned i = 0; i < numLinesPerSet; i++) {
        if(set[i].tag == tag && set[i].valid) {
            incOthers(set, i);
            return HIT;
        }
    }
    unsigned LRUindex = 0;
    unsigned LRUval = 0;
    for(unsigned i = 0; i < numLinesPerSet; i++) {
        if(set[i].valid == 0) {
            set[i].tag = tag;
            set[i].valid = 1;
            incOthers(set, i);
            return MISS;
        }
        if(set[i].counter > LRUval) {
            LRUindex = i;
            LRUval = set[i].counter;
        }
    }
    set[LRUindex].tag = tag;
    set[LRUindex].valid = 1;
    incOthers(set, LRUindex);
    return EVICTION;
}

char store(unsigned setIndex, unsigned tag)
{
    lineType *set = &cache[setIndex * numLinesPerSet];
    for (unsigned i = 0; i < numLinesPerSet; i++) {
        if(set[i].tag == tag && set[i].valid) {
            incOthers(set, i);
            return HIT;
        }
    }
    unsigned LRUindex = 0;
    unsigned LRUval = 0;
    for(unsigned i = 0; i < numLinesPerSet; i++) {
        if(set[i].valid == 0) {
            set[i].tag = tag;
            set[i].valid = 1;
            incOthers(set, i);
            return MISS;
        }
        if(set[i].counter > LRUval) {
            LRUindex = i;
            LRUval = set[i].counter;
        }
    }
    set[LRUindex].tag = tag;
    set[LRUindex].valid = 1;
    incOthers(set, LRUindex);
    return EVICTION;
}

void parseAddr(unsigned long address, unsigned *set, unsigned *tag,
    unsigned *block)
{
    unsigned i = 0;
    unsigned blockMask = 0;
    for(i = 0; i < numBlockBits; ++i) {
        blockMask <<= 1;
        blockMask++;
    }
    *block = address & blockMask;

    unsigned setMask = 0;
    for(i = 0; i < numSetBits; ++i) {
        setMask <<= 1;
        setMask++;
    }
    *set = address >> numBlockBits;
    *set &= setMask;
    *tag = address >> (numBlockBits + numSetBits);
}

unsigned char hexVal(char c)
{
    if(c >= '0' && c <= '9') {
        return c - '0';
    } else if(c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }  else if(c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else {
        return -1;
    }
}

void parseLine(char *line, ssize_t read, char *type, unsigned *size,
    unsigned long *address)
{
    if(line[0] != ' ') {
        *type = INSTRUCTION;
        return;
    }
    switch(line[1]) {
    case 'L':
        *type = LOAD;
        break;
    case 'S':
        *type = STORE;
        break;
    case 'M':
        *type = MODIFY;
        break;
    }
    char *number = line + 3;
    int index = 0;
    while (number[index] != ',') {
        *address <<= 4;
        *address += (hexVal(number[index]) & 0xF);
        index++;
    }
    index++;
    line[read-1] = 0;
    char *sizeArray = number + index;
    *size = getNumFromString(sizeArray);
}

void parseArg(int argc, char *argv[])
{
    int i;
    for(i = 0; i < argc; ++i) {
        if(strstr(argv[i], "-h") != 0) {
            printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\nOptions:\n  -h         Print this help message.\n  -v         Optional verbose flag.\n  -s <num>   Number of set index bits.\n  -E <num>   Number of lines per set.\n  -b <num>   Number of block offset bits.\n  -t <file>  Trace file.\n\nExamples:\n  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
            exit(0);
        }
        if(strstr(argv[i], "-v") != 0) {
            verboseFlag = 1;
        }
        if(strstr(argv[i], "-s") != 0) {
            char *numArray = argv[i + 1];
            numSetBits = getNumFromString(numArray);
            numSets = 1 << numSetBits;
            i++;
        }
        if(strstr(argv[i], "-E") != 0) {
            char *numArray = argv[i + 1];
            numLinesPerSet = getNumFromString(numArray);
            i++;
        }
        if(strstr(argv[i], "-b") != 0) {
            char *numArray = argv[i + 1];
            numBlockBits = getNumFromString(numArray);
            numBlocks = 1 << numBlockBits;
            i++;
        }
        if(strstr(argv[i], "-t") != 0) {
            unsigned len = strlen(argv[i + 1]);
            unsigned j;
            len = (len < 99)? len : 99;
            for(j = 0; j < len; ++j) {
                trace[j] = argv[i + 1][j];
            }
            trace[len] = 0;
            i++;
        }
    }
}

void recordHit(char isHit)
{
    switch(isHit) {
    case HIT:
        hits++;
        if(verboseFlag) {
            printf("hit ");
        }
        break;
    case MISS:
        misses++;
        if(verboseFlag) {
            printf("miss ");
        }
        break;
    case EVICTION:
        evictions++;
        misses++;
        if(verboseFlag) {
            printf("miss eviction ");
        }
        break;
    }
}
