@echo off 

make run 

set /p var=input:

echo %var%.img

D:

IF EXIST %var%.txt DEL /F %var%.txt

move %var%.img, D:\

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