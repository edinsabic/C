cls
rmdir /S /Q build
rmdir /S /Q dist64
rmdir /S /Q dist32
mkdir build
cmake -S. -Bbuild
cmake --build build
xcopy build\Debug\* dist64\
xcopy build\Debug\* dist32\
echo F|xcopy ..\libs\SDL2\lib\x64\SDL2.dll dist64\SDL2.dll
echo F|xcopy ..\libs\SDL2\lib\x86\SDL2.dll dist32\SDL2.dll
.\dist64\004_ping_pong.exe