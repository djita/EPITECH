SELECT genre.nom AS '"nom"', COUNT(film.id_film) AS '"nb_film"' FROM genre, film WHERE film.id_genre = genre.id_genre GROUP BY genre.id_genre ORDER BY genre.nom ASC;
