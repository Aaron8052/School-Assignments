@echo off
:: 切换到 .bat 所在的目录
cd /d "%~dp0"

:: 获取拖入的文件路径
set "file=%~1"

:: 如果没有文件，提示用户
if "%file%"=="" (
    echo 文件不存在
    pause
    exit
)

:: 运行 StyleScanner 并传入文件路径
.\StyleScanner "%file%" -c

:: 暂停显示结果
pause
