SELECT COUNT(nom) AS 'nbr abo', (SUM(prix) DIV COUNT(nom)) AS 'c abo' FROM abonnement;
