set PATH=%PATH%;C:\devkitPro\devkitARM\bin;C:\devkitPro\msys\bin
build.py
pause

rmdir /S /Q .\plugin
xcopy /y /i /v ".\*.plg" ".\plugin\0004000000086600\" >nul
xcopy /y /i /v  ".\*.plg" ".\plugin\00040000000A5400\" >nul

echo .
echo Enjoy The Plugin!
exit
