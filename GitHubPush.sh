cp -r ~/Documents/* ~/GitTimeMachine/EPITECH/Documents/
cp -r ~/Pictures/* ~/GitTimeMachine/EPITECH/Pictures/
date >> date.log
echo ' Commited by '>> date.log
echo $USER >> date.log
echo "\n" >> date.log
git add *
git commit
git push
