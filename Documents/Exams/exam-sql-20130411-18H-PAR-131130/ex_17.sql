SELECT film.titre, film.date_debut_affiche, film.id_film, COUNT(DISTINCT(historique_membre.id_membre)) AS "nb_vues" FROM film JOIN historique_membre ON (film.id_film = historique_membre.id_film) GROUP BY film.titre ORDER BY nb_vues DESC LIMIT 50;
