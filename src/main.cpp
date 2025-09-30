/*
Example of code: https://t.me/c/2092444113/1345/1566
Compile cmake:
cmake -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake -S ..
*/

#include <cpr/cpr.h>
#include <iostream>
#include <string>


#include <CurConverter.h>

const std::string apiKey = "18e6992ef7-0d6392a6c6-t3286k";

int main(int argc, char const *argv[])
{
    /* code */
    CurConverter c {apiKey};
    c.getRate("USD", "CZK");
    return 0;
}
