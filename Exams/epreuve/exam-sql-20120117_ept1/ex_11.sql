SELECT id_film AS "max id film" FROM film, genre WHERE genre.nom = 'action' AND genre.id_genre = film.id_genre ORDER BY id_film DESC LIMIT 0, 1;
