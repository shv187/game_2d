@echo off

pushd ..
del /s /q /f *.sln
del /s /q /f *.vcxproj
del /s /q /f *.vcxproj.user
del /s /q /f *.vcxproj.filters
popd

pause