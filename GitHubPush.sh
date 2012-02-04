cp -r ~/Documents/* ~/GitTimeMachine/EPITECH/
date >> date.log
echo ' Commited by '>> date.log
echo $USER >> date.log
echo "\n" >> date.log
git add *
git commit
git push
