@echo off
:: 切换到 .bat 所在的目录
echo cd /d "%~dp0"
cd /d "%~dp0"

set "file=%~1"

if "%file%"=="" (
    	echo Path cannot be empty
	echo Drag file into this bat!
    	pause
    	exit
)

echo .\StyleScanner "%file%" -c
.\StyleScanner "%file%" -c

pause
