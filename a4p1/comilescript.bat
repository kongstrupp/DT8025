@echo off 


echo Enter the c file for compilation
set /p var=input:

IF EXIST %var%.img DEL /F %var%.img
IF EXIST %var%.elf DEL /F %var%.elf
IF EXIST %var%.o DEL /F %var%.o

make run 

set "path=%cd%"

D:

IF EXIST %var%.img DEL /F %var%.img

C:

cd %path%

move %var%.img, D:\

D:

    setlocal enableextensions disabledelayedexpansion

    set "config=.\config.txt"
    set "newimgfile=%var%.img"

    for /f "tokens=*" %%l in ('type "%config%"^&cd.^>"%config%"'
    ) do for /f "tokens=1 delims== " %%a in ("%%~l"
    ) do if /i "%%~a"=="kernel" (
        >>"%config%" echo(kernel=%newimgfile%
    ) else (
        >>"%config%" echo(%%l
    )

    type "%config%"

    endlocal

pause