SELECT COUNT(id_abo) AS "nbr abo", SUM(prix) DIV COUNT(id_abo) AS "c abo" FROM abonnement;
