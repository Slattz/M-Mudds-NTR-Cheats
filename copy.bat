@echo off
@mode con cols=30 lines=5
:Start
cls
xcopy /y /v /i ".\*.o" ".\Copied" 
sleep 0.2
goto Start
exit