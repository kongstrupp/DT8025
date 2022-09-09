
rem setlocal enableDelayedExpansion
rem set Option1=a1p1.img

rem set /p Option1=Option1:
rem set /p Option2=Option2:
rem set /p Option3=Option3:
rem type kernel.txt




@echo off
    setlocal enableextensions disabledelayedexpansion

    set "config=.\config.txt"
    set "newimgfile=newvalue2"

    for /f "tokens=*" %%l in ('type "%config%"^&cd.^>"%config%"'
    ) do for /f "tokens=1 delims== " %%a in ("%%~l"
    ) do if /i "%%~a"=="kernel" (
        >>"%config%" echo(kernel=%newimgfile%
    ) else (
        >>"%config%" echo(%%l
    )

    type "%config%"

    endlocal
	
	
rem type kernel.txt
rem sed -e "/kernel/d" kernel.txt
rem powershell -Command "(gc kernel.txt) -replace 'foo', 'bar' | Out-File -encoding ASCII kernel.txt"
rem echo kernel=%Option1% >>kernel.txt
rem echo Option2=%Option2% >>kernel.txt
rem echo Option3=%Option3% >>kernel.txt

rem sed -i 's/Description=MAN_Human/Description=MAN_Human_V2/' kernel.txt

rem cd %C:\DT8025\a1p1%

rem make run

rem move movetxt.txt, C:\Users\Wilhelm\Desktop\innovations2311


pause 
