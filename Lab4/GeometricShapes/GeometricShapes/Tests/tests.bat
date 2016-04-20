@echo off
SET program="%1"
if %program% == "" goto err

%program% input.txt > test_output.txt
if errorlevel 1 goto testFailed
fc /b test_output.txt output.txt
if errorlevel 1 goto testFailed

%program% input_empty.txt > test_empty_output.txt
if errorlevel 1 goto testFailed
fc /b test_empty_output.txt empty_output.txt
if errorlevel 1 goto testFailed

%program% input_incorrect_values.txt > test_incorrect_values_output.txt
if errorlevel 1 goto testFailed
fc /b test_incorrect_values_output.txt incorrect_values_output.txt
if errorlevel 1 goto testFailed

echo OK
exit /b

:testFailed
echo Testing failed 
pause
exit /b

:err
echo Usage: test.bat <Path to program>