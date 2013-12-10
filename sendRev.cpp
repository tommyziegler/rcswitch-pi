#include "HomeControlAPI.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
    SwitchRev((char*)argv[1], (int)atoi(argv[2]), (bool)atoi(argv[3]));
    return 0;
}
