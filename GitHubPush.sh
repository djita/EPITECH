sh ~/Documents/pull_exams.sh
cp -ru ~/Documents/* ~/GitTimeMachine/EPITECH/Documents/
cp -ru ~/Pictures/* ~/GitTimeMachine/EPITECH/Pictures/
date >> date.log
echo -n 'Commited by '>> date.log
echo $USER >> date.log
echo '' >> date.log
git add */*
git commit -am "Backup"
git push
