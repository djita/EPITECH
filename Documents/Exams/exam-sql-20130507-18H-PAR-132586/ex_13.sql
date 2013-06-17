select titre as "titre film" from film where id_genre in (0, 6, 5) and UPPER(titre) like "E%";
