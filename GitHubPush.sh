sh ~/Documents/pull_exams.sh
cp -ru ~/Documents/* ~/GitTimeMachine/EPITECH/Documents/
cp -ru ~/Pictures/* ~/GitTimeMachine/EPITECH/Pictures/
cp -ru ~/Git/* ~/GitTimeMachine/EPITECH/Git
cp -ru ~/.*
date >> date.log
echo -n 'Commited by '>> date.log
echo $USER >> date.log
echo '' >> date.log
git add *
git commit
git push
