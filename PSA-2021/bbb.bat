@ECHO OFF
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
mkdir Result
cd Result
call ..\Debug\SPA-2021.exe -in:..\cod.txt -out:asm.asm -log:log.txt -mfst:mfst.txt
ml /c /coff /Zi asm.asm
link /OPT:NOREF /DEBUG ..\Debug\SPA_Lib.lib asm.obj  /SUBSYSTEM:CONSOLE
call asm.exe
pause