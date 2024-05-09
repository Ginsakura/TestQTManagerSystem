git  add .
set /p var=commit:
git commit -m "%var%"
git push
pause