mkdir -p /tmp/$USER/mysql/var
mysql_install_db
mysqld_safe --defaults-file=/home/guillo_e/.my.cnf&
