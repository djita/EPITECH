sh ~/Documents/pull_exams.sh
cp -ru ~/Documents/* ~/GitTimeMachine/EPITECH/Documents/
cp -ru ~/Pictures/* ~/GitTimeMachine/EPITECH/Pictures/
cp -ru /afs/epitech.net/users/all/guillo_e/epreuve/* ~/GitTimeMachine/EPITECH/Exams/epreuve-tek1/
date >> date.log
echo ' Commited by '>> date.log
echo $USER >> date.log
echo "\n" >> date.log
git add *
git commit
git push
