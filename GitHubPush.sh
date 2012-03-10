cp -r ~/Documents/* ~/GitTimeMachine/EPITECH/Documents/
cp -r ~/Pictures/* ~/GitTimeMachine/EPITECH/Pictures/
cp -r /afs/epitech.net/users/all/guillo_e/epreuve/ ~/GitTimeMachine/EPITECH/Exams
date >> date.log
echo ' Commited by '>> date.log
echo $USER >> date.log
echo "\n" >> date.log
git add *
git commit
git push
