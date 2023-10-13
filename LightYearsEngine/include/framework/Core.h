#include <stdio.h>

namespace ly
{

//a macro
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

}