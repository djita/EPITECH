SELECT DISTINCT(etage_salle) AS "num etage", COUNT(numero_salle) AS "nbr salle", SUM(nbr_siege) AS "nbr place" FROM salle GROUP BY etage_salle ORDER BY etage_salle DESC;
