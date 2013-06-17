SELECT COUNT(id_abo) AS "nbr abo", ROUND(SUM(prix) / COUNT(id_abo)) AS "c abo" FROM abonnement;
