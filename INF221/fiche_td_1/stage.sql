DROP DATABASE IF EXISTS stage;

CREATE DATABASE IF NOT EXISTS stage;
use stage;

/* clean database stage*/
DROP DATABASE IF EXISTS conventions;
DROP DATABASE IF EXISTS postulations;
DROP DATABASE IF EXISTS stages;
DROP DATABASE IF EXISTS entreprises;
DROP DATABASE IF EXISTS enseignants;
DROP DATABASE IF EXISTS etudiants;

CREATE TABLE IF NOT EXISTS etudiants(
  id_etudiant VARCHAR(10) PRIMARY KEY,
  nom_etudiant VARCHAR(255) NOT NULL,
);

CREATE TABLE IF NOT EXISTS enseignants(
  
)