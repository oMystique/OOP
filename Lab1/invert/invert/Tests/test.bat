rem @echo off
SET program="%1"
if %program% == "" goto err

echo Test1 > out.txt
%program% matrix.txt >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test2 >> out.txt
%program% matrix2.txt >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test3 >> out.txt
%program% matrix3.txt >> out.txt
if NOT ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test4 >> out.txt
%program% matrix4.txt >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test5 >> out.txt
%program% matrix5.txt >> out.txt
if NOT ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test6 >> out.txt
%program% matrix6.txt >> out.txt
if NOT ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo OK
pause
exit /B

:testFailed
echo Testing failed
pause
exit /B

:err
echo Usage: test.bat <Path to program>