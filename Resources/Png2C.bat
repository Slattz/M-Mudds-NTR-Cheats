@echo off
title= PNG2C Bat
color 07
@mode con cols=80 lines=20

:START
if exist "png2c.exe" goto Check
if not exist "png2c.exe" goto ERROR2
echo ERROR
pause
exit

:Check
if exist "libpng16.dll" goto Cont1
if not exist "libpng16.dll" goto ERROR3
echo ERROR
pause
exit

:Cont1
set /p NAME= Set Png's File Name (Without Extension): 
echo.
set /p RGB1= Set RGB? (Y/N): 
if %RGB1% == Y goto ADD
if %RGB1% == y goto ADD
if %RGB1% == Yes goto ADD
if %RGB1% == yes goto ADD
if %RGB1% == N goto CONT2
if %RGB1% == n goto CONT2
if %RGB1% == No goto CONT2
if %RGB1% == no goto CONT2
if not defined %RGB1% goto ERROR1

:CONT2
echo.
png2c -rotate %NAME%.png
exit

:ADD
echo.
png2c -rgb -rotate %NAME%.png
exit

:ERROR1
echo.
echo An error has occured: You have not set RGB correctly.
echo Please state either Yes (Y/y) or No (N/n).
echo.
pause
echo.
echo Exiting in 3 seconds.
sleep 3
exit

:ERROR2
echo An error has occured: png2c.exe is not in the current directory.
echo.
echo Either move png2c.exe to the current directory or run this Bat from
echo a directory containing png2c.exe.
echo.
pause
echo.
echo Exiting in 3 seconds.
sleep 3
exit

:ERROR3
echo An error has occured: libpng16.dll is not in the current directory.
echo.
echo Either move libpng16.dll to the current directory or run this Bat from
echo a directory containing libpng16.dll.
echo.
pause
echo.
echo Exiting in 3 seconds.
sleep 3
exit