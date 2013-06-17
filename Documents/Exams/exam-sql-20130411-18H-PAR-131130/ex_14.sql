select film.titre, film.date_debut_affiche as "date debut", film.id_distrib, distrib.nom as "nom_distrib" from film join distrib on film.id_distrib = distrib.id_distrib where UPPER(film.titre) like "%DEATH%";

