select count(id_abo) as "nbr abo", round(sum(prix)/count(id_abo)) as "c abo" from abonnement;
