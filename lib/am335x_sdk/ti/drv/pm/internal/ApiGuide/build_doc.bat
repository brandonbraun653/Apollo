
mkdir pm_api
copy *.gif pm_api\.
doxygen pm_api.cfg 2> warnings.txt
copy pm_api\*.chm ..\..\docs\
rmdir /s /q pm_api
echo Doxygen Warnings.......
type warnings.txt
