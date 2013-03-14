SELECT titre FROM film WHERE UPPER(titre) LIKE 'E%' AND id_genre IN (0, 5, 6);
