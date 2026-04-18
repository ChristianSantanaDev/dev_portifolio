CREATE DATABASE agencia;
USE agencia;
/* Criando a tabela empresa */
CREATE TABLE empresa ( idEmpresa INT PRIMARY KEY,
nome VARCHAR(100),
endereco VARCHAR(255),
CNPJ VARCHAR(14)
);
/* Criando a tabela candidato */
CREATE TABLE candidato ( idCandidato INT PRIMARY KEY,
nome VARCHAR(50),
CPFVARCHAR(11),
telefone VARCHAR(15),
cidade VARCHAR(60)
);
/* Criando tabela vaga */
CREATE TABLE vaga ( idVaga INT PRIMARY KEY,
/*chave estrangeira*/
idEmpresa INT,
CONSTRAINT fk_empresa
FOREIGN KEY (idEmpresa)
REFERENCES empresa(idEmpresa),
/*Setor*/
setor VARCHAR(60)
);
/* Criando candidata_se */
CREATE TABLE candidata_se ( dataCandidatura date,
statusVaga ENUM('PENDENTE', 'APROVADO', 'REPROVADO'),
/* Criando chaves estrangeiras */
idCandidato INT,
idVaga INT,
CONSTRAINT fk_candidato
FOREIGN KEY (idCandidato)
REFERENCES candidato(idCandidato),
CONSTRAINT fk_vaga
FOREIGN KEY (idVaga)
REFERENCES vaga(idVaga),
PRIMARY KEY(idCandidato, idVaga)
);
