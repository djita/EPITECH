SELECT DISTINCT(id_genre), COUNT(id_film) AS "nombre films" FROM film GROUP BY id_genre UNION SELECT "total", SUM(id_film) FROM film;
