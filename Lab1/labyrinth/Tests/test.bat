@echo off
SET program="labyrinth.exe"
if %program% == "" goto err

echo Test1 > out.txt
%program% input.txt output1.txt >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test2 >> out.txt
%program% input2.txt output2.txt >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test3 >> out.txt
%program% input3.txt output3.txt >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test4 >> out.txt
%program% input4.txt output4.txt >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>;