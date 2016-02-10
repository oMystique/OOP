@echo off
echo 1 test.
echo Arguments: replace.exe input.txt output1_true.txt ma mama
replace.exe input.txt output1_true.txt ma mama
echo 2 test.
echo Arguments: replace.exe input.txt output2_true.txt 1231234 chicken
replace.exe input.txt output2_true.txt 1231234 chicken
echo 3 test.
echo Arguments: replace.exe input.txt output3_true.txt Ann ASDABSJ... .
replace.exe input.txt output3_true.txt Ann ASDABSJDGABSJDGBASBDJBASDHBKAHSBDHBASDBAKHSDBHASBHDKASBHDBHJASBHDASBHDABJHSDBHASDASDASDASDASDASDASDASDASDASDASDASDGASGDGASDVGASGDVDJVHAGSDVASDASDGHASHGDAGVSDGHSADASGHDGHASDGHASGHDASGVD
echo 4 test.
echo Arguments: replace.exe input.txt output4_false.txt ma
replace.exe input.txt output4_false.txt ma
echo 5 test.
echo Arguments: replace.exe input.txt output5_false.txt ma mama mamo4ka
replace.exe input.txt output5_false.txt ma mama mamo4ka
echo 6 test.
echo Arguments: replace.exe PUTIN.txt output6_false.txt error error
replace.exe PUTIN.txt output6_false.txt error error
echo 7 test.
echo Arguments: replace.exe input.txt output7_false.txt "" empty
replace.exe input.txt output7_false.txt "" empty
echo 8 test.
echo Arguments: replace.exe input.txt output8_true.txt empty ""
replace.exe input.txt output8_true.txt empty ""
pause