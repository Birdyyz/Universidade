USE sakila;
CREATE USER 'user_leitura'@’localhost’ IDENTIFIED BY '1234';
ALTER USER 'user_leitura'@’localhost’ IDENTIFIED BY 'pasteldenatinha' PASSWORD EXPIRE INTERVAL 90 DAY;
CREATE USER 'user_analista'@’localhost’ IDENTIFIED BY '1234';

SELECT * FROM mysql.user;

CREATE ROLE 'leitor';
CREATE ROLE 'editor';

GRANT 'leitor' TO 'user_leitura'@’localhost’;

GRANT SELECT ON sakila.* TO 'leitor';

GRANT SELECT, INSERT, UPDATE ON sakila.customer TO 'editor';

GRANT SELECT, INSERT, UPDATE ON sakila.rental TO 'editor';

GRANT 'editor' TO 'user_analista'@’localhost;

SET DEFAULT ROLE 'editor' TO 'user_analista'@’localhost;

REVOKE UPDATE ON sakila.customer FROM 'editor';

CREATE VIEW vw_clientes AS SELECT customer_id, first_name, last_name, email FROM sakila.customer;

CREATE VIEW vw_filmes AS SELECT f.title, c.name categoria FROM sakila.film f 
JOIN sakila.film_category c ON fc.category_id = c.category_id;

CREATE VIEW vw_rentals_ativos AS SELECT return_date FROM rental WHERE return_date IS NULL;

CREATE VIEW vw_top_clientes AS SELECT c.customer_id, c.first_name,