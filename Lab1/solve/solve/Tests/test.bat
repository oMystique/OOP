@echo off
SET program="%1"
if %program% == "" goto err

echo Test1 > out.txt
%program% -1 -6 -3 >> out.txt
if ERRORLEVEL 1 goto testFailed

echo Test2 >> out.txt
%program% 1 4 3 >> out.txt
if ERRORLEVEL 1 goto testFailed

echo Test3 >> out.txt
%program% 1 2 1 >> out.txt
if ERRORLEVEL 1 goto testFailed

echo Test4 >> out.txt
%program% 5 10 7 >> out.txt
if NOT ERRORLEVEL 1 goto testFailed

echo Test5 >> out.txt
%program% 1.21 18.14 5.661663153343 >> out.txt
if ERRORLEVEL 1 goto testFailed

echo Test6 >> out.txt
%program% 0 1 1 >> out.txt
if NOT ERRORLEVEL 1 goto testFailed

echo Test7 >> out.txt
%program% 13 5 0 >> out.txt
if ERRORLEVEL 1 goto testFailed

echo Test8 >> out.txt
%program% 1 1 1 1 >> out.txt
if NOT ERRORLEVEL 1 goto testFailed

echo Test9 >> out.txt
%program% a b c >> out.txt
if NOT ERRORLEVEL 1 goto testFailed

echo OK
pause
exit /B

:testFailed
echo Testing failed
pause
exit /B

:err
echo Usage: test.bat <Path to program>;