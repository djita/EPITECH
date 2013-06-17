SELECT MAX(film.id_film) AS "max id film" FROM film JOIN genre ON (film.id_genre = genre.id_genre) WHERE genre.nom = "action";
